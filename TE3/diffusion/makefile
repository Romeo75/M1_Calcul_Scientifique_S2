CPPC = g++
CFLAGS = -W -Wall -Wshadow -pedantic -std=c++17
SRCS = matrices.cpp util.cpp methodes.cpp cond_init.cpp main.cpp
RM = rm -f

OBJS = $(SRCS:.cpp=.o) # fichiers objets

# Complèter la première règle => pour l'exécutable

a.out : $(OBJS)
	$(CPPC) $(OBJS) $(CFLAGS)

matrices.o : matrices.cpp matrices.h
	$(CPPC) -c $(CFLAGS) $<

util.o : util.cpp util.h
	$(CPPC) -c $(CFLAGS) $<

cond_init.o : cond_init.cpp cond_init.h
	$(CPPC) -c $(CFLAGS) $<

methodes.o : methodes.cpp methodes.h matrices.h
	$(CPPC) -c $(CFLAGS) $<

main.o : main.cpp cond_init.h matrices.h util.h methodes.h
	$(CPPC) -c $(CFLAGS) $<

run :
	./a.out

draw:
	python plot-diff.py
    
# Exemples de règles pour le ménage

clean :
	$(RM) $(OBJS) a.out *.pdf *.dat
