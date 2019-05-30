#ifndef SIZEOFCLASS_H
#define SIZEOFCLASS_H

void printSize();

class A
{};

class B : A
{};

class C
{
    char c;
};

class D
{
    char c;
    int b;
};

class Base
{
    virtual void vfun1(){}
};

class Derive : public Base
{

};

#endif // SIZEOFCLASS_H
