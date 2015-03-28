#ifndef ECE_CITY_BOARD_H
#define ECE_CITY_BOARD_H

/************************
*	LIBRARY INCLUSIONS	*
************************/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

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
	t_graph *graph;		// Structure containing all data related to the network graph
	t_PB** water_network;	// Lists all water castles
	t_PB** elec_network;	// Lists all power plants
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


/****************************
*	FUNCTION DECLARATIONS	*
****************************/

/************************
 * 	Global functions	*
 ************************/

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



#endif


