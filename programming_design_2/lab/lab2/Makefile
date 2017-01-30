lab2:lab2.o BMI.o
	g++ -o lab2 lab2.o BMI.o
    
lab2.o:lab2.cpp BMI.h
	g++ -c lab2.cpp
    
BMI.o:BMI.cpp BMI.h
	g++ -c BMI.cpp
    
clean:
	rm BMI *.o
