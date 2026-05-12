/*
    Dice Simulator
    ----------------------
    A simple yet robust C program that simulates rolling dice with different numbers of faces (6, 12, or 20).

    Author: [Sandra Martin Elias]
    Date: [2026/03/27]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int faces);
int getValidFaces();
char askRepeat();
int numberDice();

int main(){
    // Initialize random number generator
	srand(time(0));
	int faces, result, rolls=0, numDice;
	char repeat;
	
	while(1){
		int max_value=0, total=0;
		float average=0;
		
		faces=getValidFaces();
		numDice=numberDice();
        // Stores how many times each face appears
		int frequency[faces]={0};
		
		for (int i=0; i<numDice; i++) {
			result=rollDice(faces);
			printf("Obtained number in dice number %d is: %d\n", i+1, result);
			total+=result;
            // result-1 maps dice values (1-face) to array indices (0-face-1)
			frequency[result-1]++;
			
			if (result > max_value) {
				max_value=result;
			}
		}
		
		printf("--- Statistics for this roll ---\n");
		average=(float)total/numDice;
		rolls+=numDice;
		printf("Total number of dice rolled is: %d\n", rolls);
		printf("Maximum number obtained is: %d\n", max_value);
		printf("The sum of all the dice is: %d\n", total);
		printf("The average value obtained from all the dice is: %.2f\n", average);
		
		printf("--- Frequency ---\n");
		for(int i=0; i<faces; i++) {
			printf("Number %d has appeared %d times.\n", i+1, frequency[i]);
		}
		
		while(1){
			repeat=askRepeat();
			
			if (repeat=='y' || repeat=='Y') {
				break;
			} else if (repeat=='n' || repeat=='N') {
				return 0;
			} else {
				printf("Not a valid option.\n");
			}
		}
	}
}

int rollDice(int faces) {
	 return (rand() % faces +1);
}

int getValidFaces() {
	int faces, choice, options[]={6,12,20};
	
	while(1){
		printf("Select the number of faces of the dice:\n");
		printf("1- 6 faces\n");
		printf("2- 12 faces\n");
		printf("3- 20 faces\n");
		printf("Type 1, 2 or 3: ");
		
		if (scanf("%d", &choice)!=1) {
			printf("Invalid input.\n");
			while(getchar()!='\n');
			continue;
		}
			
		if(choice<1 || choice>3){
			printf("Not a valid option. Choose between the options given.\n");
			continue;
		}
		
		faces=options[choice-1];
		break;
	}
	
	return faces;
}

char askRepeat() {
	char repeat;
	
	printf("Do you want to continue throwing the dice? (y/n): ");
	scanf(" %c", &repeat);
	
	return repeat;
}

int numberDice(){
	int numDice;
	
	while (1) {
		printf("How many dice do you want to roll? ");
		
        // Validate integer input
		if(scanf("%d", &numDice)!=1) {
			printf("Invalid input.\n");
            // Remove invalid characters from input buffer
			while(getchar()!='\n');
			continue;
		}
		
		if (numDice<=0) {
			printf("Please enter a positive number.\n");
			continue;
		}
	
		break;
	}
	
	return numDice;
}