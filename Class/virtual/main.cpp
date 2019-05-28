#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base(){ cout << "~base" << endl;}  // Ϊ�λῴ����������������ַ�����16���ֽ�
    //����������һ������ĺ������������ڱ���ʱ����������������ͳһΪdestucter,����ֻҪ�����������������Ϊ�麯���������������������ǰ�Ƿ��virtual���������Ϊ�������Ż�������������д��
//    ~Base(){ cout << "~base" << endl;}    // ����ָ��ָ���������ʱ��delete����ָ�룬���޷�����������������������ڴ�й©����
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
//    ~Base(){cout << "Derive::~Base" << endl;} //����ҪҲ������������д����������
    ~Derive(){ cout << "~Derive" << endl;}
    using Base::nor_fun1;   // Ĭ���Ǻ��������ˣ��ⲿ�ò���
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
    //cout << (void*)&(b.~Base) << endl;    // ����������ַ�����ã�

    Base b2;
    cout << (void*)&(b2.fun1) << endl;

    Derive d2;
    d2.nor_fun1();  // ��Ҫ using,�������ʧ��
    d2.nor_fun1(2);
    cout << (void*)&(d2.fun1) << endl;
    cout << (void*)&(d2.fun2) << endl;
    cout << (void*)&(d2.fun3) << endl;
    d2.fun2();

    Base *pb = new Derive();
    cout << (void*)&(pb->fun1) << endl;
    cout << (void*)&(pb->fun2) << endl;
    //cout << (void*)&(pb->fun3) << endl;   // ���벻����������û���������
    delete pb;  // �������������ĵ���˳���������ٸ���

    pb = new Derive();
    Derive *d3 = dynamic_cast<Derive*>(pb); // ����ת��������ĺ������ж�����
    d3->fun3();
    cout << "dynamic_cast fun3:"<< (void*)&(d3->fun3) << endl;
    d3->nor_fun2();
    delete d3;  // �������������ĵ���

    pb = &b2;   // ��ϵ�۲촦
    cout << (void*)&(pb->fun1) << endl;
    cout << (void*)&(pb->fun2) << endl;
    delete pb;

    return 0;
}
