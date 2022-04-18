#include <iostream>
#include <stdlib.h> // for malloc function which is for C language

using namespace std;

int main(){

    // int a = 10;
    // int *p;
    // p = &a;

    // printf("%d",*p);

    // POINTER TO AN ARRAY

    int a[5] = {2,4,5,6,3};
    int *p;

    p = a; //NO NEED TO USE '&' FOR ADDRESS OF ARRAY AS THE ARRAY NAME 'a' ITSELF IS AN ADDRESS
    // OR YOU CAN WRITE"
    // p = &a[0];

    for (int i=0; i < 5; i++)
    {
        cout<<a[i]<<endl;
        cout<<p[i]<<endl; // Pointer acts as name of an array
    }

    // CREATING AN ARRAY IN THE HEAP MEMORY .... (DYNAMIC MEMORY)
    // C method

    int *h;
    h = (int *)malloc(5*sizeof(int)); // (int *) is for typcasting the pointer to return int
                                      // malloc function is used to allocate memory space in heap
                                      // here 5*int size memory is allocated
    h[0] = 10;
    h[1] = 20;
    h[2] = 30;
    h[3] = 40;
    h[4] = 50;

    for (int i=0; i < 5; i++)
    {
        cout<<h[i]<<endl;
    }

    // C++ method for heap 

    int *cpp;
    cpp = new int[5]; // THIS IS DYNAMIC ALLOCATION

    // DYNAMIC MEMORY NEEDS TO BE DE ALLOCATED THE MEMORY

    // FOR CPP :

    delete [ ] cpp;

    // FOR C :

    free(h);

    // SIZE OF POINTERS

    int p1;
    float p2;
    char p3;
    double p4;
    //or even structure pointer

    cout<<sizeof(p1)<<endl;  // in latest compilers each type of pointer takes 8 bits same
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;

    return 0;
}