#ifndef BOARD_PLAIN_H
#define BOARD_PLAIN_H

#include "board_read.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveFigures(struct step_white* white_step, char board[][8]);
#endif