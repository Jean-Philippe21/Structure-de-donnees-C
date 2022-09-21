#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct joueur{
char nom[20];
char prenom[20];
int score;
             };
 typedef struct joueur joueur;

joueur* AllocationDynamyque(int taille)
{ joueur *tab=NULL;
  tab=malloc(taille*sizeof(joueur));
  if(tab==NULL) { exit(0); }
  if(tab!=NULL) {return tab;}
}
void initialisation(joueur *tab,int taille)
{ int i;
  for(i=0;i<taille;i++)
   {  printf("entrer le nom le prenom et le score du joueur %d \n",i);
      gets(tab[i].nom);
      gets(tab[i].prenom);
      scanf("%d",&(tab+i)->score);
      getchar();
   }
}
void AffichageInfos(joueur* tab,int taille)
{ int i;
  printf("le tableau donne finalement :\n");
  for(i=0;i<taille;i++)
  {  printf("le joueur %d,nom: %s ,prenom: %s ,score: %d \n",i,(tab+i)->nom,(tab+i)->prenom,(tab+i)->score);
  }
}
void AffichageGagnant(joueur* tab,int taille)
{int i,c=0;
  for(i=0;i<taille;i++)
  { if(((tab+i)->score)<=((tab+i+1)->score))
     c=((tab+i+1)->score);
  }
  printf("\nle(s) joueur(s) gagnant(s) son(t)\n:");
  for(i=0;i<taille;i++)
  { if(((tab+i)->score)==c)
    printf("le joueur:%s",((tab+i)->nom));
  }
}
int main()
{ int taille;
  printf("entrer le nombre(s) de joueur(s) : ");
  do{
      scanf("%d",&taille);getchar();
      if(taille<=0) { printf("entrer un nombre strictement positif!!\n");}
    }while(taille<=0);
  joueur *tab=NULL;
  tab=AllocationDynamyque(taille);
   initialisation(tab,taille);
   AffichageInfos(tab,taille);
   AffichageGagnant(tab,taille);
   free(tab);

  return 0;

}
