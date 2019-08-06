
#include <iostream>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};
// Enter your code here.
 ostream& operator << (ostream& output, const Person& P){
        output <<"first_name=" << P.get_first_name() << ",last_name=" << P.get_last_name();
        return output;
    }


int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}
/**
editorial:
The most important thing is to have the correct signature of the operator. Since it's going to be used as follows:

cout << p << SOME_OTHER_VALUES

which is going to be executed as:

(cout << p) << SOME_OTHER_VALUES

then << operator for class Person must return a non-const reference to ostream object passes as the argument. Thus, the signature is:

ostream& operator<<(ostream& os, const Person& p)

and after the operator passes the correctly formatted data to the os, then it has to return the os object.
-------------------------------------
Problem Setter's code:

ostream& operator<<(ostream& os, const Person& p) {
    os << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
    return os;
}
*/
