#ifndef APRODUCT_H
#define APRODUCT_H

#include "acar.h"

class ACarBig : public ACarBase
{
public:
    ACarBig();
    ~ACarBig(){}
    virtual int getWheelCnt();

//private:
//    int m_cnt;
};

#endif // APRODUCT_H
