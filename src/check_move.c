#include "check_move.h"
#include "board_read.h"

int checkMove(struct step_white* figure, char board[][8])
{
    int from_liter = (int)figure->from[0] - 97;
    int from_digit = 8 - ((int)figure->from[1] - 48) % 9;
    int to_liter = (int)figure->to[0] - 97;
    int to_digit = 8 - ((int)figure->to[1] - 48) % 9;

    if (from_liter == to_liter && from_digit == to_digit) {
        return 0;
    }
    if (figure->figure != board[from_digit][from_liter]) {
        return 3;
    }
    if ((int)board[to_digit][to_liter] == ' ' && figure->how == 'x') {
        return 4;
    }
    if ((int)board[to_digit][to_liter] != ' ' && figure->how == '-') {
        return 5;
    }
    if ((int)board[to_digit][to_liter] >= 97
        && (int)board[to_digit][to_liter] <= 122 && (int)figure->figure >= 97
        && (int)figure->figure <= 122) {
        return 6;
    }
    if ((int)board[to_digit][to_liter] >= 65
        && (int)board[to_digit][to_liter] <= 90 && (int)figure->figure >= 65
        && (int)figure->figure <= 90) {
        return 6;
    }
    return 0;
}