#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

/**
//class structure

class ClassName {
    access_specifier1:
        type1 val1;
        type2 val2;
        ret_type1 method1(type_arg1 arg1, type_arg2 arg2,...)
        ...
    access_specifier2:
        type3 val3;
        type4 val4;
        ret_type2 method2(type_arg3 arg3, type_arg4 arg4,...)
        ...
};
*/
class Student
{
private:
    int age,standard;
    string first_name, last_name;

public:
    void set_age(int a)
    {
        age = a;
    }
    void set_standard(int a)
    {
        standard = a;
    }
    void set_first_name(string a)
    {
        first_name = a;
    }
    void set_last_name(string a)
    {
        last_name = a;
    }

    int get_age()
    {
        return age;
    }
    int get_standard()
    {
        return standard;
    }
    string get_first_name()
    {
        return first_name;
    }
    string get_last_name()
    {
        return last_name;
    }
    string reverse_String(string s)
    {
        string rs="";
        for(int i=s.size()-1; i>=0; i--)
        {
            rs += s[i];
        }
        return rs;
    }
    string toString(int a)
    {
        string s = "";

        do
        {
            s+= (a%10)-0+'0';
            a/=10;
        }
        while(a!=0);
        return reverse_String(s);
    }

    string to_String()
    {
        string s="";
        s += toString(age);
        s+=',' + first_name + ',' + last_name + ',';
        s+= toString(standard);
        return s;
    }


};

int main()
{
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_String();

    return 0;
}

/**
Other Solutions
#include <iostream>
#include <sstream>
using namespace std;


//**Enter code for class Student here.
//**Read statement for specification.

class Student{
    public:
        int age, standard;
        string first_name, last_name;
        void set_age(int a){
            age = a;
        }
        void set_first_name(string a){
            first_name = a;
        }
        void set_last_name(string a){
            last_name = a;
        }
        void set_standard(int a){
            standard = a;
        }
        int get_age(){
            return age;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        int get_standard(){
            return standard;
        }
	   string t_string(){
           string s = "";
           s+=to_string(age);
           s+=",";
           s+=first_name;
           s+=",";
           s+=last_name;
           s+=",";
           s+=to_string(standard);
           return s;
	   }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.t_string();

    return 0;
}

----------------------

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

class Student {
    private:
        int age;
        string first_name;
        string last_name;
        int standard;
    public:
        string to_string(){
            return NumberToString(age) + "," + first_name + "," + last_name + "," + NumberToString(standard);
        }
        void set_age(int a) {
            age = a;
        }
        void set_first_name(string a) {
            first_name = a;
        }
        void set_last_name(string a) {
            last_name = a;
        }
        void set_standard(int a) {
            standard = a;
        }
        int get_age() {
            return age;
        }
        string get_first_name() {
            return first_name;
        }
        string get_last_name() {
            return last_name;
        }
        int get_standard() {
            return standard;
        }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
*/

