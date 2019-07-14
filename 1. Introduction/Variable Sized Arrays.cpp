#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int>a[100005];
    int n,q,i,m;
    cin>>n>>q;
    for(i=0;i<n;i++){
        int j;
        cin>>m;
        for(j=0;j<m;j++){
            int v;
            cin>>v;
            a[i].push_back(v);
        }
    }
    for(i=0; i<q;i++){
        cin>>n>>m;
        cout<<a[n][m]<<endl;
    }

    return 0;
}
