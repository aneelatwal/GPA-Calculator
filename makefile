all:	gpa_calc

gpa_calc:	gpa_calc.o
	g++ -o gpa_calc gpa_calc.o

gpa_calc.o:	gpa_calc.cpp

clean:
	rm -f gpa_calc.o gpa_calc