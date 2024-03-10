all: clean compile run

compile: main.cpp tetrominos.cpp tetrominos.h
	@echo "-------------------------------------------"
	@echo "Compiling.."
	@g++ -o test main.cpp tetrominos.cpp

run:
	@echo "-------------------------------------------"
	@echo "Running the tests.."
	@echo "============================================================="
	./test
	@echo "============================================================="
	@echo "Completed tests.."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test