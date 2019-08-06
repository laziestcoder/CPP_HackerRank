
/* Enter your macros here */
#define INF 1000000000
#define toStr(s) #s
#define io(a) cin>>a
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define foreach(x,i) for(int i=0; i<x.size();i++)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
/**
Other Solution
// Enter your macros here
#define toStr(a) #a
#define io(v) cin >> v
#define FUNCTION(f, op) void f(int &x, int y){ if (y op x) x=y; }
#define INF 0x3fffffff
#define foreach(v, i) for (int i=0; i<v.size(); i++)

----------------------
// Enter your macros here

#define io(v) cin >> v
#define foreach(v, i) for (int i = 0; i < v.size(); i++)
#define minimum(a, b) a = min(a, b)
#define maximum(a, b) a = max(a, b)
#define toStr(s) #s
#define FUNCTION(fun, cmp)
#define INF 0x3f3f3f3f

----------------------
// Enter your macros here
#define minimum(a, b) a = min(a, b)
#define maximum(a, b) a = max(a, b)
#define INF ((1 << 31)-2)

#define io(a) cin >> a
#define toStr(a) string("Result =")

#define FUNCTION(a, b) //
#define foreach(a, b) for (int i = 0; i < a.size(); ++i)

----------------------
Problem Setter's code:

// Sample solution
#define toStr(x) #x
#define io(s) cin >> s
#define foreach(list, index) for(int index = 0; index < list.size(); index++)
#define FUNCTION(name, op) void name(int &x, int y){ if(!(x op y)) x = y; }
#define INF 1e9

//Locked from here down ---------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
}
*/
