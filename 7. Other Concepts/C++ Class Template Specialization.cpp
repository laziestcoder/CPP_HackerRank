#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template <>
struct Traits<Fruit>{
    static string name(int index){
        switch(index){
                case 0:return "apple";
                case 1: return "orange" ;
                case 2: return "pear";
        }
        return "unknown";
    }
};
template <>
struct Traits<Color>{
    static string name(int index){
        switch(index){
                case 0:return "red";
                case 1: return "green" ;
                case 2: return "orange";
        }
        return "unknown";
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}

/**
//We make an explicit specialization for both the enumeration Fruit and Color.

//Because the enumeration is an enum class, we must use casts to convert between int and enumeration values.

//We must validate the index before casting, since it isn't legal to cast an invalid enumeration value to an enumeration type.

//Problem Setter's code:

template <>
struct Traits<Fruit> {
  static const int min = static_cast<int>(Fruit::apple);
  static const int max = static_cast<int>(Fruit::pear);

  static const char *name(int index)
  {
    if (index<min || index>max) {
      return "unknown";
    }
    switch (static_cast<Fruit>(index)) {
      case Fruit::apple:  return "apple";
      case Fruit::orange: return "orange";
      case Fruit::pear:   return "pear";
    }
    return "";
  }
};

template <>
struct Traits<Color> {
  static const int min = static_cast<int>(Color::red);
  static const int max = static_cast<int>(Color::orange);

  static const char *name(int index)
  {
    if (index<min || index>max) {
      return "unknown";
    }
    switch (static_cast<Color>(index)) {
      case Color::red:    return "red";
      case Color::green:  return "green";
      case Color::orange: return "orange";
    }
    return "";
  }
};
*/
