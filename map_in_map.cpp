#include<iostream>
#include<map>
using namespace std;
int main(){ 
    
    
    int a,b;
   
    map<int,map<int,int>>mp;
    map<int, map<int, int> >::iterator itr;
    map<int, int>::iterator ptr;
    int c;
    for(int i=0;i<4;i++){
        cin>>a>>b;
        c=a+b+i;
        mp[a][b] =c;
       
       
        
    }
    for (itr = mp.begin(); itr != mp.end(); itr++) {
  
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            cout << "First key is " << itr->first
                 << " And second key is " << ptr->first
                 << " And value is " << ptr->second << endl;
        }
    }
    // tìm kiếm giá trị key;
    if(mp.find((2,3))!=mp.end())cout<<"ccccc";
    else
 

}
