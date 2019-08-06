/// I COULD NOT SOLVE this problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void answer(unsigned n,unsigned s, unsigned p, unsigned q){
    vector <int > a;
    set <int> st;
    unsigned i,w;
    w = 1U<<31;  ///2^31
    //a[0] = s%w;
    a.push_back(s % w);
    st.insert(a[0]);
    for(i=1;i<n;i++){
        a[i] = (a[i-1]*(p+q)) % w;
        st.insert(a[i]);
    }
   // cout<<"works"<<endl;
    cout<<st.size()<<endl;
}


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    unsigned long long int n,s,p,q;
    cin>>n>>s>>p>>q;
    answer(n,s,p,q);

    return 0;
}
/**
Other Solutions:


#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static unsigned long N, S, P, Q;
const static unsigned long twop31 = (unsigned long)pow(2, 31);
unsigned long f(unsigned long x) { return (x*P + Q) % twop31; }
unsigned long brent(const unsigned long x0) {
    unsigned long power = 1;
    unsigned long lam = 1;
    unsigned long tort = x0;
    unsigned long hare = f(x0);

    while (tort != hare) {
        if (power == lam) {
            if (lam >= N) {
                break;
            }
            tort = hare;
            power *= 2;
            lam = 0;
        }
        lam++;
        hare = f(hare);
    }

    unsigned long mu = 0;
    tort = hare = x0;
    for (unsigned long i = 0; i<lam; i++) {
        hare = f(hare);
    }
    while (tort != hare) {
        tort = f(tort);
        hare = f(hare);
        mu++;
        if (mu == N) return N;
    }
    return lam + mu;
}


int main() {
    set <unsigned long> myset;
     cin >> N >> S >> P >> Q;
    //N = 3; S = 1; P = 1; Q = 1;
    cout << brent(S);
    return 0;
}


--------------------------
#include <vector>
#include <iostream>

unsigned count(unsigned n, unsigned s, unsigned p, unsigned q){
  const unsigned sz=1U<<31;
  std::vector<bool> bs(sz);
  unsigned long a=s%sz, ct=1;
  bs[a]=true;
  for(unsigned i=1;i<n;++i){
    a*=p;
    a=(a+q)%sz;
    if(bs[a]){ return ct; }
    else{
      bs[a]=true;
      ++ct;
    }
  }
  return ct;
}

int main(){
  unsigned n=0,s=0,p=0,q=0;
  std::cin >> n >> s >> p >> q;
  std::cout << count(n,s,p,q);
}
------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define f(x, p, q) ( (x * p) + q )

typedef unsigned long long ULONG;

int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    ULONG p_231 = static_cast<ULONG>(pow(2, 31));

    ULONG x0 = s % p_231;
    ULONG vals = 1;

    ULONG tort = f(x0, p, q) % p_231;
    ULONG hare = f(x0, p, q) % p_231;
    hare = f(hare, p, q) % p_231;

    while (tort != hare) {
        if (vals >= n) {
            cout << vals << endl;
            return 0;
        } else {
            vals++;
        }
        tort = f(tort, p, q) % p_231;
        hare = f(hare, p, q) % p_231;
        hare = f(hare, p, q) % p_231;
    }

    ULONG mu = 0;
    tort = x0;
    while (tort != hare) {
        tort = f(tort, p, q) % p_231;
        hare = f(hare, p, q) % p_231;
        mu++;
    }

    ULONG lam = 1;
    hare = f(tort, p, q) % p_231;
    while (tort != hare) {
        hare = f(hare, p, q) % p_231;
        lam++;
    }

    cout << lam + mu << endl;

    return 0;
}
--------------------
Set by mikbalkazar
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

const unsigned M = (1ll << 31) - 1;
const int MAX = 1 << 26;
const int K = 16;
const int MSK = (1 << K) - 1;

int kb[1 << K];
unsigned f[MAX];

int main(){

#ifdef KAZAR
  freopen("f.input","r",stdin);
  freopen("f.output","w",stdout);
  freopen("error","w",stderr);
#endif

  int n = read();
  unsigned s, p, q;
  cin >> s >> p >> q;

  f[s >> 5] |= 1u << (s & 31);
  for (int i = 1; i < n; i++) {
    s = (s * p + q) & M;
    f[s >> 5] |= 1u << (s & 31);
  }

  for (int i = 0; i < (1 << K); i++) {
    kb[i] = kb[i >> 1] + (i & 1);
  }

  int res = 0;
  for (int i = 0; i < MAX; i++) {
    res += kb[f[i] >> 16] + kb[f[i] & MSK];
  }
  printf("%d\n", res);

  return 0;
}
*/
