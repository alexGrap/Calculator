all: build

rebuild: clean all

clean:
	rm -rf ../build/graph

memcheck:
	leaks -atExit -- ../build/graph 

build:
	gcc -Wall -Werror -Wextra -o ../build/graph graph.c decoding.c calculate.c

check:
	python3 ../materials/linters/cpplint.py --extensions=c *
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem ../src/*.c ../src/*.h Makefile