#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
map<pair<int,int>,int>mp;
// map<pair<int,int>,int>::iterator res;
int ways(int money,int arr[],int n){
    if(money==0)return 1;
    if(money<0||n<=0)return 0;
    // auto res =mp.find(make_pair(money,n));
    // dung auto hoac res dieu duoc
    if(mp.find(make_pair(money,n))!=mp.end()){
       return mp[make_pair(money,n)];
    }else{
        mp[make_pair(money,n)] =ways(money-arr[n-1],arr,n)+ways(money,arr,n-1);
    }
    return mp[make_pair(money,n)];
    
    

}
int change(int money,int arr[],int n){
    ways(money,arr,n);
    return ways(money,arr,n);


}

int main(){
    int n;
    int money;
    int arr[100];
    cout<<"nhap so luong menh gia:";
    cin>>n;
    cout<<"nhap menh gia moi loai tien:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"nhap so tien muon doi:";
    cin>>money;
    cout<<change(money,arr,n);
    for(auto x:mp){
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
    }
  
 

}





