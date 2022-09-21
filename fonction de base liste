#include <stdio.h>
#include <stdlib.h>
struct liste_entier{
int val;
struct liste_entier *suivant;
};
typedef struct liste_entier liste;

liste *genere(int val)
{
    liste *p=NULL;
    p=(liste *)malloc(sizeof(liste));
    if(p==NULL) { exit(0); }
    p->val=val;
    p->suivant=NULL;
    return p;
}
liste *liee(liste*a,liste*p)
{
    liste *s=a;
    while(a->suivant!=NULL)
    {
        a=(a->suivant);
    }
    (a->suivant)=p;

    return s;
}
void libere(liste*p)
{   liste *rece=p;
    p=p->suivant;
    free(p);
}
void affiche(liste *p,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
     printf("%d\t",p->val);
     p=p->suivant;
 }
}
int main()
{
 int val=0,i,m=0;
 liste *p=NULL;
 do{
    printf("combien d'elements allez-vous entrer?");
    scanf("%d",&val);
   }while(val<=0);
   printf("\n entrer les elements de votre liste!!!");
   scanf("%d",&m);
   p=genere(m);
  for(i=0;i<val-1;i++)
  {
   scanf("%d",&m);
   p=liee(p,genere(m));
  }

  printf("\nla liste obtenu est:\n");
  affiche(p,val);
   libere(p);
   return 0;
}
