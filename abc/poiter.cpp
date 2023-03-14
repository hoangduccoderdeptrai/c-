#include<iostream>
using namespace std;
void nhap(int*arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void hienthi(int*arr,int n){
    for(int i=0;i<n;i++){
        cout<<*(arr+i);
    }

}
int timmax(int*arr,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max =arr[i];
        }
        
    }
    return max;
}
int timmin(int*arr,int n){
    int min =0;
    for(int i =0;i<n;i++){
        min =arr[i];
    
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min =arr[j];
            }

        }
    }
    return min;
}
int secondmax(int*arr,int n,int max){
    int semax=0;
    for(int i=0;i<n;i++){
        if(max !=arr[i]){
            semax =arr[i];
            break;
        }
        if(max !=semax && semax<arr[i]){
            semax =arr[i];
        }
    }
    return semax;


    
}


int main(){
    int n;
    int max;
    int min;
    int semax;
    cin>>n;
    int * arr =new int[n];
    nhap(arr,n);
    // hienthi(arr,n);
    // max =timmax(arr,n);4
    // semax =secondmax(arr,n,max);
    // cout<<semax;
    min =timmin(arr,n);
    cout<<min;
    
   
   
   
}