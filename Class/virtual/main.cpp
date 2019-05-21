#include <iostream>

using namespace std;

class Base
{
public:
    void nor_fun1(){}
    virtual void fun1(){}
    virtual void fun2(){}
    //virtual void fun3() = 0;
    void nor_fun2(){}
};

class Derive : public Base
{
public:
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

    Base b2;
    cout << (void*)&(b2.fun1) << endl;

    Derive d2;
    cout << (void*)&(d2.fun1) << endl;
    cout << (void*)&(d2.fun2) << endl;
    cout << (void*)&(d2.fun3) << endl;
    d2.fun2();

    Base *pb = new Derive();
    cout << (void*)&(pb->fun1) << endl;
    cout << (void*)&(pb->fun2) << endl;
    //cout << (void*)&(pb->fun3) << endl;   // ���벻����������û���������

    Derive *d3 = dynamic_cast<Derive*>(pb); // ����ת��������ĺ������ж�����
    d3->fun3();
    cout << "dynamic_cast fun3:"<< (void*)&(d3->fun3) << endl;
    d3->nor_fun2();

    pb = &b2;   // ��ϵ�۲촦
    cout << (void*)&(pb->fun1) << endl;
    cout << (void*)&(pb->fun2) << endl;

    return 0;
}