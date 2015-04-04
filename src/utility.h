#ifndef ECE_CITY_UTILITY_H
#define ECE_CITY_UTILITY_H

/************************
*	UTILITY LIBRARIES	*
************************/

#include <stdio.h>
#include <stdlib.h>

#include "2Dpoint.h"


/************************
*	UTILITY CONSTANTS	*
************************/

#define TRUE 1
#define FALSE 0

#define BOARD_WIDTH		45
#define BOARD_HEIGHT 	35

#define ROAD_ELEM_SIZE	1
#define HABITATION_WIDTH	3
#define HABITATION_HEIGHT	3
#define PBUILDING_WIDTH		4
#define PBUILDING_HEIGHT	6

/************************
*	ENUMS AND STRUCTS	*
************************/

typedef enum object_type_enum
{
	NOTHING,
	WCASTLE,
	PPLANT,
	ROAD,
	HABITATION
}e_object_type;

#endif