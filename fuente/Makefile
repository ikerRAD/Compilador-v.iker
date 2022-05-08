CFLAGS=-Wall
FUENTES=parser.cpp main.cpp tokens.cpp Codigo.cpp PilaTablaSimbolos.cpp TablaSimbolos.cpp

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp *~

parser.cpp parser.hpp: parser.y Codigo.hpp PilaTablaSimbolos.hpp TablaSimbolos.hpp
	bison -d -o $@ $<

parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp PilaTablaSimbolos.hpp TablaSimbolos.hpp
	lex -o $@ $<

parser: $(FUENTES) Codigo.hpp PilaTablaSimbolos.hpp TablaSimbolos.hpp
	g++ $(CFLAGS) -o $@ $(FUENTES)

prueba:  
	./parser <pruebas/pruebaBuena1.dat
	./parser <pruebas/pruebaBuena2.dat
	./parser <pruebas/pruebaBuena3.dat
	./parser <pruebas/pruebaBuena4.dat
	./parser <pruebas/pruebaBuena5.dat
	./parser <pruebas/pruebaMala1.dat
	./parser <pruebas/pruebaMala2.dat
	./parser <pruebas/pruebaMala3.dat
	./parser <pruebas/pruebaMala4.dat
	./parser <pruebas/pruebaMala5.dat
