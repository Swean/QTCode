#ifndef AWHEEL_H
#define AWHEEL_H

#include <stdio.h>
#include <QString>

class IAWheel
{
public:
    virtual ~IAWheel(){}
    virtual void print() = 0;
};

class AWheelBase : public IAWheel
{
public:
    AWheelBase(){}
    virtual ~AWheelBase(){}
    virtual void print(){
        printf("AWheel\n");
    }
protected:
    QString m_sInfo;
};

class AWheelBenz : public AWheelBase
{
public:
    AWheelBenz();
    virtual void print();
};

#endif // AWHEEL_H
