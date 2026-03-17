#include <iostream>
#include <fstream>
using namespace std;

void intialize(char**& board)
{
    board = new char* [8];
    for (int i = 0; i < 8; ++i) {
        board[i] = new char[8];
    }
    ifstream file("BOARD.txt");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            file >> board[i][j];
        }
    }
    file.close();
}

void writefile(char** board, ofstream& file)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            file << board[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

void display(char**& board)
{
    cout << "Chessboard:" << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool validsource(char** board, int turn, int s_x, int s_y)
{
    if (s_x < 8 && s_x >= 0 && s_y < 8 && s_y >= 0)
    {
        if (turn == 1 && (board[s_x][s_y] == 'p' || board[s_x][s_y] == 'r'
            || board[s_x][s_y] == 'n' || board[s_x][s_y] == 'b' ||
            board[s_x][s_y] == 'q' || board[s_x][s_y] == 'k') && board[s_x][s_y] != '-')
        {
            return true;
        }
        else if (turn == 0 && (board[s_x][s_y] == 'P' || board[s_x][s_y] == 'R'
            || board[s_x][s_y] == 'N' || board[s_x][s_y] == 'B'
            || board[s_x][s_y] == 'Q' || board[s_x][s_y] == 'K') && board[s_x][s_y] != '-')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool isValidRookMove(int s_x, int s_y, int d_x, int d_y, char** board, int turn)
{
    if ((turn == 0 && (board[d_x][d_y] == 'P' || board[d_x][d_y] == 'R'
        || board[d_x][d_y] == 'N' || board[d_x][d_y] == 'B'
        || board[d_x][d_y] == 'Q' || board[d_x][d_y] == 'K') && board[d_x][d_y] != '-') || (turn == 1 && (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'r'
            || board[d_x][d_y] == 'n' || board[d_x][d_y] == 'b' ||
            board[d_x][d_y] == 'q' || board[d_x][d_y] == 'k') && board[d_x][d_y] != '-'))
    {
        return false;
    }
    if (s_x != d_x && s_y != d_y) {
        return false;
    }
    if (s_x == d_x) {
        if (s_y < d_y) {
            for (int col = s_y + 1; col < d_y; ++col) {
                if (board[s_x][col] != '-') {
                    return false;
                }
            }
        }
        else {
            for (int col = s_y - 1; col > d_y; --col) {
                if (board[s_x][col] != '-') {
                    return false;
                }
            }
        }
    }
    else if (s_y == d_y) {
        if (s_x < d_x) {
            for (int row = s_x + 1; row < d_x; ++row) {
                if (board[row][s_y] != '-') {
                    return false;
                }
            }
        }
        else {
            for (int row = s_x - 1; row > d_x; --row) {
                if (board[row][s_y] != '-') {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isVlidBishopmove(int s_x, int s_y, int d_x, int d_y, char** board, int turn)
{
    if ((turn == 0 && (board[d_x][d_y] == 'P' || board[d_x][d_y] == 'R'
        || board[d_x][d_y] == 'N' || board[d_x][d_y] == 'B'
        || board[d_x][d_y] == 'Q' || board[d_x][d_y] == 'K') && board[d_x][d_y] != '-') || (turn == 1 && (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'r'
            || board[d_x][d_y] == 'n' || board[d_x][d_y] == 'b' ||
            board[d_x][d_y] == 'q' || board[d_x][d_y] == 'k') && board[d_x][d_y] != '-'))
    {
        return false;
    }
    if (abs(s_x - d_x) != abs(s_y - d_y)) {
        return false;
    }
    if (d_x > s_x && d_y > s_y) {
        for (int row = s_x + 1, col = s_y + 1; row < d_x && col < d_y; row++, col++) {
            if (board[row][col] != '-') {
                return false;
            }
        }
    }
    if (d_x < s_x && d_y > s_y) {
        for (int row = s_x - 1, col = s_y + 1; row > d_x && col < d_y; row--, col++) {
            if (board[row][col] != '-') {
                return false;
            }
        }
    }
    if (d_x > s_x && d_y < s_y) {
        for (int row = s_x + 1, col = s_y - 1; row < d_x && col > d_y; row++, col--) {
            if (board[row][col] != '-') {
                return false;
            }
        }
    }
    if (d_x < s_x&& d_y < s_y) {
        for (int row = s_x - 1, col = s_y - 1; row > d_x && col > d_y; row--, col--) {
            if (board[row][col] != '-') {
                return false;
            }
        }
    }
    return true;
}

bool isValidPawmMove(int s_x, int s_y, int d_x, int d_y, char** board, int turn)
{
    if ((turn == 0 && (board[d_x][d_y] == 'P' || board[d_x][d_y] == 'R'
        || board[d_x][d_y] == 'N' || board[d_x][d_y] == 'B'
        || board[d_x][d_y] == 'Q' || board[d_x][d_y] == 'K') && board[d_x][d_y] != '-') || (turn == 1 && (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'r'
            || board[d_x][d_y] == 'n' || board[d_x][d_y] == 'b' ||
            board[d_x][d_y] == 'q' || board[d_x][d_y] == 'k') && board[d_x][d_y] != '-'))
    {
        return false;
    }

    if (turn == 1)
    {
        if (((d_x == s_x + 1 && d_y == s_y + 1) || (d_x == s_x + 1 && d_y == s_y - 1)) && board[d_x][d_y] != '-')
        {
            return true;
        }
        if (s_x + 1 > 7 || board[s_x + 1][s_y] != '-')
        {
            return false;
        }
        if (s_x == 1 && d_x == s_x + 2 && d_y == s_y && board[s_x + 2][s_y] == '-')
        {
            return true;
        }
        if (s_y != d_y || d_x < s_x || d_x == s_x || s_x + 1 != d_x)
        {
            return false;
        }
    }
    else if (turn == 0)
    {
        if (board[d_x][d_y] != '-' && ((d_x == s_x - 1 && d_y == s_y + 1) || (d_x == s_x - 1 && d_y == s_y - 1)))
        {
            return true;
        }
        if (s_x - 1 < 0 || board[s_x - 1][s_y] != '-')
        {
            return false;
        }
        if (s_x == 6 && d_x == s_x - 2 && d_y == s_y && board[s_x - 2][s_y] == '-')
        {
            return true;
        }
        if (s_y != d_y || d_x != s_x - 1)
        {
            return false;
        }
    }
    return true;
}

bool isValidHorseMove(int s_x, int s_y, int d_x, int d_y, char** board, int turn)
{
    if ((turn == 0 && (board[d_x][d_y] == 'P' || board[d_x][d_y] == 'R'
        || board[d_x][d_y] == 'N' || board[d_x][d_y] == 'B'
        || board[d_x][d_y] == 'Q' || board[d_x][d_y] == 'K') && board[d_x][d_y] != '-') || (turn == 1 && (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'r'
            || board[d_x][d_y] == 'n' || board[d_x][d_y] == 'b' ||
            board[d_x][d_y] == 'q' || board[d_x][d_y] == 'k') && board[d_x][d_y] != '-'))
    {
        return false;
    }
    int dx = abs(d_x - s_x);
    int dy = abs(d_y - s_y);
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) {
        return false;
    }
    return true;
}

bool isValidKINGMove(int s_x, int s_y, int d_x, int d_y, char** board, int turn)
{
    if ((turn == 0 && (board[d_x][d_y] == 'P' || board[d_x][d_y] == 'R'
        || board[d_x][d_y] == 'N' || board[d_x][d_y] == 'B'
        || board[d_x][d_y] == 'Q' || board[d_x][d_y] == 'K') && board[d_x][d_y] != '-') || (turn == 1 && (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'r'
            || board[d_x][d_y] == 'n' || board[d_x][d_y] == 'b' ||
            board[d_x][d_y] == 'q' || board[d_x][d_y] == 'k') && board[d_x][d_y] != '-'))
    {
        return false;
    }
    if (d_x > s_x + 1 || d_x < s_x - 1 || d_y > s_y + 1 || d_y < s_y - 1)
    {
        return false;
    }
    if (d_x == s_x && d_y == s_y)
    {
        return false;
    }
    return true;
}

bool isValidQueenMove(int s_x, int s_y, int d_x, int d_y, char** board, int turn)
{
    if ((turn == 0 && (board[d_x][d_y] == 'P' || board[d_x][d_y] == 'R'
        || board[d_x][d_y] == 'N' || board[d_x][d_y] == 'B'
        || board[d_x][d_y] == 'Q' || board[d_x][d_y] == 'K') && board[d_x][d_y] != '-') || (turn == 1 && (board[d_x][d_y] == 'p' || board[d_x][d_y] == 'r'
            || board[d_x][d_y] == 'n' || board[d_x][d_y] == 'b' ||
            board[d_x][d_y] == 'q' || board[d_x][d_y] == 'k') && board[d_x][d_y] != '-'))
    {
        return false;
    }
    if (isValidRookMove(s_x, s_y, d_x, d_y, board, turn))
    {
        return true;
    }
    if (isVlidBishopmove(s_x, s_y, d_x, d_y, board, turn))
    {
        return true;
    }
    return false;
}

bool validdestination(char** board, int turn, int s_x, int s_y, int d_x, int d_y)
{
    if (d_x < 0 || d_x >= 8 || d_y < 0 || d_y >= 8)
    {
        return false;
    }
    if (board[s_x][s_y] == 'R' || board[s_x][s_y] == 'r') {
        if (isValidRookMove(s_x, s_y, d_x, d_y, board, turn))
        {
            return true;
        }
    }
    else if (board[s_x][s_y] == 'B' || board[s_x][s_y] == 'b') {
        if (isVlidBishopmove(s_x, s_y, d_x, d_y, board, turn))
        {
            return true;
        }
    }
    else if (board[s_x][s_y] == 'K' || board[s_x][s_y] == 'k') {
        if (isValidKINGMove(s_x, s_y, d_x, d_y, board, turn))
        {
            return true;
        }
    }
    else if (board[s_x][s_y] == 'N' || board[s_x][s_y] == 'n') {
        if (isValidHorseMove(s_x, s_y, d_x, d_y, board, turn))
        {
            return true;
        }
    }
    else if (board[s_x][s_y] == 'Q' || board[s_x][s_y] == 'q') {
        if (isValidQueenMove(s_x, s_y, d_x, d_y, board, turn))
        {
            return true;
        }
    }
    else if (board[s_x][s_y] == 'P' || board[s_x][s_y] == 'p') {
        if (isValidPawmMove(s_x, s_y, d_x, d_y, board, turn)) {
            return true;
        }
    }
    return false;
}

void makemove(char** board, int s_x, int s_y, int d_x, int d_y)
{
    char pawnpro = 0;
    char store = 0;
    if (board[s_x][s_y] == 'p' && d_x == 7)
    {
        cout << "Pawn promotion: Select one of the following!!!  q  r  n  b" << endl;
        cin >> pawnpro;
        board[d_x][d_y] = pawnpro;
        board[s_x][s_y] = '-';
    }
    else if (board[s_x][s_y] == 'P' && d_x == 0)
    {
        cout << "Pawn promotion: Select one of the following!!!  Q  R  N  B" << endl;
        cin >> pawnpro;
        board[d_x][d_y] = pawnpro;
        board[s_x][s_y] = '-';
    }
    else
    {
        store = board[s_x][s_y];
        board[d_x][d_y] = store;
        board[s_x][s_y] = '-';
    }
}

void changeTurn(int& turn)
{
    if (turn == 0)
    {
        turn = 1;
    }
    else if (turn == 1)
    {
        turn = 0;
    }
}

bool isCheck(char** board, int turn)
{
    int d_x = -1;
    int d_y = -1;

    if (turn == 0)
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'K') { d_x = i; d_y = j; }
    }
    else
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'k') { d_x = i; d_y = j; }
    }

    if (d_x == -1) return false;

    int attacker = 1 - turn;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (attacker == 1)
            {
                if (board[i][j] == 'r')
                {
                    if (isValidRookMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'n')
                {
                    if (isValidHorseMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'b')
                {
                    if (isVlidBishopmove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'q')
                {
                    if (isValidQueenMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'p')
                {
                    if (isValidPawmMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
            }
            else
            {
                if (board[i][j] == 'R')
                {
                    if (isValidRookMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'N')
                {
                    if (isValidHorseMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'B')
                {
                    if (isVlidBishopmove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'Q')
                {
                    if (isValidQueenMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
                else if (board[i][j] == 'P')
                {
                    if (isValidPawmMove(i, j, d_x, d_y, board, attacker))
                        return true;
                }
            }
        }
    }
    return false;
}

bool moveLeavesKingInCheck(char** board, int turn, int s_x, int s_y, int d_x, int d_y)
{
    char temp = board[d_x][d_y];
    board[d_x][d_y] = board[s_x][s_y];
    board[s_x][s_y] = '-';

    bool inCheck = isCheck(board, turn);

    board[s_x][s_y] = board[d_x][d_y];
    board[d_x][d_y] = temp;
    return inCheck;
}

bool isCheckmate(char** board, int turn)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (validsource(board, turn, i, j))
            {
                for (int di = 0; di < 8; di++)
                {
                    for (int dj = 0; dj < 8; dj++)
                    {
                        if (validdestination(board, turn, i, j, di, dj))
                        {
                            if (!moveLeavesKingInCheck(board, turn, i, j, di, dj))
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int d_x;
    int d_y;
    char** board;
    int s_x;
    int s_y;
    int turn = 1;
    int opponentturn = 0;
    char undo = 0;

    cout << "========================================" << endl;
    cout << "       WELCOME TO CHESS GAME!" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "  Player 1  ->  UPPERCASE letters  (P R N B Q K)" << endl;
    cout << "  Player 2  ->  lowercase letters  (p r n b q k)" << endl;
    cout << endl;
    cout << "  Pieces:" << endl;
    cout << "    P/p = Pawn" << endl;
    cout << "    R/r = Rook" << endl;
    cout << "    N/n = Knight" << endl;
    cout << "    B/b = Bishop" << endl;
    cout << "    Q/q = Queen" << endl;
    cout << "    K/k = King" << endl;
    cout << "      -  = Empty square" << endl;
    cout << endl;
    cout << "  Enter moves as:  row col  (e.g. 6 4)" << endl;
    cout << "  Rows and columns are numbered 0 to 7." << endl;
    cout << endl;
    cout << "  Good luck to both players!" << endl;
    cout << "========================================" << endl;
    cout << endl;

    intialize(board);

    display(board);

    while (true)
    {
        if (turn == 0)
        {
            opponentturn = 1;
        }
        else
        {
            opponentturn = 0;
        }

        if (isCheck(board, turn))
        {
            if (isCheckmate(board, turn))
            {
                cout << "Checkmate! Player " << opponentturn + 1 << " wins!" << endl;
                break;
            }
            cout << "Player " << turn + 1 << " is in check!" << endl;
        }
        else if (isCheckmate(board, turn))
        {
            cout << "Stalemate! It's a draw!" << endl;
            break;
        }

        ofstream file2("previousMove.txt");
        writefile(board, file2);

        do {
            cout << "Player " << turn + 1 << " enter source: ";
            cin >> s_x >> s_y;
            cin.ignore(1000, '\n');
            if (validsource(board, turn, s_x, s_y) == false)
            {
                cout << "Invalid source! Try again." << endl;
            }
        } while (validsource(board, turn, s_x, s_y) == false);

        do {
            cout << "Now enter the move: ";
            cin >> d_x >> d_y;
            cin.ignore(1000, '\n');
            if (validdestination(board, turn, s_x, s_y, d_x, d_y) == false || moveLeavesKingInCheck(board, turn, s_x, s_y, d_x, d_y) == true)
            {
                cout << "Invalid move! Try again." << endl;
            }
        } while (validdestination(board, turn, s_x, s_y, d_x, d_y) == false || moveLeavesKingInCheck(board, turn, s_x, s_y, d_x, d_y) == true);

        makemove(board, s_x, s_y, d_x, d_y);

        display(board);

        changeTurn(turn);

        ofstream file3("currentMove.txt");
        writefile(board, file3);

        cout << "Do you want to undo the move? press U to undo; press any other to not undo" << endl;
        cin >> undo;
        cin.ignore(1000, '\n');
        if (undo == 'U')
        {
            ifstream file4("previousMove.txt");
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    file4 >> board[i][j];
                }
            }
            file4.close();
            changeTurn(turn);
            display(board);
        }

        cout << "It is player " << turn + 1 << " turn now!" << endl;
    }
    return 0;
}