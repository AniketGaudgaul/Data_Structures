#include <iostream>
using namespace std;

int * func(int size){ //int * means return type is a pointer (array), also can be written as int []
    int *p;
    p = new int[size]; // ARRAY IS CREATED IN HEAP, USING POINTER, DYNAMIC MEMORY

    for(int i=0; i<size;i++)
    p[i] = i+1;
    return p;
}

int main(){

    int *ptr, size=5;

    ptr = func(size);

    for (int i = 0; i < size; i++)
    {
        /* code */
        cout<<ptr[i]<<endl;
    }
    

    return 0;
}