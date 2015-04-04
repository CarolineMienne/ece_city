/****************************
*   Generic vector module   *
*   by Julien BREHIN (2014) *
****************************/

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/** @brief 'Homemade' vector implementation for personal C projects
 * Resizable array
 */
typedef struct vector
{
    int nb_ent;     /** Number of entities */
    int max_ent;    /** Max number of entities */
    void **ent;     /** Generic table of pointers to entities */
}t_vector;



/** @brief Constructor
 * Creates an instance of vector structure
 * with the allocated memory to store
 * pointers to any kind of entity.
 *
 * @param (int) max_ent_init  Specifies how much space should be
 * allocated at the beginning
 * @return (t_vector*) pointer to the created vector instance
 */
t_vector *vector_create(int max_ent_init);

///Destructor
void vector_destroy(t_vector *v, void (*entity_destroy)(void *));

///Allows user to add a single entity to the specified vector instance
void vector_add_entity(t_vector *v, void *e);

///Returns the n-th element from the specified vector container
void *vector_get_entity_n(t_vector *v, int n);

///Returns the number of entities in the vector container
int vector_get_size(t_vector *v);

#endif // VECTOR_H_INCLUDED
