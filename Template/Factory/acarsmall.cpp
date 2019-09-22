#include "acarsmall.h"
#include "afactory.h"
#include <iostream>

ACarSmall::ACarSmall()
{
    m_cnt = 4;
}

int ACarSmall::getWheelCnt()
{
    std::cout << "small:" << m_cnt << std::endl;
    return m_cnt;
}
REGISTER_TO_FACTORY_MAP(IACar, ACarSmall, "small")
