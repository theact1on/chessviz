COMPILER = gcc
FLAGS = -std=gnu11 -Wall -Werror

.PHONY: clean start all

all: bin/main

test: bin/main-test

-include build/src/*.d

bin/main: build/src/main.o build/src/board_print_html.o build/src/board_read.o build/src/board_plain.o build/src/check_move.o
	$(COMPILER) $(FLAGS) -o $@ $^ #Список всех зависимостей обрабатываемого правила

build/src/main.o: src/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/src/board_print_html.o: src/board_print_html.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/src/board_read.o: src/board_read.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/src/board_plain.o: src/board_plain.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/src/check_move.o: src/check_move.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила




-include build/test/*.d

bin/main-test: build/test/main.o build/test/check_move.o build/test/tests.o
	$(COMPILER) $(FLAGS) -o $@ $^

build/test/main.o: test/main.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

build/test/tests.o: test/tests.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

build/test/check_move.o: src/check_move.c
	$(COMPILER) -I thirdparty -I src $(FLAGS) -MMD -c -o $@ $<

start: bin/main
	bin/main

clean:
	rm -rf build/src/*.o build/src/*.d build/test/*.o built/test/*.d *.html