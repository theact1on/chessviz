#include "stdio.h"
#include "stdlib.h"

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

    fprintf(output_html,
            "\n"
            R"(<table class="chessboard">)");
    for (int i = 0; i < 8; i++) {
        fprintf(output_html,
                "\n"
                R"(<tr>)");
        for (int j = 0; j < 8; j++) {
            fprintf(output_html,
                    "\n"
                    R"(<td>)");
            if (board[i][j] != ' ') {
                if (board[i][j] == 'r')
                    fprintf(output_html, R"(<span class="black rook"></span>)");
                if (board[i][j] == 'n')
                    fprintf(output_html,
                            R"(<span class="black knight"></span>)");
                if (board[i][j] == 'b')
                    fprintf(output_html,
                            R"(<span class="black bishop"></span>)");
                if (board[i][j] == 'q')
                    fprintf(output_html,
                            R"(<span class="black queen"></span>)");
                if (board[i][j] == 'k')
                    fprintf(output_html, R"(<span class="black king"></span>)");
                if (board[i][j] == 'p')
                    fprintf(output_html, R"(<span class="black pawn"></span>)");
                if (board[i][j] == 'R')
                    fprintf(output_html, R"(<span class="white rook"></span>)");
                if (board[i][j] == 'N')
                    fprintf(output_html,
                            R"(<span class="white knight"></span>)");
                if (board[i][j] == 'B')
                    fprintf(output_html,
                            R"(<span class="white bishop"></span>)");
                if (board[i][j] == 'Q')
                    fprintf(output_html,
                            R"(<span class="white queen"></span>)");
                if (board[i][j] == 'K')
                    fprintf(output_html, R"(<span class="white king"></span>)");
                if (board[i][j] == 'P')
                    fprintf(output_html, R"(<span class="white pawn"></span>)");
            }
            fprintf(output_html, R"(</td>)");
        }
        fprintf(output_html, R"(</tr>)");
    }
    fprintf(output_html, R"(</table>)");

    fprintf(output_html, R"(</body>
        </html>)");
    fclose(output_html);
    return 0;
}