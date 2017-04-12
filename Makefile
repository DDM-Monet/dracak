all: dracak

OBJ=main.o quest1.o questDaniel.o

clean:
	$(RM) $(OBJ) dracak

dracak: $(OBJ)
	$(CC) -o $@ $^

questDaniel.o: questDaniel.c hrdina.h
quest1.o: quest1.c hrdina.h
main.o: main.c hrdina.h
