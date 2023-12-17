/*
 * YRI_CPP_MONITOR_EDGE.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_CPP_MONITOR_EDGE_HPP_
#define _YRI_CPP_MONITOR_EDGE_HPP_


/**
 * TO KEEP EXACTLY AS A RELATIVE PATH
 * SO TO AVOID build errors in
 * 'yri-db-runtime-verif' project.
 */
#include "utils/YRI_CPP_UTILS.hpp"

#include "YRI_CPP_MONITOR_object.hpp"

#include "YRI_CPP_MONITOR.hpp"

#include "YRI_CPP_MONITOR_STATE.hpp"

#include "YRI_CPP_MONITOR_EDGE.hpp"

#include "YRI_CPP_MONITOR_EVENT.hpp"


#include <QtCore/QString>


class YRI_CPP_notinset_inset_TRACE_expression;

class YRI_CPP_MONITOR_EVENT;



class YRI_CPP_MONITOR_EDGE : public YRI_CPP_MONITOR_object
{
	Q_OBJECT

public:

    YRI_CPP_CLASS_OPERATORS

	YRI_CPP_MONITOR_EDGE(QString SOURCE_STATE_KEY,
    					QString TARGET_STATE_KEY);

    YRI_CPP_MONITOR_EDGE(YRI_CPP_MONITOR_STATE &SOURCE_STATE,
                        YRI_CPP_MONITOR_STATE &TARGET_STATE);


protected:

    inline YRI_CPP_MONITOR_EDGE()
    :_SOURCE_STATE(0),
     _TARGET_STATE(0),
	 _guarded_CONDITION_expression(0),
	 _EDGE_EVENT(0)
    {
    }


public:

    virtual ~ YRI_CPP_MONITOR_EDGE();

    QString YRI_EXPORT_edge_CLASS_INSTANCE();

    bool operator== (YRI_CPP_MONITOR_EDGE &e1);

    virtual bool evaluate_GUARDED_CONDITION_expression();

    virtual inline void set_GUARDED_CONDITION(YRI_CPP_notinset_inset_TRACE_expression *GUARDED_CONDITION)
    {
        _guarded_CONDITION_expression = GUARDED_CONDITION;
    }

    virtual inline YRI_CPP_notinset_inset_TRACE_expression *get_guarded_CONDITION_expression()
    {
        return _guarded_CONDITION_expression;
    }

    virtual inline QString get_guarded_CONDITION_expression__TO_STRING(bool PRINT_WITH_STANDARD_trace_syntax = false)
    {
        return (0 == _guarded_CONDITION_expression) ? "" :
        		_guarded_CONDITION_expression->toString(PRINT_WITH_STANDARD_trace_syntax);
    }

    virtual inline YRI_CPP_MONITOR_EVENT *get_EDGE_EVENT()
    {
        return _EDGE_EVENT;
    }

    virtual inline QString get_EDGE_EVENT_TOKEN()
    {
        return (0 != _EDGE_EVENT) ?
               _EDGE_EVENT->get_EVENT_TOKEN() : YRI_CPP_UTILS::EMPTY_STRING;
    }

    virtual inline QString toString()
    {
    	return QString("[%1] / %2")
    			.arg(get_guarded_CONDITION_expression__TO_STRING(),
    				 get_EDGE_EVENT_TOKEN());
    }


    virtual YRI_CPP_MONITOR_EVENT *set_EDGE_EVENT(QString event_token);


    virtual inline QString get_Recovery_SQL_query_string_ON_ERROR_ACCEPTING_target_state()
    {
        return
            (0 != _TARGET_STATE) ? _TARGET_STATE->Get_SQL_RECOVERY_QUERY_STRING()
                                 : "";
    }


    virtual inline QString get_SOURCE_STATE_KEY()
    {
        return _SOURCE_STATE_KEY;
    }

    virtual inline QString get_TARGET_STATE_KEY()
    {
        return _TARGET_STATE_KEY;
    }

    virtual inline YRI_CPP_MONITOR_STATE *get_SOURCE_STATE()
    {
        return _SOURCE_STATE;
    }

    virtual inline YRI_CPP_MONITOR_STATE *get_TARGET_STATE()
    {
        return _TARGET_STATE;
    }


    virtual QString Get__precondition__STRING_VALUE_EXPRESSION(bool PRINT_WITH_STANDARD_trace_syntax = false);

    virtual QString Get__POSTcondition__STRING_VALUE_EXPRESSION(bool PRINT_WITH_STANDARD_trace_syntax = false);


    virtual
    void set_PRE_CONDITION_notIN(QString DB_VARIABLE,
                                 QString db_query_TABLE__db_query_COLUMN);


    virtual
    void set_PRE_CONDITION_IN(QString DB_VARIABLE,
                              QString db_query_TABLE__db_query_COLUMN);


    virtual
    void set_POST_CONDITION_notIN(QString DB_VARIABLE,
                                  QString db_query_TABLE__db_query_COLUMN);


    virtual
    void set_POST_CONDITION_IN(QString DB_VARIABLE,
                               QString db_query_TABLE__db_query_COLUMN);


    virtual
    bool CHECK_SOURCE_STATE_in_OR_notin_CONDITION(YRI_CPP_MONITOR_STATE &a_potential_START_state,
                                                  YRI_CPP_MONITOR &a_runtime_monitor);

    virtual
    bool ADDITIONAL_FINAL_STATE_lookup(YRI_CPP_MONITOR_STATE &a_potential_final_state,
                                       YRI_CPP_MONITOR &a_runtime_monitor);

    virtual
    void GET_error_final_STATES__OVER_EDGES(YRI_CPP_MONITOR &a_runtime_monitor,
                                			QList<YRI_CPP_MONITOR_STATE *> &results_states);

    virtual void print_FOR_YERITH_ERP();

    virtual void print();

    virtual QString print_to_dot_file(bool PRINT_WITH_SQL_EVENT_LOG_TOKEN = false);


    QStringList _EVENT_PARAMETERS_LIST;

protected:

    QList < YRI_CPP_MONITOR_STATE * >FINAL_ERROR_states;

    YRI_CPP_MONITOR_STATE *_SOURCE_STATE;

    YRI_CPP_MONITOR_STATE *_TARGET_STATE;

    QString _SOURCE_STATE_KEY;

    QString _TARGET_STATE_KEY;


private:

    YRI_CPP_notinset_inset_TRACE_expression *_guarded_CONDITION_expression;

    YRI_CPP_MONITOR_EVENT *_EDGE_EVENT;
};


#endif //_YRI_CPP_MONITOR_EDGE_HPP_
