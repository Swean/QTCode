#ifndef AFACTORY_H
#define AFACTORY_H
#include <QMap>
#include <QString>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>
#include <QMutex>
#include <QMutexLocker>

template<typename T>
class IARegister
{
public:
    virtual ~IARegister(){}
    virtual T * get() = 0;
};

template<typename T>
class AFactoryMap
{
private:
    AFactoryMap(){}
public:
    static AFactoryMap &getInstance(){
        static AFactoryMap<T> g_instance;
        return g_instance;
    }

    bool addToMap(const QString &sType, IARegister<T> *p){
        if(p == NULL)
            return false;
        QWriteLocker lock(&m_lockMap);
        m_map.insert(sType, p);
        return true;
    }
    T * get(const QString &sType)
    {
        QReadLocker lock(&m_lockMap);
        if(false == m_map.contains(sType))
            return NULL;
        IARegister<T> *p = m_map[sType];
        return p->get();
    }

private:
    QMap<QString, IARegister<T>*> m_map;
    QReadWriteLock m_lockMap;
};

template <typename T>
class AFactory
{
public:
    AFactory(){}
    static T* get(QString sType)
    {
        return AFactoryMap<T>::getInstance().get(sType);
    }
};

#define REGISTER_TO_FACTORY_MAP(baseName, className, typeName)\
class RegisterToMap_##className : public IARegister<baseName>\
{\
public:\
    RegisterToMap_##className(){\
        AFactoryMap<baseName>::getInstance().addToMap(typeName, this);\
    }\
\
    baseName * get(){\
        return new className();\
    }\
};\
static RegisterToMap_##className g_registerToMap_##className;



#endif // AFACTORY_H
