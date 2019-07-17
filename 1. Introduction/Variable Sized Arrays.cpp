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

/**
Judges Solution

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    int q;
    cin >> n >> q;

    // Create an array of pointers to integer arrays
    // (i.e., an array of variable-length arrays)
    int** outer = new int*[n];

    // Fill each index of 'outer' with a variable-length array
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        // Create an array of length 'k' at index 'i'
        outer[i] = new int[k];

        // Fill each cell in the 'inner' variable-length array
        for(int j = 0; j < k; j++) {
            cin >> outer[i][j];
        }
    }

    // Perform queries:
    while(q-- > 0) {
        int outer_index;
        int inner_index;
        cin >> outer_index >> inner_index;

        // Find the variable-length array located at outer_index
        // and print the value of the element at inner_index.
        cout << outer[outer_index][inner_index] << endl;
    }

    return 0;
}

Problem Setter's code:

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <iostream>

#define pb push_back
#define all(x) (x).begin(), (x).end()

#ifdef KAZAR
  #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
  #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

const int N = 123456;

int *a[N];

int main(){

#ifdef KAZAR
  freopen("f.input","r",stdin);
  freopen("f.output","w",stdout);
  freopen("error","w",stderr);
#endif

  int n = read();
  int q = read();

  assert(1 <= n && n <= 1e5);
  assert(1 <= q && q <= 1e5);

  for (int i = 0; i < n; i++) {
    int k = read();
    a[i] = new int[k];
    for (int j = 0; j < k; j++) {
      a[i][j] = read();
    }
  }

  for (int i = 0; i < q; i++) {
    int x = read();
    int y = read();
    printf("%d\n", a[x][y]);
  }

  return 0;
}

Problem Tester's code:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
    int *arr[100004], siz[100004];
    int n,q;
    int tot = 0;
    scanf("%d %d", &n, &q);
    assert(n >= 1 && n <= 100000 && q >= 1 && q <= 100000);
    for(int i = 0 ; i< n ; i++)
    {
        int num;
        scanf("%d", &num);
        assert(num >= 1 && num <= 300000);
        tot += num;
        siz[i] = num;
        arr[i] = (int*)malloc(num*sizeof(int));
        for(int j = 0 ; j < num; j++)
        {
            scanf("%d", &arr[i][j]);
            assert(arr[i][j] >= 0 && arr[i][j] <= 1000000);
        }
    }
    assert(tot >= 1 && tot <= 300000 && tot >= n);
    while(q--)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        assert(a >= 0 && a < n && b >= 0 && b < siz[a]);
        printf("%d\n", arr[a][b]);
    }
    return 0;
}

*/
