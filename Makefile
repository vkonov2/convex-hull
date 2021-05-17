FLAGS = -Wunused -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual

all: a.out

a.out: functions.o class_point.o hull.o 
	g++ functions.o class_point.o hull.o -o a.out

functions.o: functions.cpp functions.h class_point.h
	g++ -c $(FLAGS) functions.cpp

class_point.o: class_point.cpp class_point.h
	g++ -c $(FLAGS) class_point.cpp

hull.o: hull.cpp
	g++ -c $(FLAGS) hull.cpp

clean:
	rm -rf *.0 a.out
