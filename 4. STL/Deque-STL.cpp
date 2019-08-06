#include <iostream>
#include <deque>
using namespace std;
// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
void printKMax(int arr[], int n, int k)
{
    //Write your code here.
    deque <int> dq(k);//Creates a double ended queue of deque of int type
    //mydeque.push_back(1); //Pushes element at the end
    //mydeque.push_front(2); //Pushes element at the beginning

    //mydeque.pop_back(); //Pops element from the end
    //mydeque.pop_front(); //Pops element from the beginning
    //mydeque.empty() //Returns a boolean value which tells whether the deque is empty or not
    //int length = mydeque.size();
    int i;
    for(i=0; i<k; i++)
    {
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for( ; i<n; i++)
    {
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()] <<endl;
}

int main()
{

    int t;
    cin >> t;
    while(t>0)
    {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0; i<n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}

/**
Other Solutions
#include <iostream>
#include <deque>
#include <vector>
#include<algorithm>
//using namespace std;


int main()
{

   int T;
   scanf("%d", &T);
   for (int t=0; t < T; t++)
   {
      int n, k;
       std::cin >> n >> k;
       std::deque<int> arr;
       for( int j=0; j<n; j++)
       {
           int x;
           scanf("%d", &x);
           arr.push_back(x);

       }
        int first_max = *max_element(arr.begin(), arr.begin()+k);
        int max = (int)first_max;
        int y = arr[0];
        std::cout << max <<" ";
        arr.pop_front();
        int i=0;
        while( i < n-k)
        {
            if (y != max)
            {
                if (arr[k-1] > max)
                {
                   printf("%d ", arr[k-1]);
                    max = (int)arr[k-1];
                }
                else
                {
                    printf("%d ", max);
                }

            }
            else
            {
                   int maxss = *max_element(arr.begin(), arr.begin()+k);
                   max = (int)maxss;
                   printf("%d ", max);
                    }
           y = arr[0];
           arr.pop_front();
           i++;

             }


       std::cout << std::endl;

   }
     return 0;
}
----------------------
Problem Setter's code:

#include <iostream>
#include <deque>

using namespace std;

// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k
void printKMax(int arr[], int n, int k)
{
    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in Qi, i.e.,
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int>  Qi(k);

    // Process first k (or first window) elements of array
    int i;
    for (i = 0; i < k; ++i)
    {
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();  // Remove from rear

        // Add new element at rear of queue
        Qi.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i)
    {
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";

        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue

        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

         // Add current element at the rear of Qi
        Qi.push_back(i);
    }

    // Print the maximum element of last window
    cout << arr[Qi.front()] << endl;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while(t>0) {
    int n,k;
    cin >> n >> k;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
    cin >> arr[i];
    printKMax(arr, n, k);
    t--;
    }
    return 0;
}
-----------
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct Val {
	int x;
	Val() : x(-INF) {}
	Val(int x_) : x(x_) {}
	Val &operator+=(const Val &that) {
		amax(x, that.x);
		return *this;
	}
};

struct TwoStackQueue {
	typedef Val Sum;

	//queue = reverse(vals2) ++ vals1
	vector<Val> vals1, vals2;
	vector<Sum> sums1, sums2;

	pair<Sum,Sum> getsumparts() const {
		Sum s1 = sums1.empty() ? Sum() : sums1.back();
		Sum s2 = sums2.empty() ? Sum() : sums2.back();
		return make_pair(s1, s2);
	}
	void push(const Val &v) {
		Sum s = !sums1.empty() ? sums1.back() : Sum();
		s += v;
		vals1.push_back(v);
		sums1.push_back(s);
	}
	void pop() {
		ensure();
		if(!vals2.empty()) {
			vals2.pop_back();
			sums2.pop_back();
		}
	}

private:
	void ensure() {
		if(!vals2.empty()) return;
		reverse(all(vals1));
		vals2.swap(vals1);
		sums1.clear();
		Sum s;
		sums2.resize(vals2.size());
		for(size_t i = 0; i < vals2.size(); ++ i) {
			s += vals2[i];
			sums2[i] = s;
		}
	}
};

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int N, K;
		scanf("%d%d", &N, &K);
		vector<int> A(N);
		for(int i = 0; i < N; ++ i)
			scanf("%d", &A[i]);
		TwoStackQueue q;
		rep(i, K)
			q.push(A[i]);
		vector<int> ans(N - K + 1);
		for(int i = K;; ++ i) {
			pair<Val,Val> p = q.getsumparts();
			ans[i - K] = max(p.first.x, p.second.x);
			if(i == N) break;
			q.pop();
			q.push(A[i]);
		}
		for(int i = 0; i < N - K + 1; ++ i) {
			if(i != 0) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}
------------
#include<bits/stdc++.h>
using namespace std;
int main(){

  int t;
  cin >> t;
  while(t--){
       int n , k , x ;
       cin >> n >> k ;

       vector<int> vec;
       for(int i =  0 ; i < n ; ++i ){
          cin >> x;
          vec.push_back(x);
       }
        int mx = 0;
        vector<int> nval;
       for(int i =  0 ; i < n ; ++i ){

                  if(i%k == 0)
                   mx = vec[i];
                else
                mx = max( mx , vec[i] );
                nval.push_back(mx);
       }
       mx = 0;
       vector<int> val;
       for(int i = n-1 ; i >= 0 ; --i ){
             if(i%k == (k-1))
               mx = vec[i];
               else
               mx = max( mx , vec[i]);
               val.push_back(mx);

       }
       for(int i = 0 ; i < vec.size()-k+1  ; ++i )
             cout << max( nval[i+k-1] , val[val.size()-i-1]) <<" ";
             cout << endl;
             }
             return 0;

}
------------------
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>

#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(auto it= (o).begin(); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inrep int t;cin>>t; while(t--)
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii > vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll > vpll;
typedef vector<string> vs;
typedef long double ld;

template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )
        o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )
        o<<" "<<v[i];
    return o<<endl;
}
template<typename T,typename U> ostream& operator<< ( ostream &o,pair<T,U> v ) {

    return o<<"("<<v.first<<", "<<v.second<<")";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {

    for ( unsigned   i=0; i<v.size(); i++ )
        in>>v[i];
    return in;
}
int main() {
    ios_base::sync_with_stdio ( false );
    inrep {
        int n,k;
        cin>>n>>k;
        vi a ( n );
        cin>>a;
        deque<pii> d;
        vi res;
        rep ( i,k ) {
            while ( !d.empty() && a[i]>d.back().first )
                d.pop_back();
            d.push_back ( mp ( a[i],i ) );
        }
        reu ( i,k,n ) {
//             cout<<vpii ( all ( d ) );
            res.push_back ( d.front().first );
            if ( d.front().second==i-k ) d.pop_front();
            while ( !d.empty() && a[i]>d.back().first )
                d.pop_back();
            d.push_back ( mp ( a[i],i ) );

        }
        res.push_back ( d.front().first );
        cout<<res;
    }
}
-------------
#include <iostream>
#include <deque>
#include <vector>
#include<algorithm>
using namespace std;


int main(){

   int T;
   scanf("%d", &T);
   for(int t=0; t<T; t++){
      int n,k;
       cin>>n>>k;
       deque<int> arr;   // read in the data
       for(int j=0;j<n;j++){
           int x;
           scanf("%d", &x);
           arr.push_back(x);

       }
        int fist_max=*max_element(arr.begin(), arr.begin()+k); // find the max for the fist subset
        int max=(int)fist_max; // read the value from the pointer
       int y=arr[0];          // read the first element of the first subset
       printf("%d ", max);    // print the max for the first subset
       arr.pop_front();       // remove the first element of the first subset
       int i=0;
       while(i<n-k){
            if (y!=max){      // if the previously removed value is not the max of that subset
                if (arr[k-1]>max){   // if the newly added value is bigger than the previous max value
                   printf("%d ", arr[k-1]); // the newly added value is the new max
                    max=(int)arr[k-1];   // update the max
                }
                else{
                    printf("%d ", max); // if the newly added value is smaller than the previous max value
                }                         // the max remains the same

            }
            else {  // if the previous max value is dropped from the current subset
                   int maxss=*max_element(arr.begin(), arr.begin()+k); // find the new max of the current subset
                   max=(int)maxss;    // assign the value to the variable
                   printf("%d ", max);  // print the max
                    }
           y=arr[0];   // reset the first value to compare with the max for next subset
           arr.pop_front(); // drop the first element of the subset
           i++;

             }

       printf("\n");

   }
     return 0;
}
*/
