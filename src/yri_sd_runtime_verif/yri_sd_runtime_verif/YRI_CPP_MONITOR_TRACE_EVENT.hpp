/*
 * YRI_CPP_MONITOR_TRACE_EVENT.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_CPP_MONITOR_TRACE_EVENT_HPP_
#define _YRI_CPP_MONITOR_TRACE_EVENT_HPP_


#include "utils/YRI_CPP_UTILS.hpp"

#include "YRI_CPP_MONITOR_object.hpp"


#include <QtCore/QString>

#include <QtCore/QList>


class YRI_CPP_MONITOR_EVENT;


class YRI_CPP_MONITOR_TRACE_EVENT:public YRI_CPP_MONITOR_object
{
Q_OBJECT public:

    YRI_CPP_CLASS_OPERATORS YRI_CPP_MONITOR_TRACE_EVENT()
    {
    }

    virtual ~ YRI_CPP_MONITOR_TRACE_EVENT()
    {
    }

    bool is_in_TRACE_EVENT(QString &A_TRACE_EVENT);

protected:

    QList < YRI_CPP_MONITOR_EVENT * >_TRACE_EVENTS;

};


#endif // _YRI_CPP_MONITOR_TRACE_EVENT_HPP_
