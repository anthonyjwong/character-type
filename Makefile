#-----------------------------------------------------------------------------
# Name: Anthony Wong
# CruzID: 1652596
# Class: 12M
# Date: 7 Feb 2019
# Desc: Makefile
# File Name: Makefile
#-----------------------------------------------------------------------------

FLAGS = -std=c99 -Wall
SOURCES = charType.c README Makefile
OBJECTS = charType.o
EXEBIN = charType
LAB = lab4
SUBMIT = submit cmps012b-pt.w19 $(LAB)

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)

submit: $(SOURCES)
	$(SUBMIT) $(SOURCES)
