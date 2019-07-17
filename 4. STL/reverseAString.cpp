#include <iostream>
using namespace std;

string FirstReverse(string str) {

  // code goes here
  for(int i=0,j=str.length()-1;i<str.length()/2;i++,j--)
  {
    str[i]^=str[j]^=str[i]^=str[j];
  }
  return str;

}

int main() {

  // keep this function call here
  cout << FirstReverse(gets(stdin));
  return 0;

}


/**
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string FirstReverse(string str) {

    vector <char> s;
    int i;
    for(i=str.size()-1;i>=0 ;i --){
        s.push_back(str[i]);
    }
    for(i=0;i<str.size();i++){
        str[i]=s[i];
    }
  // code goes here
  return str;

}

int main() {

  // keep this function call here
  cout << FirstReverse(gets(stdin));
  return 0;

}

*/
