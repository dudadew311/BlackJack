

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

//void displayMenu(PLAYER**);
void welcomeScreen();

void blackjack(){
	CLEAR;
	printf("\n\n");
	printf("\tXXXXXXXX   XXX             XXX       XXXXXXXX  XX     XX          \n");
	printf("\tXX     XX  XXX           XX   XX     XX        XX   XX           \n");
	printf("\tXX     XX  XXX          XX     XX    XX        XX XX             \n");
	printf("\tXXXXXXXX   XXX          XXXXXXXXX    XX        XX X              \n");
	printf("\tXX    XX   XXX         XXXXXXXXXXX   XX        XX X              \n");
	printf("\tXX     XX  XXX         XX       XX   XX        XX  XX            \n");
	printf("\tXX     XX  XXX        XX         XX  XX        XX    XX          \n");
	printf("\tXXXXXXXX   XXXXXXXXX XX           XX XXXXXXXX  XX      XX      \n\n");
 
	printf("\t      XXXXXXXXXXXXX     XXXX        XXXXXXXX     XX     XX          \n");
	printf("\t           XXXX        XX  XX       XX           XX    XX           \n");
	printf("\t           XXXX       XX    XX      XX           XX  XX             \n");
	printf("\t           XXXX       XXXXXXXXX     XX           XX XX              \n");
	printf("\t           XXXX      XXXXXXXXXXX    XX           XX XX              \n");
	printf("\t           XXXX      XX       XX    XX           XX   XX            \n");
	printf("\t       XX  XXXX     XX         XX   XX           XX     XX          \n");
	printf("\t        XXXXXX      XX         XX   XXXXXXXX     XX       XX      \n\n");
	printf("\n");
	PAUSE;
}//End function blackjack

void welcomeScreen(){
	CLEAR;
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n $        $  $$$$$$$  $      $$$$$$$  $$$$$$$$$  $$$   $$$  $$$$$$$   \n");
	printf(" $        $  $        $      $        $       $  $  $ $  $  $         \n");
	printf(" $        $  $$$$$$$  $      $        $  $$$  $  $  $ $  $  $$$$$$$    \n");
	printf(" $  $$$   $  $        $      $        $  $$$  $  $  $$$  $  $         \n");
	printf(" $  $  $  $  $        $      $	      $       $  $       $  $         \n");
	printf(" $$$$  $$$$  $$$$$$$  $$$$$$ $$$$$$$  $$$$$$$$$  $       $  $$$$$$$  \n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
	printf("\n\n");
	printf("\t\t\tRULES OF THE GAME:\n");
	printf("---------------------------------------------------------------------\n");
	printf("1.Blackjack may be played with a 52-card decks.\n");
	printf("2.Aces may be counted as 1 or 11 points, 2 to 9 according to pip value\n");
	printf("and tens and face cards count as ten points.\n");
	printf("3.The value of a hand is the sum of the point values of the individual\n");
	printf("cards. Except, a 'blackjack' is the highest hand, consisting of an ace\n");
	printf("and any 10-point card, and it outranks all other 21-point hands.\n");
	printf("4.If the dealer goes over 21 points, then any player who didn't already bust will win.\n");
	PAUSE;
}//End function welcomeScreen



void drawCard(char card){
	printf("-------\n");
	printf("|      |\n");
	printf("|  %c   |\n", card);
	printf("|      |\n");
	printf("-------\n");
} //End drawCard

