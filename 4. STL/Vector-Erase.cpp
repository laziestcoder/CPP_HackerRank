#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <int> v;
    int s,n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }
    cin>>n>>a>>b;
    a>b? a=a:b=a,a=b;
    a==0?a:a-=1;

    v.erase(v.begin()+(a-1),v.begin()+b);
    s = v.size();
    cout<<s<<endl;
    n=0;
    while(s--)
    {
        cout<<v.at(n)<<" ";
        n++;
    }
    cout<<endl;
    return 0;
}

/**
Other Solutions
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    vector <long long int> v;
    long long n,x,a,b;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    cin>>x>>a>>b;
    v.erase(v.begin()+x-1);
    v.erase(v.begin()+a-1,v.begin()+b-1);
    cout<<v.size()<<endl;
    for(long long i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}

---------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, a, x, b, c;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    cin >> x >> b >> c;
    v.erase(v.begin() + x - 1);
    v.erase(v.begin() + b - 1, v.begin() + c - 1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
---------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    vector<int> data;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        data.push_back(x);
    }
    int p;
    cin >> p;
    p--;
    data.erase(data.begin()+p);

    int l,u;
    cin >> l >> u;
    l--;
    u--;
    data.erase(data.begin()+l,data.begin()+u);

    cout << data.size() << endl;
    for (auto a : data) {
        cout << a << " ";
    }
    return 0;
}
*/
