#ifndef ACARSMALL_H
#define ACARSMALL_H

#include "acar.h"

class ACarSmall : public ACarBase
{
public:
    ACarSmall();
    ~ACarSmall(){}
    virtual int getWheelCnt();

private:
    int m_cnt;
};

#endif // ACARSMALL_H
