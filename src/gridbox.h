#ifndef ECE_CITY_GRIDBOX_H
#define ECE_CITY_GRIDBOX_H

/****************************
*	 LIBRARY INCLUSIONS		*
****************************/

#include "utility.h"

/****************************
*	STRUCTURE DECLARATION	*
****************************/
typedef struct gridbox
{
	// Points to the corresponding entity
	void* object; 

	// Enum that can take different values accoridng to the type of 
	// object, e.g. WCASTLE for a water castle (see more in utility.h)
	e_object_type object_type;
};

/****************************
*	CONSTANT DECLARATIONS	*
****************************/

/****************************
*	FUNCTION DECLARATIONS	*
****************************/

/** BOX CONSTRUCTOR/DESTRUCTOR **/

/**
 * Box contructor
 * @return (t_box*) box allocated instance
 */
t_box* boxConstruct();
/**
 * Box destructor
 * @param (t_box*) box destructor
 * @param (void *) pointer function to the object destructor
 */
void boxDestroy(t_box* box, void (*ptrObjectDestroy) (void* object));

/** BOX GETTERS **/

/**
 * Retrieves the enum value of the object pointed by the box
 * @param	(t_box*) box
 * @return	(int) Enum value corresponding to the entity pointed by the box
 */
int getBoxObjectType(t_box* box);
/**
 * Tells whether there is something in the box or not
 * @param	(t_box*) box
 * @return	(int) boolean : '1' if there is something constructed on this gridbox, 
 * 							'0' else
 */
int hasObject(t_box* box);
/**
 * Tells whether the object is a water castle or not
 * @param	(t_box*) box
 * @return	(int) boolean : '1' if the object is a water castle
 * 							'0' else
 */
int isBoxObjectWCastle(t_box* box);
/**
 * Tells whether the object is a power plant or not
 * @param	(t_box*) box
 * @return	(int) boolean : '1' if the object is a power plant
 * 							'0' else
 */
int isBoxObjectPPlant(t_box* box);
/**
 * Tells whether the object is a habitation or not
 * @param	(t_box*) box
 * @return	(int) boolean : '1' if the object is a habitation
 * 							'0' else
 */
int isBoxObjectHabitation(t_box* box);
/**
 * Tells whether the object is a road element or not
 * @param	(t_box*) box
 * @return	(int) boolean : '1' if the object is a road element
 * 							'0' else
 */
int isBoxObjectRoad(t_box* box);


#endif