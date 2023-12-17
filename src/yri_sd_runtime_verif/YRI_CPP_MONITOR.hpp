/*
 * YRI_CPP_MONITOR.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_CPP_MONITOR_HPP_
#define _YRI_CPP_MONITOR_HPP_


/**
 * TO KEEP EXACTLY AS A RELATIVE PATH
 * SO TO AVOID build errors in
 * 'yri-db-runtime-verif' project.
 */
#include "utils/YRI_CPP_UTILS.hpp"

#include "YRI_CPP_MONITOR_object.hpp"


#include <QtSql/QSqlDatabase>

#include <QtSql/QSqlError>


#include <QtCore/QObject>

#include <QtCore/QString>

#include <QtCore/QMap>

#include <QtCore/QList>



class YRI_CPP_MONITOR_ERP_database;

class YRI_CPP_notinset_inset_TRACE_expression;

class YRI_CPP_MONITOR_EDGE;

class YRI_CPP_MONITOR_STATE;

class YRI_CPP_MONITOR_STATE_PROPERTY_VALUE;


class YRI_CPP_MONITOR : public YRI_CPP_MONITOR_object
{
	Q_OBJECT

public:

    YRI_CPP_CLASS_OPERATORS

    static YRI_CPP_MONITOR *CREATE_MONITOR(QString RUNTIME_MONITOR_NAME = YRI_CPP_UTILS::EMPTY_STRING);

    static YRI_CPP_MONITOR *CREATE_MONITOR(QString db_type,
                                          QString db_name,
                                          QString db_ip_address,
                                          QString db_user_name,
                                          QString db_user_pwd,
                                          QString db_connection_options = YRI_CPP_UTILS::EMPTY_STRING,
                                          QString RUNTIME_MONITOR_NAME = YRI_CPP_UTILS::EMPTY_STRING);

    virtual ~YRI_CPP_MONITOR();

    void set_yri_root_edge(YRI_CPP_MONITOR_EDGE *ROOT_EDGE);


    //######################## RUNNING THE RUNTIME MONITOR //########################


    /**
     * function "YRI_register_final_state_CALLBACK_FUNCTION"
     * IS CALLED BACK WHENEVER A final state is reached !
     */
    void YRI_register_set_final_state_CALLBACK_FUNCTION
			(void (*CALL_BACK_final_state)(YRI_CPP_MONITOR 		*a_runtime_monitor,
										   YRI_CPP_MONITOR_EDGE 	*an_EDGE_leading_TO_error_FINAL_state));


    /**
     * SETS THE CURRENT STATE TO the start state.
     */
    bool RESET_RUNTIME_MONITOR();



    //######################## RECOVERING FROM ERROR ACCEPTING STATES

    // WE ONLY SUPPORT "MISSING DATABASE TABLE COLUMN VALUE DEFINITION" as
    // DESCRIBED IN yerith_qvge user's guide (https://zenodo.org/record/8387240).

    virtual bool CAN_recover_FROM_THIS_ACCEPTING_ERROR_State
                    (YRI_CPP_MONITOR_STATE *an_error_accepting_state);


    virtual void execute_RECOVERY_SQL_QUERY_from_accepting_error_state
                    (YRI_CPP_MONITOR_STATE *a_previous_source_state,
                     YRI_CPP_MONITOR_STATE *an_error_accepting_state);


    virtual void set_Recovery_action(YRI_CPP_MONITOR_STATE *a_previous_source_state,
                                     YRI_CPP_MONITOR_STATE *an_error_accepting_state);

    //########################



    /**
     * "TRUE" is returned in case an edge event
     * "an_edge_event" was triggered !
     */
    bool YRI_trigger_an_edge_event(QString 			an_edge_event,
    							  bool 				debug_MSG = true);


    //######################## CHECKING SET APPARTENANCE (\in, \notin) //########################

    virtual bool SET_DB_CONFIGURATION_PARAMETERS(QString db_type,
                                                 QString db_name,
                                                 QString db_ip_address,
                                                 QString db_user_name,
                                                 QString db_user_pwd,
                                                 QString db_connection_options = YRI_CPP_UTILS::EMPTY_STRING);

    virtual bool is_in_SET_ALGEBRA(QString a_SET_VARIABLE,
                                   QString a_SUPPOSED_SET_VARIABLE);

    //########################

    bool CHECK_whether__STATE__is__Accepting(YRI_CPP_MONITOR_STATE &A_POTENTIAL_ACCEPTING_STATE);

    //########################

    bool CHECK_PRE_CONDITION_notIN(QMap<QString, QString> &SET_NOTin_PRE_STATEPROPERTYKEY_TO_VALUE_map);

    bool CHECK_PRE_CONDITION_IN(QMap<QString, QString> &SET_in_PRE_STATEPROPERTYKEY_TO_VALUE_map);

    bool CHECK_post_condition_notIN(QMap<QString, QString> &SET_notIN_POST_STATEPROPERTYKEY_TO_VALUE_map);

    bool CHECK_post_condition_IN(QMap<QString, QString> &SET_IN_POST_STATEPROPERTYKEY_TO_VALUE_map);

    //########################


    QString YRI_open_HEADER_TEMPLATE_FILE();

    QString YRI_open_SOURCE_TEMPLATE_FILE();


    QString YRI_generate_cplusplus_headers_files__AND__SAVE__TO__DISK
                (QString A_hpp_FILE_NAME,
                 QString a_class_NAME = "YRI_DB_RUNTIME_VERIF_Main");


    QString YRI_generate_cplusplus_headers_files(QString A_hpp_FILE_NAME,
                                                QString a_class_NAME);


    QString GENERATE_METHOD_event_call(QString _event_METHOD_name,
                                       QString _STRING_bool_GUARDED_CONDITION = YRI_CPP_UTILS::EMPTY_STRING);


	QString YRI_GENERATE_FINAL_STATE_auto_CODE(QString               &a_last_edge_VARIABLE_STRING_pointer,
                                              YRI_CPP_MONITOR_EDGE   &_AN_EDGE);


    QString YRI_GENERATE_START_FINAL_STATE_CODE(QString 				&a_last_edge_VARIABLE_STRING_pointer,
                                               YRI_CPP_MONITOR_EDGE 	&_AN_EDGE);


    QString GENERATE_pre_post_conditions_code(QString 				&a_last_edge_VARIABLE_STRING_pointer,
                                              YRI_CPP_MONITOR_EDGE 	&_AN_EDGE);


    QString YRI_generate_cplusplus_sources_files__AND__SAVE__TO__DISK
                (QString A_cpp_FILE_NAME,
                 QString a_class_NAME = "YRI_DB_RUNTIME_VERIF_Main");


    QString YRI_generate_cplusplus_sources_files(QString A_cpp_FILE_NAME,
                                                QString a_class_NAME);


    void save_yri_SOURCE_FILES(QString a_header_OR_SOURCE_file_NAME,
                              QString a_header_OR_SOURCE_file_CONTENT);

    //########################

    void find_yri_monitor_edges(YRI_CPP_MONITOR_EDGE 				&an_edge,
                               QList<YRI_CPP_MONITOR_EDGE *> 	&resulting_edges);

    void find_yri_monitor_edges(QString 						start_state_key,
                               QString 						end_state_key,
                               QList<YRI_CPP_MONITOR_EDGE *> &resulting_edges);


    //########################

    YRI_CPP_MONITOR_EDGE *create_yri_monitor_edge(QString source_state_key,
                                                QString target_state_key);

    YRI_CPP_MONITOR_EDGE *create_yri_monitor_edge(QString source_state_key,
                                                QString target_state_key,
                                                QString event_string);

    YRI_CPP_MONITOR_EDGE *
		create_yri_monitor_edge(QString source_state_key,
                               QString target_state_key,
                               QString event_string,
							   YRI_CPP_notinset_inset_TRACE_expression *guarded_condition);

    YRI_CPP_MONITOR_EDGE *create_yri_monitor_edge(QString source_state_key,
                                                QString target_state_key,
                                                QString event_string,
                                                QString guarded_condition_STRING);

    bool DELETE_yri_monitor_edge(YRI_CPP_MONITOR_EDGE *an_edge);


    //########################

    YRI_CPP_MONITOR_STATE *find_yri_monitor_state(QString a_state_key);

    YRI_CPP_MONITOR_STATE *create_yri_monitor_state(QString a_state_key = YRI_CPP_UTILS::EMPTY_STRING);

    bool DELETE_yri_monitor_state(int a_state_ID);


    //########################

    inline QList<YRI_CPP_MONITOR_EDGE *> &get_EDGES()
    {
        return _EDGES;
    }

    virtual QString generate_in_DOT_format(const QString &digraph_dot_name,
    							   	   	   bool 		 PRINT_WITH_SQL_EVENT_LOG_TOKEN);

    virtual QString generate_in_DOT_format(bool PRINT_WITH_SQL_EVENT_LOG_TOKEN = false);

    virtual QString print_TO_dot_FILE(const QString &program_working_directory,
                                      const QString &dot_file_name,
    						  	  	  bool 			PRINT_WITH_SQL_EVENT_LOG_TOKEN = false,
    						  	  	  bool          YRI_VIEW_RESULTING_PDF_FILE = true,
    						  	  	  bool          YRI_DEBUG_OUTPUT_PARAMETERS = true);


    inline virtual QString print_TO_dot_FILE(const QString &dot_file_name,
                                             bool 		   PRINT_WITH_SQL_EVENT_LOG_TOKEN = false,
                                             bool          YRI_VIEW_RESULTING_PDF_FILE = true,
                                             bool          YRI_DEBUG_OUTPUT_PARAMETERS = true)
    {
        return print_TO_dot_FILE(".",
                                 dot_file_name,
                                 PRINT_WITH_SQL_EVENT_LOG_TOKEN,
                                 YRI_VIEW_RESULTING_PDF_FILE,
                                 YRI_DEBUG_OUTPUT_PARAMETERS);
    }


    inline virtual QString print_TO_dot_FILE(bool PRINT_WITH_SQL_EVENT_LOG_TOKEN = false,
                                             bool YRI_VIEW_RESULTING_PDF_FILE = true)
    {
        return print_TO_dot_FILE(QString("%1")
        							.arg(_RUNTIME_MONITOR_NAME),
                                 PRINT_WITH_SQL_EVENT_LOG_TOKEN,
                                 YRI_VIEW_RESULTING_PDF_FILE);
    }


    //########################

    virtual inline void set_RUNTIME_MONITOR_NAME(QString RUNTIME_MONITOR_NAME)
    {
        _RUNTIME_MONITOR_NAME = RUNTIME_MONITOR_NAME.trimmed();
    }

    virtual inline QString get_RUNTIME_MONITOR_NAME()
    {
        return _RUNTIME_MONITOR_NAME.trimmed();
    }


    //########################

    void set_current_MONITOR_STATE(YRI_CPP_MONITOR_STATE *a_current_STATE);

    inline YRI_CPP_MONITOR_STATE *get_current_MONITOR_STATE()
    {
        return _current_STATE;
    }


    //########################

    inline bool IS_in_TRACE_LOG(QString an_EVENT_TOKEN)
    {
    	return _TRACE_LOG.contains(an_EVENT_TOKEN);
    }

    inline void TRACE_LOG_current_RECEIVED_EVENT_TOKEN(QString a_current_received_EVENT_TOKEN)
    {
    	_TRACE_LOG.append(a_current_received_EVENT_TOKEN);
    }


    //########################

    inline virtual YRI_CPP_MONITOR_EDGE *GET_root_edge()
    {
    	return _ROOT_EDGE;
    }

    void set_current_triggered_EDGE(YRI_CPP_MONITOR_EDGE *a_current_triggered_EDGE);

    inline YRI_CPP_MONITOR_EDGE *get_current_triggered_EDGE()
    {
        return _current_triggered_EDGE;
    }

    inline uint YRI_CPP_monitor_edge_count()
    {
    	return (uint) _EDGES.size();
    }

    inline uint YRI_CPP_monitor_state_count()
    {
    	return (uint) _STATES.size();
    }

protected:


    inline YRI_CPP_MONITOR()
    :_ROOT_EDGE(0),
	 _CALL_BACK_final_state(0),
     _yri_SET_ALGEBRA_inclusion_DATABASE_to_query_for_STATUS(0),
     _RUNTIME_MONITOR_NAME(YRI_CPP_UTILS::EMPTY_STRING),
     _current_STATE(0),
	 _current_triggered_EDGE(0)
    {
    }

    inline YRI_CPP_MONITOR(QString RUNTIME_MONITOR_NAME)
    :_ROOT_EDGE(0),
	 _CALL_BACK_final_state(0),
	 _yri_SET_ALGEBRA_inclusion_DATABASE_to_query_for_STATUS(0),
	 _RUNTIME_MONITOR_NAME(RUNTIME_MONITOR_NAME),
	 _current_STATE(0),
	 _current_triggered_EDGE(0)
    {
    }



    QList<QString> _TRACE_LOG;

    YRI_CPP_MONITOR_EDGE *_ROOT_EDGE;

protected:

    void (*_CALL_BACK_final_state)(YRI_CPP_MONITOR 		*a_runtime_monitor,
    							   YRI_CPP_MONITOR_EDGE 	*an_EDGE_leading_TO_error_FINAL_state);


    static const char INCOMING_TRACE_EVENT_SEPARATOR_CHARACTER;


    YRI_CPP_MONITOR_ERP_database *_yri_SET_ALGEBRA_inclusion_DATABASE_to_query_for_STATUS;

    QString _RUNTIME_MONITOR_NAME;

    YRI_CPP_MONITOR_STATE *_current_STATE;

    YRI_CPP_MONITOR_EDGE *_current_triggered_EDGE;


    QMap<YRI_CPP_MONITOR_STATE *, QString> _recoverable_error_STATES__To__SQL_query_TOEXECUTE_for_Recovery;


    QList<YRI_CPP_MONITOR_EDGE *> _EDGES;

    QList<YRI_CPP_MONITOR_STATE *> _STATES;
};



#endif // _YRI_CPP_MONITOR_HPP_
