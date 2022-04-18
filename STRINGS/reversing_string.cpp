#include <iostream>
using namespace std;

int main(){

    // METHOD 1: SWAP LAST AND FIRST 
    char s[] = "python";
    int j,i=0;

    for (i = 0; s[i] != '\0'; i++)
    {
        
    }
    j=i-1;
    for (i = 0; i<j; i++,j--)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    cout<<s;

    // METHOD 2 : COPY REVERSE OF STRING IN ANOTHER ARRAY AND THEN COPY BACK

    return 0;
}