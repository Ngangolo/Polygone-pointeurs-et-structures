#ifndef _POLYGONE_H
#define _POLYGONE_H

typedef struct point  
 {
  double X,Y;  
 } point_t;

 typedef struct Polygone * polygone_t;
 
typedef struct Polygone
 {
  point_t * Pt;
  polygone_t Suivant;
 } Polygone;
  
// Partie 1
point_t * Saisie_Point( );
void Affiche_Point(point_t pt);
polygone_t Polygone_Vide( );
polygone_t Inserer_Debut(polygone_t* Poly , point_t* Pt);
polygone_t Creer_Polygone(int Nb_Pts);
void Afficher_Polygone(polygone_t Poly);
// Partie 2
polygone_t Inserer_Fin(polygone_t  Poly , point_t * Pt);
int Compte_Points(polygone_t Poly);
void Supprime_Point(polygone_t Poly , int position);
void Vider_Polygone(polygone_t Poly);
// Partie 3
double Distance(point_t* Pt1 , point_t* Pt2);
double Perimetre(polygone_t* Poly);
int Point_in_Segment(point_t* Pt1 , point_t* Pt2 , point_t* Pt3);
int Point_in_Perimetre_Polygone(point_t* Pt1 , polygone_t Poly);

#endif

//systeme utiliser windows 10
//environnement de dévéloppement Dev c++

