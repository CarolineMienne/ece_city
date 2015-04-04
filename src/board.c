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
	board->nb_habitations = NB_HABITATIONS_AT_START;

	/* Structure allocations */
	board->graph = (t_graph*) graphConstruct();
	board->grid  = (t_box***) gridConstruct();
	if (board->grid == NULL)
	{
		fprintf(stderr, "Error while allocating game grid !\nProgram must quit");
		exit(EXIT_FAILURE);
	}

	// We use the generic vector constructor that returns an empty vector of size MIN_VECTOR_SIZE
	board->water_network = vector_create(MIN_VECTOR_SIZE);
	board->elec_network	 = vector_create(MIN_VECTOR_SIZE);
	board->habitation_network = vector_create(MIN_VECTOR_SIZE);

	return board;
}

/** Board destructor **/
void boardDestroy(t_board* board)
{
	void* destructor;
	// If there is any water castle instance we have to destroy it
	if (hasWaterNetwork(board))
	{
		// We call the vector destroy with the corresponding specific destructor
		destructor = (void*) &PBDestroy;
		vector_destroy(board->water_network,destructor);
		board->water_network = NULL;
	}
	// If there is any power plant instance we have to destroy it
	if (hasElecNetwork(board))
	{
		// We call the vector destroy with the corresponding specific destructor
		destructor = (void*) &PBDestroy;
		vector_destroy(board->elec_network,destructor);
		board->elec_network = NULL;
	}
	// If there is any habitation building instance we have to destroy it	
	if (hasHabitationNetwork(board))
	{
		// We call the vector destroy with the corresponding specific destructor
		destructor = (void*) &habitationDestroy;
		vector_destroy(board->habitation_network,destructor);
		board->habitation_network = NULL;
	}
	// We destroy the grid
	gridDestroy(board->grid);
	board->grid = NULL;

	// We destroy the graph
	graphDestroy(board->graph);
	board->graph = NULL;

	free(board);
	printf("Board successfully destroyed !\n");
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
/** Getter for board's nb_habitations field */
int getHabitationNb(t_board* board)
{
	return board->nb_habitations;
}

/** Tells whether there is any water castle on the game board or not */
int hasWaterNetwork(t_board* board)
{
	return getWaterCastleNb(board) ? 1 : 0;
}
/** Tells whether there is any power plant on the game board or not */
int hasElecNetwork(t_board* board)
{
	return getPowerPlantNb(board) ? 1 : 0;
}
/** Tells whether there is any habitation building on the game board or not */
int hasHabitationNetwork(t_board* board)
{
	return getHabitationNb(board) ? 1 : 0;
}

/** BOARD SETTERS **/
/** Adds the specified power plant to the gameboard (at the right position on the grid)*/
void addPPlantToBoard(t_board* board, t_PB* pplant)
{
	int x,y;
	// If the building can be built entirely in the grid frame limits
	if (pplant->coord->x + PBUILDING_WIDTH <= BOARD_WIDTH && pplant->coord->y + PBUILDING_HEIGHT <= BOARD_HEIGHT)
	{
		// We first add it to the grid
		for (y = 0; y < PBUILDING_HEIGHT ; y++)
		{
			for (x = 0; x < PBUILDING_WIDTH ; x++)
			{
				board->grid[pplant->coord->y + y][pplant->coord->x + x] = (void*) pplant;
			}
		}
		// And then add it to the corresponding collection
		vector_add_entity(board->elec_network,pplant);
		board->nb_pplants = vector_get_size(board->elec_network);
	}
}
/** Adds the specified water castle to the gameboard (at the right position on the grid) */
void addWCastleToBoard(t_board* board, t_PB* wcastle)
{
	int x,y;
	// If the building can be built entirely in the grid frame limits
	if (wcastle->coord->x + PBUILDING_WIDTH <= BOARD_WIDTH && wcastle->coord->y + PBUILDING_HEIGHT <= BOARD_HEIGHT)
	{
		// We first add it to the grid
		for (y = 0; y < PBUILDING_HEIGHT ; y++)
		{
			for (x = 0; x < PBUILDING_WIDTH ; x++)
			{
				board->grid[wcastle->coord->y + y][wcastle->coord->x + x] = (void*) wcastle;
			}
		}
		// And then add it to the corresponding collection
		vector_add_entity(board->water_network,wcastle);
		board->nb_wcastles = vector_get_size(board->water_network);
	}
}
/** Adds the specified habitation to the gameboard (at the right position on the grid) */
void addHabitationToBoard(t_board* board, t_habit* habitation)
{
	int x,y;
	// If the building can be built entirely in the grid frame limits
	if (habitation->coord->x + HABITATION_WIDTH <= BOARD_WIDTH && habitation->coord->y + HABITATION_HEIGHT <= BOARD_HEIGHT)
	{
		// We first add it to the grid
		for (y = 0; y < HABITATION_HEIGHT ; y++)
		{
			for (x = 0; x < HABITATION_WIDTH ; x++)
			{
				board->grid[habitation->coord->y + y][habitation->coord->x + x] = (void*) habitation;
			}
		}
		// And then add it to the corresponding collection
		vector_add_entity(board->habitation_network,habitation);
		board->nb_habitations = vector_get_size(board->water_network);
	}	
}

/** BOARD UI ROUTINES **/
/** Prints the board data in the specified (opened) file */
void boardPrintToFile(t_board* board, FILE* f)
{
	fprintf(f, "Inhabs :\t%d\n", board->nb_inhabs);
	fprintf(f, "Power plants :\t%d\n", board->nb_pplants);
	fprintf(f, "Water castles :\t%d\n", board->nb_wcastles);
    fprintf(f, "Habitations :\t%d\n", board->nb_habitations);
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
