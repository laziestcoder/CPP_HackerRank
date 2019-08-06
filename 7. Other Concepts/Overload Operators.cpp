/**
You are given a class - Complex.

class Complex
{
public:
    int a,b;
};
Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:

type operator sign (parameters) { //... body .../ }
You need to overload operators + and << for the Complex class.

The operator + should add complex numbers according to the rules of complex addition:

(a+ib)+(c+id) = (a+c) + i(b+d)
Overload the stream insertion operator << to add "a+ib" to the stream:

cout<<c<<endl;
The above statement should print "a+ib" followed by a newline where a=c.a and b =c.b .
*/

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

///Overload operators + and << for the class complex
///+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
///<< should print a complex number in the format "a+ib"
Complex operator + (Complex cm1, Complex cm2){
    Complex sum;
    sum.a = cm1.a + cm2.a ;
    sum.b = cm1.b + cm2.b ;
    return sum;
}
ostream& operator <<(ostream& output, Complex cm_num)
    {
        output <<cm_num.a<<"+i"<<cm_num.b<<endl;
        return output;
    }

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

/**
Other Solutions:


//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator + (const Complex & a, const Complex & b) {
    return Complex{a.a + b.a, a.b + b.b};
}

ostream & operator << (ostream & os, const Complex & a) {
    os << a.a << "+i" << a.b;
    return os;
}
-------------------
Problem Tester's code:

//Operator Over

#include<iostream>

using namespace std;

class complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

complex operator+(const complex &A, complex &B)
{
    complex z;
    z.a = A.a + B.a;
    z.b = A.b + B.b;
    return z;
}

ostream& operator<<(ostream& out, complex z)
{
    out<<z.a<<"+i"<<z.b;
    return out;
}
//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
int main()
{
    complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    complex z=x+y;
    cout<<z<<endl;
}

*/
