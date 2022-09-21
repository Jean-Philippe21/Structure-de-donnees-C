#include <stdio.h>
#include <stdlib.h>
 struct node{
 int data;
 struct node *p_next;
 struct node *p_prev;
            };
 typedef struct dlist{
 int length;
 struct node *p_tail;
 struct node *p_head;
                     }Dlist;
Dlist *dlist_new(void)
{ Dlist * p_new;
  p_new = malloc(sizeof (*p_new));
  if (p_new != NULL)
    { p_new->length =0;
      p_new->p_head = NULL;
      p_new->p_tail = NULL;
    }
  return p_new;
}
Dlist *dlist_append(Dlist *p_list,int data)
{ if(p_list!= NULL)
   {struct node *p_new = malloc(sizeof *p_new);
    if(p_new!=NULL)
     { if(p_list->p_tail==NULL)
        {p_new->data=data;
         p_new->p_next=NULL;
         p_new->p_prev=NULL;
         p_list->p_head=p_new;
         p_list->p_tail=p_new;
        }
       else
        { p_new->data=data;
          p_new->p_next = NULL;
          p_list->p_tail->p_next=p_new;
          p_new->p_prev=p_list->p_tail;
          p_list->p_tail=p_new;
        }
        p_list->length++;
    }
      }
      return p_list;
}
 Dlist *dlist_remove(Dlist *p_list,int data)
 { if(p_list!=NULL)
    { struct node *p_temp;
       p_temp=p_list->p_head;
       int found=0;
       while(p_temp!=NULL&&found==0)
        { if(p_temp->data==data)
           { if(p_temp->p_next==NULL)//le dernier element
               { p_list->p_tail=p_temp->p_prev;
                 p_list->p_tail->p_next=NULL;
               }
             else if(p_temp->p_prev==NULL)
              {p_list->p_head=p_temp->p_next;
             p_list->p_head->p_prev = NULL;
              }
        else
        {p_temp->p_next->p_prev=p_temp->p_prev;
         p_temp->p_prev->p_next=p_temp->p_next;
        }
    free(p_temp);
    p_list->length--;
    found = 1;
}
else
{p_temp=p_temp->p_next;}
}
}
return p_list;
}

void dlist_delete(Dlist **p_list)
{ if(*p_list!=NULL)
{ struct node *p_temp=(*p_list)->p_head, *p_del;
  while(p_temp!=NULL)
    { p_del=p_temp;
      p_temp=p_temp->p_next;
      free(p_del);
    }
    free(*p_list);
    *p_list=NULL;
}
}
void *affiche(Dlist *p_list)
{
 struct node *p=p_list->p_head;
 int t=p_list->length;
 while(t!=0)
 {
     printf("\n%d",p->data);
     p=p->p_next;
     t--;
 }
}
int main()
{
    int i,e=0,val=0,wi=0,val1=0;
    Dlist *p_new=dlist_new();
    printf("combien d'elements voulez vous?");
    scanf("%d",&e);
    Dlist *p_list=NULL;
    for(i=0;i<e;i++)
    {
     printf("entrer d'element %d\t",i+1);
     scanf("%d",&val);
     p_list=dlist_append(p_new,val);
    }
    printf("\n la liste obtenu est:\n");
    affiche(p_list);
    printf("voulez-vous supprimer un element? si oui entrer 1 si non entrer 0\t");
    scanf("%d",&wi);
    if(wi)
     {  printf("\nlequelle?\t");
        scanf("%d",&val1);
         p_list=dlist_remove(p_list,val1);

     printf("\n            finalement on a               ");
     affiche(p_list);
     }
    return 0;
}
