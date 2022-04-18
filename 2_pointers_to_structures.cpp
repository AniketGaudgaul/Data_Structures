#include <iostream>
#include <stdlib.h>

using namespace std;

struct rectangle{

    int length;
    int breadth;

};

int main(){

    struct  rectangle r = {10,5};
    // in cpp u can also directly: rectangle r = {1,2}

    rectangle *p = &r;
    cout<<p->length<<endl;  // YOU CANNOT DIRECTLY P.LENGTH for structures ---- YOU HAVE TO - (p*).length
                            // INSTEAD USE P->length its convinient
    cout<<p->breadth<<endl;


    // CREATING A STRUCTURE IN HEAP

    // C
    rectangle *c;
    c = (struct rectangle *)malloc(sizeof(struct rectangle));

    cout<<c->length<<endl;
    cout<<c->breadth<<endl;

    // C++
    struct rectangle *cpp;
    cpp = new rectangle;

    return 0;
}