#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base(){ cout << "~base" << endl;}  // 为何会看到两个析构函数地址？相差16个字节
    //析构函数是一个特殊的函数，编译器在编译时，析构函数的名字统一为destucter,所以只要父类的析构函数定义为虚函数，不管子类的析构函数前是否加virtual（可以理解为编译器优化），都构成重写。
//    ~Base(){ cout << "~base" << endl;}    // 父类指针指向子类对象时，delete父类指针，会无法调用子类的析构函数，有内存泄漏问题
    void nor_fun1(){}
//    void nor_fun1(int a){cout << a << endl;}
    virtual void fun1(){}
    virtual void fun2(){}
    //virtual void fun3() = 0;
    void nor_fun2(){}
};

class Derive : public Base
{
public:
//    ~Base(){cout << "Derive::~Base" << endl;} //不需要也不能在子类重写，编译会出错
    ~Derive(){ cout << "~Derive" << endl;}
    using Base::nor_fun1;   // 默认是函数隐藏了，外部用不了
    void nor_fun1(int a){cout << a << endl;}
    void nor_fun2(){}
    virtual void fun2(){ cout << "base fun2:" << (void*)&(Base::fun2) << endl;}
    virtual void fun3(){}
};

int main(int argc, char *argv[])
{
    Base b;
    cout << (void*)&b << endl;
    cout << (void*)&(b.fun1) << endl;
    cout << (void*)&(b.fun2) << endl;
    //cout << (void*)&(b.~Base) << endl;    // 析构函数地址不让拿？

    Base b2;
    cout << (void*)&(b2.fun1) << endl;

    Derive d2;
    d2.nor_fun1();  // 需要 using,否则编译失败
    d2.nor_fun1(2);
    cout << (void*)&(d2.fun1) << endl;
    cout << (void*)&(d2.fun2) << endl;
    cout << (void*)&(d2.fun3) << endl;
    d2.fun2();

    Base *pb = new Derive();
    cout << (void*)&(pb->fun1) << endl;
    cout << (void*)&(pb->fun2) << endl;
    //cout << (void*)&(pb->fun3) << endl;   // 编译不过，基类里没有这个函数
    delete pb;  // 留意析构函数的调用顺序，先子类再父类

    pb = new Derive();
    Derive *d3 = dynamic_cast<Derive*>(pb); // 类型转换后，子类的函数运行都可以
    d3->fun3();
    cout << "dynamic_cast fun3:"<< (void*)&(d3->fun3) << endl;
    d3->nor_fun2();
    delete d3;  // 留意析构函数的调用

    pb = &b2;   // 设断点观察处
    cout << (void*)&(pb->fun1) << endl;
    cout << (void*)&(pb->fun2) << endl;
    delete pb;

    return 0;
}
