
%{
#include "YR_HEADING.h"
void yr_printf(string a_val_str);
int yyerror(char *s);
int yylex(void);
%}

%union{
  int		int_val;
  string*	opt_val;
}

%start	input 

%token	<opt_val>	SPACE_TOK
%token	<opt_val>	MEALY_AUTOMATON_SPEC_TOK
%token	<opt_val>	RIGHT_ARROW_TOK
%token	<int_val>	DIGIT_TOK
%token	<opt_val>	ALPHA_NUM_TOK
%token	<opt_val>	LEFT_INTERVAL_TOK
%token	<opt_val>	RIGHT_INTERVAL_TOK
%token	<opt_val>	LEFT_PAREN_TOK
%token	<opt_val>	RIGHT_PAREN_TOK
%token	<opt_val>	LEFT_PARENTHESIS_TOK
%token	<opt_val>	RIGHT_PARENTHESIS_TOK
%token	<opt_val>	DOT_TOK
%token	<opt_val>	COLON_TOK
%token	<opt_val>	COMA_TOK
%token	<opt_val>	SEMI_COLON_TOK
%token	<opt_val>	STRING_TOK
%token	<opt_val>	IN_SET_TRACE_TOK
%token	<opt_val>	NOT_IN_SET_TRACE_TOK
%token	<opt_val>	IN_PRE_TOK
%token	<opt_val>	IN_POST_TOK
%token	<opt_val>	NOT_IN_PRE_TOK
%token	<opt_val>	NOT_IN_POST_TOK
%token	<opt_val>	STATE_TOK

%type	<opt_val>	mealy_automaton_spec
%type	<opt_val>	body_spec
%type	<opt_val>	state_property_specification
%type	<opt_val>	sut_edge_state_spec
%type	<opt_val>	algebra_set_specification
%type	<opt_val>	in_spec
%type	<opt_val>	not_in_spec
%type	<opt_val>	inside_algebra_set_specification
%type	<opt_val>	not_inside_algebra_set_specification
%type	<opt_val>	db_table
%type	<opt_val>	db_column
%type	<opt_val>	prog_variable
%type	<opt_val>	sut_edge_mealy_automaton_spec
%type	<opt_val>	event_method_call

%left	SEMI_COLON_TOK
%left	RIGHT_ARROW_TOK

%%

input : /* empty */
			| MEALY_AUTOMATON_SPEC_TOK SPACE_TOK ALPHA_NUM_TOK SPACE_TOK 
					LEFT_PARENTHESIS_TOK 
						mealy_automaton_spec DOT_TOK	
					RIGHT_PARENTHESIS_TOK																													{ yr_printf("mealy_automaton_spec"); }
			;
mealy_automaton_spec : sut_state_spec 																									{ }
										 | sut_state_spec RIGHT_ARROW_TOK sut_edge_state_spec 							{ }
										 ;
sut_edge_state_spec : sut_edge_mealy_automaton_spec RIGHT_ARROW_TOK mealy_automaton_spec{ }
										;
sut_edge_mealy_automaton_spec : event_method_call																				{ }
															;
event_method_call : STRING_TOK																													{ yr_printf("event_method_call"); }
									;
sut_state_spec : state_property_specification	SEMI_COLON_TOK algebra_set_specification	{ }
							 ;
algebra_set_specification : inside_algebra_set_specification 														{ }
													| not_inside_algebra_set_specification												{ }
													;
in_spec : IN_PRE_TOK																																		{ }
				| IN_POST_TOK																																		{ }
				;
not_in_spec : NOT_IN_PRE_TOK																														{ }
						| NOT_IN_POST_TOK																														{ }
						;
inside_algebra_set_specification : in_spec 
																 		LEFT_PAREN_TOK 
																 			prog_variable COMA_TOK db_table DOT_TOK db_column 
																		RIGHT_PAREN_TOK																			{ }
																 ;
not_inside_algebra_set_specification : not_in_spec
																		 		LEFT_PAREN_TOK 
																		 			prog_variable COMA_TOK db_table DOT_TOK db_column 
																				RIGHT_PAREN_TOK																	{ }
																		 ;
state_property_specification : STATE_TOK 
														 		LEFT_PAREN_TOK 
																	ALPHA_NUM_TOK 
																RIGHT_PAREN_TOK																					{ yr_printf("state_property_specification"); }
														 ;
prog_variable : ALPHA_NUM_TOK		{ }
				 ;
db_table : ALPHA_NUM_TOK				{ }
				 ;
db_column : ALPHA_NUM_TOK				{ }
					;

/*
trace_specification : LEFT_INTERVAL_TOK IN_SET_TRACE_TOK LEFT_PAREN_TOK COMA_TOK  "["in_set_trace(prog_variable, prog_trace)"]" |
		        "["not_in_set_trace(prog_variable, prog_trace)"]"

edge_mealy_automaton_guard_cond ::= "["trace_specification"]"
*/



%%

void yr_printf(string a_val_str)
{
	extern char *yytext;	// defined and maintained in lex.c
	printf("%s: %s\n", a_val_str.c_str(), yytext);
}

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}


