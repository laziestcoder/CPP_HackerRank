
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    set<int>s;
    set<int>::iterator itr;
    int q,n,x;
    cin>>q;
    while(q--){
        cin>>n;
        if(n==1){
            cin>>x;
            s.insert(x);
        }
        else if(n==2){
            cin>>x;
            itr = s.find(x);
            //cout<<itr<<endl;
            if(itr != s.end()) s.erase(x);
        }else{
            cin>>x;
            itr = s.find(x);
            if(itr !=s.end()) cout<<"Yes"<<endl; else cout<<"No"<<endl;
        }
    }
    return 0;
}

/**
Others Solutions:
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int c,t,n;
    scanf("%d",&n);
    set<int> ns;
    while(n--) {
        scanf("%d %d",&c,&t);
        switch(c) {
            case 1:
                ns.insert(t);
                break;
            case 2:
                ns.erase(t);
                break;
            case 3:
                if (ns.find(t)!=ns.end())
                    cout << "Yes"<<endl;
                else
                    cout <<"No"<<endl;
                break;
            default:
                cout<<"invalid switch value: "<<c<<endl;

        }
    }

    return 0;
}
--------------------------
#include <bits/stdc++.h>
using namespace std;


int main() {

    set<long long> s;
    set<long long>::iterator it;
    long long q,x;
    int qt;
    cin>>q;
    while(q--){
        cin>>qt>>x;
        switch(qt){
            case 1:s.insert(x);
                    break;
            case 2:s.erase(x);
                    break;
            case 3:it=s.find(x);
                    if(it==s.end())
                        cout<<"No"<<endl;
                    else
                        cout<<"Yes"<<endl;
                    break;
        }
    }
    return 0;
}

---------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int q;
    cin >> q;
    set<int> data;
    while (q--) {
        int t, n;
        cin >> t >> n;

        switch (t) {
            case 1:
                data.insert(n);
            break;

            case 2:
                data.erase(n);
            break;

            case 3:
                if (data.find(n) != data.end())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            break;
        }
    }

    return 0;
}

*/

