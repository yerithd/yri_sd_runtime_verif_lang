/*
 * YRI_CPP_MONITOR_EVENT.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_CPP_MONITOR_EVENT_HPP_
#define _YRI_CPP_MONITOR_EVENT_HPP_


#include "utils/YRI_CPP_UTILS.hpp"

#include "YRI_CPP_MONITOR_object.hpp"


#include <QtCore/QString>


class YRI_CPP_MONITOR_EVENT : public YRI_CPP_MONITOR_object
{
	Q_OBJECT

public:

    YRI_CPP_CLASS_OPERATORS

	inline YRI_CPP_MONITOR_EVENT(QString &event_token)
    :_event_token(event_token.trimmed())
    {
    }

    inline virtual ~YRI_CPP_MONITOR_EVENT()
    {
    }

    inline bool operator== (YRI_CPP_MONITOR_EVENT &monitor_event_1);

    inline QString get_EVENT_TOKEN()
    {
        return _event_token.trimmed();
    }

protected:

    inline YRI_CPP_MONITOR_EVENT()
    :_event_token(YRI_CPP_UTILS::EMPTY_STRING)
    {
    }

private:

    QString _event_token;
};


bool YRI_CPP_MONITOR_EVENT::operator== (YRI_CPP_MONITOR_EVENT &monitor_event_1)
{
    return YRI_CPP_UTILS::isEqualsCaseInsensitive(_event_token,
                                                monitor_event_1.get_EVENT_TOKEN());
}


#endif // _YRI_CPP_MONITOR_EVENT_HPP_
