#include <iostream>
using namespace std;


struct matrix{
    int *A;
    int n; 
};

void set(struct matrix *m, int i, int j, int x){

    // ROW MAJOR REPRESENTATION
    if(i>=j){
        m->A[i*(i-1)/2+j-1] = x;
    }

    // COLUMN MAJOR REPRESENTATION
    // if(i>=j){
    //     m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
    // }
}
int get(struct matrix m, int i, int j){

    if(i<=j){
        return m.A[i*(i-1)/2+j-1];

    }

    // COLUMN MAJOR

    // if(i<=j){
    //     return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];

    // }
    else{
        return 0;
    }

}

void display(struct matrix m){
    int i,j;
    for ( i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if(i>=j){
                cout<<m.A[i*(i-1)/2+j-1]<<" ";
            }

            // COLUMN MAJOR
            // if(i>=j){
            //     cout<<m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]<<" ";
            // }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
    
}

int main(){

    int i,j,x;

    struct matrix m;
    cout<<"Enter Dimension : ";
    cin>>m.n;

    m.A= new int[m.n];

    cout<<"Enter all elements : ";
    for ( i = 1; i <=m.n; i++)
    {
        for ( j = 1; j <=m.n; j++)
        {
            cin>>x;
            set(&m,i,j,x);
        }
        
    }

    cout<<endl<<endl;
    display(m);
    

    return 0;
}