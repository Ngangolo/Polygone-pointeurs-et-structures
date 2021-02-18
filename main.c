#include <stdio.h>
#include <stdlib.h>
#include "polygone.h"

 polygone_t liste;

int main(int argc, char *argv[])  
 {   
     int choix, ch;
    
  do {  
          do {
           	  system("color 5f");
  	          printf("\n\n...... Menu de test des differentes parties.....\n");
     	      printf("\t1.  pour la premiere partie\n");
     	      printf("\t2.  pour la deuxieme partie\n");
     	      printf("\t3.  pour la troisieme partie\n");
     	      printf("\t4. pour Quiter!!\n");
     	      printf("\tFaites un choix:\n");
     	      scanf("\t%d",& choix);
          } while( choix<1 ||  choix>4 );
         
     switch(choix) 
	   {
	   	case 1:	 
	   	     {  
                liste= Polygone_Vide( );
                liste= Creer_Polygone(4);
                Afficher_Polygone(liste); 
		      }
	   	break;
	   	
	   	case 2:
	   		{ 
	   		   int a,rep,posit;
	   		   point_t* pt ;
               liste=Polygone_Vide( );
               do
	           {
	             printf("voulez vous ajouter des points au polygone?\n");
     	         printf("Taper 1 pour oui\n");
     	         printf("Taper 0 pour non\n");
     	         scanf("%d",&rep);
     	         if(rep==1)
     	          {
     	            pt= Saisie_Point( );	
     	            liste=Inserer_Fin(liste,pt );
     	            printf("point ajouter!!!\n\n");
		           }
		         else if(rep==0)
		         break;
               } while(rep!=0);
               printf("\n");
               printf("Affichage avant suppression\n");
               Afficher_Polygone(liste);
               a=Compte_Points(liste);
               printf("\n\nle nombre de point  est: %d\n",a);
               printf("Donner une position a supprimer\n");
               scanf("%d",&posit);
               printf("Effectuer avec succes!!!\n");
               Supprime_Point(liste, posit);
               printf("Affichage apres suppression\n");
               Afficher_Polygone(liste);
               Vider_Polygone(liste);
			 }
	   		  
	   	break;
	   	
	   	case 3:
	   		{  
	   		   int N,A;
	   		   point_t* pt;
	   		   printf("Donner le nombre de polynome a saisir\n");
               scanf("%d",&N);
               liste= Creer_Polygone(N);
               printf("Donner les coordonnees du point a verifier\n");
               pt= Saisie_Point( );
               A = Point_in_Perimetre_Polygone(pt,liste);
               if(A==1) 
               printf("Le point appartient au perimetre du polygone\n");
               else
               printf("Le point n'appartient pas au perimetre du polygone\n");
               Vider_Polygone(liste);
               
			}
           
	   	break;
	   	
	   	case 4:
	   		    printf("Programme terminer!!!!\n");
	   	break;
     	
     	default:
     		  printf("Faites un bon choix!!\n");
       	 
      }
      
     }while(choix!=4);
   
  	return 0;
  
}
