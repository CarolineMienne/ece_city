#include "board.h"


/************************************
*	STATIC FUNCTIONS DECLARATIONS	*
*************************************/

/**
 * Grid constructor
 * @return (t_box ***) Full size grid for the game, with boxes pointing to NULL
 */
static t_box*** gridConstruct();
/**
 *	Grid destructor
 *	@param (t_box***) grid to destroy
 */
static void gridDestroy(t_box*** grid);

/**
 * Prints the grid to the specified file
 * @param (t_box***) grid
 * @param (FILE*) f File to write in. Must have been already opened before!
 */
static void gridPrintToFile(t_box*** grid, FILE* f);

/********************************
*	FUNCTION IMPLEMENTATIONS	*
********************************/

/************************
* 	Global functions	*
*************************/

/** BOARD CONSTRUCTOR/DESTRUCTOR **/

/** Board constructor **/
t_board* boardConstruct()
{
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
	board->grid  = (t_box***) gridConstruct();
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
	if (hasWaterNetwork(board))
	{
		free(board->water_network);
		board->water_network = NULL;
	}
	if (hasElecNetwork(board))
	{
		free(board->elec_network);
		board->elec_network = NULL;
	}
	gridDestroy(board->grid);
	board->grid = NULL;

	graphDestroy(board->graph);
	board->graph = NULL;

	free(board);	
}

/** BOARD GETTERS **/

/** Getter for board's nb_wcastles field **/
int getWaterCastleNb(t_board* board)
{
	return board->nb_wcastles;
}
/** Getter for board's nb_pplants field **/
int getPowerPlantNb(t_board* board)
{
	return board->nb_pplants;
}

int hasWaterNetwork(t_board* board)
{
	return getWaterCastleNb(board) ? 1 : 0;
}
int hasElecNetwork(t_board* board)
{
	return getPowerPlantNb(board) ? 1 : 0;
}

/** BOARD SETTERS **/

/** BOARD UI ROUTINES **/
/** Prints the board data in the specified (opened) file */
void boardPrintToFile(t_board* board, FILE* f)
{
	fprintf(f, "Inhabs :\t%d\n", board->nb_inhabs);
	fprintf(f, "Power plants :\t%d\n", board->nb_pplants);
	fprintf(f, "Water castles :\t%d\n", board->nb_wcastles);
	fprintf(f, "ECE-Flouz :\t%d\n", board->flouz);
	fprintf(f, "Months (in game) :\t%d\n", board->months);
	gridPrintToFile(board->grid,f);
}
/** Prints the board data in the stdout file */
void boardPrintToConsole(t_board* board)
{
	boardPrintToFile(board,stdout);
}

/************************
*	Static functions	*
************************/

/** Grid constructor **/
static t_box*** gridConstruct()
{
	int x,y;
	t_box*** grid = NULL;

	// Allocating lines...
	grid = (t_box***) malloc(BOARD_HEIGHT * sizeof(t_box**));

	// ...and then columns
	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		grid[y] = (t_box**) malloc(BOARD_WIDTH * sizeof(t_box*));
	}

	// If grid != NULL we can proceed with initialization
	if (grid)
	{
		for (y = 0; y < BOARD_HEIGHT; y++)
		{
			for (x = 0; x < BOARD_WIDTH; x++)
			{
				grid[y][x] = (t_box*) boxConstruct();
			}
		}
	}
	
	// Wether it is NULL or successfully allocated (and initialized), we return the grid
	return grid;
}

/** Grid destructor */
static void gridDestroy(t_box*** grid)
{
	int x,y;

	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		for (x = 0; x < BOARD_WIDTH; x++)
		{
			boxDestroy(grid[y][x],NULL);
		}
		free(grid[y]);
	}
	free(grid);
}

static void gridPrintToFile(t_box*** grid, FILE* f)
{
	int x,y;

	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		fprintf(f, "|");
		for (x = 0; x < BOARD_WIDTH; x++)
		{
			fprintf(f,"[");
			if (grid[y][x]->object_type == NOTHING)
			{
				fprintf(f,"0");
			}
			else
			{
				fprintf(f, "%d\n", grid[y][x]->object_type);
			}
			fprintf(f,"]");
		}
		fprintf(f,"|\n");
	}
}