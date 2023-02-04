#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define FACTION_NUMBER 86

int main(void) {
    int player_number = 0;
    int picks = 0;
    int i, j;

    printf("How many players?\n");
    scanf("%i", &player_number);

    printf("How many picks per player?\n");
    scanf("%i", &picks);

    printf("You entered: %i players and %i picks\n", player_number, picks);

    srand(time(0));

    int draft_array[picks * player_number];

    for(i = 0; i < picks; i++)
        for(j = 0; j < player_number; j++){
            draft_array[indexFromCoords(i, j, picks)] = 0;
        }

    for(j = 0; j < player_number; j++){
        draft(picks, player_number, draft_array, j);
    }

    // Print the draft
    for(j = 0; j < player_number; j++) {
        printf("Player %i picks from:", j+1);
        for (i = 0; i < picks; i++) {
            printf(" %i", draft_array[indexFromCoords(i, j, picks)]);
        }
        printf("\n");
    }

    return 0;
}

void draft(int picks, int player_number, int* draft_array, int j){
    // Generates a draft for one player
    int i;
    int random_pick;
    for(i = 0; i < picks; i++) {
        random_pick = (rand() % FACTION_NUMBER) + 1;

        while(!pickUnique(random_pick, draft_array, picks, player_number)){
            random_pick = (rand() % FACTION_NUMBER) + 1;
        }
        draft_array[indexFromCoords(i, j, picks)] = random_pick;
    }
}

int pickUnique(int random_pick, int draft_array[], int picks, int player_number){
    for(int i = 0; i < picks; i++)
        for(int j = 0; j < player_number; j++){
        if(random_pick == draft_array[indexFromCoords(i, j, picks)]) return 0;
        }
    return 1;
}

int indexFromCoords(int i, int j, int picks){
    return j * picks + i;
}