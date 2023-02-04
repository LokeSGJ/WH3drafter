//
// Created by Loke on 04/02/2023.
//

#ifndef WH3DRAFTER_MAIN_H
#define WH3DRAFTER_MAIN_H

void draft(int picks, int player_number, int* draft_array, int j);
int pickUnique(int random_pick, int draft_array[], int picks, int player_number);
int indexFromCoords(int i, int j, int picks);

#endif //WH3DRAFTER_MAIN_H
