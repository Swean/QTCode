#ifndef SIZEOFCLASS_H
#define SIZEOFCLASS_H

void printSize();

class A // 字节1
{};

class B : A // 字节1
{};

class C // 字节1,可见有点类似union，默认的1字节是公用的
{
    char c;
};

class D // 字节8，证明了上面描述，并且有struct一样的字节对齐
{
    char c;
    double a;
    int b;
};

#endif // SIZEOFCLASS_H
