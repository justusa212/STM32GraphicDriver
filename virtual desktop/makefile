BUILDPATH="./build"
CFLAGS= -Wall -pedantic -std=gnu99 -g

all: babydriver kuromi fonts testme

babydriver: babydriver.c
	gcc -c $(CFLAGS) babydriver.c -o $(BUILDPATH)/babydriver.o

kuromi: kuromi.c
	gcc -c $(CFLAGS) kuromi.c -o $(BUILDPATH)/kuromi.o

fonts: fonts.c
	gcc -c $(CFLAGS) fonts.c -o $(BUILDPATH)/fonts.o

testme: testme.c
	gcc $(CFLAGS) testme.c $(BUILDPATH)/fonts.o $(BUILDPATH)/babydriver.o $(BUILDPATH)/kuromi.o -o $(BUILDPATH)/testme
