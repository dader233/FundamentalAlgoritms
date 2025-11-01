all: main.out

main.out: main1.out functions.out
	gcc main1.out functions.out -o main.out 

functions.out: ./src/functions.c
	gcc ./src/functions.c -c -o functions.out 

main1.out: main.c
	gcc main.c -c -o main1.out