#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
} Node; 

typedef struct _list{
    int size;
    Node* head;
    Node* tail;
} LinkedList;

void list_init(LinkedList* l)
{
    l->size =0;
    l->head = NULL;
    l->tail = NULL;
}


void list_insert(LinkedList* l, int val)
{   
    scanf("%d",val);
    Node *p = (Node*)malloc(sizeof(Node));
    p->value = val;
    p->next = NULL;
    Node *tail = l->head;
    if (tail){
        while (tail->next){
            tail = tail->next;
        }
        tail->next =p;
    }else{
        l->head = p;
    }
    l->size+=1;
}

void list_clear(LinkedList* l)
{
    Node *p = (Node*)malloc(sizeof(Node));
    Node *q;
    for (p=l->head;p;p=q){
        q = p->next;
        free(p);
    }
    l->size=0;
}
/*
Node* list_remove(LinkedList* l, Node* target)
{
    Node *q;
    Node *p;
    for (q=NULL, p =l->head; p; q=p,p=p->next){
        if(p->value==target){
            if (q){
            q->next = p->next;
        }else{
            l->head = p->next;
        }
        free(p);
        break;
        }
    }
    l->size-=1;
    return NULL;
}*/

int main(){
    LinkedList l;
    list_clear(&l);
}
