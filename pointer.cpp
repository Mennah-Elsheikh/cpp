// pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 
int main()
{
    int val = 5; // هنا عرفت المتغير واعطيته قيمة كمان ولكل متغير قيمة ومكان في الميموري 
    int* ptr = &val; //بقول ليه خلي البوينتر ده يشاور على مكان 
    //المتغير ده في الميموري 
    //int *ptr ; 
    //ptr = &val;
    cout << val << endl;//5
    cout << ptr << endl;//0000003832BAF514
    cout << *ptr << endl;//5
    cout << &val << endl;//0000003832BAF514
    cout << *&val << endl;//5
    cout << &*ptr << endl;//0000003832BAF514
    cout << *&*ptr << endl;//5
    val = 7; 
    cout << val << endl;//7
    cout << *ptr << endl;//7
    cout << ptr << endl;
 
}

 