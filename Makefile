COMPILER = g++
OPTIONS = -std=c++11 -Wall
PROGRAM = main.out


all: $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


$(PROGRAM): main.cpp Quiz.cpp printResult.cpp 
	$(COMPILER) $(OPTIONS) main.cpp Quiz.cpp printResult.cpp -o $(PROGRAM)

clean:
	rm *.out