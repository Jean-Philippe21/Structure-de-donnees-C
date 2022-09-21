#include <stdio.h>
#include <stdlib.h>

struct noeud_s{
int val;
struct noeud_s*gauche;
struct noeud_s*droite;
};
typedef struct noeud_s *arbre_t;

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
void parcours(arbre_t arbre,int v,arbre_t c)
{  
   arbre_t s=NULL;
    if(arbre!=NULL)
     { if(c->gauche!=NULL)
        {
           if(c->gauche->val==v)
            {
              if(arbre->gauche==NULL && arbre->droite==NULL && arbre->val==v)
               {
                 free(arbre);
                 s=c;
                 s->gauche=NULL;
                    return;
               }
            }
        }
        if(c->droite!=NULL)
        {
         if(c->droite->val==v)
          {
              if(arbre->gauche==NULL && arbre->droite==NULL && arbre->val==v)
               {
                 free(arbre);
                 s=c;
                 s->droite=NULL;
                    return;
               }
          }
        }
               s=arbre;
           parcours(arbre->gauche,v,s);
           parcours(arbre->droite,v,s);
       }
}

void parcours1(arbre_t arbre,int v,arbre_t c)
{
    if(arbre!=NULL)
     { if(c->gauche!=NULL)
        {
           if(c->gauche->val==v)
            {
              if((arbre->gauche==NULL || arbre->droite==NULL) && arbre->val==v)
               {
                  arbre_t b=NULL;
                 if(arbre->gauche==NULL)
                 {
                     b=arbre->droite;
                     free(arbre);
                     c->gauche=b;
                     return;
                 }
                  b=arbre->gauche; 
                 free(arbre);
                 c->gauche=b;
                 return;

               }
            }
        }


        if(c->droite!=NULL)
        {
         if(c->droite->val==v)
          {
              if((arbre->gauche==NULL || arbre->droite==NULL) && arbre->val==v)
               {
                   arbre_t b=NULL;
                   if(arbre->gauche==NULL)
                   {
                       b=arbre->droite;
                       free(arbre);
                       c->droite=b;
                       return;
                   }
                  b=arbre->gauche; 
                 free(arbre);
                 c->droite=b;
                    return;
               }
          }
        }

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

arbre_t trouve_noeud(arbre_t arbre,int valeur)
{
   if(arbre==NULL)
      return NULL;
   if(valeur==arbre->val)
      return arbre;
   if(valeur<arbre->val)
      return trouve_noeud(arbre->gauche,valeur);
   else
      return trouve_noeud(arbre->droite,valeur);
}

arbre_t trouve_pere(arbre_t arbre,int valeur)
{
  arbre_t p=NULL;
 p=trouve_noeud(arbre,valeur);
  if(p==NULL)
   {
    printf("\nElement inexistant!!");
    return NULL;
   }
   else
   {
     if(arbre==NULL)
       return NULL;

     if(arbre->val==valeur)
         return arbre;
     if((valeur==arbre->gauche->val) || (valeur==arbre->droite->val))
        return arbre;
     if(valeur< arbre->val)
        return trouve_pere(arbre->gauche,valeur);
     if(valeur> arbre->val)
        return trouve_pere(arbre->droite,valeur);
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
    int b=0,f=0,v=0;
    arbre_t a=NULL,sur=NULL;
    a=malloc(sizeof(arbre_t));
    if(a==NULL) exit(0);
    a->gauche=NULL;
    a->droite=NULL;
    a->val=0;
    arbre_t arbre=NULL;

     printf("\nEntrer les valeurs de votre arbre et -229 pour finir!!");

       do
       {
         scanf("%d",&b);
         if(b==-229) break;
         arbre=insertion(arbre,b);
       }while(b!=-229);
    sur=arbre;
    affiche(arbre);

    printf("\nVoulez-vous supprimer une feuille? si oui taper 1");
    scanf("%d",&f);

   if(f==1)
   {
    printf("\nEntrer la valeur de l'element a supprimer:");
    scanf("%d",&v);
    arbre=sur;
    parcours(arbre,v,a);
    printf("\nFinalemnt on a l'arbre:");
    affiche(arbre);
   }
    arbre=sur;

    a->gauche=NULL;
    a->droite=NULL;

    printf("\nQuelle pere voulez-vous supprimer?");
    scanf("%d",&f);
    a=trouve_pere(arbre,f);
    parcours1(trouve_noeud(arbre,f),f,a);

    affiche(arbre);
    arbre=sur;

    supprime(arbre);

    free(a);

    return 0;
}


