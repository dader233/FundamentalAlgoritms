all: main.out

main.out: main1.out functions.out
	gcc main1.out functions.out -g -o main.out -lm

functions.out: functions.c
	gcc functions.c -g -c -o functions.out

main1.out: main.c
	gcc main.c -g -c -o main1.out -lm