#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle
{
public:
    int width, height;
    void display()
    {
        cout<< width <<" " <<height<<endl;
    }
};
class RectangleArea: public Rectangle
{
public:
    void read_input()
    {
        cin>> this->width >> this->height ;
    }
    void display()
    {
        cout<<width*height<<endl;
    }

};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}
/**
Other Solutions:
struct Rectangle {
	int w, h;
	void Display() {
		printf("%d %d\n", w, h);
	}
};
struct RectangleArea : Rectangle {
	void Input() {
		scanf("%d%d", &w, &h);
	}
	void Display() {
		printf("%d\n", w * h);
	}
};
---------------------
class Rectangle {
    protected:
    int width, height;
    public:
       void Display(){
           cout<<width<<' '<<height<<endl;
       }
};

class RectangleArea : public Rectangle {
    public:

       void Input() {
           cin>>width>>height;
       }
       void Display(){
           cout<<width*height;
       }
};
--------------
class Rectangle{

    public:
    int w; int h;
    void Input(){
        cin>>w>>h;
    }
    void Display(){
        cout<<w<<" "<<h<<endl;
    }
};

class RectangleArea:public Rectangle{
    public:
     void Display(){
        cout<<w*h<<endl;
    }
};
*/
