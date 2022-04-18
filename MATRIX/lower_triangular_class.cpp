 #include <iostream>
 using namespace std;
 
 class lower_tri
 {
 private:
     int n;
     int *A;
 public:
     lower_tri(int n);
     ~lower_tri();
     void set(int i, int j, int x);
     void display();
     int get(int i, int j);
     int getdim(){
         return n;
     };
 };
 
 lower_tri::lower_tri(int n)
 {  
     this->n=n;
     A = new int[n*(n+1)/2]; // ROW MAJOR
     // COLUMN MAJOR just replace formula by [n*(j-1)-(j-2)*(j-1)/2+i-j]
 }
 
 lower_tri::~lower_tri()
 {
     delete []A; 
 }

 void lower_tri::set(int i, int j, int x)
 {
     if(i>=j){
         A[i*(i-1)/2+j-1]=x;
     }
 }
 int lower_tri::get(int i, int j)
 {
     if(i>=j){
         return A[i*(i-1)/2+j-1];
     }
     else{
         return 0;
     }
 }
 void lower_tri::display(){
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= n; j++)
         {
             if(i>=j){
                 cout<<A[i*(i-1)/2+j-1]<<" ";
             }
             else{
                 cout<<"0"<<" ";
             }
         }
         cout<<endl;
         
     }
     
 }
 

 int main(){
 
     int d;
     cout<<"Enter Dimensions : ";
     cin>>d;

     lower_tri lm(d);

     int x;
     cout<<"Enter all elements : ";
     for (int i = 1; i <= d; i++)
     {
         for (int j = 1; j <= d; j++)
         {
             cin>>x;
             lm.set(i,j,x);
         }
         
     }

     lm.display();
     
 
     return 0;
 }