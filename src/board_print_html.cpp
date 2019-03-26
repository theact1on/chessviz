#include "board_print_html.h"

void outputHTML(char output_board[][8], char str_info[])
{
    FILE* output_html_write;
    output_html_write = fopen("chessviz.html", "a+");

    fclose(output_html_write);
}