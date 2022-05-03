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

prueba:  parser ../pruebas/pruebaBuena1.dat ../pruebas/pruebaBuena2.dat ../pruebas/pruebaBuena3.dat ../pruebas/pruebaBuena4.dat ../pruebas/pruebaBuena5.dat ../pruebas/pruebaMala1.dat ../pruebas/pruebaMala2.dat ../pruebas/pruebaMala3.dat
	./parser <../pruebas/pruebaBuena1.dat
	./parser <../pruebas/pruebaBuena2.dat
	./parser <../pruebas/pruebaBuena3.dat
	./parser <../pruebas/pruebaBuena4.dat
	./parser <../pruebas/pruebaBuena5.dat
	./parser <../pruebas/pruebaMala1.dat
	./parser <../pruebas/pruebaMala2.dat
	./parser <../pruebas/pruebaMala3.dat
