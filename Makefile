COMPILER = gcc
FLAGS = -std=gnu11 -Wall -Werror

.PHONY: clean start all

all:bin/main

-include build/*.d

bin/main: build/main.o build/board_print_html.o build/board_read.o build/board_plain.o build/check_move.o
	$(COMPILER) $(FLAGS) -o $@ $^ #Список всех зависимостей обрабатываемого правила

build/main.o: src/main.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/board_print_html.o: src/board_print_html.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/board_read.o: src/board_read.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/board_plain.o: src/board_plain.c
	$(COMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/check_move.o: src/check_move.c
	$(COMPILER)  $(FLAGS) -MMD -c -o $@ $<

start: bin/main
	bin/main

clean:
	rm build/*