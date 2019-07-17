#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Write Your Code Here
    if(n==1) cout<<"one";
    else if(n==2) cout<<"two";
    else if(n==3) cout<<"three";
    else if(n==4) cout<<"four";
    else if(n==5) cout<<"five";
    else if(n==6) cout<<"six";
    else if(n==7) cout<<"seven";
    else if(n==8) cout<<"eight";
    else if(n==9) cout<<"nine";
    else cout<<"Greater than 9";
    cout<<endl;
    return 0;
}
/**
Judges Solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;
    if(n == 1) {
        cout << "one";
    }
    else if(n == 2) {
        cout << "two";
    }
    else if(n == 3) {
        cout << "three";
    }
    else if(n == 4) {
        cout << "four";
    }
    else if(n == 5) {
        cout << "five";
    }
    else if(n == 6) {
        cout << "six";
    }
    else if(n == 7) {
        cout << "seven";
    }
    else if(n == 8) {
        cout << "eight";
    }
    else if(n == 9) {
        cout << "nine";
    }
    else {
        cout << "Greater than 9";
    }

    return 0;
}

-----------------------------------------
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    string represent[10] = {"Greater than 9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cin >> n;

    if(n > 9) {
        cout << represent[0];
    }
    else {
        cout << represent[n];
    }

    return 0;
}


*/
