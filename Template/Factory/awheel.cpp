#include "awheel.h"
#include "afactory.h"

AWheelBenz::AWheelBenz()
{
    m_sInfo = ("benz");
}
void AWheelBenz::print()
{
    printf("wheel:%s\n", m_sInfo.toStdString().data());
}


REGISTER_TO_FACTORY_MAP(IAWheel, AWheelBenz, "benz")
