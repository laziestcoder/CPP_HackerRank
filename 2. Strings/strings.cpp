#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program

	string a,b,c;
	cin>>a>>b;
	cout<<a.size()<<" "<<b.size()<<endl;
	cout<<a+b<<endl;
	swap(a[0],b[0]);
	cout<<a<<" "<<b<<endl;
    return 0;
}

/**
Others Solution
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    cout << a.length() << ' ' << b.length() << endl;

    cout << a + b << endl;

    swap( a[0], b[0] );
    cout << a << ' ' <<  b << endl;

    return 0;
}

*/
