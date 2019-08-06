#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template <bool a> int reversed_binary_value() { return a; }

template <bool a, bool b, bool... d> int reversed_binary_value() {
  return (reversed_binary_value<b, d...>() << 1) + a;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
/**
Editorial:
As with many template programs, the first step is to defer the solution to a class, where we can more easily use partial specialization. Partial specialization is not allowed for function templates.


We'll call the class ReversedBinaryValue. With such a class, we can write:

template <bool...digits>
int reversed_binary_value()
{
    return ReversedBinaryValue<digits...>::value;
}
The use of the member name  is common with these kinds of class templates.

Our class template declaration will look like this:

template <bool...> struct ReversedBinaryValue;
Note the use of struct here. In C++, struct means a public class. This avoids having to explicitly declare everything public when we don't actually need any private members.


Now we need to think about how to solve this recursively. We can start by thinking of special cases:

f(0) = 0
f(1) = 1
f(0,1) = 2
f(1,1) = 3
f(0,0,1) = 4
f(1,0,1) = 5
One particularly easy way to define this is

f(x,y...) = 2*f(y...) + x
Writing this as a class template specialization, we have

template <bool x,bool...y>
struct ReversedBinaryValue<x,y...> {
    static constexpr int value = 2*ReversedBinaryValue<y...> + x;
}
By making the  member be a static constexpr int, we can access the value without needing an instance.


Note that the fact that the digits are in reverse order makes this especially convenient, since C++ requires that the variadic parameter be last.


The only other issue is to define the base case. We could define two templates for the  and  case, but it turns out to be even simpler if we handle the case of no digits:

f() = 0
which we can write simply as

template <>
struct ReversedBinaryValue<> {
    static constexpr int value = 0;
}
Problem Setter's code:

template <bool... digits> struct ReversedBinaryValue;

template <>
struct ReversedBinaryValue<> {
    static constexpr int value = 0;
};

template <bool first,bool... digits>
struct ReversedBinaryValue<first,digits...> {
    static constexpr int value = first + 2*ReversedBinaryValue<digits...>::value;
};

template <bool...digits>
int reversed_binary_value()
{
    return ReversedBinaryValue<digits...>::value;
}
*/
