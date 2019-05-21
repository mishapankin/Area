TARGET = bin/prog
EXPR_COMPILER = bin/exprc
JS_LOC = html/expr.js

PROG_OBJECTS = obj/main.o obj/func.o obj/methods.o obj/parse_args.o obj/test_funcs.o
COMPILER_OBJECTS = obj/exprc.o obj/expr_tree.o obj/make_asm.o obj/make_js.o

C_FLAGS = -std=c99 -Wall -m32 -c
ASM_FLAGS = -f elf32
LINK_FLAGS = -Wall -m32 -lm


all: $(TARGET) $(EXPR_COMPILER)

run: $(TARGET)
	./$(TARGET) --human

clean:
	find bin/ -name "*" -type f | grep -v "bin/.gitkeep" | xargs rm -f
	find obj/ -name "*" -type f | grep -v "obj/.gitkeep" | xargs rm -f

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
	./$(EXPR_COMPILER) $< $@ $(JS_LOC)

src/main.o: src/func.h src/methods.h src/parse_args.h src/test_funcs.h
src/func.o: src/func.h
src/methods.o: src/methods.h
src/parse_args.o: src/parse_args.h
src/test_funcs.o: src/test_funcs.h

src/exprc.o: src/expr_tree.h src/make_js.h src/make_asm.h
src/expr_tree.o: src/expr_tree.h
src/make_asm.o: src/make_asm.h src/expr_tree.h src/constants.h
src/make_js.o: src/make_js.h src/expr_tree.h