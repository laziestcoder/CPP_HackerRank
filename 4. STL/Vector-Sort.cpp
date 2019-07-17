#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <int> v;
    int s,n;
    cin>>n;
    while(n--){
        cin>>s;
        v.push_back(s);
    }
    s = v.size();
    sort(v.begin(),v.end());
    n=0;
    while(s--){
        cout<<v.at(n)<<" ";
        n++;
        //v.pop_back();
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
    //* Enter your code here. Read input from STDIN. Print output to STDOUT
    int n=0,a=0;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        cout<<v[i];
        cout<<" ";
    }
    return 0;
}
--------------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N = 0;
    cin>>N;

    vector<int> vecInt;
    int number = 0;

    while (cin>>number)
        vecInt.push_back(number);

    sort(vecInt.begin(), vecInt.end());

    for ( vector<int>::iterator it = vecInt.begin(); it != vecInt.end(); it++)
        cout<<*it<<" ";
    return 0;
}

----------------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int>v;
    int N;
    int a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    return 0;
}

*/
