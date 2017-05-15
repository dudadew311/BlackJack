//  Created by:		Raul Diaz
//  Created on:		11/25/15
//	Descriptin:		BlackJack

#define _CRT_SECURE_NO_WARNINGS
#ifdef _WIN32
#include <windows.h>
#define PAUSE system("pause")
#define CLEAR system("cls")
#define FLUSH fflush(stdin)
#else
#include <unistd.h>
#define PAUSE printf("Pause Would go Here\n")
#define CLEAR printf("Clear Happens here\n")
#define FLUSH fpurge(stdin)
#endif
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void shuff(int []);
int convert(int);
void pic(int num);
int play();


void shuff(int cards[]){
	int t;
	int i;
	int desk[52] = {0};
	for (i = 0; i < 52; i++)
		desk[i] = (i / 13 + 3) * 100 + i % 13 + 1;
	
	srand((unsigned)time(NULL));
	for (i = 0; i < 52; i++){
		do {
			t = rand() % 52;
		} while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	} //end for
} //end shuff

int convert(int a){
	if ((a % 100 == 11) || (a % 100 == 12) || (a % 100 == 13))
		return (a / 100) * 100 + 10;
	else
		return a;
} //end convert

void pic(int num){
	char fl;
	int cardNum;
	
	fl = num / 100;
	cardNum = num % 100;
	switch (cardNum){
		case 1:{
			printf("******\n");
			printf("* %c   *\n", fl);
			printf("*  A *\n");
			printf("*    *\n");
			printf("******\n");
			break;
		}
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:{
			printf("******\n");
			printf("* %c   *\n", fl);
			printf("* %2d *\n", cardNum);
			printf("*    *\n");
			printf("******\n");
			break;
		}
		case 11:{
			printf("******\n");
			printf("* %c   *\n", fl);
			printf("*  J *\n");
			printf("*    *\n");
			printf("******\n");
			break;
		}
		case 12:{
			printf("******\n");
			printf("* %c   *\n", fl);
			printf("*  Q *\n");
			printf("*    *\n");
			printf("******\n");
			break;
		}
		case 13:{
			printf("******\n");
			printf("* %c   *\n", fl);
			printf("*  K *\n");
			printf("*    *\n");
			printf("******\n");
			break;
		}
	} //end switch
} //end pic

int play() {
	int i;
	int playerSum = 0;
	int dealerSum = 0;
	int playerCards[5] = {0};
	int dealerCards[5] = {0};
	int cards[52];
	//char choice;
	int aChoice;
	
	//shuff the cards
	shuff(cards);
	
	//give the cards
	playerCards[0] = cards[0];
	playerCards[1] = cards[1];
	dealerCards[0] = cards[2];
	dealerCards[1] = cards[3];
	
	//the 2 cards player get
	printf("One of computer's cards:\n");
	pic(dealerCards[0]);
	printf("\n");
	printf("Cards of player:\n");
	pic(playerCards[0]);
	pic(playerCards[1]);
	
	i = 0;
	for (i = 0; i < 2; i++){
		if (playerCards[i] % 100 == 1){
			printf("choose A value of the card %d, input 11 or 1 : ", i+1);
			do{
				scanf("%i", &aChoice); FLUSH;
				switch (aChoice) {
					case 1:
						break;
					case 11:
						break;
					default:
						printf("\tNot a valid Choice, Pick again!!\n");
						break;
				} //end switch
			} while (aChoice != 1 && aChoice != 11);
			
			if (aChoice == 11){
				printf("You've chosen value 11 for card A.\n");
				playerSum = playerSum + 11;
			} else if (aChoice == 1){
				printf("You've chosen value 1 for card A.\n");
				playerSum = playerSum +1;
			}//end if/else
		} else if (convert(playerCards[i]) % 100 == 10)
			playerSum = playerSum + 10;
		else
			playerSum = playerSum + playerCards[i] % 100;
		//end if/else
		if (playerSum > 21) {
			printf("Sum of player's cards now:%d\n\n",playerSum);
			printf("Computer win!\n");
			return 1;
		} else if (playerSum == 21){
			printf("Sum of player's cards now:%d\n\n",playerSum);
			printf("Player win!\n");
			return 1;
		} //end if/else
	}
	printf("Sum of player's cards now:%d\n\n",playerSum);
	
	//whether player get another cards
	for (i = 0; i < 3; i++) {
		char choice = 'n';
		
		do {
			printf("Want more cards? Input y or n: ");
			scanf("%c", &choice); FLUSH;
			tolower(choice);
			if (choice != 'y' && choice != 'n')
				printf("\tNot a valid Choice, Pick again!!\n");
		} while (choice != 'y' && choice != 'n');
		
		if (choice == 'y'){
			printf("You've got another card now.\n");
			playerCards[i+2] = cards[i+4];
			printf("and your card %d is:\n", i+3);
			pic(playerCards[i+2]);
			
			if (playerCards[i+2] % 100 == 1){
				
				do {
					printf("Choose A value of the card %d, input 'y' for 11 or 'n' for 1: ", i+3);
					scanf("%c", &choice); FLUSH;
					tolower(choice);
					if (choice != 'y' || choice != 'n')
						printf("\tNot a valid Choice, Pick again!!\n");
				} while (choice!='y' && choice!='n');
				if (choice == 'y'){
					printf("You've chosen value 11 for card A.\n");
					playerSum = playerSum + 11;
				} else if (choice == 'n') {
					printf("You've chosen value 1 for card A.\n");
					playerSum = playerSum +1;
				}//end if/else
			} else if (convert(playerCards[i+2]) %100 ==10)
				playerSum = playerSum + 10;
			else
				playerSum = playerSum + playerCards[i+2] % 100;
			
			if (playerSum > 21){
				printf("Sum of player's cards now: %i\n\n", playerSum);
				printf("Computer win!\n");
				return 0;
			} else if (playerSum == 21) {
				printf("Sum of player's cards now: %i\n\n", playerSum);
				printf("Player win!\n");
				return 1;
			} else//end if/else
				printf("Sum of player's cards now: %i\n\n", playerSum);
		} else {
			printf("Sum of player's cards now: %i\n\n", playerSum);
			break;
		}//end if/else
	}
	if (i == 3) {
		printf("Player win! Because the sum of your 5 cards is no larger than 21! So lucky!\n");
		return 0;
	} //end iif
	
	//the 2 cards of computer
	printf("Computer's cards:\n");
	pic(dealerCards[0]);
	pic(dealerCards[1]);
	
	if (dealerCards[0] % 100 + dealerCards[1] % 100 == 2) {
		dealerSum = 12; //two A cards
		printf("Sum of computer's cards now: %i\n\n", dealerSum);
	} else if ((convert(dealerCards[0])) % 100 + (convert(dealerCards[1])) % 100 == 1){
		dealerSum = 21;
		printf("Sum of computer's cards now: %i\n\n", dealerSum);
		printf("Computer win!\n");
		return 0;
	} else if (dealerCards[0] % 100==1 || dealerCards[1] % 100 == 1) {
		dealerSum = (dealerCards[0]+dealerCards[1]) % 100 + (rand() % 2) * 10;
		printf("Sum of computer's cards now: %i\n\n", dealerSum);
	} else {
		dealerSum = (convert(dealerCards[0])) % 100 + (convert(dealerCards[1])) % 100;
		printf("Sum of computer's cards now: %i\n\n", dealerSum);
	}//end if/else
	
	//whether computer get another cards until dealerSum>16
	for (i = 0; i < 3 && dealerSum < 17; i++) {
		dealerCards[i+2] = cards[i+7];
		printf("Computer's card %i is: \n", i+3);
		pic(dealerCards[i+2]);
		
		if (dealerCards[i+2] % 100 == 1){
			if (dealerSum+11 <= 21){
				printf("Computer has chosen A as 11\n");
				dealerSum = dealerSum+11;
				printf("Sum of computer's cards now: %i\n\n", dealerSum);
			} else {
				printf("Computer has chosen A as 1\n");
				dealerSum = dealerSum+1;
				printf("Sum of computer's cards now: %i\n\n", dealerSum);
			}//end if/else
		} else {
			dealerSum = dealerSum + convert(dealerCards[i+2])%100;
			printf("Sum of computer's cards now: %i\n\n", dealerSum);
		} //end if/else
	}
	if (i == 3) {
		printf("Computer win! Because the sum of its 5 cards is no larger than 21! So lucky!\n");
		return 0;
	}
	
	//the last step
	if (dealerSum>21 || playerSum>dealerSum) {
		printf("Player win!\n");
		return 1;
	} else if (playerSum == dealerSum) {
		printf("Oh, player and computer get the same score!\n");
		return 3;
	} else if (playerSum < dealerSum) {
		printf("Computer win!\n");
		return 0;
	}//end if/else
	return 3;
} //end play

