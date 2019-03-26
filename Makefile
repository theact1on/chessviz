COPMPILER = g++
FLAGS = -std=c++11 -Wall -Werror

.PHONY: clean start all

all:bin/main

-include build/*.d

bin/main: build/main.o build/board_print_html.o build/board.o
	$(COPMPILER) $(FLAGS) -o $@ $^ #Список всех зависимостей обрабатываемого правила

build/main.o: src/main.cpp
	$(COPMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/board_print_html.o: src/board_print_html.cpp
	$(COPMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

build/board.o: src/board.cpp
	$(COPMPILER) $(FLAGS) -MMD -c -o $@ $< # Имя цели | Имя первой зависимости обрабатываемого правила

start: bin/main
	bin/main

clean:
	rm build/*