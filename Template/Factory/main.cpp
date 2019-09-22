#include <QCoreApplication>
#include "afactory.h"
#include "awheel.h"
#include "acar.h"
#include <stdio.h>

void test()
{
    IACar *p2 = NULL;
    p2 = AFactory<IACar>::get("small");
    if(NULL == p2)
    {
        printf("smallcar is null\n");
    }
    else
    {
        p2->getWheelCnt();
        delete p2;
    }

    p2 = NULL;
    p2 = AFactory<IACar>::get("big");
    if(NULL == p2)
    {
        printf("big is null\n");
    }
    else
    {
        p2->getWheelCnt();
        delete p2;
    }


    IAWheel *p3 = AFactory<IAWheel>::get("benz");
    if(NULL == p3)
    {
        printf("benz is null\n");
    }
    else
    {
        p3->print();
        delete p3;
    }
    p3 = AFactory<IAWheel>::get("bmw");
    if(NULL == p3)
    {
        printf("bmw is null\n");
    }
    else
    {
        p3->print();
        delete p3;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();

    printf("hehe end\n");
    return a.exec();
}
