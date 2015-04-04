#ifndef ECE_CITY_BOARD_H
#define ECE_CITY_BOARD_H

/************************
*	LIBRARY INCLUSIONS	*
************************/

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "habitation.h"
#include "publicbuildings.h"
#include "gridbox.h"
#include "vector.h"
#include "utility.h"

/****************************
*	STRUCTURE DECLARATION	*
****************************/
typedef struct board
{
	int nb_inhabs; 	// Number of inhabitants in the city
	int months;		// Current time (in months)
	int flouz;		// Current amount of money in the coffers of the city

	/* Board related fields */
	int nb_pplants;		// Number of power plants currently on game
	int nb_wcastles;	// Number of water castles currently on the game
	int nb_habitations;	// Number of dwellings (including everything from wasteland to skyscrapers) currently on the game
	t_graph *graph;		// Structure containing all data related to the network graph
	t_vector* habitation_network; // Lists all habitations
	t_vector* water_network;	// Lists all water castles
	t_vector* elec_network;	// Lists all power plants
	t_box*** grid;	// Matrix that represents the gameboard. Each index points to a box structure
}t_board;

/****************************
*	CONSTANT DECLARATIONS	*
****************************/

#define TIME_AT_START 	0
#define FLOUZ_AT_START 	500000
#define NB_INHABS_AT_GAME_START 0
#define NB_PPLANTS_AT_START 	0
#define NB_WCASTLES_AT_START 	0
#define NB_HABITATIONS_AT_START 0
#define MIN_VECTOR_SIZE	2


/****************************
*	FUNCTION DECLARATIONS	*
****************************/

/************************
 * 	Global functions	*
 ************************/

/** BOARD CONSTRUCTOR/DESTRUCTOR **/

/**
 * Board constructor
 * @return (t_board *) allocated board instance
 */
t_board* boardConstruct();

/**
 * Board destructor
 * @param (t_board *) board instance to be destroyed
 */
void boardDestroy(t_board* board);

/** BOARD GETTERS **/

/**
 * Retrieves the number of water castles on the game board
 * @param	(t_board*) board
 * @return	(int) number of water castles
 */
int getWaterCastleNb(t_board* board);
/**
 * Retrieves the number of power plants on the game board
 * @param	(t_board*) board
 * @return	(int) number of power plants
 */
int getPowerPlantNb(t_board* board);
/**
 * Retrieves the number of habitation buildings on the game board
 * @param  (t_board*) board
 * @return (int) number of power plants
 */
int getHabitationNb(t_board* board);

/**
 * Tells whether there is any water castle on the game board or not
 * @param	(t_board*) board 
 * @return	(int) boolean : '1' if there is at least one water castle
 */
int hasWaterNetwork(t_board* board);
/**
 * Tells whether there is any power plant on the game board or not
 * @param	(t_board*) board
 * @return	(int) boolean : '1' if there is at least one power plant
 */
int hasElecNetwork(t_board* board);
/**
 * Tells whether there is any power plant on the game board or not
 * @param  (t_board*) board
 * @return (int) boolean : '1' if there is at least one habitation building
 */
int hasHabitationNetwork(t_board* board);

/** BOARD SETTERS **/
/**
 * Adds the specified power plant to the gameboard
 * @param (t_board*) board  
 * @param (t_PB*) pplant Power plant instance to be added
 */
void addPPlantToBoard(t_board* board, t_PB* pplant);
/**
 * Adds the specified water castle to the gameboard
 * @param (t_board*) board  
 * @param (t_PB*) wcastle Water castle instance to be added
 */
void addWCastleToBoard(t_board* board, t_PB* wcastle);
/**
 * Adds the specified hanitation to the gameboard
 * @param (t_board*) board 
 * @param (t_habit*) habitation Habitation instance to be added
 */
void addHabitationToBoard(t_board* board, t_habit* habitation);

/** BOARD UI ROUTINES **/

/**
 * Prints the board data in the specified file
 * @param (t_board*) board Board to be printed
 */
void boardPrintToFile(t_board* board, FILE* f);
/**
 * Prints the board data in the stdout file
 * @param (t_board*) board Board to be printed
 */
void boardPrintToConsole(t_board* board);

#endif


