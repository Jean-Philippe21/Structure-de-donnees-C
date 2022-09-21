#include <stdio.h>
#include <stdlib.h>
struct noeud_s{
int val;
struct noeud_s*gauche;
struct noeud_s*droite;
};
typedef struct noeud_s *arbre_t;

struct Element
{
 arbre_t elem;
 struct Element *suivant;
};
typedef struct Element Element;

struct File
{
   Element*premier;
};
typedef struct File File;

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
void Defilage(File*f)
{
   Element*s=f->premier;
    f->premier=s->suivant;
    s->suivant=NULL;
   return;
}

void parcours(arbre_t arbre)
{
    File*f=initialise1();
    Element *e=NULL;
    e=malloc(sizeof(Element));
    if(e==NULL) exit(0);
    e->elem=arbre;
    e->suivant=NULL;
    Enfilage(f,e);

    while(f->premier!=NULL && arbre!=NULL)
    {

        if(f->premier->elem==NULL)
            return;

        printf("%d\t",f->premier->elem->val);
        Element*e1=malloc(sizeof(Element));
        if(e1==NULL) exit(0);
        
        e1->elem=f->premier->elem->gauche;
        e1->suivant=NULL;
        Enfilage(f,e1);
        Element*e2=malloc(sizeof(Element));
        if(e2==NULL) exit(0);
        
        e2->elem=f->premier->elem->droite;
        e2->suivant=NULL;
        Enfilage(f,e2);
        Defilage(f);
    }

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


arbre_t cree_arbre(int val,arbre_t gauche,arbre_t droite)
{
    arbre_t arbre=malloc(sizeof(struct noeud_s));
    if(arbre==NULL) exit(0);
    arbre->val=val;
    arbre->gauche=gauche;
    arbre->droite=droite;
    return arbre;
}
arbre_t insertion(arbre_t arbre,int val)
{
    if(arbre==NULL)
    {
        return cree_arbre(val,NULL,NULL);
    }
    else
    {
        if(val<arbre->val)
        {
            arbre->gauche=insertion(arbre->gauche,val);
        }

        else
        {
            arbre->droite=insertion(arbre->droite,val);
        }
        return arbre;
    }
}
void affiche(arbre_t arbre)
{
    if(arbre==NULL)
    {
        printf("_");
    }
    else
    {
        printf("{");
        affiche(arbre->gauche);
        printf(",%d,",arbre->val);
        affiche(arbre->droite);
        printf("}");
    }
}
void supprime(arbre_t arbre)
{
    if(arbre==NULL)
        return;
    supprime(arbre->gauche);
    supprime(arbre->droite);
    free(arbre);
    return ;
}


int main()
{
    int b=0;
    arbre_t sur=NULL;
    arbre_t arbre=NULL;

     printf("\nEntrer les valeurs de votre arbre et -229 pour finir!!");

       do
       {
         scanf("%d",&b);
         if(b==-229) break;
         arbre=insertion(arbre,b);
       }while(b!=-229);
    sur=arbre;
    printf("\nL'arbre est :");
    affiche(arbre);
    arbre=sur;
    printf("\nVoici l'argorithme de parcour en largeur!!");

    parcours(arbre);

  return 0;
}



