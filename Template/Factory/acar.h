#ifndef ACAR_H
#define ACAR_H

class IACar
{
public:
    virtual ~IACar(){}
    virtual int getWheelCnt() = 0;
};


class ACarBase : public IACar
{
public:
    ACarBase();
    virtual ~ACarBase(){}
    virtual int getWheelCnt();

protected:
    int m_cnt;
};

#endif // ACAR_H
