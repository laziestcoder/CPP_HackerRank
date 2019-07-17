#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
		/*int a,b;
		vector<int>v;
		a=A;
		cout<<"0x";
		while(a){
            b = a%16;
            v.push_back(b);
            a/=16;
		}
		b = v.size();
		while(b--){
            cout<<v.back();
            v.pop_back();
		}
		cout<<endl;*/
		ios_base::fmtflags flags = cout.flags();
cout << setw(0) << showbase << hex << nouppercase << left << (long long)A << endl;

cout.flags(flags);

cout << fixed << setw(15) << setprecision(2) << setfill('_') << right << showpos << B << endl;

cout.flags(flags);

cout << scientific << setw(15) << setprecision(9) << noshowbase << right << C << endl;

cout.flags(flags);
	}
	return 0;

}
/**
Other Solutions
    // LINE 1
    cout << hex << left << showbase << nouppercase; // formatting
    cout << (long long) A << endl; // actual printed part

    // LINE 2
    cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2); // formatting
    cout << B << endl; // actual printed part

    // LINE 3
    cout << scientific << uppercase << noshowpos << setprecision(9); // formatting
    cout << C << endl; // actual printed part


-----------------

Problem Setter's code:

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        // BEGIN: unlocked
          // Sample solution:
            cout << left << hex << showbase << nouppercase;
            cout << (long long) A << endl;

            // One decimal place, right aligned, show sign, and fill left with underscores
            cout.precision(2);
            cout << showpos << fixed << setfill('_') << setw(15) << right;
            cout << B << endl;

            // Scientific notation with 9 decimal places
            cout.precision(9);
            cout << noshowpos << uppercase << scientific;
            cout << C << endl;
        // END: unlocked
    }
    return 0;
}
-------------------
		// Enter your code here
        typedef long long llint;
        llint AA = llint(A);
        printf("0x%llx\n", AA);

        char tmp[100];
        sprintf(tmp, "%s%.2f", B >= 0? "+": "-", B);
        string sb(tmp);

        for (int i = 0; i + sb.size() < 15; i++) {
            printf("_");
        }
        puts(tmp);

        printf("%.9E\n", C);
------------------------
		// Enter your code here
        printf("0x%llx\n",(long long int)A);

        char q[100];
        sprintf(q,"%+.2lf",B);
        int i=0; while (q[i]!=0) i++;
        while (i<15) {printf("_");i++;}
        printf("%s\n",q);
        printf("%.9lE\n",C);

------------------
		// Enter your code here

    cout << setw(0) << internal;
    const int buf_size = 128;
    char buffer[buf_size] = { 0 };
    long long a = (long long)A;
    sprintf(buffer, "0x%llx", a);
    cout << buffer << endl;

    sprintf(buffer, "%+.2f", B);
    char* head = buffer;
    while (*head)
        head++;
    int len = head - buffer;
    for (int i = 0; i < 15 - len; i++)
        cout << '_';
    cout << buffer << endl;

    sprintf(buffer, "%.9E", C);
    cout << buffer << endl;

*/
