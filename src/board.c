#include "board.h"


/************************************
*	STATIC FUNCTIONS DECLARATIONS	*
*************************************/

/**
 * Grid constructor
 * @return (t_box **) Full size grid for the game, with boxes pointing to NULL
 */
static t_box** gridConstruct();

/********************************
*	FUNCTION IMPLEMENTATIONS	*
********************************/

/************************
 * 	Global functions	*
 ************************/

/** Board constructor **/
t_board boardConstruct()
{
	int x,y;
	t_board* board = NULL;

	board = (t_board*) malloc(sizeof(t_board));
	if (board == NULL)
	{
		fprintf(stderr, "Error while allocating board instance !\nProgram must quit\n");
		exit(EXIT_FAILURE);
	}

	/* Variable initialization */
	board->nb_inhabs 	= NB_INHABS_AT_GAME_START;
	board->months 		= TIME_AT_START;
	board->flouz 		= FLOUZ_AT_START;
	board->nb_pplants 	= NB_PPLANTS_AT_START;
	board->nb_wcastles 	= NB_WCASTLES_AT_START;

	/* Structure allocations */
	board->graph = (t_graph*) graphConstruct();
	board->grid  = (t_grid*) gridConstruct();
	if (board->grid == NULL)
	{
		fprintf(stderr, "Error while allocating game grid !\nProgram must quit");
		exit(EXIT_FAILURE);
	}

	// Since there are no resource provider (water castles/power plants) 
	// at the beginning we can't allocate anything.
	// Thus, we set these lists as pointing to NULL.
	board->water_network = NULL;
	board->elec_network	 = NULL;

	return board;
}

/** Board destructor **/
void boardDestroy(t_board* board)
{
	int x,y;

	if(hasWaterNetwork(board))
	{
		free(board->water_network);
	}	
}

int hasWaterNetwork(t_board* board)
{
	return getwaterCastleNb(board) ? 1 : 0;
}

int hasElecNetwork(t_board* board)
{
	return getpowerPlantNb(board) ? 1 : 0;
}

/************************
*	Static functions	*
************************/

static t_box** gridConstruct()
{
	t_box** grid = NULL;
	(t_box**) malloc(BOARD_HEIGHT * sizeof(t_box*));
	if (grid == NULL)
	{
		return NULL;
	}

	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		grid[y] = (t_box*) boxConstruct();
	}

	return grid;
}