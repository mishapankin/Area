TARGET = prog
EXPR_COMPILER = exprc

PROG_OBJECTS = obj/main.o obj/func.o obj/methods.o
COMPILER_OBJECTS = obj/exprc.o obj/expr_tree.o obj/make_asm.o obj/make_js.o

C_FLAGS = -Wall -m32 -c
ASM_FLAGS = -f elf32
LINK_FLAGS = -Wall -m32

all: $(TARGET) $(EXPR_COMPILER)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf obj/*
	rm -rf ./$(TARGET)
	rm -rf ./$(EXPR_COMPILER)

.PHONY: all clean run

$(TARGET): $(PROG_OBJECTS)
	gcc $(LINK_FLAGS) $(PROG_OBJECTS) -o $(TARGET)

$(EXPR_COMPILER): $(COMPILER_OBJECTS)
	gcc $(LINK_FLAGS) $(COMPILER_OBJECTS) -o $(EXPR_COMPILER)

obj/%.o: src/%.c
	gcc $(C_FLAGS) $< -o $@

obj/%.o: src/%.nasm
	nasm $(ASM_FLAGS) $< -o $@


src/main.c: src/func.h src/methods.h
src/methods.c: src/methods.h

src/exprc.c: src/expr_tree.h src/make_js.h src/make_asm.h
src/expr_tree.c: src/expr_tree.h
src/make_asm.c: src/make_asm.h src/expr_tree.h
src/make_js.c: src/make_js.h src/expr_tree.h