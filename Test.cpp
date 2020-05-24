#include "Board.hpp"
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include "doctest.h"
using namespace WarGame;

TEST_CASE("Game Board 1") {
    Board board(4, 4);
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 0}] = new FootCommander(1);
    board[{1, 0}] = new FootCommander(2);
    board[{1, 1}] = new FootCommander(2);
    for (int i = 0; i < 100; i++) {
        CHECK(board.has_soldiers(1));
        CHECK(board.has_soldiers(2));
        CHECK_NOTHROW(board.move(1, {0, 1}, Board::Right));
    }
}