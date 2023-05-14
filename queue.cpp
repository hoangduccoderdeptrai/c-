#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
class Solution  {
public:
    long long solve(vector<vector<int>>& questions,int day,int pre,int end, map<pair<int,int>,int>stored){
        if(day==0){
            for(int j=0;j<3;j++){
                if(pre!=j&&end!=j){
                    return questions[0][j];
                }
            }
        }
        if(stored.find(make_pair(pre,end))!=stored.end())return stored[make_pair(pre,end)];
        int max1=0;
        for(int j=0;j<3;j++){
            if(pre!=j&&end!=j){
                int take =questions[day][j]+solve(questions,day-1,end,j,stored);
                max1=max(max1,take);
                
               
                
            }
        }
        stored[make_pair(pre,end)] =max1;
        return stored[make_pair(pre,end)];
        
        

    }
    int mostPoints(vector<vector<int>>& questions){

        int n =questions.size();
        vector<int>dp(n,-1);
        // vector<vector<int>>stored(n,vector<int>(4,-1));
        map<pair<int,int>,int>stored;
        
        return solve(questions,n-1,3,3,stored);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<4;j++){
        //         cout<<stored[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        

        
    }
   
};
int main(){
    
    vector<vector<int>>questions{
        {1,2,5},{3,1,1},{3,3,3},{7,4,2}
    };
    
    
    Solution t;
    cout<<t.mostPoints(questions);
    
    
}


