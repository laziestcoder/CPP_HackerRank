#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val) {};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val) {};
};

class Cache
{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache: public Cache{
public:
    LRUCache(int capacity)
    {
        cp =capacity;

    }
    void set(int k, int val)
    {
        Node *node;

        if(mp.empty())
        {
            node = new Node(k,val);
            tail = head = node;
            mp[k] = node;
            return;
        }
        auto it = mp.find(k);
        if(it !=mp.end())
        {
            it->second->value = val;
            if(head == it->second)
            {
                return;
            }
            it->second->prev->next = it->second->next;
            if(tail == it->second)
            {
                tail = tail->prev;
            }
            else
            {
                it->second->next->prev = it->second->prev;
            }
            it->second->next = head;
            it->second->prev = nullptr;
            head->prev = it->second;
            head = it->second;
        }
        else
        {
            node = new Node(head->prev,head,k,val);
            head->prev = node;
            head = node;
            mp[k] = node;

            if(mp.size() > cp)
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = nullptr;
            }

        }
    }
    int get(int k)
    {
        auto it = mp.find(k);
        if (it != mp.end())
        {
            return it->second->value;
        }

        return -1;
    }
};

int main()
{
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0; i<n; i++)
    {
        string command;
        cin >> command;
        if(command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
/**
Other Solution:
class LRUCache : public Cache {
public:
    LRUCache(size_t capacity)
    {
        cp = capacity;
        tail = 0;
        head = 0;
    }

    ~LRUCache() {
        while(tail) {
            auto node = tail;
            tail = tail->prev;
            delete node;
        }
    }

    // Set/insert the value off the key, if present, otherwise
    // add the key as the most recently used key. If the cache
    // has reached its capacity, it should replace the least
    // recently used key with a new key.
    void set(int key, int value) {
        Node* node;
        auto it = mp.find(key);
        if(mp.end() == it) {
            if(mp.size() < cp) {
                node = new Node(key, value);
                if(tail) {
                    tail->next = node;
                    node->prev = tail;
                } else {
                    tail = node;
                    head = node;
                }
            } else {
                node = tail;
                mp.erase(tail->value);
            }
            mp.insert(make_pair(key, node));
        } else {
            node = it->second;
        }
        node->key = key;
        node->value = value;
        set_mru(node);
    }

    // Get the value (will always be positive) of the key
    // if the key exists in the cache and then make that key
    // as the most recently used key; otherwise, return -1.
    int get(int key) {
        auto it = mp.find(key);
        if(mp.end() == it)
            return -1;

        auto node = it->second;
        set_mru(node);
        return node->value;
    }

private:
    void set_mru(Node* node) {
        if(node->next) {
            node->next->prev = node->prev;
        }
        if(node->prev) {
            node->prev->next = node->next;
        }
        if(tail == node)
            tail = node->prev;
        node->prev = 0;
        node->next = head;
        head = node;
    }
};
-------------
class LRUCache {
public:
	map<int, int> mp;
	LRUCache(int x) {}
	int get(int key) {
		if (mp.count(key)) return mp[key];
		return -1;
	}
	void set(int key, int val) {
		mp[key] = val;
	}
};
-------------
class LRUCache : public Cache {
    public:
      LRUCache(int cap) {
          cp = cap;
          head = new Node(-1, -1);
          head->prev = NULL;
          head->next = NULL;
          tail = head;
          for (int i = 0; i < cap; ++i) {
              Node *o = tail;
              tail = new Node(-1, -1);
              tail->next = NULL;
              tail->prev = o;
              o->next = tail;
          }
      }
      void set(int k, int v) {
          if (mp[k]) { mp[k]->key = k; mp[k]->value = v; return; }
          Node *a = new Node(k, v);
          a->next = head;
          a->prev = NULL;
          head->prev = a;
          head = a;
          mp[k] = head;

          a = tail->prev;
          if (tail->key >= 0) {
              mp[tail->key] = NULL;
          }
          delete tail;
          tail = a;
      }

      int get(int k) {
          if (mp[k]) return mp[k]->value;
          return -1;
      }
};
-------------
*/
