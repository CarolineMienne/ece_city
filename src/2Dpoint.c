/***********************************
 
    point.c
 
    Implémentation pour le module
    de gestion de points du plan
    pour application de géométrie
    
    Copyright© Robin Fercoq
 
************************************/

#include <math.h>
 
#include "2Dpoint.h"
 
/// Constructeur
t_2Dcoord * point_creer(int x, int y)
{
    // Pointeur vers la nouvelle instance à créer
    t_2Dcoord *p;
 
    // Allocation de l'instance (UNE instance)
    p = (t_2Dcoord *)malloc(1*sizeof(t_2Dcoord));
 
    // Initialisation des attributs de l'instance
    /// INDISPENSABLE : tout initialiser
    /// (à 0 ou NULL ou "" en l'absence de paramètres...)
    point_modifier(p,x,y);
 
    // Retourner l'instance à l'appelant
    return p;
}
 
/// Destructeur
void point_detruire(t_2Dcoord *p)
{ 
    free(p);
}
 
/// Constructeur par copie
t_2Dcoord * point_copier(t_2Dcoord *p)
{
    // Pointeur vers la nouvelle instance duplicata
    t_2Dcoord *pdup;
 
 
    // Allouer duplicata : eviter de refaire usage de malloc
    // utiliser le constructeur déjà disponible...
    pdup = point_creer(p->x, p->y);
  
    // Retourner l'instance dupliquée à l'appelant
    return pdup;
}
 
/// Saisie de point
void point_saisir(t_2Dcoord *p)
{
    printf("Abscisse : ");
    scanf("%d", &p->x);
    printf("Ordonnee : ");
    scanf("%d", &p->y);
}
 
/// Modification de point
void point_modifier(t_2Dcoord *p, int x, int y)
{
    p->x = x;
    p->y = y;
}
 
/// Affichage de point
void point_afficher(t_2Dcoord *p)
{
    printf("(%d, %d)\n", p->x, p->y);
}
 
/// Translation selon le vecteur vx vy
/// ( exemple de modification de l'objet )
void point_translater(t_2Dcoord *p, int vx, int vy)
{
    p->x = p->x + vx;
    p->y = p->y + vy;
}

/// Distance entre 2 points
/// ( exemple de fonction qui utilise 2 instances )
double point_distance(t_2Dcoord *p1, t_2Dcoord *p2)
{
    // Coord. du vecteur p1 p2
    int vx, vy;
 
    // Calcul du vecteur p1 p2
    vx = p2->x - p1->x;
    vy = p2->y - p1->y;
 
    // Retourner la norme du vecteur
    return 1.0;//sqrt( vx*vx + vy*vy );
}