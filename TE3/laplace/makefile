CPPC = g++
CFLAGS = -W -Wall -Wshadow -pedantic -std=c++17
SRCS = matrices.cpp io.cpp condlim.cpp main.cpp
RM = rm -f

OBJS = $(SRCS:.cpp=.o) # fichiers objets

# Complèter la première règle => pour l'exécutable

a.out : $(OBJS)
	$(CPPC) $(OBJS) $(CFLAGS)

matrices.o : matrices.cpp matrices.h
	$(CPPC) -c $(CFLAGS) $<

io.o : io.cpp io.h
	$(CPPC) -c $(CFLAGS) $<

condlim.o : condlim.cpp condlim.h
	$(CPPC) -c $(CFLAGS) $<

main.o : main.cpp condlim.h matrices.h io.h
	$(CPPC) -c $(CFLAGS) $<

run :
	./a.out

draw:
	python plot-laplace.py
    
# Exemples de règles pour le ménage

clean :
	$(RM) $(OBJS) a.out *.pdf *.dat
