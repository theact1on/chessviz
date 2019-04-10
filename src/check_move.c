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

    if (figure->figure == 'R' || figure->figure == 'r') {
        if (from_liter == to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    if (from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else {
                while (1) {
                    from_digit++;
                    if (from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        } else if (from_digit == to_digit) {
            if (from_liter > to_liter) {
                while (1) {
                    from_liter--;
                    if (from_liter == to_liter)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else {
                while (1) {
                    from_liter++;
                    if (from_liter == to_liter)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        }
    }

    /*КОРОЛЬ*/
    if (figure->figure == 'K' || figure->figure == 'k') {
        if (abs(from_liter - to_liter) == 1
            && (abs(from_digit - to_digit) == 0
                || abs(from_digit - to_digit) == 1)) {
            return 1;
        } else if (
                abs(from_digit - to_digit) == 1
                && (abs(from_liter - to_liter) == 0
                    || abs(from_liter - to_liter) == 1)) {
            return 1;
        }
    }

    /*КОНЬ*/
    if (figure->figure == 'N' || figure->figure == 'n') {
        if (abs(from_digit - to_digit) == 1
            && abs(from_liter - to_liter) == 2) {
            return 1;
        }
        if (abs(from_liter - to_liter) == 1
            && abs(from_digit - to_digit) == 2) {
            return 1;
        }
    }

    return 0;
}