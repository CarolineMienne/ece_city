#ifndef ECE_CITY_HABITATION_H
#define ECE_CITY_HABITATION_H

/************************
*	LIBRARY INCLUSIONS	*
************************/

#include <time.h>

#include "utility.h"

/****************************
*	STRUCTURE DECLARATION	*
****************************/

typedef struct habitation
{
	char stage;			// Current development stage for the habitation instance
	int nb_inhabs;		// Number of inhabitants in the building (maybe unnecessary ?)
	time_t proper_time;	// Proper time for the instance (time_t is defined in time.h standard C library)

	char has_elec;			// Indicates whether the building is provided electricity or not
	int** pplants_numbers;	// Indicates which power plant(s) provide electricity to the instance and how much
	char water_amount;		// Total amount of water that is provided to the building
	int** wcastles_numbers;	// Indicates which water castle(s) provide(s) water to the instance and how much

	t_2Dcoord* coord;	// Coordinates on the grid map
}t_habit;

/****************************
*	CONSTANT DECLARATIONS	*
****************************/

/****************************
*	FUNCTION DECLARATIONS	*
****************************/

/************************
 * 	Global functions	*
 ************************/

/** HABITATION CONSTRUCTOR/DESTRUCTOR **/

/**
 * Habitation constructor
 * @return (t_habit *) allocated habitation instance
 */
t_habit* habitationConstruct();

/**
 * Habitation destructor
 * @param (t_habit *) habitation instance to be destroyed
 */
void habitationDestroy(t_habit* habitation);

/** HABITATION GETTERS **/


/** BOARD SETTERS **/

/** BOARD UI ROUTINES **/

#endif