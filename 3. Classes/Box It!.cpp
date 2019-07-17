#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
private:
    int l,b,h;
public:
    Box()
    {
        l = 0;
        b = 0;
        h = 0;
    }
    Box(int a, int d, int c)
    {
        l=a;
        b=d;
        h=c;
    }
    Box(const Box& B)
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }

    int getLength()
    {
        return l;
    }
    int getBreadth ()
    {
        return b;
    }
    int getHeight ()
    {
        return h;
    }
    long long CalculateVolume()
    {
        return (long long) l*h*b;
    }

    friend bool operator < (Box& A, Box& B)
    {
        if((A.l < B.l)||((A.b<B.b) && (A.l==B.l))||((A.h < B.h) && (A.b == B.b) && (A.l == B.l)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream& operator <<(ostream& output, const Box& B)
    {
        output <<B.l<<" "<<B.b<<" "<<B.h;
        return output;
    }

};
void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0; i<n; i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}


/**
Other Solutions

class Box {
	int l, b, h;
public:
	Box() : l(0), b(0), h(0) { BoxesCreated++; }
	Box(int length, int breadth, int height) : l(length), b(breadth), h(height) { BoxesCreated++; }
	Box(const Box& b) : l(b.l), b(b.b), h(b.h) { BoxesCreated++; }
	int getLength() const {
		return l;
	}
	int getBreadth() const {
		return b;
	}
	int getHeight() const {
		return h;
	}
	long long CalculateVolume() const {
		return 1LL * l * b * h;
	}
	~Box() {
		BoxesDestroyed++;
	}
	bool operator<(const Box& another) const {
		if (l != another.l) {
			return l < another.l;
		}
		if (b != another.b) {
			return b < another.b;
		}
		return h < another.h;
	}
	void output(ostream& out) const {
		out << l << " " << b << " " << h;
	}
};

ostream& operator<<(ostream& out, Box b) {
	b.output(out);
	return out;
}
-----------------------
class Box {
    int l, b, h;
public:
    Box() : l(0), b(0), h(0) { ++BoxesCreated; }
    Box(int l, int b, int h) : l(l), b(b), h(h) { ++BoxesCreated; }
    Box(const Box &other) : l(other.l), b(other.b), h(other.h) { ++BoxesCreated; }
    ~Box() { ++BoxesDestroyed; }

    int getLength() const { return l; }
    int getBreadth () const { return b; }
    int getHeight () const { return h; }
    long long CalculateVolume() const { return (long long)l * b * h; }

    bool operator<(const Box &other) const {
        if (l < other.l)
            return true;
        if (b < other.b && l == other.l)
            return true;
        if (h < other.h && b == other.b && l == other.l)
            return true;
        return false;
    }
};

std::ostream &operator<<(std::ostream &out, Box box) {
    out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight();

    return out;
}
--------------------------
class Box
{
    int l, b, h;

public:
    Box() : l(0), b(0), h(0)
    {
        ++BoxesCreated;
    }

    Box(int length, int breadth, int height) : l(length), b(breadth), h(height)
    {
        ++BoxesCreated;
    }

    Box(const Box &other) : l(other.l), b(other.b), h(other.h)
    {
        ++BoxesCreated;
    }

    ~Box()
    {
        ++BoxesDestroyed;
    }

    inline int getLength() const // Return box's length
    {
        return l;
    }
    inline int getBreadth () const // Return box's breadth
    {
        return b;
    }

    inline int getHeight () const //Return box's height
    {
        return h;
    }

    long long CalculateVolume() const // Return the volume of the box
    {
        long long ret = l;   // Ensure the multiplications happen in 64-bit.
        ret *= b;
        ret *= h;
        return ret;
    }

    bool operator<(const Box &other) const
    {
        if (l != other.l)
            return l < other.l;
        if (b != other.b)
            return b < other.b;
        return h < other.h;
    }
};

// Technically incorrect method of invocation, but required to get the right number of constructor calls.
ostream &operator<<(ostream &os, Box box)
{
    os << box.getLength() << ' ' << box.getBreadth() << ' ' << box.getHeight();
    return os;
}
----------------------


*/
