#include "board.h"
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
        char target = fgetc(input_file);
        step_white white;
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
        }
    }
}