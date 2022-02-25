CFLAGS=-Wall

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser 

parser.cpp: parser.y
	bison -d -o $@ $^

parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	lex -o $@ $^

parser: parser.cpp main.cpp tokens.cpp
	g++ $(CFLAGS) -o $@ *.cpp 

prueba:  parser ../pruebas/prueba1.in ../pruebas/prueba2.in ../pruebas/prueba3.in ../pruebas/pruebamala1.in ../pruebas/pruebamala2.in ../pruebas/pruebamala3.in
	./parser <../pruebas/prueba1.in
	./parser <../pruebas/prueba2.in
	./parser <../pruebas/prueba3.in
	./parser <../pruebas/pruebamala1.in
	./parser <../pruebas/pruebamala2.in
	./parser <../pruebas/pruebamala3.in
