#ifndef SIZEOFCLASS_H
#define SIZEOFCLASS_H

void printSize();

class A // �ֽ�1
{};

class B : A // �ֽ�1
{};

class C // �ֽ�1,�ɼ��е�����union��Ĭ�ϵ�1�ֽ��ǹ��õ�
{
    char c;
};

class D // �ֽ�8��֤��������������������structһ�����ֽڶ���
{
    char c;
    double a;
    int b;
};

#endif // SIZEOFCLASS_H
