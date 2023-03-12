#include<iostream>
using namespace std;
int heap_sort(int arr[],int n,int i){
    int largest =i;
    int left =2*i+1;
    int right =2*i+2;
    if(left<n&&arr[left]>arr[largest]){
        largest =left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest =right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heap_sort(arr,n,largest);
    }
}
int main(){
    int arr[6]={2,3,8,4,5,1};
    int n=6;
    for(int i=6-1/2;i>=0;i--){
        heap_sort(arr,6,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heap_sort(arr,i,0);
    }
 
    for(int i=0;i<6;i++){
        cout<<arr[i];
    }

}