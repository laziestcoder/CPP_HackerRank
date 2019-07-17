#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int pf = 1, st = 1;
class Person
{
public:
    string name;
    int age;

    virtual void getdata(){
        cin>>name>>age;
    }
    virtual void putdata(){
        cout<<name<<" "<<age<<" ";
    }


};
class Professor : public Person
{
public:
    int publications;
    void getdata(){
        cin>>name>>age>>publications;
    }
    void putdata(){
        cout<<name<<" "<<age<<" "<<publications<<" "<<pf++<<endl;
    }

};
class Student : public Person
{
public:
    int i = 6,marks[6], sum_of_the_marks = 0;
    void getdata(){
        cin>>name>>age;
        while(i--){
            cin>>marks[i];
            sum_of_the_marks+=marks[i];
        }
    }
    void putdata(){
        cout<<name<<" "<<age<<" "<<sum_of_the_marks<<" "<<st++<<endl;
    }
};
int main()
{

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0; i < n; i++)
    {

        cin>>val;
        if(val == 1)
        {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else
            per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0; i<n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
/**
Other Solutions

#include <string>

int currentIDStudent= 0;
int currentIDProff = 0;


class Person
{
public:
	Person();
	~Person();

	string name;
	int age;
	virtual void getdata() = 0;
	virtual void putdata() = 0;

private:

};

Person::Person()
{
	age = 0;
	name = "";

}

Person::~Person()
{
}
class Professor : public Person
{
public:
	Professor();
	~Professor();
	int publications;
	int id;


	void getdata()
	{
		std::cin >> name;
		std::cin >> age;
		std::cin >> publications;


	}
	void putdata()
	{
		std::cout << name << " " << age << " " << publications << " " << id << "\n";


	}
private:

};

Professor::Professor()
{
	id = ++currentIDProff;
}

Professor::~Professor()
{
}

class Student : public Person
{
public:
	Student();
	~Student();
	int marks[6];
	int id;
	void getdata()
	{
		std::cin >> name;
		std::cin >> age;
		for (int i = 0; i < 6; i++)
		{

			std::cin >> marks[i];
		}

	}
	void putdata()
	{
		std::cout << name << " " << age << " ";

		int sum = 0;
		for (auto& num : marks)
		sum += num;

		std::cout << sum << ' ' <<  id << endl;
	}
private:

};

Student::Student()
{
	id = ++currentIDStudent;

}

Student::~Student()
{
}

-----------------

class Person {
protected:
    string name;
    int age;
public:
    static int prof_id;
    static int stud_id;
    virtual void getdata()=0;
    virtual void putdata()=0;
};

int Person::prof_id = 1;
int Person::stud_id = 1;

class Student : public Person{
public:
    int marks[6];
    int cur_id;
    Student() {
        cur_id = stud_id++;
    }
    void getdata() {
        cin >> name >> age;
        for(int i = 0; i < 6; ++i) cin >> marks[i];
    }
    void putdata() {
        int sum = 0;
        for(int i = 0; i < 6; ++i) sum += marks[i];
        cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << endl;
    }
};

class Professor : public Person{
public:
    Professor() {
        cur_id = prof_id++;
    }
    int publications;
    int cur_id;
    void getdata() {
        cin >> name >> age >> publications;
    }
    void putdata() {
        cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << endl;
    }
};

---------------

class Person {
public:
	int id;
	string name;
	int age;
	virtual void getdata() {
		cin >> name >> age;
	}
	virtual void putdata() const {
		cout << name << " " << age;
	}
};

class Professor : public Person{
	int publications;
	static int cur_id;
public:
	Professor() {
		id = cur_id++;
	}
	void getdata() {
		Person::getdata();
		cin >> publications;
	}
	void putdata() const {
		Person::putdata();
		cout << " " << publications << " " << id << endl;
	}
};

int Professor::cur_id = 1;

class Student : public Person {
	int marks[6];
	static int cur_id;
	int sum;
public:
	Student() {
		id = cur_id++;
	}
	void getdata() {
		Person::getdata();
		sum = 0;
		for (int i = 0; i < 6; i++) {
			cin >> marks[i];
			sum += marks[i];
		}
	}
	void putdata() const {
		Person::putdata();
		cout << " " << sum << " " << id << endl;
	}
};

int Student::cur_id = 1;
*/
