#Aditya Badrinath
#EECS281
#Project 1

PATH := /usr/um/gcc-4.7.0/bin:$(PATH)
LD_LIBRARY_PATH := /usr/um/gcc-4.7.0/lib64
LD_RUN_PATH := /usr/um/gcc-4.7.0/lib64

all:
	g++ -g proj1.cpp build.cpp print.cpp stqu.cpp -o proj1
