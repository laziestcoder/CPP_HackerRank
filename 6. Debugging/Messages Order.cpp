#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


///Editable

class Message
{
private:
    static int id;
    int cu_id;
    string msg;
public:
    Message(){}

    ///new method / member function
    void setMsg(string text){
        msg = text;
        cu_id++;
    }

    const string& get_text()
    {
        ///2nd edit
        return msg;
    }
    bool operator < (const Message &m) const {
        return cu_id < m.cu_id;
    }
};

class MessageFactory
{
public:
    MessageFactory(){}
    Message create_message(const string& text)
    {
        ///4th edit
        Message msg;
        msg.setMsg(text);
        return msg;
    }
};


///Editable ends
class Recipient
{
public:
    Recipient() {}
    void receive(const Message& msg)
    {
        messages_.push_back(msg);
    }
    void print_messages()
    {
        fix_order();
        for (auto& msg : messages_)
        {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order()
    {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network
{
public:
    static void send_messages(vector<Message> messages, Recipient& recipient)
    {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages)
        {
            recipient.receive(msg);
        }
    }
};



int main()
{
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text))
    {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

/**
Editorial by pkacprzak
The idea is have a class Message that can hold the text value as well as the unique identifier that can be used to order the messages by the < operator. Then, MessageFactory can hold an internal counter which current value will be passes to every of created message and then incremented.

Set by pkacprzak
Problem Setter's code:

class Message {
public:
    Message() {}
    Message(const string& text, int id) : text_(text), id_(id) {}
    const string& get_text() {
        return text_;
    }
    bool operator<(const Message& rhs) const {
        return this->id_ < rhs.id_;
    }
private:
    string text_;
    int id_;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text, current_id++);
    }
private:
    int current_id = 0;
};
*/
