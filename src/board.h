#ifndef BOARD_H
#define BOARD_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct step_white {
    char num[5] = "";
    char figure = 'P';
    char from[3] = "";
    char to[3] = "";
    char how = ' ';
    char shah_mat = ' ';
    void clean()
    {
        figure = 'P';
        from[0] = (char)0;
        from[1] = (char)0;
        from[2] = (char)0;
        to[0] = (char)0;
        to[1] = (char)0;
        to[2] = (char)0;
        how = (char)0;
        shah_mat = (char)0;
    }
};

void checkSteps(char* txt, char board[][8]);
void moveFigures(step_white* white_step, char board[][8]);
#endif