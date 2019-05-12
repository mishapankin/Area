TARGET = prog
PROG_OBJECTS = obj/main.o obj/func.o obj/methods.o

C_FLAGS = -Wall -c
ASM_FLAGS = -f elf32
LINK_FLAGS = -Wall

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf obj/*
	rm -rf ./$(TARGET)

.PHONY: all clean run

$(TARGET): $(PROG_OBJECTS)
	gcc $(LINK_FLAGS) $(PROG_OBJECTS) -o $(TARGET)

obj/%.o: src/%.c
	gcc $(C_FLAGS) $< -o $@ 

methods.c: methods.h
func.c: func.h
