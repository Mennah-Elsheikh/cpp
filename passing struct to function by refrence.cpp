 
#include <iostream>
#include <string.h>
using namespace std;
struct student
{
    string fname;
    string lname;
    int age;

};
student fun(student & a)
{
    cout << a.fname << endl;
    cout << a.lname << endl;
    cout << a.age << endl;
    return a;
}
int main()
{
    student student1;
    student1 = { "a","b", 19 };
    fun(student1);
    student b = student1;
    cout << b.age << endl;
    b = { "x", "y" , 20 };
    cout << student1.age << endl;
    student* a;
    a = &student1;
    a->age = 13;
    fun(student1);
    *a = {"d" , "h" , 15};
    fun(student1);
}

 