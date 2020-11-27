# An admittedly primitive Makefile
# To compile, type "make" or make "all"
# To remove files, type "make clean"

CC = g++
CFLAGS = -Wall
#change this according to your cpp file names
OBJS = main1.o Student.o StudentArray.o main2.o Polar.o main3.o DNode.o DoublyLinkedList.o main4.o Complex.o 

.SUFFIXES: .cpp .o

#change this according to your cpp file names
main1: main1.o Student.o StudentArray.o
	$(CC) $(CFLAGS) -o main1 main1.o Student.o StudentArray.o

main2: main2.o Polar.o
	$(CC) $(CFLAGS) -o main2 main2.o Polar.o

main3: main3.o DNode.o DoublyLinkedList.o
	$(CC) $(CFLAGS) -o main3 main3.o DNode.o DoublyLinkedList.o

main4: main4.o Complex.o
	$(CC) $(CFLAGS) -o main4 main4.o Complex.o

clean:
	-rm -f $(OBJS) main1 main2 main3 main4

#run make, then run ./main to run your code