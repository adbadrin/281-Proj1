#Aditya Badrinath
#EECS281
#Project 1

PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

all:
	g++ -O3 proj1.cpp build.cpp print.cpp stqu.cpp -o proj1

clean:
	rm *.o proj1

old:
	g++ -O3 proj1o.cpp build.cpp print.cpp stquo.cpp -o proj1o

bigTest:
	g++ coordinateTest.cpp build.cpp -o builder
