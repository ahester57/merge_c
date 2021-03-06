OBJECTS = run.o merge.o bubble.o mkrand.o handler.o
HEADERS = merge.h bubble.h mkrand.h handler.h
FLAGS = -std=c99 -lm

default: all 

%.o: %.c $(HEADERS)
	gcc -c $< $(FLAGS) -o $@

all: $(OBJECTS)
	-make merge

merge: $(OBJECTS) 
	gcc $(OBJECTS) $(FLAGS) -o $@ 
	-make bubble

bubble: $(OBJECTS)
	gcc $(OBJECTS) $(FLAGS) -o $@
	-rm -f $(OBJECTS)

clean:
	-rm -f $(OBJECTS)
	-rm -f merge bubble
	-rm -f _sortedArray.log _randomArray.rnd
