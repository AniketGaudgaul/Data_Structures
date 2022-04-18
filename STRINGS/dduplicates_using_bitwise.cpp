#include <iostream>
using namespace std;

int main(){


    // errors 
    char a[] = "finding";
    long int H=0, x=0;

    for (int i = 0; a[i]!='\0'; i++)
    {   

        x=1;
        // masking 
        x=x<<(a[i]-97);
        if(x&H>0){
           printf("%c",a[i]);
        }
        else{
            // merging 
            H = x|H;
        }
    }
    

    return 0;
}