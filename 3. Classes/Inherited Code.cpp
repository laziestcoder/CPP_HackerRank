#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException
{
private:
    int n;
public:
    BadLengthException(int n) /// I have use two n as variable
    {
        this->n = n;  /// this->n means class property and n means the argument/parameter
    }
    //virtual const int what() const throw(){ /// correct one
    const int what() const throw()  /// it also works
    {
        return n;
    }
};


bool checkUsername(string username)
{
    bool isValid = true;
    int n = username.length();
    if(n < 5)
    {
        throw BadLengthException(n);
    }
    for(int i = 0; i < n-1; i++)
    {
        if(username[i] == 'w' && username[i+1] == 'w')
        {
            isValid = false;
        }
    }
    return isValid;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string username;
        cin >> username;
        try
        {
            bool isValid = checkUsername(username);
            if(isValid)
            {
                cout << "Valid" << '\n';
            }
            else
            {
                cout << "Invalid" << '\n';
            }
        }
        catch (BadLengthException e)
        {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}

/**
Solutions:
Your exception should have this header:

class BadLengthException: public exception
and should define the following function:

virtual const char* what() const throw()

-----------
Problem Setter's code:
class BadLengthException: public exception {
      private:
        char *msg;

      public:
        BadLengthException(int len) {
            msg = new char[2];
            msg[0] = len+'0'; // len < 5
            msg[1] = '\0';
        }

        virtual const char* what() const throw() {
            return msg;
        }
    };
--------------

*/
