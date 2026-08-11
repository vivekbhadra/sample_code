// Tic-Tac-Toe Game Simulator (two human players)
// SOLUTION: all TODO gaps filled in.
// Compile: g++ -std=c++17 -O2 tictactoe_solution.cpp -o tictactoe

#include <array>
#include <iostream>
#include <limits>
#include <string>

class TicTacToe {
public:
    TicTacToe() { board_.fill({' ', ' ', ' '}); }

    // Attempt a move; returns false if invalid (out of range or occupied).
    bool makeMove(int row, int col, char mark) {
        // TODO 1 solution
        if (row < 0 || row > 2 || col < 0 || col > 2) return false;
        if (board_[row][col] != ' ') return false;
        board_[row][col] = mark;
        ++movesMade_;
        lastRow_ = row;
        lastCol_ = col;
        return true;
    }

    // Win check: only inspect the row, column and diagonals
    // touched by the LAST move (this keeps it O(1) per move).
    char checkWinner() const {
        if (movesMade_ == 0) return ' ';
        const int r = lastRow_, c = lastCol_;
        const char m = board_[r][c];

        // TODO 2 solution
        if (board_[r][0] == m && board_[r][1] == m && board_[r][2] == m) return m;
        if (board_[0][c] == m && board_[1][c] == m && board_[2][c] == m) return m;
        if (r == c && board_[0][0] == m && board_[1][1] == m && board_[2][2] == m) return m;
        if (r + c == 2 && board_[0][2] == m && board_[1][1] == m && board_[2][0] == m) return m;
        return ' ';
    }

    bool isDraw() const {
        // TODO 3 solution
        return movesMade_ == 9 && checkWinner() == ' ';
    }

    void printBoard() const {
        std::cout << "\n    0   1   2\n";
        for (int r = 0; r < 3; ++r) {
            std::cout << "  " << r << " ";
            for (int c = 0; c < 3; ++c) {
                std::cout << board_[r][c];
                if (c < 2) std::cout << " | ";
            }
            std::cout << "\n";
            if (r < 2) std::cout << "    ---------\n";
        }
        std::cout << "\n";
    }

private:
    std::array<std::array<char, 3>, 3> board_;
    int movesMade_ = 0;
    int lastRow_ = -1, lastCol_ = -1;
};

// Read an integer, re-prompting on bad input (letters, etc).
int readInt(const std::string& prompt) {
    int x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) return x;
        // TODO 4 solution
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, please enter a number.\n";
    }
}

void takeTurn(TicTacToe& game, char mark) {
    while (true) {
        std::cout << "Player " << mark << "'s turn.\n";
        int r = readInt("  Row (0-2): ");
        int c = readInt("  Col (0-2): ");
        // TODO 5 solution
        if (game.makeMove(r, c, mark)) return;
        std::cout << "Invalid move (out of range or cell taken). Try again.\n";
    }
}

int main() {
    std::cout << "=== Tic-Tac-Toe: Player X vs Player O ===\n";

    TicTacToe game;
    char current = 'X';  // X always moves first

    game.printBoard();
    while (true) {
        takeTurn(game, current);
        game.printBoard();

        // TODO 6 solution
        char winner = game.checkWinner();
        if (winner != ' ') {
            std::cout << "Player " << winner << " wins!\n";
            break;
        }
        if (game.isDraw()) {
            std::cout << "It's a draw!\n";
            break;
        }
        current = (current == 'X') ? 'O' : 'X';
    }
    return 0;
}
