#include "awheelbmw.h"
#include <stdio.h>
#include "afactory.h"

AWheelBMW::AWheelBMW()
{
    m_sInfo = ("bmw");
}

void AWheelBMW::print()
{
    printf("wheel:%s\n", m_sInfo.toStdString().data());
}

REGISTER_TO_FACTORY_MAP(IAWheel, AWheelBMW, "bmw")
