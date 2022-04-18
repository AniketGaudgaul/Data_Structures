#include <iostream>
using namespace std;

class Array{

    private:
        int *A;
        int size;
        int length;

    public:
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }    
        Array(int sz){
            size = sz;
            length = 0;
            A = new int[size];
        }    
        ~Array(){
            delete []A;
        }

        void display(){
            for (int i = 0; i < length; i++)
            {
                cout<<A[i]<<" ";
            }
            
        }

        void append(int x){
            if(length<size){
                A[length] = x;
                length++;
            }
        }

        void insert(int x, int index){
            if(index>=0&&index<length){
                for (int i = length; i > index; i--)
                {
                    A[i] = A[i-1];
                }
                A[index] = x;
                length++;
            }           
        } 

        void Delete(int index){
            if(index>=0&&index<length){
                for (int i = index; i < length-1; i++)
                {
                    A[i] = A[i+1];
                }
                length--;
            }           
        }

        void swap(int *x, int *y){

            int temp = *x;
            *x = *y;
            *y = temp;

        }   

        bool linearsearch(int key){
            for (int i = 0; i < length; i++)
            {
                if(A[i]==key){
                    true;
                }
            }
            return false;
            
        }

        // ONLY WORKS FOR SORTED ARRAY
        bool binarysearch(int key){

            int h,l,mid;

            h = length-1;
            l=0;
            
            while(l<=h){
                mid = (l+h)/2;
                if(A[mid]==key){
                    return mid;
                }
                else if(key<A[mid]){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            return -1;

        } 

        int Get(int index)
        {
            if(index>=0 && index<length)
            return A[index];
            return -1;
        }

        void Set(int index,int x)
        {
            if(index>=0 && index< length)
            A[index]=x;
        }

        int Max()
        {
            int max=A[0];
            int i;
            for(i=1;i<length;i++)
            {
            if(A[i]>max)
            max=A[i];
            }
            return max;
        }

        int Min()
        {
            int min=A[0];
            int i;
            for(i=1;i<length;i++){
                if(A[i]<min)
                min=A[i];
            }
            return min;
        }
        int Sum()
        {
            int s=0;
            int i;
            for(i=0;i<length;i++){
                s+=A[i];
            }

            return s;
        }

        float Avg()
        {
            return (float)Sum()/length;
        }

        void reverse(){
            int i,j;
            int *B = new int[length]; 

            for ( i = length-1,  j = 0; i >= 0; i--,j++)
            {
                B[j] = A[i];
            }

            for (int i = 0; i < length; i++)
            {
                A[i] = B[i];
            }
                        
        }

        void reverse2(){int i,j;

            for ( i = length-1,  j = 0; i >= 0; i--,j++)
            {
                swap(&A[i],&A[j]);
            }

        }

        void InsertSort(int x)
        {
            int i= length-1;
            if( length== size){

                return;
            }
            while(i>=0 && A[i]>x)
            {
                A[i+1]= A[i];
                i--;
            }
            A[i+1]=x;
            length++;
        }

        int isSorted()
        {
            int i;
            for(i=0;i<length-1;i++)
            {
                if(A[i]>A[i+1])
                return 0;
            }
            return 1;
        }

        void Rearrange()
        {
            int i,j;
            i=0;
            j= length-1;
            while(i<j)
            {
                while( A[i]<0)i++;
                while( A[j]>=0)j--;
                if(i<j)swap(& A[i],& A[j]);
            }
        }

        Array * merge(Array arr2){

            int i,j,k;
            i=j=k=0;

            Array *arr3 = new Array(length+arr2.length);

            while (i<length && j<arr2.length)
            {
                if(A[i]<arr2.A[j]){
                    arr3->A[k++]=A[i++];
                }
                else{
                    arr3->A[k++]=arr2.A[j++];
                }
            }
            for(i;i<length;i++){
                arr3->A[k++] = A[i];
            }
            for(j;j<length;j++){
                arr3->A[k++] = A[j];
            }
            arr3->length=length+arr2.length;

            return arr3;

        }

        Array* Union(Array arr2)
        {
            int i,j,k;
            i=j=k=0;
            Array *arr3=new Array(length+arr2.length);
            while(i<length && j<arr2.length)
            {
                if(A[i]<arr2.A[j]){

                    arr3->A[k++]=A[i++];
                }
                else if(arr2.A[j]<A[i]){

                    arr3->A[k++]=arr2.A[j++];
                }
                else
                {
                    arr3->A[k++]=A[i++];
                    j++;
                }
            }
            for(;i<length;i++)
                arr3->A[k++]=A[i];
            for(;j<arr2.length;j++)
                arr3->A[k++]=arr2.A[j];

            arr3->length=k;
            return arr3;
        }

        Array* Inter(Array arr2)
        {
            int i,j,k;
            i=j=k=0;
            Array *arr3=new Array(length+arr2.length);
            while(i<length && j<arr2.length)
            {
                if(A[i]<arr2.A[j]){

                    i++;
                }
                else if(arr2.A[j]<A[i]){

                    j++;
                }
                else if(A[i]==arr2.A[j])
                {
                    arr3->A[k++]=A[i++];
                    j++;
                }
            }
            arr3->length=k;
            return arr3;
        }

        Array* Diff(Array arr2)
        {
            int i,j,k;
            i=j=k=0;
            Array *arr3=new Array(length+arr2.length);
            while(i<length && j<arr2.length)
            {
                if(A[i]<arr2.A[j]){

                    arr3->A[k++]=A[i++];
                }
                else if(arr2.A[j]<A[i]){

                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            for(;i<length;i++)
                arr3->A[k++]=A[i];

            arr3->length=k;
            return arr3;
        }


        //FINDIND ONE MISSING ELEMENT IN AN SORTED ARRAY OF NATURAL NUMBERS

        void oneNmiss(){
            int sum,actsum;
            actsum=0;
            sum = length*(length+1)/2;

            for (int i = 0; i < length-1; i++)
            {
                actsum=actsum+A[i];
            }
            cout<<"The missing element is : "<<sum-actsum;
        }

};


int main(){

    Array arr(10);
    // arr.insert(1,0);
    // arr.insert(2,1);
    // arr.insert(3,2);
    // arr.insert(4,3);
    // arr.insert(6,4);
    // arr.insert(7,5);
    // arr.insert(8,6);
    // arr.insert(9,7);


    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    arr.append(6);
    arr.append(7);

    arr.display();

    arr.oneNmiss();

    return 0;
}