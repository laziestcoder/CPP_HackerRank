#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //m.erase(val);

    map<string, int> m;
    map<string,int>::iterator it;
    int q,n,x;
    string s;
    cin>>q;
    while(q--)
    {
        cin>>n;
        if(n==1)
        {
            cin>>s>>x;
            if(m.find(s) != m.end()){
             it = m.find(s);
             //cout<<it->second<<endl;
             x += it->second;
             //cout<<"x1 = "<<x<<endl;
             m.erase(s);
            }
            //cout<<"x2 = "<<x<<endl;
            m.insert(make_pair(s,x));
        }
        else if(n==2)
        {
            cin>>s;
            m.erase(s);
        }
        else
        {
            cin>>s;
            if(m[s])
            {
                cout<<m[s]<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
/**
Other Solutions:
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    map<string, int> m;

    while (n--) {
        int t;
        cin >> t;

        string s;
        cin >> s;

        if (t == 1) {
            int a;
            cin >> a;

            m[s] += a;
        } else if (t == 2) {
            m[s] = 0;
        } else {
            cout << m[s] << "\n";
        }
    }

    return 0;
}
-------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int Q;
    cin >> Q;

    map<string,int> student_marks;

    while ( Q-- ) {
        int qtype;
        cin >> qtype;

        string name;
        cin >> name;

        switch ( qtype ) {
            case 1 : {

                int marks;
                cin >> marks;

                int oldmarks = student_marks[name];
                oldmarks += marks;
                student_marks[name] = oldmarks;

                break;
            }
            case 2 : {
                student_marks[name] = 0;
                break;
            }

            case 3 : {
                cout << student_marks[name]  << endl;
                break;
            }

        }
    }

    return 0;
}
-------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    ///* Enter your code here. Read input from STDIN. Print output to STDOUT
    int n;
    cin >> n;
    map<string, int> m;
    map<string, int>::iterator itr;
    for (int i=0; i<n; ++i) {
        string s;
        int c, n;
        cin >> c;
        switch (c) {
            case 1:
                cin >> s >> n;
                if ((itr = m.find(s)) != m.end()) {
                    itr->second += n;
                } else {
                    m.insert(make_pair(s, n));
                };
                break;
            case 2:
                cin >> s;
                m.erase(s);
                break;
            case 3:
                cin >> s;
                cout << (((itr = m.find(s)) != m.end()) ? itr->second : 0) << endl;
                break;
            default:;
        };
    };
    return 0;
}

*/


