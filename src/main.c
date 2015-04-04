#include "utility.h"
#include "board.h"

int main(int argc, char const *argv[])
{
	t_board* board;
	
	board = boardConstruct();
	printf("First build test\n");
	boardPrintToConsole(board);

	boardDestroy(board);
	return 0;
}