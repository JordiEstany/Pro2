OPCIONS = -DJUDGE -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-sign-compare -std=c++11

#
program.exe: program.o Mensaje.o Cjt_Mensajes.o Rejilla.o Cjt_Rejillas.o Patron.o Cjt_Patrones.o
	g++ -o program.exe program.o Mensaje.o Cjt_Mensajes.o Rejilla.o Cjt_Rejillas.o Patron.o Cjt_Patrones.o

#
Mensaje.o: Mensaje.cc Mensaje.hh
	g++ -c Mensaje.cc $(OPCIONS)

#
Cjt_Mensajes.o: Cjt_Mensajes.cc Cjt_Mensajes.hh
	g++ -c Cjt_Mensajes.cc $(OPCIONS)

#
Rejilla.o: Rejilla.cc Rejilla.hh
	g++ -c Rejilla.cc $(OPCIONS)

#
Cjt_Rejillas.o: Cjt_Rejillas.cc Cjt_Rejillas.hh
	g++ -c Cjt_Rejillas.cc $(OPCIONS)

#
Patron.o: Patron.cc Patron.hh
	g++ -c Patron.cc $(OPCIONS)

#
Cjt_Patrones.o: Cjt_Patrones.cc Cjt_Patrones.hh
	g++ -c Cjt_Patrones.cc $(OPCIONS)

#
program.o: program.cc Mensaje.hh Cjt_Mensajes.hh Rejilla.hh Cjt_Rejillas.hh Patron.hh Cjt_Patrones.hh
	g++ -c program.cc $(OPCIONS)

#
tar: Mensaje.cc Mensaje.hh Cjt_Mensajes.cc Cjt_Mensajes.hh Rejilla.cc Rejilla.hh Cjt_Rejillas.cc Cjt_Rejillas.hh Patron.cc Patron.hh Cjt_Patrones.cc Cjt_Patrones.hh program.cc Makefile html.zip jp_jordi.estany.zip
	tar cvf practica.tar program.cc Mensaje.hh Mensaje.cc Cjt_Mensajes.cc Cjt_Mensajes.hh Rejilla.cc Rejilla.hh Cjt_Rejillas.cc Cjt_Rejillas.hh Patron.cc Patron.hh Cjt_Patrones.cc Cjt_Patrones.hh Makefile html.zip jp_jordi.estany.zip

#
clean:
	rm -f *.o
	rm -f *.exe
