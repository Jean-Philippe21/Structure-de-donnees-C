#include <stdio.h>
#include <stdlib.h>
struct list_entier{
int val;
struct list_entier*suivant;
};
struct list_entier*elem_new(int val)
{
 struct list_entier*p=NULL;
 p=(struct list_entier*)malloc(sizeof(struct list_entier));
 if(p==NULL) {exit(0);}
 p->val=val;
 p->suivant=NULL;
 return p;
}
struct list_entier *list_append(struct list_entier *L,int val)
{
  if(L==NULL)
  {
    L=elem_new(val);
    return L;
  }
  else{
  struct list_entier *u=NULL;
  u=elem_new(val);

  struct list_entier *s=NULL;
  s=L;
  while(L->suivant!=NULL)
  {
    L=L->suivant;
  }
  L->suivant=u;
  return s;
      }
}
struct list_entier *list_push(struct list_entier*L,int val)
{
 if(L==NULL)
 {
   L=elem_new(val);
   return L;
 }
 else{
 struct list_entier*u=NULL;
 u=elem_new(val);
 u->suivant=L;
 return u;
     }
}
void insert(struct list_entier*L,int val1,int val)
{
    while(L->val!=val1)
    {
        L=L->suivant;
    }
    if(L->suivant==NULL)
     {
      struct list_entier*o=NULL;
      o=list_append(L,val);
     }
    struct list_entier*u=NULL;
    u=elem_new(val);
    u->suivant=L->suivant;
    L->suivant=u;
}
int taille_list(struct list_entier*L)
{
 int len=0;
 if(L==NULL) {printf("\t la liste est vide!!!"); }
 while(L->suivant!=NULL)
 {
     L=L->suivant;
     len++;
 }
 len++;
 return len;
}
void supprime(struct list_entier*L,int val1)
{
    while(L->val!=val1)
    {
        L=L->suivant;
    }
    if(L->suivant->suivant==NULL)
    {
      free(L->suivant);
      L->suivant=NULL;
    }
    else
     {
      struct list_entier*u=NULL;
      u=L->suivant->suivant;
      free(L->suivant);
      L->suivant=u;
     }
}
void list_print(struct list_entier*L)
{   if(L==NULL) { printf("\n la liste est vide!!");  }
    while(L->suivant!=NULL)
    {
        printf("\t%d",L->val);
        L=L->suivant;
    }
}
void libere(struct list_entier*L)
{ while(L!=NULL)
   {
     struct list_entier*rece=L;
     L=L->suivant;
     free(rece);
   }

}
int main()
{
    int val=0,val1=0,v=0,t=0,i=0;
    struct list_entier *L1=NULL,*L=NULL;
    printf("Quelle est la taille de votre liste?\t");
    scanf("%d",&t);
    printf("\nEntrer la premiere valeur de la liste:\t");
    scanf("%d",&val);
    L1=elem_new(val);
    printf("\n Entrer 1 pour completer en fin de liste ou 0 pour completer en debut de liste:\t");
    scanf("%d",&v);
    printf("\nEntrer les valeurs de la liste:\t");
    if(v==1)
    {   while(i!=t)
        {   scanf("%d",&val);
            L=list_append(L1,val);
            i++;
        }
    }
    else
    {  while(i!=t)
        {   scanf("%d",&val);
            L=list_push(L1,val);
            L1=L;
            i++;
        }

    }
    printf("\nla liste obtenu est:");
    list_print(L);
    printf("\nPour inserer un element entrer 2");
    scanf("%d",&v);
    if(v==2)
    { printf("\nApres quelle element voulez-vous inserez?");
      scanf("%d",&val1);
      printf("\nEntrer l'element a inserer:\t");
      scanf("%d",&val);
      insert(L,val1,val);
      printf("\nOn a maintenant:");
    list_print(L);
    }
    printf("\nEntrer 3 pour supprimer un element");
    scanf("%d",&v);
    if(v==3)
    { printf("\nApres quelle element voulez-vous supprimer?");
      scanf("%d",&val1);
      if(L->val==val1)
      { printf("\nVous voulez donc supprimer le premier element!!");
      L1=L->suivant;
      free(L);
      L=L1;
      }
      else{
        supprime(L,val1);
      }
     printf("\n\n Finalement on obtient:\n");
     list_print(L);
    }

    libere(L);

    return 0;

}

