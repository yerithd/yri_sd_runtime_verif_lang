/*
 * YRI_CPP_UTILS.hpp
 *
 *      Author: Pr.  Prof.  Dr.-Ing. Xavier Noundou
 */

#ifndef _YRI_CPP_UTILS_HPP_
#define _YRI_CPP_UTILS_HPP_


#include "../yri-expressions-conditions/YRI_CPP_notinset_inset_TRACE_expression.HPP"


#include <algorithm>
using namespace std;

#include <QtCore/QFile>
#include <QtCore/QObject>


#include <cstdlib>


#define YRI_CPP_CLASS_OPERATORS  \
    inline void *operator new[](size_t size){ return calloc(1, size); } \
    inline void *operator new(size_t size){ return calloc(1, size); } \
    inline void operator delete[](void *ptr){ free(ptr); } \
    inline void operator delete[](void *ptr, size_t){ free(ptr); } \
    inline void operator delete(void *ptr){ free(ptr); } \
    inline void operator delete(void *ptr, size_t){ free(ptr); }


class YRI_CPP_UTILS : public QObject
{
	Q_OBJECT

public:

    YRI_CPP_CLASS_OPERATORS

	YRI_CPP_UTILS();

    inline ~YRI_CPP_UTILS()
    {
    }

    inline static bool isEqualsCaseSensitive(const QString &str1,
                                             const QString &str2)
    {
        return (0 == str1.compare(str2, Qt::CaseSensitive));
    }

    inline static bool isEqualsCaseInsensitive(const QString &str1,
                                               const QString &str2)
    {
        return (0 == str1.compare(str2, Qt::CaseInsensitive));
    }

    static void YERITH_READ_FILE_CONTENT(QFile &file,
                                         QString &fileContentVar);

    static void qDebugStrings(const QString &firstString,
                              const QStringList &aStringList);

    static void qDebugStrings(const QString &firstString,
                              const QString &secondString =
                                              YRI_CPP_UTILS::EMPTY_STRING);


    static bool execQuery(const QString &strQuery,
                          bool          dbg_MSG = false);


    static int execQueryRowCount(const QString &strQuery,
                                 bool          dbg_MSG = false);


    /**
     * Returns the size of the output file created
     * by execution of the program 'program' !
     */
    static int start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const QString &
                                                               program_executable_location_full_path,
                                                               const QString &
                                                               output_file_full_path,
                                                               const QStringList &
                                                               program_executable_args);

    /**
     * Returns the size of the output file created
     * by execution of the program 'program' !
     */
    inline static int start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const QString &
                                                                      program_executable_location_full_path,
                                                                      const QString &
                                                                      program_working_directory_full_path,
                                                                      const QString &
                                                                      output_file_name,
                                                                      const QStringList &
                                                                      program_executable_args)
    {
        return YRI_CPP_UTILS::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE
               (program_executable_location_full_path,
                QString("%1/%2").arg(program_working_directory_full_path,
                                     output_file_name), program_executable_args);
    }


    static QString YRI_HEARDER_hpp_TEMPLATE_RUNTIME_MONITOR;

    static QString YRI_SOURCE_cpp_TEMPLATE_RUNTIME_MONITOR;

    static const QString EMPTY_STRING;

    enum SQL_CONSTANT_IDENTIFIER
    {
        INSERT = 12,
        SELECT = 24,
        UPDATE = 36,
        DELETE = 48,
        UNDEFINED_SQL_COMMAND = 60
    };

    static const QString STRING_delete;
    static const QString STRING_insert;
    static const QString STRING_select;
    static const QString STRING_update;
    static const QString STRING_DB_STMT_UNDEFINED;


    static QMap < uint, QString > _DB_STMT_verification_ToUserViewString;
};


#define FILE_YRI_hpp_TEMPLATE_RUNTIME_MONITOR	":yri_runtime_monitor_template.HPP"

#define FILE_YRI_cpp_TEMPLATE_RUNTIME_MONITOR	":yri_runtime_monitor_template.CPP"


#define GET_C_STR_FROM_QSTRING(X) X.toStdString().c_str()


#define YRI_QVERIFY2_QSTRING(B, QS) QVERIFY2(B, GET_C_STR_FROM_QSTRING(QS))


#define BOOLEAN_STRING_TRUE "True"

#define BOOLEAN_STRING_FALSE "False"

#define INT_TO_STRING(B) ((0 != B) ? "OUI" : "NON")

#define BOOL_TO_STRING(B) (B ? BOOLEAN_STRING_TRUE : BOOLEAN_STRING_FALSE)


#define QDEBUG_STRING_OUTPUT_1(X) 		YRI_CPP_UTILS::qDebugStrings(X, YRI_CPP_UTILS::EMPTY_STRING)

#define QDEBUG_STRING_OUTPUT_2_N(X, Y) 	YRI_CPP_UTILS::qDebugStrings(X, QString::number(Y))

#define QDEBUG_STRING_OUTPUT_2(X, Y) 	YRI_CPP_UTILS::qDebugStrings(X, Y)

#define QDEBUG_QSTRINGLIST_OUTPUT(X, Y) YRI_CPP_UTILS::qDebugStrings(X, Y)


#endif // _YRI_CPP_UTILS_HPP_
