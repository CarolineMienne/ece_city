#ifndef ECE_CITY_GRAPH_H
#define ECE_CITY_GRAPH_H

/****************************
*	 LIBRARY INCLUSIONS		*
****************************/

#include <stdio.h>
#include <stdlib.h>

#include "utility.h"
#include "2Dpoint.h"

/****************************
*	STRUCTURE DECLARATION	*
****************************/

typedef struct graph
{
	char** adjacency_matrix;
	int nb_edges;
	t_2Dcoord** edges_coord;
}t_graph;

/****************************
*	CONSTANT DECLARATIONS	*
****************************/

/****************************
*	FUNCTION DECLARATIONS	*
****************************/

/** GRAPH CONSTRUCTOR/DESTRUCTOR **/

/**
 * Graph constructor
 * @return (t_graph*) allocated and initialized empty graph
 */
t_graph* graphConstruct();
/**
 * Graph destructor
 * @param (t_graph*) graph to be destroyed
 */
void graphDestroy(t_graph* graph);

/** GRAPH GETTERS **/
/**
 * Retrieves the number of edges on the graph
 * @param	(t_graph*) graph
 * @return	(int) number of edges
 */
int getGraphNbEdges(t_graph* graph);

/** GRAPH SETTERS **/

#endif