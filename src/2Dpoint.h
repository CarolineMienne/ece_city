/***********************************
 
    point.h
 
    Interface pour le module
    de gestion de points du plan
    pour application de géométrie
 
************************************/
 
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
 
#include "utility.h"

/// Structure principale du module
 
typedef struct coordinates2D {
    int x;
    int y;
} t_2Dcoord;
 
 
/// Prototypes des sous-programmes
 
// Constructeur
t_2Dcoord * point_creer(int x, int y);
 
// Destructeur
void point_detruire(t_2Dcoord *coord);
 
// Constructeur par copie
t_2Dcoord * point_copier(t_2Dcoord *coord);
 
// Saisie de point
void point_saisir(t_2Dcoord *coord);
 
// Modification de point
void point_modifier(t_2Dcoord *coord, int x, int y);
 
// Affichage de point
void point_afficher(t_2Dcoord *coord);
 
// Translation selon le vecteur vx vy
// ( exemple de modification de l'objet )
void point_translater(t_2Dcoord *coord, int vx, int vy);
 
// Distance entre 2 points
// ( exemple de fonction qui utilise 2 instances )
double point_distance(t_2Dcoord *coord1, t_2Dcoord *coord2);
 
#endif // POINT_H_INCLUDED