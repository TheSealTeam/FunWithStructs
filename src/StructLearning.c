/*
 ============================================================================
 Name        : StructLearning.c
 Author      : Simon Olofsson
 Version     : 1.0
 Copyright   : -
 Description : Program to help give a better understanding of structs in C
 ============================================================================
 */

#include <stdio.h>	/*Included because of printf and puts*/
#include <stdlib.h> /*Included so we can use return EXIT_SUCCESS which is the same as return 0, could be removed*/
#include <string.h> /*Included because of strcpy*/

/*Struct def*/
typedef struct {
		int numberOfParts;
		char *Motherboard;
		char *GPU;
		char *CPU;
		char *SSD;
		char *RAM;
		char *CPU_FAN;
		char *Case;
}computer;

typedef struct {
	int playtime;
	int rating;
	char *datePlayed;
	char *difficulty;
}game;

/* function declaration */
int setGameAttributes(game *myGame);
/*End of function declaration*/

/*Functions*/
int setGameAttributes(game *myGame){
	myGame->playtime = 200;
	myGame->rating = 10;
	myGame->datePlayed = "Oct 28";
	myGame->difficulty = "easy";
	return 0;
}

/*main*/
int main() {
	int a = 5;
	printf("---------------------------------------------------------------\n");
	printf("a has the value of: %d\n", a); // Regular printf from stdio.h
	puts("Hello World!"); // Simpler version of printf, also from stdio.h

	char str[15]; // Create array of 15 elements
	strcpy(str, "Hello_World"); // Copies the string "HelloWorld" to the string str
	puts(str); //Print the stored string

	/*Playing around with structs*/
	// Allocate memory for the pointers themselves and other elements in the struct.
	computer *myComputer = malloc(sizeof(computer));
	printf("---------------------------------------------------------------\n");
	printf("sizeof(myComputer) = %d\n", (int)sizeof(computer));
	myComputer->numberOfParts = 7;
	myComputer->Motherboard = "MSI_Z87-G45_GAMING";
	myComputer->GPU = "GTX_760";
	myComputer->CPU = "i5-4670k";
	myComputer->SSD = "Samsung_SSD_840";
	myComputer->RAM = "8GB";
	myComputer->CPU_FAN = "Water_Cooled";
	myComputer->Case = "Fractal";
	printf("Number of computer parts are: %d\n", myComputer->numberOfParts);
	printf("My Motherboard is: %s\n", myComputer->Motherboard);
	printf("My GPU is: %s\n", myComputer->GPU);
	printf("My CPU is: %s\n", myComputer->CPU);
	printf("My SSD is: %s\n", myComputer->SSD);
	printf("My RAM is: %s\n", myComputer->RAM);
	printf("My CPU_FAN is: %s\n", myComputer->CPU_FAN);
	printf("My Case is: %s\n", myComputer->Case);
	printf("---------------------------------------------------------------\n");
	free(myComputer);

	//Create a game a set the member of the struct using refrence, aka calling the function with a pointer to the struct
	//When u create a pointer to a structure you need to allocate memory for it
	game *Witcher3 = malloc(sizeof(game));
	setGameAttributes(Witcher3);
	printf("The playtime of Witcher3 is: %d\n", Witcher3->playtime);
	printf("The rating of Witcher3 is: %d\n", Witcher3->rating);
	printf("The datePlayed of Witcher3 is: %s\n", Witcher3->datePlayed);
	printf("The difficulty of Witcher3 is: %s\n", Witcher3->difficulty);
	free(Witcher3);
	return 0;
}
