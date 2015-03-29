#ifndef ECE_CITY_PUBLICBUILDINGS_H
#define ECE_CITY_PUBLICBUILDINGS_H

/****************************
*	 LIBRARY INCLUSIONS		*
****************************/

#include "utility.h"

/****************************
*	STRUCTURE DECLARATION	*
****************************/
typedef struct publicbuildings
{
	char PB_type;
	int remaining_res;
	t_2Dcoord coord;
}t_PB;

/****************************
*	CONSTANT DECLARATIONS	*
****************************/

/****************************
*	FUNCTION DECLARATIONS	*
****************************/


/** BOX CONSTRUCTOR/DESTRUCTOR **/

/**
 * PB Constructor
 * @return (t_PB*) allocated and initialized instance of t_PB
 */
t_PB* PBConstruct();
void PBDestroy(t_PB* pb);

#endif