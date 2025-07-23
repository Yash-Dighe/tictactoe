#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
    turn = 'X';
}

void Game::play(){
    bool gameOver = false;
    while (!gameOver){
        Game::printBoard();
        int x, y;
        cout << turn << "'s turn to play! Enter a row and column (1-3): ";
        cin >> x;
        if (x < 1 || x > 3){
            cout << "nga where are u placing ts\ntry ts again bro";
            continue;
        }
        cin >> y;
        if (y < 1 || y > 3){
            cout << "nga where are u placing ts\ntry ts again bro";
            continue;
        }
        if (!makeMove(x, y)){
            continue;
        }

        if (checkWin()){
            printBoard();
            cout << turn << " won gg\n"; 
            gameOver = true;
        }
        else if (checkDraw()){
            printBoard();
            cout << "ts rlly ended in a tie lmao\n";
            gameOver = true;
        }
        else{
            switchTurn();
        }
    }
}

void Game::printBoard(){
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << "*---*---*---*\n";
        for (int j = 0; j < 3; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "*---*---*---*\n";
}

bool Game::makeMove(int x, int y){
    x--; y--;
    if (board[x][y] != ' ') {
        cout << "ts taken gng\n";
        return false;
    }
    board[x][y] = turn;
    rotBoard[y][-x+2] = turn;
    if (x == y){
        cross1[x] = turn;
    }
    if (2-x == y){
        cross2[2-x] = turn;
    }
    turns++;
    return true;
}

void Game::switchTurn(){
    turn = (turn == 'X') ? 'O' : 'X';
}

bool Game::checkWin(){
    if (turns < 5) return false;
    for (int i = 0; i < 3; i++){
        if (board[i] == xWin || board[i] == oWin || rotBoard[i] == xWin || rotBoard[i] == oWin){
            return true;
        }
    }
    if (cross1 == xWin || cross1 == oWin || cross2 == xWin || cross2 == oWin){
        return true;
    }
    
    return false;
}

bool Game::checkDraw(){
    return turns == 9;
}