#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;
// thuat toan sap xep bang merge
int merge(int arr[],int st,int mid,int end){
    int k=st;
    int n1 =mid-st;
    int n2 =end-mid-1;
    int *l =new int [n1];
    int *r =new int [n2];
    for(int i=0; i<=n1;i++){
        l[i] =arr[st+i];
    }
    for(int i=0; i<=n2;i++){
        r[i] =arr[mid+i+1];
    }
    int i=0,j=0;
    int dem=0;
    while(i<=n1&&j<=n2){
        if(l[i]>r[i])dem+=n1-i;
        arr[k++]=(l[i]<=r[j])?l[i++]:r[j++];
       
        
    }
    
    while(i<=n1)arr[k++] =l[i++];
    while(j<=n2)arr[k++] =r[j++];
    cout<<dem;

}
int arrange(int arr[],int n,int st,int end){
    
    if(st<end){
        int mid =(st+end)/2;
        if(end>n-1)end =n-1;
        arrange(arr,n,st,mid);
        arrange(arr,n,mid+1,end);
        // cout<<st<<" "<<mid<<" "<<end<<endl;
        merge(arr,st,mid,end);
    }

}
int main(){
    int arr[6] ={8,7,1,9,2,3};
    arrange(arr,6,0,6);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

   
  
  
}
