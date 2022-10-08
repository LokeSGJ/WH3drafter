#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int draft(int picks, int player){
    // Generates a draft for one player
    int i = 0;
    int draft_array[picks];
    while(i < picks) {
        draft_array[i] = rand() % 86 + 1;
        i++;
    }

    // Prints the draft
    printf("Player %i chooses from: ", player);
    i = 0;
    while(i < picks) {
        printf("%i ", draft_array[i]);
        i++;
    }
    printf("\n");

    return draft_array[0];
}

int main(void) {
    int player_number = 0;

    printf("How many players?\n");
    scanf("%i", &player_number);

    int picks = 0;

    printf("How many picks per player?\n");
    scanf("%i", &picks);

    printf("You entered: %i players and %i picks\n", player_number, picks);

    srand(time(0));


    int i = 1;
    while(i < player_number+1){
        draft(picks, i);
        i++;
    }

    return 0;
}