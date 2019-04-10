#include "board_plain.h"
#include "board_print_html.h"
#include "board_read.h"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void moveFigures(struct step_white* white_step, char board[][8])
{
    if ((int)white_step->from[0] < 97 || (int)white_step->from[0] > 104 || (int)white_step->from[1] < 49 || (int)white_step->from[1] > 56) {
        printf(ANSI_COLOR_RED "In " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED " line. ERROR. Field " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED " not found.\n", white_step->num, white_step->from);
        printf("ERROR>>FIELD_NOT_FOUND\nExiting...\n" ANSI_COLOR_RESET);
        exit(1);
    }

    int step_liter = (int)white_step->from[0] - 97;
    int step_digit = 8 - ((int)white_step->from[1] - 48) % 9;

    if (board[step_digit][step_liter] == white_step->figure) {
        board[step_digit][step_liter] = ' ';
        if (white_step->how == 'x') {
            step_liter = (int)white_step->to[0] - 97;
            step_digit = 8 - ((int)white_step->to[1] - 48) % 9;
            if (board[step_digit][step_liter] == ' ') {
                printf(ANSI_COLOR_RED "In " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED " line. ERROR. Type of stroke " ANSI_COLOR_GREEN "%c" ANSI_COLOR_RED ", but in field " ANSI_COLOR_GREEN
                                      "%s" ANSI_COLOR_RED " dont have figure.\n",
                       white_step->num,
                       white_step->how,
                       white_step->to);
                printf("ERROR>>TAKE_BUT_FIELD_DONT_HAVE_FIGURE\nExiting..."
                       "\n" ANSI_COLOR_RESET);
            }
        }
        step_liter = (int)white_step->to[0] - 97;
        step_digit = 8 - ((int)white_step->to[1] - 48) % 9;
        board[step_digit][step_liter] = white_step->figure;
    } else {
        printf(ANSI_COLOR_RED "In " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED " line. ERROR. Figure " ANSI_COLOR_GREEN "%c" ANSI_COLOR_RED " not found on " ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED " field.\n",
               white_step->num,
               white_step->figure,
               white_step->from);
        printf("ERROR>>FIGURE_NOT_ON_FIELD_FROM\nExiting..."
               "\n" ANSI_COLOR_RESET);
        exit(1);
    }

    char str_info[30];
    white_step->figure = toupper(white_step->figure);
    sprintf(str_info, "%s. %c%s%c%s%c", white_step->num, white_step->figure, white_step->from, white_step->how, white_step->to, white_step->shah_mat);

    outputHTML(board, str_info);
}