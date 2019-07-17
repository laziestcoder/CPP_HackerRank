
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
    pair<vector<int>::iterator, vector<int>::iterator> flag;
    vector<int>::iterator low,up;

    int s,n,q,i,l;
    cin>>n;
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }
    s=v.size();
    cin>>q;
    while(q--)
    {
        cin>>n;
        flag = equal_range(v.begin(), v.end(), n);
        int result;
        //cout<<flag.first - v.begin();

        //up = upper_bound (v.begin(), v.end(), 20);
        result = binary_search (v.begin(), v.end(), n);
        if(result)
        {
            cout<<"Yes "<<flag.first - v.begin() +1 <<endl;
        }
        else
        {
            low = lower_bound (v.begin(), v.end(), n);
            cout<<"No "<<low - v.begin() + 1<<endl;
        }
    }

    return 0;
}
/**
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    vector<long long int> v;
    long long n,q,x;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>q;
        v.push_back(q);
    }
    cin>>q;
    vector<long long>::iterator low,up;
    while(q--){
        cin>>x;
        if(binary_search(v.begin(),v.end(),x)){
            low=lower_bound(v.begin(),v.end(),x);
            cout<<"Yes "<<(low-v.begin()+1)<<endl;
        }
        else{
            up=upper_bound(v.begin(),v.end(),x);
            cout<<"No "<<(up-v.begin()+1)<<endl;
        }
    }
    return 0;
}

-------------
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

    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int index = lower_bound (data.begin(), data.end(), x) - data.begin();
        if (data[index] == x)
            cout << "Yes ";
        else
            cout << "No ";

        cout << index + 1 << endl;
    }
    return 0;
}
-------------
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   int N;
   cin >> N;

   vector<int> V(N);

   for(auto & v : V)
      cin >> v;

   int Q;
   cin >> Q;

   while(Q--)
   {
      int Y;
      cin >> Y;

      auto it = lower_bound(V.begin(), V.end(), Y);

      if(*it == Y)
         cout << "Yes ";
      else
         cout << "No ";

      cout << (it - V.begin() + 1) << endl;
   }


   return 0;
}
*/
