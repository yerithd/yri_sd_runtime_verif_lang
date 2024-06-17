/*
* @AUTEUR: Pr. Prof. Dr. Xavier Noundou
*/

%option noinput nounput nodefault yylineno
%option noyywrap

%{
#include "YRI_HEADING.h"
#include "tok.h"
int yyerror(char *s);
%}


space									[ \t\n]+
right_arrow						"->"
mealy_automaton_spec	"yri_sd_mealy_automaton_spec"
IN_SQL_EVENT_LOG			"in_sql_event_log"
NOT_IN_SQL_EVENT_LOG	"not_in_sql_event_log"
in_set_trace					"in_set_trace"
not_in_set_trace			"not_in_set_trace"
recovery_sql_query		"recovery_sql_query"
in_before							"IN_BEFORE"
in_after							"IN_AFTER"
in_pre								"IN_PRE"
in_post								"IN_POST"
notin_before					"NOT_IN_BEFORE"
notin_after						"NOT_IN_AFTER"
notin_pre							"NOT_IN_PRE"
notin_post						"NOT_IN_POST"
end_state_auto				"END_STATE_AUTO"
end_state							"END_STATE"
error_state_auto			"ERROR_STATE_AUTO"
error_state						"ERROR_STATE"
final_state_auto			"FINAL_STATE_AUTO"
final_state						"FINAL_STATE"
begin_state						"BEGIN_STATE"
start_state						"START_STATE"
state									"STATE"
string								"'"[ \t\n\.?_,()`a-zA-Z0-9]*"'"
alpha_num							[_a-zA-Z]+[_0-9a-zA-Z]*
alpha_num_DASH_SIGN		[-_a-zA-Z]+[_0-9a-zA-Z]*
slash									"/"
dot										"."
coma									","
colon									":"
l_bracket							"["
r_bracket							"]"
l_parenthesis					"("
r_parenthesis					")"
l_brace								"{"
r_brace								"}"


%%
{space}            			; /* Do nothing */
{mealy_automaton_spec}	{ yylval.opt_val = new std::string(yytext); return YRI_SD_MEALY_AUTOMATON_SPEC_TOK; }
{right_arrow}						{ yylval.opt_val = new std::string(yytext); return RIGHT_ARROW_TOK; }
{IN_SQL_EVENT_LOG}			{ yylval.opt_val = new std::string(yytext); return IN_SQL_EVENT_LOG_TOK; }
{NOT_IN_SQL_EVENT_LOG}	{ yylval.opt_val = new std::string(yytext); return NOT_IN_SQL_EVENT_LOG_TOK; }
{in_set_trace}					{ yylval.opt_val = new std::string(yytext); return IN_SET_TRACE_TOK; }
{not_in_set_trace}			{ yylval.opt_val = new std::string(yytext); return NOT_IN_SET_TRACE_TOK; }
{in_before}							{ yylval.opt_val = new std::string(yytext); return IN_BEFORE_TOK; }
{in_after}							{ yylval.opt_val = new std::string(yytext); return IN_AFTER_TOK; }
{in_pre}								{ yylval.opt_val = new std::string(yytext); return IN_PRE_TOK; }
{in_post}								{ yylval.opt_val = new std::string(yytext); return IN_POST_TOK; }
{notin_before}					{ yylval.opt_val = new std::string(yytext); return NOT_IN_BEFORE_TOK; }
{notin_after}						{ yylval.opt_val = new std::string(yytext); return NOT_IN_AFTER_TOK; }
{notin_pre}							{ yylval.opt_val = new std::string(yytext); return NOT_IN_PRE_TOK; }
{notin_post}						{ yylval.opt_val = new std::string(yytext); return NOT_IN_POST_TOK; }
{recovery_sql_query}		{ yylval.opt_val = new std::string(yytext); return RECOVERY_SQL_QUERY_TOK; }
{end_state_auto}				{ yylval.opt_val = new std::string(yytext); return END_STATE_AUTO_TOK; }
{end_state}							{ yylval.opt_val = new std::string(yytext); return END_STATE_TOK; }
{error_state_auto}			{ yylval.opt_val = new std::string(yytext); return ERROR_STATE_AUTO_TOK; }
{error_state}						{ yylval.opt_val = new std::string(yytext); return ERROR_STATE_TOK; }
{final_state_auto}			{ yylval.opt_val = new std::string(yytext); return FINAL_STATE_AUTO_TOK; }
{final_state}						{ yylval.opt_val = new std::string(yytext); return FINAL_STATE_TOK; }
{begin_state}						{ yylval.opt_val = new std::string(yytext); return BEGIN_STATE_TOK; }
{start_state}						{ yylval.opt_val = new std::string(yytext); return START_STATE_TOK; }
{state}									{ yylval.opt_val = new std::string(yytext); return STATE_TOK; }
{string}								{ yylval.opt_val = new std::string(yytext); return STRING_TOK; }
{alpha_num}							{ yylval.opt_val = new std::string(yytext); return ALPHA_NUM_TOK; }
{alpha_num_DASH_SIGN}		{ yylval.opt_val = new std::string(yytext); return ALPHA_NUM_DASH_SIGN_TOK; }
{slash}									{ yylval.opt_val = new std::string(yytext); return SLASH_TOK; }
{dot}										{ yylval.opt_val = new std::string(yytext); return DOT_TOK; }
{coma}									{ yylval.opt_val = new std::string(yytext); return COMA_TOK; }
{colon}									{ yylval.opt_val = new std::string(yytext); return COLON_TOK; }
{l_bracket}							{ yylval.opt_val = new std::string(yytext); return LEFT_BRACKET_TOK; }
{r_bracket}							{ yylval.opt_val = new std::string(yytext); return RIGHT_BRACKET_TOK; }
{l_parenthesis}					{ yylval.opt_val = new std::string(yytext); return LEFT_PARENTHESIS_TOK; }
{r_parenthesis}					{ yylval.opt_val = new std::string(yytext); return RIGHT_PARENTHESIS_TOK; }
{l_brace}								{ yylval.opt_val = new std::string(yytext); return LEFT_BRACE_TOK; }
{r_brace}								{ yylval.opt_val = new std::string(yytext); return RIGHT_BRACE_TOK; }
.												{ std::cerr << "SCANNER "; yyerror(""); exit(1);	}
%%


