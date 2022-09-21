#include <stdio.h>
#include <stdlib.h>
struct Element
{
 int val;
 struct Element *suivant;
};
typedef struct Element Element;

struct pile
{
  Element*sommet;
};
typedef struct pile pile;

struct File
{
   Element*premier;
};
typedef struct File File;

pile*initialise(void)
{
    pile*p=malloc(sizeof(pile));
    if(p==NULL) exit(0);
    p->sommet=NULL;
    return p;
}
void Empilage(pile*p,Element*e)
{
    if(p==NULL || e==NULL)
    {
        exit(0);
    }
  e->suivant=p->sommet;
  p->sommet=e;

}
Element* Depilage(pile*p)
{
  Element*s=p->sommet;
  p->sommet=p->sommet->suivant;
  s->suivant=NULL;
  return s;
}
void affichage(pile*p)
{
 // coucou Element*s1=p->sommet;
 Element*s=p->sommet;
 printf("\nla pile obtenu est: ");
 while(s!=NULL)
 {
   printf("%d\t",s->val);
   s=s->suivant;
 }
 // coucou p->sommet=s1;
}
File*initialise1(void)
{
    File*f=malloc(sizeof(File));
    if(f==NULL) exit(0);
    f->premier=NULL;
    return f;
}
void Enfilage(File*f,Element*e)
{
  if(f->premier==NULL)
  {
     e->suivant=NULL;
     f->premier=e;
  }
  else
  { Element*s=f->premier;
    while(s->suivant!=NULL)
    {
      s=s->suivant;
    }
    e->suivant=NULL;
    s->suivant=e;
  }
}
Element* Defilage(File*f)
{
   Element*s=f->premier;
    f->premier=s->suivant;
    s->suivant=NULL;
   return s;
}
void affiche1(File*f)
{
  Element*s=f->premier;
  while(s!=NULL)
  {
      printf("%d\t",s->val);
      s=s->suivant;
  }

}
int NombreElement(pile*p)
{
   int n=0;
   // coucou Element*s1=p->sommet;
   Element*s=p->sommet;
 while(s!=NULL)
 {
   s=s->suivant;
   n++;
 }
 printf("\n\nLA LA TAILLE EST %d",n);
 // coucou p->sommet=s1;
 return n;
}
int NombreElement1(File*f)
{
   int n=0;
   Element*s=f->premier;
 while(s->suivant!=NULL)
 {
   s=s->suivant;
   n++;
 }
 return n;
}
void invertion(pile*p)
{
   int v=NombreElement(p);
   int v1=v;
   Element*s=p->sommet;
   Element*e=NULL;
   e=malloc(sizeof(Element));
   if(e==NULL) exit(0);
   File*f=NULL;
   f=initialise1();
   while(v!=0)
    {
     e=Depilage(p);
     Enfilage(f,e);
     v--;
    }
   while(v1!=0)
    {
     e=Defilage(f);
     Empilage(p,e);
     v1--;
    }

}
int main()
{
  int v1=0,v2=0,v3=0,i;
  pile*p=NULL;
  File*f=NULL;
  printf("Entrer 1 pour entrer un pile et 0 pour une file:");
  scanf("%d",&v1);
  if(v1==1)
  {
    p=initialise();
    printf("\nEntrer les elements de la pile");
    printf("\nEntrer 5 pour la fin de la pile");


    while(v2!=5)
    {
        Element *e=NULL;
        e=malloc(sizeof(Element));
        if(e==NULL) exit(0);
        scanf("%d",&v2);
        if(v2==5) {break;}
        e->val=v2;
        e->suivant=NULL;
        Empilage(p,e);
       // printf("coucou");
    }
    affichage(p);
    printf("\nVoulez-vous depiler? Si oui taper 1");
    scanf("%d",&v3);
    if(v3==1)
    {
        printf("\nCombien d'element voulez-vous depiler?");
        scanf("%d",&v2);
        while(v2!=0)
        {
            Depilage(p);
            v2--;
        }
    }
    printf("\nOn a finalement:");
    affichage(p);
    printf("\nEntrer 3 pour inverser votre pile");
    scanf("%d",&v2);
    if(v2==3)
    {
        invertion(p);
        printf("\nApres invertion on a:");
        affichage(p);
    }
  }
  if(v1==0)
  {
    f=initialise1();
    printf("\nEntrer les elements de la file");
    printf("\nEntrer -229 pour la fin de la file");

    while(v2!=-229)
    {
        Element*e=NULL;
        e=malloc(sizeof(Element));
        if(e==NULL) exit(0);
        scanf("%d",&v2);
        if(v2==-229) {break;}
        e->val=v2;
        Enfilage(f,e);
    }
    affiche1(f);
    printf("\nVoulez-vous defiler? Si oui taper 1");
    scanf("%d",&v3);
    if(v3==1)
    {
        printf("\nCombien d'element voulez-vous defiler?");
        scanf("%d",&v2);
        Element *e1=NULL;
        while(v2!=0)
        {
            e1=Defilage(f);
            v2--;
        }
    }
    printf("\nOn a finalement:");
    affiche1(f);
  }

  return 0;
}


