/*
 * YRI_CPP_MONITOR_STATE.hpp
 *
 *      Author: Pr.  Prof.  Dr.-Ing. Xavier Noumbissi Noundou
 */

#ifndef _YRI_CPP_MONITOR_STATE_HPP_
#define _YRI_CPP_MONITOR_STATE_HPP_


#include "utils/YRI_CPP_UTILS.hpp"

#include "YRI_CPP_MONITOR_object.hpp"

#include <algorithm>

#include <QtCore/QString>

#include <QtCore/QMap>


class YRI_CPP_MONITOR;

class YRI_CPP_MONITOR_EDGE;

class YRI_CPP_MONITOR_TRACE_EVENT;

class YRI_CPP_MONITOR_STATE_PROPERTY_VALUE;


class YRI_CPP_MONITOR_STATE : public YRI_CPP_MONITOR_object
{
	Q_OBJECT

public:

    YRI_CPP_CLASS_OPERATORS

	inline YRI_CPP_MONITOR_STATE(const QString &MONITOR_STATE_NAME)
    :MONITOR_STATE_NAME("MONITOR_STATE_NAME"),
	 _AN_INCOMING_EDGE(0),
	 _AN_OUTGOING_EDGE(0),
	 _state_id(-1),
	 _start_state(false),
	 _final_state(false),
	 _MONITOR_STATE_TRACE_EVENTS(0)
    {
        _statepropertyKEY_TO_statepropertyVALUE
        	.insert(YRI_CPP_MONITOR_STATE::MONITOR_STATE_NAME,
        			MONITOR_STATE_NAME);
    }


    inline YRI_CPP_MONITOR_STATE()
    :MONITOR_STATE_NAME("MONITOR_STATE_NAME"),
	 _AN_INCOMING_EDGE(0),
	 _AN_OUTGOING_EDGE(0),
     _state_id(-1),
     _start_state(false),
     _final_state(false),
	 _MONITOR_STATE_TRACE_EVENTS(0)
    {
    }


    inline virtual ~YRI_CPP_MONITOR_STATE()
    {
        _state_id = -1;
    }


    inline virtual QString get_MONITOR_STATE_NAME()
    {
        return get_MONITOR_STATE_STATEPROPERTYVALUE(_MONITOR_STATE_NAME_string_key);
    }


    inline virtual void set_MONITOR_STATE_NAME(QString a_monitor_state_name)
    {
        _statepropertyKEY_TO_statepropertyVALUE
        	.insert(_MONITOR_STATE_NAME_string_key,
        			a_monitor_state_name);
    }


    inline virtual YRI_CPP_MONITOR_EDGE *get_AN_incoming_edge()
    {
    	return _AN_INCOMING_EDGE;
    }


    inline virtual YRI_CPP_MONITOR_EDGE *get_AN_outgoing_edge()
    {
    	return _AN_OUTGOING_EDGE;
    }


    inline virtual void set_AN_incoming_edge(YRI_CPP_MONITOR_EDGE *AN_INCOMING_EDGE)
    {
    	_AN_INCOMING_EDGE = AN_INCOMING_EDGE;
    }


    inline virtual void set_AN_outgoing_edge(YRI_CPP_MONITOR_EDGE *AN_OUTGOING_EDGE)
    {
    	_AN_OUTGOING_EDGE = AN_OUTGOING_EDGE;
    }


    inline virtual QString GET_IN_STATEPROPERTY_KEY_VALUE(QString AN_inset_state_property_key)
    {
        return _SET_IN_PRE_STATEPROPERTYKEY_TO_VALUE
        			.value(AN_inset_state_property_key,
        				   YRI_CPP_UTILS::EMPTY_STRING);
    }


    inline virtual QString GET_notIN_STATEPROPERTY_KEY_VALUE(QString a_state_property_key)
    {
        return _SET_notIN_PRE_STATEPROPERTYKEY_TO_VALUE.value(a_state_property_key,
                                                          	  YRI_CPP_UTILS::EMPTY_STRING);
    }


    inline virtual QString GET_db_IN_STATEPROPERTY_KEY_VALUE(QString a_state_property_key)
    {
        return _SET_IN_POST_STATEPROPERTYKEY_TO_VALUE.value(a_state_property_key,
                                                            YRI_CPP_UTILS::EMPTY_STRING);
    }


    inline virtual QString GET_db_NOT_IN_STATEPROPERTY_KEY_VALUE(QString a_state_property_key)
    {
        return _SET_notIN_POST_STATEPROPERTYKEY_TO_VALUE
        			.value(a_state_property_key,
        				   YRI_CPP_UTILS::EMPTY_STRING);
    }


    virtual
	void set_IN_PRE_STATEPROPERTYKEY__to__VALUE(QString a_stateproperty_KEY,
                                                QString a_VALUE);


    virtual
	void set_notIN_PRE_STATEPROPERTYKEY__to__VALUE(QString a_stateproperty_KEY,
                                                   QString a_VALUE);


    virtual
	void set_in_post_STATEPROPERTYKEY__to__VALUE(QString a_stateproperty_KEY,
                                                 QString a_VALUE);


    virtual
	void set_notin_POST_STATEPROPERTYKEY__to__VALUE(QString a_stateproperty_KEY,
                                                    QString a_VALUE);


    virtual inline QString get_STATE_CONDITION__db_variable()
    {
        return _STATE_CONDITION__db_variable;
    }


    virtual inline QString get_STATE_CONDITION__db_query_TABLE__db_query_COLUMN()
    {
        return _STATE_CONDITION__db_query_TABLE__db_query_COLUMN;
    }


    virtual inline QString Get_PRE_CONDITION_notIN()
    {
        return _SET_notIN_PRE_STATEPROPERTYKEY_TO_VALUE
                .value(_STATE_CONDITION__db_variable);
    }


    virtual inline QString Get_PRE_CONDITION_IN()
    {
        return _SET_IN_PRE_STATEPROPERTYKEY_TO_VALUE
                .value(_STATE_CONDITION__db_variable);
    }


    virtual inline QString Get_POST_CONDITION_notIN()
    {
        return _SET_notIN_POST_STATEPROPERTYKEY_TO_VALUE
                .value(_STATE_CONDITION__db_variable);
    }


    virtual inline QString Get_POST_CONDITION_IN()
    {
        return _SET_IN_POST_STATEPROPERTYKEY_TO_VALUE
                .value(_STATE_CONDITION__db_variable);
    }


    /**
     * NOT_IN_PRE(DB_VARIABLE, db_query_TABLE__db_query_COLUMN)
     *
     * REMOVES ANY OTHER state-condition.
     */
    void set_PRE_CONDITION_notIN(QString DB_VARIABLE,
                                 QString db_query_TABLE__db_query_COLUMN);


    /**
     * IN_PRE(DB_VARIABLE, db_query_TABLE__db_query_COLUMN)
     *
     * REMOVES ANY OTHER state-condition.
     */
    void set_PRE_CONDITION_IN(QString DB_VARIABLE,
                              QString db_query_TABLE__db_query_COLUMN);


    /**
     * NOT_IN_POST(DB_VARIABLE, db_query_TABLE__db_query_COLUMN)
     *
     * REMOVES ANY OTHER state-condition.
     */
    void set_POST_CONDITION_notIN(QString DB_VARIABLE,
                                  QString db_query_TABLE__db_query_COLUMN);


    /**
     * IN_POST(DB_VARIABLE, db_query_TABLE__db_query_COLUMN)
     *
     * REMOVES ANY OTHER state-condition.
     */
    void set_POST_CONDITION_IN(QString DB_VARIABLE,
                               QString db_query_TABLE__db_query_COLUMN);


    inline virtual QString get_MONITOR_STATE_STATEPROPERTYVALUE(QString a_state_property_key)
    {
        return _statepropertyKEY_TO_statepropertyVALUE.
               value(a_state_property_key, YRI_CPP_UTILS::EMPTY_STRING);
    }


    inline virtual YRI_CPP_MONITOR_TRACE_EVENT *get_MONITOR_TRACE_EVENTS()
    {
        return _MONITOR_STATE_TRACE_EVENTS;
    }


    virtual QString GET_STRING_representation_OF_state_condition();


    virtual QString GET_STRING_representation_OF_state_condition__ENGINEERING_ACRONYM();


    /**
     * !!! SHALL BE CALLED whenever this SUT state
     * couldn't trigger a state diagram transition
     * event !!!
     */
    inline void remove_RUNTIME_MONITOR_INCOMING_TRACE_EVENT()
    {
    	_TRACE.clear();
    }

    /**
     * !!! SHALL BE CALLED just before triggering
     * any SUT event from this runtime monitor
     * state !!!
     */
    const QStringList &ADD_RUNTIME_MONITOR_INCOMING_TRACE_EVENT(QList<QString> &a_runtime_monitor_trace_event);


    const QStringList &ADD_RUNTIME_MONITOR_TRACE_EVENT(QString a_runtime_monitor_trace_event);


    inline const QStringList &GET_TRACE_OF_THIS_RUNTIME_MONITOR_STATE() const
    {
        return _TRACE;
    }


    virtual inline void Set_SQL_RECOVERY_QUERY_STRING
                         (QString A_SQL_RECOVERY_QUERY_STRING_VERBATIM)
    {
        _SQL_RECOVERY_QUERY_STRING_VERBATIM = A_SQL_RECOVERY_QUERY_STRING_VERBATIM;
    }


    virtual inline bool Is_SQL_RECOVERY_QUERY_STRING_Empty()
    {
        return
            QString(_SQL_RECOVERY_QUERY_STRING_VERBATIM)
                .remove("'").isEmpty();
    }


    virtual inline QString Get_SQL_RECOVERY_QUERY_STRING()
    {
        return _SQL_RECOVERY_QUERY_STRING_VERBATIM;
    }


    inline QString bool_To_String(bool a_boolean_VALUE)
    {
        return (true == a_boolean_VALUE) ? QString("TRUE") : QString("FALSE");
    }


    inline virtual void CLEAR_INCOMING_trace_event_log()
    {
    	_TRACE.clear();
    }


    virtual void set_START_STATE(YRI_CPP_MONITOR 	&A_RUNTIME_MONITOR,
    							 bool 				is_start_state);


    inline virtual void set_ERROR_STATE(bool is_final_state)
    {
    	set_FINAL_STATE(is_final_state);
    }


    virtual void set_FINAL_STATE(bool is_final_state);


    virtual inline bool is_START_STATE()
    {
        return _start_state;
    }


    virtual inline bool is_FINAL_STATE()
    {
        return _final_state;
    }


    virtual inline bool is_ERROR_STATE()
    {
    	return is_FINAL_STATE();
    }


    virtual void print();


    QString MONITOR_STATE_NAME;

    static const QString _MONITOR_STATE_NAME_string_key;

    QString _STATE_CONDITION__db_variable;

    QString _STATE_CONDITION__db_query_TABLE__db_query_COLUMN;

    QMap <QString, QString> _SET_IN_PRE_STATEPROPERTYKEY_TO_VALUE;

    QMap <QString, QString> _SET_notIN_PRE_STATEPROPERTYKEY_TO_VALUE;

    QMap <QString, QString> _SET_IN_POST_STATEPROPERTYKEY_TO_VALUE;

    QMap <QString, QString> _SET_notIN_POST_STATEPROPERTYKEY_TO_VALUE;

    QMap <QString, QString> _statepropertyKEY_TO_statepropertyVALUE;


    YRI_CPP_MONITOR_EDGE *_AN_INCOMING_EDGE;

    YRI_CPP_MONITOR_EDGE *_AN_OUTGOING_EDGE;


protected:

    int _state_id;

    bool _start_state;

    bool _final_state;

    QString _SQL_RECOVERY_QUERY_STRING_VERBATIM;

    QStringList _TRACE;

    YRI_CPP_MONITOR_TRACE_EVENT *_MONITOR_STATE_TRACE_EVENTS;
};



class YRI_CPP_MONITOR_STATE_functor
{
public:

    inline YRI_CPP_MONITOR_STATE_functor(QString a_state_name)
    :_a_state_name_TO_FIND(a_state_name)
    {
    }

    inline bool operator()(YRI_CPP_MONITOR_STATE *a_state) const
    {
        return (0 != a_state) ?
                ( YRI_CPP_UTILS::isEqualsCaseInsensitive(_a_state_name_TO_FIND,
            	   a_state->get_MONITOR_STATE_STATEPROPERTYVALUE
    				  	  (YRI_CPP_MONITOR_STATE::_MONITOR_STATE_NAME_string_key)) ) : false;
    }

private:

    QString _a_state_name_TO_FIND;
};



#endif // _YRI_CPP_MONITOR_STATE_HPP_
