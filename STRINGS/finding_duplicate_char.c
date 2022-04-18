#include <stdio.h>
// using namespace std;

int main(){

    char s[] = "boilerplatecode";
    int hashtable[26] = {0};

    int i;

    // SUBTRACTING 97 AS ARRAY H WILL BE OF SIZE 26 INSTEAD OF UNNECESARY 107..
    for ( i = 0; s[i]!='\0'; i++)
    {
        hashtable[s[i]-97]+=1;
    }
    for ( i = 0; i<26; i++)
    {   

        if(hashtable[i]>1){
            printf("%c\n",i+97);
        };
    }
    

    return 0;
}