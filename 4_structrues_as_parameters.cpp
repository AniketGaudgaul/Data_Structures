#include <iostream>
using namespace std;

struct rectangle{
    int length;
    int breadth;
};

// CALL BY VALUE :

void func1(struct rectangle r1){
    // any changes made here wont reflect on the original one 
    cout<<"Length "<<r1.length<<endl<<"breadth "<<r1.breadth<<endl;
}

// CALL BY ADDRESS :

//any changes made here will reflect in the original one
void func2(struct rectangle *p){
    p->breadth = 5;
    cout<<"Length "<<p->length<<endl<<"breadth "<<p->breadth<<endl;
}

// CREATING AN STRUCTURE IN HEAP USING FUNCTION WHICH RETURNS A POINTER.

struct rectangle * func3(){
    struct rectangle *p;
    p = new rectangle; // CPP STYLE OF CREATING IN HEAP 
    // p = (struct rectangle *)malloc(sizeof(struct rectangle)); // C STYLE OF CREATING IN HEAP 

    p->length=15;
    p->breadth=11;

    return p;

}

int main(){

    struct rectangle r ={10,2};
    func1(r);
    func2(&r);
    struct rectangle *ptr = func3();

    cout<<"Length "<< ptr->length<<endl<<"Breadth "<<ptr->breadth<<endl;
    return 0;
}