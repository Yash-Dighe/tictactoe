#pragma once
#include <array>

class Game{
public:
    Game();
    void play();

private:
    std::array<std::array<char, 3>, 3> board;
    std::array<std::array<char, 3>, 3> rotBoard;

    char turn;

    void printBoard();
    bool makeMove(const int row, const int col);
    bool checkWin();
    bool checkDraw();
    void switchTurn();

    const std::array<char, 3> xWin = {'X', 'X', 'X'};
    const std::array<char, 3> oWin = {'O', 'O', 'O'};
    std::array<char, 3> cross1, cross2;
    int turns = 0;
};