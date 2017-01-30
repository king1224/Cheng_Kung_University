All: Clock.o lab3_B.cpp lab3_A.cpp
	g++ -o lab3_B lab3_B.cpp Clock.o
	g++ -o lab3_A lab3_A.cpp

Clock.o: Clock.cpp Clock.h
	g++ -c Clock.cpp

clean:
	rm *.o lab3_A lab3_B
	touch Clock.h
