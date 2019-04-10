#include "board_read.h"
#include "board_plain.h"
#include "board_print_html.h"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void checkSteps(char* txt, char board[][8])
{
    printf("\n");
    FILE* input_file;
    input_file = fopen(txt, "a+");
    if (input_file == NULL) {
        printf("Cannot open file\n ERROR #1");
    }
    rewind(input_file);
    while (!feof(input_file)) {
        struct step_white sw_def = {"", 'P', "", "", ' ', ' '};
        char target = fgetc(input_file);
        struct step_white white = sw_def;
        int pars = 1;
        while (target != ' ') {
            if (!isdigit(target) && target != '.') {
                printf(ANSI_COLOR_RED
                       "ERROR. Was exepted digit -> "
                       "found - %c\n" ANSI_COLOR_RESET,
                       target);
                exit(1);
            }
            if (target == '.') {
                target = fgetc(input_file);
                continue;
            }
            char bufer_temp[2] = {target, '\0'};
            strcat(white.num, bufer_temp);
            target = fgetc(input_file);
        }
        strcpy(sw_def.num, white.num);
        target = fgetc(input_file);
        int its_black = 0;
        while (1) {
            if (target == ' ' || target == '\n' || target == EOF) {
                if (target == '\n' || target == EOF) {
                    moveFigures(&white, board);
                    white = sw_def;
                    its_black = 0;
                    printf(ANSI_COLOR_GREEN
                           "SUCCESS. Line %s.\n" ANSI_COLOR_RESET,
                           white.num);
                    break;
                }
                moveFigures(&white, board);
                white = sw_def;
                pars = 1;
                target = fgetc(input_file);
            }
            if (pars == 1) {
                if (target == 'K' || target == 'Q' || target == 'R'
                    || target == 'B' || target == 'N'
                    || ((int)target >= 94 && (int)target <= 122)) {
                    if ((int)target < 94 || (int)target > 122) {
                        if (its_black) {
                            white.figure = (char)(target + 32);
                            target = fgetc(input_file);
                        } else {
                            white.figure = target;
                            target = fgetc(input_file);
                        }
                    } else {
                        if (its_black) {
                            white.figure = 'p';
                        }
                    }
                    its_black = !its_black;
                    pars++;
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [K|Q|R|N|B| ] -> "
                           "found - %c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 2) {
                if ((int)target >= 97 && (int)target <= 104) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.from, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [a-h] -> found - "
                           "%c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 3) {
                if ((int)target >= 49 && (int)target <= 56) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.from, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [1-8] -> found - "
                           "%c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 4) {
                if (target == '-' || target == 'x') {
                    pars++;
                    white.how = target;
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [-|x] -> found - "
                           "%c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 5) {
                if ((int)target >= 97 && (int)target <= 104) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.to, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [a-h] -> found - "
                           "%c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 6) {
                if ((int)target >= 49 && (int)target <= 56) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.to, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [1-8] -> found - "
                           "%c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 7) {
                if (target == '#' || target == '+' || target == 'K'
                    || target == 'Q' || target == 'R' || target == 'B'
                    || target == 'N' || target == 'e') {
                    white.shah_mat = target;
                    if (target == 'e') {
                        target = fgetc(input_file);
                        target = fgetc(input_file);
                        target = fgetc(input_file);
                    }
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf(ANSI_COLOR_RED
                           "ERROR in %s line. Was exepted [#|+|e.p|FIGURE| ] "
                           "-> found - "
                           "%c\n" ANSI_COLOR_RESET,
                           white.num,
                           target);
                    exit(1);
                }
            }
        }
    }
}

void errorHandler(int Error, struct step_white* move)
{
    if (Error == 0) {
        printf(ANSI_COLOR_RED
               "ERROR in %s line. Figure " ANSI_COLOR_GREEN "%c" ANSI_COLOR_RED
               " can not move from " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED
               " to " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED
               "\n" ANSI_COLOR_RESET,
               move->num,
               toupper(move->figure),
               move->from,
               move->to);
    }
    if (Error == 3) {
        printf(ANSI_COLOR_RED
               "ERROR in %s line. Figure " ANSI_COLOR_GREEN "%c" ANSI_COLOR_RED
               " not found on field " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED
               "\n" ANSI_COLOR_RESET,
               move->num,
               toupper(move->figure),
               move->from);
    }

    if (Error == 4) {
        printf(ANSI_COLOR_RED
               "ERROR in %s line. Type of move is '" ANSI_COLOR_GREEN
               "x" ANSI_COLOR_RED "' but in the field " ANSI_COLOR_GREEN
               "%s" ANSI_COLOR_RED " there is no figure.\n" ANSI_COLOR_RESET,
               move->num,
               move->to);
    }

    if (Error == 5) {
        printf(ANSI_COLOR_RED
               "ERROR in %s line. Type of move is '" ANSI_COLOR_GREEN
               "-" ANSI_COLOR_RED "' but in the field " ANSI_COLOR_GREEN
               "%s" ANSI_COLOR_RED " there is a figure.\n" ANSI_COLOR_RESET,
               move->num,
               move->to);
    }

    if (Error == 6) {
        printf(ANSI_COLOR_RED
               "ERROR in %s line. Type of stroke is '" ANSI_COLOR_GREEN
               "x" ANSI_COLOR_RED "' but in the field " ANSI_COLOR_GREEN
               "%s" ANSI_COLOR_RED
               " there is a friendly color figure.\n" ANSI_COLOR_RESET,
               move->num,
               move->to);
    }
}