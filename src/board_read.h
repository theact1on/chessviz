#ifndef BOARD_READ_H
#define BOARD_READ_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct step_white {
    char num[5];
    char figure;
    char from[3];
    char to[3];
    char how;
    char shah_mat;
};

void checkSteps(char* txt, char board[][8]);
void errorHandler(int Error, struct step_white* move);
#endif