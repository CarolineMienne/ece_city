#include "utility.h"
#include "board.h"

int main(int argc, char const *argv[])
{
	t_board* board;

	board = boardConstruct();
	printf("First build test\n");
	boardPrintToConsole(board);

	boardDestroy(board);
	printf("Board successfully destroyed !\n");
	return 0;
}