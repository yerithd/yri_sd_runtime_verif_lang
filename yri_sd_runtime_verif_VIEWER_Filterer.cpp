/*
 * yri_sd_runtime_verif_VIEWER_Filterer.hpp
 *
 */

#include "yri_sd_runtime_verif_VIEWER_Filterer.hpp"


#include "utils/yri-db-runtime-verif-logger.hpp"



void YRI_DB_Runtime_Verif_Viewer_FILTERER::
            VIEW_only_STATEMENT(enum YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER A_SQL_Event_Stmt)
{
    switch(A_SQL_Event_Stmt)
    {
    case YRI_CPP_UTILS::INSERT:
        filter_View___INSERT_stmts(true);
        filter_View___SELECT_stmts(false);
        filter_View___UPDATE_stmts(false);
        filter_View___DELETE_stmts(false);
        break;

    case YRI_CPP_UTILS::SELECT:
        filter_View___INSERT_stmts(false);
        filter_View___SELECT_stmts(true);
        filter_View___UPDATE_stmts(false);
        filter_View___DELETE_stmts(false);
        break;


    case YRI_CPP_UTILS::UPDATE:
        filter_View___INSERT_stmts(false);
        filter_View___SELECT_stmts(false);
        filter_View___UPDATE_stmts(true);
        filter_View___DELETE_stmts(false);
        break;


    case YRI_CPP_UTILS::DELETE:
        filter_View___INSERT_stmts(false);
        filter_View___SELECT_stmts(false);
        filter_View___UPDATE_stmts(false);
        filter_View___DELETE_stmts(true);
        break;


    default:
        break;
    }
}


void YRI_DB_Runtime_Verif_Viewer_FILTERER::filter_View_All_stmts()
{
    _FILTER_view_All_STMTS___ = true;

    _FILTER__View___INsert_STMTS___ = false;

    _FILTER__View___SElect_STMTS___ = false;

    _FILTER__View___UPdate_STMTS___ = false;

    _FILTER__View___DElete_STMTS___ = false;
}


void YRI_DB_Runtime_Verif_Viewer_FILTERER::FILTER___view__only____INSERT___CMDs(yri_cur_SQL_command,
                                                                                yri_sql_table_name,
                                                                                yri_sql_record_qty_MODIFIED,
                                                                                yri_CPP_FILE_NAME,
                                                                                yri_cpp_line_number)
{
    if (YRI_CPP_UTILS::INSERT == yri_cur_SQL_command    &&
        _FILTER__View___INsert_STMTS___                 &&
        ! _FILTER_view_All_STMTS___)
    {
        qDebug() << "\t "
                 << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]")
                     .arg(YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.value(yri_cur_SQL_command),
                         yri_sql_table_name,
                         QString::number(yri_cur_SQL_command),
                         QString::number(yri_sql_record_qty_MODIFIED),
                         yri_CPP_FILE_NAME,
                         yri_cpp_line_number);
    }
}


void YRI_DB_Runtime_Verif_Viewer_FILTERER::FILTER___view__only____SELECT___CMDs(yri_cur_SQL_command,
                                                                                yri_sql_table_name,
                                                                                yri_sql_record_qty_MODIFIED,
                                                                                yri_CPP_FILE_NAME,
                                                                                yri_cpp_line_number)
{
    if (YRI_CPP_UTILS::SELECT == yri_cur_SQL_command    &&
        _FILTER__View___SElect_STMTS___                 &&
        ! _FILTER_view_All_STMTS___)
    {
        qDebug() << "\t "
                 << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]")
                     .arg(YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.value(yri_cur_SQL_command),
                         yri_sql_table_name,
                         QString::number(yri_cur_SQL_command),
                         QString::number(yri_sql_record_qty_MODIFIED),
                         yri_CPP_FILE_NAME,
                         yri_cpp_line_number);
    }
}


void YRI_DB_Runtime_Verif_Viewer_FILTERER::FILTER___view__only____UPDATE___CMDs(yri_cur_SQL_command,
                                                                                yri_sql_table_name,
                                                                                yri_sql_record_qty_MODIFIED,
                                                                                yri_CPP_FILE_NAME,
                                                                                yri_cpp_line_number)
{
    if (YRI_CPP_UTILS::UPDATE == yri_cur_SQL_command    &&
        _FILTER__View___UPdate_STMTS___                 &&
        ! _FILTER_view_All_STMTS___)
    {
        qDebug() << "\t "
                 << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]")
                     .arg(YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.value(yri_cur_SQL_command),
                         yri_sql_table_name,
                         QString::number(yri_cur_SQL_command),
                         QString::number(yri_sql_record_qty_MODIFIED),
                         yri_CPP_FILE_NAME,
                         yri_cpp_line_number);
    }
}


void YRI_DB_Runtime_Verif_Viewer_FILTERER::FILTER___view__only____DELETE___CMDs(yri_cur_SQL_command,
                                                                                yri_sql_table_name,
                                                                                yri_sql_record_qty_MODIFIED,
                                                                                yri_CPP_FILE_NAME,
                                                                                yri_cpp_line_number)
{
    if (YRI_CPP_UTILS::DELETE == yri_cur_SQL_command    &&
        _FILTER__View___DElete_STMTS___                 &&
        ! _FILTER_view_All_STMTS___)
    {
        qDebug() << "\t "
                 << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]")
                     .arg(YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.value(yri_cur_SQL_command),
                         yri_sql_table_name,
                         QString::number(yri_cur_SQL_command),
                         QString::number(yri_sql_record_qty_MODIFIED),
                         yri_CPP_FILE_NAME,
                         yri_cpp_line_number);
    }
}


