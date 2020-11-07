// add1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <list>
#include <algorithm>
#include <iostream>
#include "print.h"
using namespace std;

//function object that adds the value with which it is initialized
class AddValue {
private:
    int theValue;   // the value to add
public:
    //constructor initializes the value to add
    AddValue(int v) : theValue(v) {

    }

    // the "function call" for the element adds the value
    void operator() (int& elem) const {
        elem += theValue;
    }
};

int main()
{
    list<int> coll;

    //insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    PRINT_ELEMENTS(coll, "initialized:       ");

    // add value 10 to each element
    for_each(coll.begin(), coll.end(),  //range
        AddValue(10));                  // operation

    PRINT_ELEMENTS(coll, "after adding 10:       ");

    // add value of first element to each element
    for_each(coll.begin(), coll.end(),     //range
        AddValue(*coll.begin()));           // operation

    PRINT_ELEMENTS(coll, "after adding the first element: ");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
