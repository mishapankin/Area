TARGET = bin/prog
EXPR_COMPILER = bin/exprc

PROG_OBJECTS = obj/main.o obj/func.o obj/methods.o
COMPILER_OBJECTS = obj/exprc.o obj/expr_tree.o obj/make_asm.o obj/make_js.o

C_FLAGS = -std=c99 -Wall -m32 -c
ASM_FLAGS = -f elf32
LINK_FLAGS = -Wall -m32 -lm

all: $(TARGET) $(EXPR_COMPILER)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf obj/*
	rm -rf bin/*
	rm -rf ./$(TARGET)
	rm -rf ./$(EXPR_COMPILER)

.PHONY: all clean run

$(TARGET): $(PROG_OBJECTS)
	gcc $(PROG_OBJECTS) -o $@ $(LINK_FLAGS)

$(EXPR_COMPILER): $(COMPILER_OBJECTS)
	gcc $(COMPILER_OBJECTS) -o $@ $(LINK_FLAGS)

obj/%.o: src/%.c
	gcc $(C_FLAGS) $< -o $@

obj/%.o: src/%.nasm
	nasm $(ASM_FLAGS) $< -o $@

src/%.nasm: src/%.expr $(EXPR_COMPILER)
	./$(EXPR_COMPILER) $< $@

src/main.c: src/func.h src/methods.h
src/methods.c: src/methods.h src/constants.h

src/exprc.c: src/expr_tree.h src/make_js.h src/make_asm.h
src/expr_tree.c: src/expr_tree.h
src/make_asm.c: src/make_asm.h src/expr_tree.h src/constants.h
src/make_js.c: src/make_js.h src/expr_tree.h