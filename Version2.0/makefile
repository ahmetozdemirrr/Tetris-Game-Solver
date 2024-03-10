all: compile run clean

compile: main.cpp tetrominos.h tetris.h tetris.cpp tetrominos.cpp 
	@echo "-------------------------------------------"
	@echo "Compiling.."
	@g++ main.cpp tetris.cpp tetrominos.cpp -o a.out

run:
	@echo "-------------------------------------------"
	@echo "Running the tests.."
	@echo "============================================================="
	./a.out
	@echo "============================================================="
	@echo "Completed tests.."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
