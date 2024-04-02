a.out: Question.o QuizDriver.o
	g++ Question.o QuizDriver.o

Question.o: Question.cpp Question.h
	g++ -c Question.cpp

QuizDriver.o: QuizDriver.cpp Question.h
	g++ -c QuizDriver.cpp
