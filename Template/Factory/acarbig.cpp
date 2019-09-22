#include "acarbig.h"
#include <iostream>
#include "afactory.h"


ACarBig::ACarBig()
{
    m_cnt = 6;
    std::cout << "big car create" << std::endl;
}
int ACarBig::getWheelCnt()
{
    std::cout << "big car:" << m_cnt << std::endl;
    return m_cnt;
}

REGISTER_TO_FACTORY_MAP(IACar, ACarBig, "big")
