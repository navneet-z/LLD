#include<iostream>
#include<map>
#include "board.cpp"

using namespace std;

class Trello {
    private:
        map<int, Board*> boards;

    public:
        int addBoard(string boardName) {
            Board* board = new Board(boardName);
            boards[board->getBoardId()] = board;
            return board->getBoardId();
        }

        Board* getBoardById(int boardId) {
            return boards[boardId];
        }
};
