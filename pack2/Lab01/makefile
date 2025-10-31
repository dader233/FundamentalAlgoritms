all: main.out

main.out: main1.out func.out
	gcc main1.out func.out -o main.out -lm

func.out: ./src/func.c
	gcc ./src/func.c -c -o func.out -lm

main1.out: main.c
	gcc main.c -c -o main1.out