#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=n-1;i>=0;i--){
        cout<<a[i];
        if(i!=0)
        cout<<" ";
    }
    cout<<endl;

    return 0;
}
/**
Different Solutions
#include <iostream>
int main() {
    int N,i=0;
    std::cin>>N;
    int *A = new int[N];
    while(std::cin>>A[i++]);
    while(std::cout<<A[--N]<<' ' && N);
    delete[] A;
    return 0;
}

----------------
#include <iostream>
using namespace std;


// Every C++ program starts with the main method
int main() {

    // Declare a variable, N for the number of
    // values entered in from stdin
    int N;
    // Declare a variable i for incrementing
    int i=0;
    // Read in the initial value from cin into N,
    // for the number of elements in the array
    cin>>N;
    // Declare a pointer of type int, called A,
   // and allocated new memory for it of size N
    int *A = new int[N];

    // Setup a while loop for as long as cin
    // is reading in variables, all into the array, A
    while(std::cin>>A[i++]);

    // Setup another while loop to output (cout) every
    // value in A in reverse, using --N to decrement the
    // the value of N so long as N is true (not equal to zero)
    while(std::cout<<A[--N]<<' ' && N);

    // Un-allocate the memory given to A
    delete[] A;

    // Return zero to indicate success
    return 0;
}
----------------
Judges Solution


*/
