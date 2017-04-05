all: dracak

OBJ=main.o quest1.o

clean:
	$(RM) $(OBJ) dracak

dracak: $(OBJ)
	$(CC) -o $@ $^

quest1.o: quest1.c hrdina.h
main.o: main.c hrdina.h
