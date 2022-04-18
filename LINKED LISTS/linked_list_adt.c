#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        RDisplay(p->next);
        printf("%d ",p->data);

    }
}

int count(struct Node *p){

    int count = 0;

    while (p!=0)
    {
        count++;
        p=p->next;
    }
    
    return count;

}

int sum(struct Node *p){

    int sum=0;

    while (p!=0)
    {
        sum+=p->data;
        p=p->next;
    }
    
    return sum;

}

int maximum(struct Node *p){

    int maxno=-32768; // THIS IS THE MINIMUM POSSIBLE VALUE USING 2 BYTES IE 16 BITS

    while (p!=0)
    {
        if(maxno<p->data){
            maxno = p->data;
        }
        p=p->next;
    }
    
    return maxno;

}

// REGULAR LINEAR SEARCH

// BINARY SEARCH CANNOT BE IMPLEMENTED AS WE CANT FIND THE MIDDLE OF THE LIST

struct Node * lsearch(struct Node *p,int key){

    while (p!=0)
    {
        if(p->data==key){
            return(p);
        }
    }

    return NULL;
    

}

// IMPROVISED LINEAR SEARCH , HERE WE USE MOVE TO HEAD

struct Node * lsearchMTH(struct Node *p,int key){

    struct Node *q= NULL; // q is for pointing to previous node

    while (p!=0)
    {
        if(p->data==key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }

        q=p;
        p=p->next;
    }

    return NULL;
    

}

// INSERTING IN A LINKED LIST

void insert(struct Node *p ,int pos, int x){

    struct Node *t;

    if(pos==0){

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;

    }

    else if(pos>0){

        p = first;

        for (int i = 0; i < pos-1&&p!=0; i++)
        {
            p=p->next; // Moving P to the previous node position
        }
        
        if(p){ // if p is true i.e if p != null

        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;

        }

    }

}

void sortedInsert(struct Node *p, int x){

    struct Node *t,*q=NULL;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{

        while (p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first){

            t->next = first;
            first = t;

        }
        else{

            t->next=q->next;
            q->next=t;

        }

    }

}

int delete(struct Node *p, int pos){

    struct Node *q=NULL;
    int x = -1;

    if(pos < 1 || pos > count(p)){
        return -1;
    }

    if(pos==1){

        q=first;
        x=first->data;
        first=first->next;
        free(q) ;
        return x;

    }

    else{
        for (int i = 0; i < pos-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
        
    }

}

int isSorted(struct Node *p){

    int x = -65536; // SMALLEST NUMBER FOR A 4 BYTE INTIGER

    while (p!=0)
    {
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
    
}

// REMOVES DUPLICATE FROM A SORTED LINKED LIST

void removeDuplicate(struct Node *p){

    struct Node *q=p->next;

    while (q!=NULL)
    {
        if(p->data!=q->data){

            p=q;
            q=q->next;

        }
        else{

            p->next=q->next;
            free(q);
            q=p->next;

        }
    }
    
}

// REVERSING A LINK LIST USING ARRAY , NOT PREFFERED
void Reverse1(struct Node *p){

    int *A;
    int i = 0;
    struct Node *q=p;

    A=(int *)malloc(sizeof(int)*count(p));

    while (q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;

    while (q!=NULL){

        q->data=A[i];
        q=q->next;
        i--;
    }
}

// REVERSING THE LINKS OF LIST INSTEAD CHANGING DATA

void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void concat(struct Node *p, struct Node *q){

    third = p;

    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;

}

void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;

    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;

        }
    }
    if(p)last->next=p;
    if(q)last->next=q;

}

int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *temp;
    int A[]={3,5,5,10,25};
    // int B[]={1,2,6,8,15};

    create(A,5);
    // create2(B,5);


    Display(first);
    // printf("\n\n");
    // Display(second);

    printf("\n\n");
    // printf("\nLength is %d\n",count(first));
    // printf("\nSum is %d\n",sum(first));
    // printf("\nMax is %d\n",maximum(first));
    // printf("\nSearch for 10 %u\n",lsearchMTH(first,10));
    // insert(first,3,9);
    // sortedInsert(first,9);
    // delete(first,4);
    // printf("is sorted : %d",isSorted(first));
    // removeDuplicate(first);
    // Reverse1(first);
    // Reverse2(first);
    // concat(first,second);
    // Merge(first,second);


    // Display(third);

    // This will make the linked list a loop
    // struct Node *t1,*t2;
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;

    //  printf("%d\n",isLoop(first));

    printf("\n\n");
    Display(first);

    // printf("\n\n");
    // Display(second);

    return 0;
}