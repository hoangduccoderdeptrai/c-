#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int ways(int arr[][100],int i,int j,int row,int col,int x1,int y1){
    
    if(i==row||j==col)return 0;
    if(i==row-1&&j==col-1)return 1;
    if(i==x1&&j==y1)return 0;
    if(arr[i][j]!=0)return arr[i][j];
    else{
        arr[i][j]=ways(arr,i+1,j,row,col,x1,y1)+ways(arr,i,j+1,row,col,x1,y1);
    }
    return arr[i][j];
    
    
}
int change(int arr[][100],int i,int j,int row,int col,int x1,int y1){
    ways(arr,i,j,row,col,x1,y1);
    return ways(arr,i,j,row,col,x1,y1);
}



int main(){ 
    int arr[100][100];
    int n,m;
    cout<<"nhap row and column:";
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=0;

        }
    }
    int x1,y1;
    cout<<"vi tri dat chot:";
    cin>>x1>>y1;

    cout<<change(arr,0,0,n,m,x1,y1);
   

 
    
}
        
   

       
       
     
        
   
    
 


