#include "sizeofclass.h"
#include <iostream>
using namespace std;
void printSize()
{
    A a;
    B b;
    C c;
    D d;
    Base b1;
    Derive d1;
    cout << sizeof(A) << " " << sizeof(a) << endl;
    cout << sizeof(B) << " " << sizeof(b) << endl;
    cout << sizeof(C) << " " << sizeof(c) << endl;
    cout << sizeof(D) << " " << sizeof(d) << endl;
    cout << sizeof(Base) << " " << sizeof(b1) << endl;
}
