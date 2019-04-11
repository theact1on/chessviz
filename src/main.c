#include "board_print_html.h"
#include "board_read.h"
#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

int main(int argc, char* argv[])
{
    char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    FILE* output_html;
    output_html = fopen("chessviz.html", "w+");
    fprintf(output_html, R"( <html>
        <head>
        <title>Chessviz</title>
        <style type="text/css">
        table.chessboard {
          border: 5px solid #333;
          border-collapse: collapse;
          height: 320px;
          margin: 20px;
          width: 320px;
        }
        table.chessboard caption {
          text-align: left;
        }
        table.chessboard td {
          background-color: #fff;
          font-size: 25px;
          height: 40px;
          text-align: center;
          vertical-align: middle;
          width: 40px;
        }
        table.chessboard tr:nth-child(odd) td:nth-child(even),
        table.chessboard tr:nth-child(even) td:nth-child(odd) {
          background-color: #999;
        }

        table.chessboard .white.king:before   { content: "\2654"; }
        table.chessboard .white.queen:before  { content: "\2655"; }
        table.chessboard .white.rook:before   { content: "\2656"; }
        table.chessboard .white.bishop:before { content: "\2657"; }
        table.chessboard .white.knight:before { content: "\2658"; }
        table.chessboard .white.pawn:before   { content: "\2659"; }

        table.chessboard .black.king:before   { content: "\265A"; }
        table.chessboard .black.queen:before  { content: "\265B"; }
        table.chessboard .black.rook:before   { content: "\265C"; }
        table.chessboard .black.bishop:before { content: "\265D"; }
        table.chessboard .black.knight:before { content: "\265E"; }
        table.chessboard .black.pawn:before   { content: "\265F"; }
      </style>
        </head>
        <body>)");
    fclose(output_html);
    char str_start[30] = "0. start_position";
    outputHTML(board, str_start);
    switch (argc) {
    case 1:
        // stepsFromConsole();
        break;
    case 2:
        checkSteps(argv[1], board);
        break;
    default:
        printf("Не верные входные данные");
        return 1;
    }
    output_html = fopen("chessviz.html", "a+");
    fprintf(output_html, R"(</body>
        </html>)");
    fclose(output_html);
    printf(ANSI_COLOR_GREEN
           "\nThe program has successfully completed.\nOpen "
           "file" ANSI_COLOR_YELLOW " chessviz.html " ANSI_COLOR_GREEN
           "for see visualization.\n\n" ANSI_COLOR_RESET);
    return 0;
}
