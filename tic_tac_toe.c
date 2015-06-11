#include <stdio.h>
#include "tic_tac_toe.h"

#define EMPTY "."
#define XX "X"
#define OO "O"

int BOARD_SIZE = 3;
// The board. We'll represent it as three arrays of rows.
// Need to allocate this dynamically when we move to an arbitrary board size
char* board[3][3] = {
	{EMPTY, EMPTY, EMPTY}, 
	{EMPTY, EMPTY, EMPTY}, 
	{EMPTY, EMPTY, EMPTY}};
int
main(){
	int max_turns = BOARD_SIZE * BOARD_SIZE;
	int num_turns = 0;
	char *c_player = XX;
	printf("A basic game of tic-tac-toe.\n");
	printf("Board size is %i x %i\n", BOARD_SIZE, BOARD_SIZE);
	while (check_win() != 1){
		if (c_player == XX){
			c_player = OO;
		}else{
			c_player = XX;
		}
		if (num_turns++ >= max_turns){
			print_board();
			printf("Draw game!\n");
			return 0;
		}
		do{
			print_board();
		}while (perform_move(c_player));

	}
	printf("Game over! The winner was %s\n", c_player);
	return 0;
}

// Take in the coordinates of the player's move. Take the input with row/col indexes
// starting at 1, then shift so they start at 0.
int
perform_move(char *player){
	int row, col;
	printf("Player %s enter the 'row column' pair to make your move:\n", player);
	scanf("%i %i",&row, &col);
	row -= 1;
	col -= 1;
	if (row >= BOARD_SIZE || row < 0 | col >= BOARD_SIZE | col < 0){
		printf("That space is not on the board!\n");
		return 1;
	}
	if (board[row][col] != EMPTY){
		printf("That is a non-empty space!\n");
		return 1;
	}
	board[row][col] = player;
	return 0;
}

int
check_win(){
	int i, j;
	char* prev = 0;
	prev = board[0][0];
	//Check the board for a win in the rows
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			//check the rows
			if (board[i][j] == EMPTY || board[i][j] != prev){
				// There cannot be a win in this row, stop looking (break to next row)
				prev = board[i][j];
				break;
			}else if (j == BOARD_SIZE - 1){
				// We've checked all the rows
				printf("Found a win in row %i\n", i + 1);
				return 1;
			}
			prev = board[i][j];
		}
	}
	//Check for a win in the cols
	prev = board[0][0];
	for (j = 0; j < BOARD_SIZE; j++){
		for (i = 0; i < BOARD_SIZE; i++){
			//check the rows
			if (board[i][j] == EMPTY || board[i][j] != prev){
				// There cannot be a win in this col, stop looking (break to next column)
				prev = board[i][j];
				break;
			}else if (i == BOARD_SIZE - 1){
				// We've checked all the columns
				printf("Found a win in column %i\n", j + 1);
				return 1;
			}
			prev = board[i][j];
		}
	}

	//Check for a win in the positive diagonal
	prev = board[0][0];
	for (i = 0; i < BOARD_SIZE; i++){
		if (board[i][i] == EMPTY || board[i][i] != prev){
			// Cannot be a win on this diagonal, break
			break;
		}else if (i == BOARD_SIZE - 1){
			printf("Found a win on the diagonal!\n");
			return 1;
		}
		prev = board[i][i];
	}

	//Check for a win in the nagative diagonal
	prev = board[0][BOARD_SIZE - 1];
	for (i = BOARD_SIZE - 1; i >= 0; i--){
		if (board[i][BOARD_SIZE - (i + 1)] == EMPTY || board[i][BOARD_SIZE - (i + 1)] != prev){
			// Cannot be a win on this diagonal, break
			printf("Checking win on neg diag, i= %i, prev = %s\n", i, prev);
			break;
		}else if (i == 0){
			printf("Found a win on the negative diagonal!\n");
			return 1;
		}
		prev = board[i][BOARD_SIZE - (i + 1)];
	}
	return 0;
}

int
print_board(void){
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			printf("%s ", board[i][j]);
		}
	printf("\n");
	}
	return 0;
}
