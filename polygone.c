#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polygone.h"

  //partie 1

 point_t * Saisie_Point( )
  {
	 point_t * point = (point_t *)malloc(sizeof(point_t));
	 printf("donner la valeur de x:\n");
	 scanf("%lf",&point->X);
	 printf("donner la valeur de y:\n");
	 scanf("%lf",&point->Y);

     return point;
  }


 void Affiche_Point(point_t pt)
  {
  	
  	 printf(" (%lf , %lf)",pt.X, pt.Y);
 	
  }
  

 polygone_t Polygone_Vide( )
  {
  	polygone_t poly = NULL;  
    return poly;
  }

  
 polygone_t Inserer_Debut(polygone_t* Poly , point_t*  Pt)
   {
  	
	 Polygone * nouveau_poly = ( Polygone *) malloc (sizeof ( struct Polygone)); 
     nouveau_poly->Pt=Pt;
     nouveau_poly->Suivant= NULL;
     nouveau_poly->Suivant=*Poly ;
     *Poly=   nouveau_poly;
    
    return *Poly;
   }
 
 
 polygone_t Creer_Polygone(int Nb_Pts)
   {
      polygone_t  liste;
      polygone_t  polg;
      int i;
      liste= Polygone_Vide();
   	  for(i=0; i<Nb_Pts; i++)
   	    {              
   	       polg=( Polygone*)malloc(sizeof( Polygone));
   	       polg->Pt=Saisie_Point();
   	       polg->Suivant=liste;
   	       liste= polg;
         }
       return  liste;
   }
        
        
 void Afficher_Polygone(polygone_t Poly)
   {
      Polygone* tmp =malloc(sizeof(Polygone));
      tmp = Poly;
      printf("(");
      if(tmp == NULL)
      printf("LISTE VIDE!!!!!!");
      while(tmp != NULL)
       {
        Affiche_Point(*(tmp->Pt));
        tmp = tmp->Suivant;
        if(tmp == NULL)
        continue;
        printf(",");
       }
       printf(")");
    }
  
  //partie 2


polygone_t Inserer_Fin(polygone_t Poly , point_t * Pt)
{
	polygone_t nouveau, q;
	nouveau= (polygone_t)malloc(sizeof(Polygone));
	 nouveau->Pt=Pt;
	  nouveau->Suivant=NULL;
	  if(Poly==NULL)Poly=nouveau;
	  else
	  {
	  	q=Poly;
	  	while( q->Suivant!=NULL)q=q->Suivant;
	  	 q->Suivant=nouveau;
	  }
	 return Poly;
}

 
 int Compte_Points(polygone_t Poly)
   {
   	  Polygone* tmp ;
      int nb = 0;
      if(Poly == NULL)
         nb=0; 
      else
	    {
      	  tmp=Poly;
          while(tmp!=NULL)
           {
            nb++;
            tmp =tmp->Suivant;
           }
	    }
     return nb;
   }


  void Supprime_Point(polygone_t  Poly , int position)
{
	polygone_t  tmp , aide;
    tmp=Poly;
	if(tmp==NULL)
	{
	  printf("\n");
	}
	else if(position==1){
     Poly=NULL;
	}
	else{
		int i=1;
	    	while(tmp!=NULL && i!= position){
	    	    aide=tmp;
		        tmp=tmp->Suivant;
		        i++;
			}
		   	aide->Suivant=tmp->Suivant;
	        free(tmp);
	        tmp=NULL;
	}    	
}


 void Vider_Polygone(polygone_t  Poly)
  {
		polygone_t  tmp ;
     	tmp=Poly;

	    	while(tmp!=NULL){
	    	(tmp)=tmp->Suivant;
	        free(tmp);
	        tmp=NULL;
			}
		Poly= Polygone_Vide( );
	}     	
	
	
 
  //partie 3 
 
 double Distance(point_t* Pt1 , point_t* Pt2)
 {
    return sqrt(pow((Pt2->Y - Pt1->Y),2) + pow((Pt2->X - Pt1->X),2));
}
 	 

 double Perimetre(polygone_t* Poly)
 {
 	double res=0;
 	Polygone* tmp =malloc(sizeof(Polygone));
 	Polygone* ptmp =malloc(sizeof(Polygone));
      tmp = *Poly;
      while(tmp != NULL)
       { 
        ptmp = tmp->Suivant;
        res += Distance(tmp->Pt , ptmp->Pt);
        tmp = ptmp;
       }
       return res;
 }
 

 int Point_in_Segment(point_t* Pt1 , point_t* Pt2 , point_t* Pt3)
 {
 		if( Distance( Pt2, Pt3)==Distance( Pt2, Pt1)+Distance( Pt1, Pt3)) 
             return 1;
         else
          return 0;
 }
 
   
   
 int Point_in_Perimetre_Polygone(point_t* Pt1 , polygone_t Poly)
 {
    int c;
    polygone_t tmp,ptmp;
    tmp = Poly;
    ptmp=tmp->Suivant;
       while(ptmp!= NULL)
       { 
         c=Point_in_Segment( Pt1 , tmp->Pt , ptmp->Pt);
         if(c==1)
           break;
         tmp=ptmp;
         ptmp = ptmp->Suivant;
          if(ptmp== NULL)
         c=Point_in_Segment( Pt1 , tmp->Pt , Poly->Pt);
       }
     return c;
  }


