#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a,b,n;
    cin>>a>>b;
    for(n=a; n<=b; n++){
         if(n==1) cout<<"one";
        else if(n==2) cout<<"two";
    else if(n==3) cout<<"three";
    else if(n==4) cout<<"four";
    else if(n==5) cout<<"five";
    else if(n==6) cout<<"six";
    else if(n==7) cout<<"seven";
    else if(n==8) cout<<"eight";
    else if(n==9) cout<<"nine";
    else if(n>9 && n%2==0) cout<<"even";
    else cout<<"odd";
    cout<<endl;
    }
    return 0;
}
/**
Judges Solution
Problem Tester's code:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int a, b;
    string represent[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> a >> b;
    for(int i = a; i <= b; i++) {

        if(i > 9) {
            if(i % 2 == 0)
                cout << "even\n";
            else cout << "odd\n";
        }
        else {
            cout << represent[i]<<endl;
        }
    }
    return 0;
}

*/
