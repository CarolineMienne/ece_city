/****************************
*   Generic table module    *
*   by Julien BREHIN (2014) *
****************************/

#include "vector.h"

///Constructor
t_vector *vector_create(int max_ent_init)
{
    t_vector *v = NULL;

    v = malloc(1 * sizeof(t_vector));

    if(max_ent_init<2) max_ent_init = 2;
    v->ent      = malloc(max_ent_init * sizeof(void *));
    v->max_ent  = max_ent_init;
    v->nb_ent   = 0;

    return v;
}

///Destructor
void vector_destroy(t_vector *v,void (*entity_destroy)(void *))
{
    int i = 0;

    for(i=0;i<v->nb_ent;i++)
    {
        entity_destroy(v->ent[i]);
    }
    free(v->ent);
    free(v);
}

///Allows user to add a single entity to the specified vector instance
void vector_add_entity(t_vector *v, void *e)
{
    //If the vector is almost full (only 1 empty space left)...
    if(v->nb_ent == v->max_ent-1)
    {
        //... then we augment the capacity of the container with realloc
        v->max_ent = 3 * v->max_ent / 2;
        printf("max_ent is now : %d\n", v->max_ent);
        v->ent = realloc(v->ent,v->max_ent * sizeof(void *));
    }
    //Finally, the specified element is added at the end of the container
    v->ent[v->nb_ent] = e;
    v->nb_ent++;
}

///Returns the n-th element from the specified vector container
void *vector_get_entity_n(t_vector *v, int n)
{
    return v->ent[n];
}

///Returns the number of entities in the vector container
int vector_get_size(t_vector *v)
{
    return v->nb_ent;
}
