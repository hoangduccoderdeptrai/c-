#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
   int arr[6]={4,4,5,6,8,2};
   vector<int>mp;
   for(int i=0;i<6;i++){
        mp.insert(mp.begin()+i,arr[i]);
   }
   
}