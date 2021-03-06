CPPC = g++
CFLAGS = -W -Wall -Wshadow -pedantic -std=c++17
SRCS = fcts.cpp util.cpp methode.cpp main.cpp
RM = rm -f

OBJS = $(SRCS:.cpp=.o) # fichiers objets

# Complèter la première règle => pour l'exécutable

a.out : $(OBJS)
	$(CPPC) $(OBJS) $(CFLAGS)

fcts.o : fcts.cpp fcts.h
	$(CPPC) -c $(CFLAGS) $<

util.o : util.cpp util.h
	$(CPPC) -c $(CFLAGS) $<

methode.o : methode.cpp methode.h
	$(CPPC) -c $(CFLAGS) $<

main.o : main.cpp methode.h fcts.h util.h
	$(CPPC) -c $(CFLAGS) $<

run :
	./a.out

# Exemples de règles pour le ménage

clean :
	$(RM) $(OBJS) a.out *.txt *.pdf
