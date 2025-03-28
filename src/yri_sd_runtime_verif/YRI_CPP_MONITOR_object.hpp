/*
 * YRI_CPP_MONITOR_object.hpp
 *
 *      Author: Pr.  Prof.  Dr.-Ing. Xavier Noundou
 */

#ifndef _YRI_CPP_MONITOR_OBJECT_HPP_
#define _YRI_CPP_MONITOR_OBJECT_HPP_


#include "utils/YRI_CPP_UTILS.hpp"

#include <QtCore/QObject>

class YRI_CPP_MONITOR_object:public QObject
{
Q_OBJECT public:

    YRI_CPP_CLASS_OPERATORS YRI_CPP_MONITOR_object():_MONITOR_OBJECT_ID(-1)
    {
        _MONITOR_OBJECT_ID = get_next_id();
    }

    virtual ~ YRI_CPP_MONITOR_object();

    inline virtual int GET_ID()
    {
        return _MONITOR_OBJECT_ID;
    }

    inline virtual QString GET_QSTRING_ID()
    {
        return QString::number(_MONITOR_OBJECT_ID);
    }

    inline virtual void set_MONITOR_object_ID(int a_MONITOR_OBJECT_ID)
    {
        _MONITOR_OBJECT_ID = a_MONITOR_OBJECT_ID;
    }

    inline virtual int get_MONITOR_object_ID()
    {
        return _MONITOR_OBJECT_ID;
    }

protected:

    int _MONITOR_OBJECT_ID;

    inline virtual QString SIMULATE_QSTRING_NEXT_ID()
    {
        return QString::number(1 + MONITOR_OBJECTS_CURRENT_ID_GENERATOR);
    }

    inline virtual int get_next_id()
    {
        return MONITOR_OBJECTS_CURRENT_ID_GENERATOR++;
    }

private:

    static uint MONITOR_OBJECTS_CURRENT_ID_GENERATOR;
};



#endif // _YRI_CPP_MONITOR_OBJECT_HPP_
