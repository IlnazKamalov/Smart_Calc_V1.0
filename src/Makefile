GCC_F = gcc -Wall -Werror -Wextra
LIB = s21_smart_calc.a
OS := $(shell uname -s)
Calc = $(wildcard Calc_main/*.c)
Calc_Files = $(patsubst %.c, %.o, $(Calc))
TEST_COMMAND = test
TESTS_DIR = $(wildcard test_Calc/*.c)

ifeq ($(OS),Linux)
	APP = build/Calculator
  	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(OS),Darwin)
	APP = build/Calculator
	OPEN_CMD = open
	ADD_LIB = -lcheck
endif

all: install

s21_smart_calc.a: clean $(Calc_Files)
	@ar rc $(LIB) $(Calc_Files)
	@ranlib $(LIB)

install: 
	@mkdir -p build
	@cd build/ && qmake ../Calculator.pro && make
	@mkdir -p $(HOME)/Desktop/SmartCalc/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc/
	@$(HOME)/Desktop/SmartCalc/Calculator

uninstall:
	@rm -rf build/
	@rm -rf $(HOME)/Desktop/SmartCalc/

test: clean $(LIB)
	@$(GCC_F) -o test $(TESTS_DIR) $(LIB) $(ADD_LIB)
	@./$(TEST_COMMAND)

gcov_report: clean $(LIB)
	@$(GCC_F) $(Calc) $(TESTS_DIR) $(ADD_LIB) $(LIB) -o $(TEST_COMMAND) --coverage
	@./$(TEST_COMMAND)
	@lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	$(OPEN_CMD) ./report/index.html

clean:
	@clear
	@rm -rf $(Calc_Files) 
	@rm -rf $(TEST_COMMAND)
	@rm -rf $(LIB)
	@rm -rf ./report
	@rm -rf *.gcno *.gcda *.gcov *.info *.txt *.o
	@rm -rf build*

style: clean
	clang-format -style=Google -n ./Calc_main/*.c  ./test_Calc/*.c
	clang-format -style=Google -n ./Calc_main/*.h  ./test_Calc/*.h

valgrind: $(LIB)
	@$(GCC_F) -g ${TESTS_DIR} $(LIB) -o $(TEST_COMMAND) $(ADD_LIB)
	valgrind --quiet --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose  ./$(TEST_COMMAND)

dvi: 
	open ../README_RUS.md
	  
dist:
	@mkdir -p $(HOME)/Desktop/dist
	@cp $(HOME)/Desktop/SmartCalc/Calculator $(HOME)/Desktop/dist
	@cd $(HOME)/Desktop/dist && tar cvzf  SmartCalc_v1.0.tgz *
	@cd $(HOME)/Desktop/dist && rm -rf  Calculator


.PHONY:	s21_smart_calc.a test clean style gcov_report valgrind all 
