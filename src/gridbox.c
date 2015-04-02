#include "gridbox.h"

/************************************
*	STATIC FUNCTIONS DECLARATIONS	*
*************************************/

/********************************
*	FUNCTION IMPLEMENTATIONS	*
********************************/

/************************
* 	Global functions	*
*************************/

/** BOX CONSTRUCTOR/DESTRUCTOR **/

/** Box constructor */
t_box* boxConstruct()
{
	t_box* box;

	box = (t_box*) malloc(sizeof(t_box));
	if (box == NULL)
	{
		fprintf(stderr, "Error while allocating gridbox unit !\nProgram must quit");
		exit(EXIT_FAILURE);
	}
	box->object_type = NOTHING;
	box->object 	 = NULL;

	return box;
}
/** Box destructor */
void boxDestroy(t_box* box, void (*ptrObjectDestroy) (void* object))
{
	if (box->object && ptrObjectDestroy)
	{
		ptrObjectDestroy(box->object);
	}
	free(box);
}

/** BOX GETTERS **/

/** Tells whether ther is something in the box or not */
int getBoxObjectType(t_box *box)
{
	return box->object_type;
}
/** Tells whether there is something in the box or not */
int hasObject(t_box* box)
{
	int obj_type = getBoxObjectType(box);
	return (obj_type != NOTHING) ? 1 : 0;
}
/** Tells whether the object is a water castle or not */
int isBoxObjectWCastle(t_box *box)
{
	int obj_type = getBoxObjectType(box);
	return (obj_type == WCASTLE) ? 1 : 0;
}
/** Tells whether the object is a power plant or not */
int isBoxObjectPPlant(t_box* box)
{
	int obj_type = getBoxObjectType(box);
	return (obj_type == PPLANT) ? 1 : 0;
}
/** Tells whether the object is a habitation or not */
int isBoxObjectHabitation(t_box* box)
{
	int obj_type = getBoxObjectType(box);
	return (obj_type == HABITATION) ? 1 : 0;
}
/** Tells whether the object is a road element or not */
int isBoxObjectRoad(t_box* box)
{
	int obj_type = getBoxObjectType(box);
	return (obj_type == ROAD) ? 1 : 0;
}

/** BOX SETTERS **/

/************************
*	Static functions	*
************************/