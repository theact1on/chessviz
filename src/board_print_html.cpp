#include "board_print_html.h"

void outputHTML(char output_board[][8], char str_info[])
{
    FILE* output_html_write;
    output_html_write = fopen("chessviz.html", "a+");

    fprintf(output_html_write,
            "\n"
            R"(<table class="chessboard">)"
            "<caption>%s</caption>",
            str_info);
    for (int i = 0; i < 8; i++) {
        fprintf(output_html_write,
                "\n"
                R"(<tr>)");
        for (int j = 0; j < 8; j++) {
            fprintf(output_html_write,
                    "\n"
                    R"(<td>)");
            if (output_board[i][j] != ' ') {
                if (output_board[i][j] == 'r')
                    fprintf(output_html_write,
                            R"(<span class="black rook"></span>)");
                if (output_board[i][j] == 'n')
                    fprintf(output_html_write,
                            R"(<span class="black knight"></span>)");
                if (output_board[i][j] == 'b')
                    fprintf(output_html_write,
                            R"(<span class="black bishop"></span>)");
                if (output_board[i][j] == 'q')
                    fprintf(output_html_write,
                            R"(<span class="black queen"></span>)");
                if (output_board[i][j] == 'k')
                    fprintf(output_html_write,
                            R"(<span class="black king"></span>)");
                if (output_board[i][j] == 'p')
                    fprintf(output_html_write,
                            R"(<span class="black pawn"></span>)");
                if (output_board[i][j] == 'R')
                    fprintf(output_html_write,
                            R"(<span class="white rook"></span>)");
                if (output_board[i][j] == 'N')
                    fprintf(output_html_write,
                            R"(<span class="white knight"></span>)");
                if (output_board[i][j] == 'B')
                    fprintf(output_html_write,
                            R"(<span class="white bishop"></span>)");
                if (output_board[i][j] == 'Q')
                    fprintf(output_html_write,
                            R"(<span class="white queen"></span>)");
                if (output_board[i][j] == 'K')
                    fprintf(output_html_write,
                            R"(<span class="white king"></span>)");
                if (output_board[i][j] == 'P')
                    fprintf(output_html_write,
                            R"(<span class="white pawn"></span>)");
            }
            fprintf(output_html_write, R"(</td>)");
        }
        fprintf(output_html_write, R"(</tr>)");
    }

    fclose(output_html_write);
}