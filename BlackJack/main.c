//Written by...: Alejandra Valencia && Raul Diaz
//Date written.: Novemeber 28, 2015
//Purpose......: Exam 4 - BlackJack !!!

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
#include <stdlib.h>
#include "gui.h"
#include "menuOperations.h"
#include "game.h"

void welcomeScreen();

int main() {
	int choice = 0, i, flag = 0;
	FILE *scores;
	PLAYER user[10];
	PLAYER** playerArray;
	int bet;
	
	playerArray = calloc(10, sizeof(PLAYER*));
	
	for (i =0; i < SIZE; i++) {
		playerArray[i] = calloc(1, sizeof(PLAYER));
	}
	blackjack();
	welcomeScreen();
	
	scores = fopen("scores.bin", "rb");
	if (scores == NULL){
		scores = fopen("scores.bin", "wb");
		
		for (i = 0; i < SIZE; i++) {
			playerArray[i]->bank = 0;
			playerArray[i]->wins = 0;
			playerArray[i]->loses = 0;
			playerArray[i]->streak = 0;
			playerArray[i]->gamesPlayed = 0;
			strcpy(playerArray[i]->name, "name");
		}
		fwrite(user, sizeof(PLAYER), 10, scores);
	

	} else
			fread(user, sizeof(PLAYER), 10, scores);
	
	fclose(scores);
	for (i = 0; i < SIZE; i++) {
		playerArray[i]->bank = user[i].bank;
		playerArray[i]->gamesPlayed = user[i].gamesPlayed;
		playerArray[i]->loses = user[i].loses;
		playerArray[i]->wins = user[i].wins;
		playerArray[i]->streak = user[i].streak;
		strcpy(playerArray[i]->name, user[i].name);
	}

	//getScores(playerArray);
	playerSelect(playerArray);
	do{
		
		choice = getChoice(playerArray);
		switch (choice){
			case 1: //Play BlackJack
				
				printf("What is your Bet %s? ", playerArray[0]->name);
				scanf("%i", &bet); FLUSH;
				
				PAUSE;
				CLEAR;
				do {
					if (bet > playerArray[0]->bank){
						printf("Not enough money in the Bank!!\n");
					}
				} while (bet > playerArray[0]->bank);
				flag = play();
				switch (flag) {
					case 0:
						playerArray[0]->bank = playerArray[0]->bank - bet;
						playerArray[0]->loses = (playerArray[0]->loses + 1);
						if (playerArray[0]->streak > 0){
							playerArray[0]->streak = -1;
						} else {
							playerArray[0]->streak = playerArray[0]->streak - 1;
						}
						break;
					case 1:
						playerArray[0]->bank = playerArray[0]->bank + bet;
						playerArray[0]->wins = (playerArray[0]->wins + 1);
						if (playerArray[0]->streak < 0){
							playerArray[0]->streak = 1;
						} else {
							playerArray[0]->streak = playerArray[0]->streak + 1;
						}
						break;
					case 3:
						printf("Its a TIE!!\n");
						break;
				}
				PAUSE;
				playerArray[0]->gamesPlayed = playerArray[0]->gamesPlayed + 1;

				break;
			case 2: //Display Top 10
				CLEAR;
				showScores(playerArray);
				break;
			case 3:
				//change user
				playerSelect(playerArray);
				break;
			case 4: //Quit Message
				CLEAR;
				printf("\n\tTHANK YOU FOR PLAYING BLACKJACK !!! UNTIL NEXT TIME.\n\n");
				saveScores(playerArray);
				break;
			default:
				printf("INVALID SELECTION !!! PLEASE TRY AGAIN.\n\n");
				break;
		}// End switch
	} while (choice != 4);
	PAUSE;
	return 0;
}//End main
