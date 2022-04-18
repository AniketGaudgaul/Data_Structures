#include <iostream>
using namespace std;

int main(){

    // ANAGRAM - STRING USING SAME ALPHABETS BUT DIFFERENT WORDS eg- decimal and medical
    // they should have same number of alphabets

    char A[] = "decimal";
    char B[] = "medical";

    int i;
    int H[26]={0};

    for ( i = 0; A[i] != '\0'; i++)
    {
        H[A[i]-97]++;
    }
    for ( i = 0; B[i] != '\0'; i++)
    {
        H[B[i]-97]--;
        if(H[B[i]-97]<0){
            cout<<"not anagram";
            break;
        }
    }
    if(B[i]=='\0'){
    cout<<"Anagram";

    }
    

    return 0;
}