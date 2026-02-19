#include <string>
#include <vector>

class Solution {
public:
	bool validTicTacToe(std::vector<std::string>& board) {
		int numOs = 0;
		int numXs = 0;
		// Count Xs and Os
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(board[i][j] == 'X') {
					numXs++;
				} else if(board[i][j] == 'O') {
					numOs++;
				}
			}
		}
		char winnersSquares[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};
		int numWinners = 0;
		// Across row wins.
		for(int i = 0; i < 3; i++) {
			const bool winner = board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2];
			if(winner) {
				winnersSquares[i][0] = board[i][0];
				winnersSquares[i][1] = board[i][1];
				winnersSquares[i][2] = board[i][2];
				numWinners++;
			}
		}
		// Down column wins.
		for(int i = 0; i < 3; i++) {
			const bool winner = board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i];
			if(winner) {
				winnersSquares[0][i] = board[0][i];
				winnersSquares[1][i] = board[1][i];
				winnersSquares[2][i] = board[2][i];
				numWinners++;
			}
		}
		// Diagonal winner 1.
		const bool diagWin1 = board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2];
		if(diagWin1) {
			winnersSquares[0][0] = board[0][0];
			winnersSquares[1][1] = board[1][1];
			winnersSquares[2][2] = board[2][2];
			numWinners++;
		}
		// Diagonal winner 2.
		const bool diagWin2 = board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2];
		if(diagWin2) {
			numWinners++;
			winnersSquares[2][0] = board[2][0];
			winnersSquares[1][1] = board[1][1];
			winnersSquares[0][2] = board[0][2];
		}
		if(numWinners > 2) {
			return false;
		}
		bool xWasWinner = false;
		bool oWasWinner = false;
		int numXWinners = 0;
		int numOWinners = 0;
		int numWinnerSquaresSet = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				const auto c = winnersSquares[i][j];
				if(c == ' ') {
					continue;
				}
				numWinnerSquaresSet++;
				if(c == 'X') {
					numXWinners++;
					xWasWinner = true;
				} else {
					numOWinners++;
					oWasWinner = true;
				}
			}
		}
		if(numXWinners > 0 && numOWinners > 0) {
			return false;
		}
		if(numWinnerSquaresSet > 5) {
			return false;
		}
		// numXs must be at most >= num0s and <= num0s + 1.
		if(numXs < numOs || numXs > numOs + 1) {
			return false;
		}
		// If X was the winner, then numXs must be > numOs.
		if(xWasWinner && numXs <= numOs) {
			return false;
		}
		// If ) was the winner, then numOs must be == numXs
		if(oWasWinner && numOs != numXs) {
			return false;
		}
		return true;

	}
};

int main() {
	std::vector<std::string> board = {"XOX","OXO","OXX"};
	Solution s;
	const auto result = s.validTicTacToe(board);
	return 0;
}
