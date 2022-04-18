#include <iostream>
using namespace std;

void function(int x[], int n){  
    // ARRAYS ARE ALWAYS PASSED BY ADDRESS
    // x is pointer to an array
    // YOU CAN ALSO PASS AN POINTER LIKE int *x

    // here size of x is size of pointer and not array
    // cout<<sizeof(x)/sizeof(int)<<endl;


    // YOU CANNOT ACCESS THIS. you need regular for loop

    //  for(int a:x){ 
    //     cout<<a<<endl;
    // }

    for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<endl;
    }

}

int main(){

    int A[] = {2,3,4,5,6,7,8};
    int n=6;

    function(A,n);

    for(int x:A){ //this syntax is like python range
        cout<<x<<endl;
    }
    return 0;
}