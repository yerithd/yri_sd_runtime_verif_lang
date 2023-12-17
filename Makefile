# Makefile

SRC = src

OBJ_DIR = obj

OBJS	= bison.o lex.o yri_main.o \
				${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.o \
				${OBJ_DIR}/YRI_SPEC_STMT_MEALY_AUTOMATON.o

CC	= g++  

CFLAGS	= -g -Wall -pedantic \
					-fPIC -Wextra -pipe \
					-D_REENTRANT -DQT_NO_VERSION_TAGGING -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_SQL_LIB -DQT_CORE_LIB \
					-Isrc \
					-I/usr/lib/x86_64-linux-gnu \
					-I/usr/lib/x86_64-linux-gnu \
					-I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ \
					-I/usr/include/x86_64-linux-gnu/qt5 
					

LINKFLAGS	= -Llib -lyri_sd_runtime_verif \
			  -L/usr/lib/x86_64-linux-gnu -lQt5Sql -lQt5Core
					


yri_sd_runtime_verif_lang:		$(OBJS)
		$(CC) -o yri_sd_runtime_verif_lang_comp $(OBJS) $(LINKFLAGS) 


${OBJ_DIR}/YRI_SPEC_STMT_MEALY_AUTOMATON.o:		${SRC}/YRI_SPEC_STMT_MEALY_AUTOMATON.cpp
		mkdir -p ${OBJ_DIR}
		$(CC) $(CFLAGS) -c ${SRC}/YRI_SPEC_STMT_MEALY_AUTOMATON.cpp -o ${OBJ_DIR}/YRI_SPEC_STMT_MEALY_AUTOMATON.o


${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.o: ${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.cpp 
	$(CXX) -c $(CFLAGS) -o ${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.o ${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.cpp

${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.cpp: yri_sd_runtime_verif_lang.qrc \
	/usr/lib/qt5/bin/rcc \
	yri_runtime_monitor_template.HPP \
	yri_runtime_monitor_template.CPP
	/usr/lib/qt5/bin/rcc -name yri_sd_runtime_verif_lang yri_sd_runtime_verif_lang.qrc -o ${OBJ_DIR}/qrc_yri_sd_runtime_verif_lang.cpp


lex.o:		lex.c
		$(CC) $(CFLAGS) -c lex.c -o lex.o

lex.c:		yri_sd_runtime_verif_lang.lex
		flex yri_sd_runtime_verif_lang.lex
		cp lex.yy.c lex.c

bison.o:	bison.c
		$(CC) $(CFLAGS) -c bison.c -o bison.o

bison.c:	yri_sd_runtime_verif_lang.y
		mkdir -p lib ${OBJ_DIR}
		bison -d -v yri_sd_runtime_verif_lang.y
		cp yri_sd_runtime_verif_lang.tab.c bison.c
		cmp -s yri_sd_runtime_verif_lang.tab.h tok.h || cp yri_sd_runtime_verif_lang.tab.h tok.h

yri_main.o:		yri_main.cc
		$(CC) $(CFLAGS) -c yri_main.cc -o yri_main.o

lex.o yac.o yri_main.o	: YRI_HEADING.h
lex.o yri_main.o		: tok.h



clean:
	rm -f ${OBJ_DIR}/* \
		*.o \
		*~ \
		lex.c \
		lex.yy.c \
		bison.c \
		tok.h \
		yri_sd_runtime_verif_lang.tab.c \
		yri_sd_runtime_verif_lang.tab.h \
		yri_sd_runtime_verif_lang.output

