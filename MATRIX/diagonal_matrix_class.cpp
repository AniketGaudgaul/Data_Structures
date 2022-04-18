 #include <iostream>
 using namespace std;
 
 class diagonal
 {
 private:
     int n;
     int *A;
 public:
     diagonal(int n);
     ~diagonal();
     void set(int i, int j, int x);
     void display();
     int get(int i, int j);
 };
 
 diagonal::diagonal(int n)
 {  
     this->n=n;
     A = new int[n];
 }
 
 diagonal::~diagonal()
 {
     delete []A; 
 }

 void diagonal::set(int i, int j, int x)
 {
     if(i==j){
         A[i-1]=x;
     }
 }
 int diagonal::get(int i, int j)
 {
     if(i==j){
         return A[i-1];
     }
     else{
         return 0;
     }
 }
 void diagonal::display(){
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             if(i==j){
                 cout<<A[i]<<" ";
             }
             else{
                 cout<<"0"<<" ";
             }
         }
         cout<<endl;
         
     }
     
 }
 

 int main(){
 
     diagonal mat(5);
     mat.set(1,1,1);
     mat.set(2,2,2);
     mat.set(3,3,3);
     mat.set(4,4,4);
     mat.set(5,5,5);

     mat.display();
 
     return 0;
 }