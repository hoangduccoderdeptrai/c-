#include<iostream>
#include<algorithm>
using namespace std;
struct paramater{
    int weight,value;
    float bill;
    void nhap();
    void hienthi();

};
bool cmp(paramater a,paramater b){
    return a.bill>b.bill;
}
void paramater::hienthi(){
    cout<<weight<<" "<<value<<" "<<bill<<endl;
}
void paramater::nhap(){
    cin>>weight>>value;
    bill =float(value)/float(weight);
}
void order(paramater arr[],int n){
    sort(arr,arr+n,cmp);

}
int total(paramater arr[],int n,int kg){
    int tong=0;
    int dem=0;
    int i=0;
    while (i<4 ){
        dem =kg/arr[i].weight;
        kg =kg%arr[i].weight;
        tong =dem*arr[i].value+tong;
        i++;


    }
    return tong;

}

int main(){
    paramater ldv[10];
    for(int i=0;i<4;i++){
        ldv[i].nhap();
    }
    order(ldv,4);
    // for(int i=0;i<4;i++){
    //     ldv[i].hienthi();
    // }
    cout<<total(ldv,4,37);



}