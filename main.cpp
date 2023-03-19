#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;
int n,d_cheo1[100],d_cheo2[100],cot[100];
int x[100];
int arr[100][100];
int dem=0;
int inkq(){
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){
        arr[i][x[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;


}
void backtrack(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]==0&&d_cheo1[i-j+n]==0&&d_cheo2[i+j-1]==0){
            x[i] =j;
            cot[j]=d_cheo1[i-j+n]=d_cheo2[i+j-1]=1;
            if(i==n){
                inkq();
                dem++;
            }else{
                backtrack(i+1);
                
            }
            cot[j]=d_cheo1[i-j+n]=d_cheo2[i+j-1]=0;

        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<50;i++){
        d_cheo1[i]=d_cheo2[i]=cot[i]=0;

    }
    
    backtrack(1);
    cout<<dem;
    

}