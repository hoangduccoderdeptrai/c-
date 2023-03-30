#include<iostream>
#include<cstring>
using namespace std;
int partition(int arr[],int l,int r){
	int i =l-1;
	int pivot =arr[r];
	for(int j =l;j<r;j++){
		if(arr[j]<pivot){
			i=i+1;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}
int quick_sort(int arr[],int l,int r){
	if(l<=r){
		int pivot =partition(arr,l,r);
		quick_sort(arr,l,pivot-1);
		quick_sort(arr,pivot+1,r);
	}

}
int main(){

	int arr[100];
	for(int i=0;i<10;i++){
		arr[i] =rand()%(20-1+1)+1;
	}
	quick_sort(arr,0,9);
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}

}
