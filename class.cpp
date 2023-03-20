#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
bool cmp(pair<float,int>a,pair<float,int>b){

    return a.second>b.second;
}
bool cmp2(pair<float,int>a,pair<float,int>b){

    return a.second<b.second;
}

struct DonThuc{
    float heso;
    int somu;
    
};
struct Dathuc
{
    DonThuc a[50];
    void nhap(DonThuc a[],int n);
    void xuat(DonThuc a[],int n);
    
    void sepxep(DonThuc a[],int n);
    friend float cout_valuse(DonThuc a[],int n);
    friend void cong(Dathuc a,int n1,Dathuc b,int n2);
};

void Dathuc::sepxep(DonThuc a[],int n){
    vector<pair<float,int>>vt;
    for(int i=0;i<n;i++){
        vt.push_back(make_pair(a[i].heso,a[i].somu));

    }
    sort(vt.begin(),vt.end(),cmp);
    for(int i=0;i<n;i++){
        // cout<<vt[i].first<<vt[i].second<<endl;
        cout<<vt[i].first<<"X^"<<vt[i].second;
        if(i<n-1 && vt[i+1].first>0){
            cout<<" + ";
        }


    }

    

}

void Dathuc::xuat(DonThuc a[],int n){
    for(int i=0;i<n;i++){
        
        cout<<a[i].heso <<"x^"<<a[i].somu;
        if(i<n-1 && a[i+1].heso>0)cout<<" + ";
   
        
    }
    
}
void Dathuc::nhap(DonThuc a[],int n ){
    for(int i=0;i<n;i++){
        cout<<"nhap heso:";
        cin>>a[i].heso;
        cout<<"nhap so mu x^:";
        cin>>a[i].somu;
       

    }
}
float cout_valuse(DonThuc a[],int n){
    int x;
    float tong =0;
    cout<<"nhap gia tri x de tinh gia tri bieu thuc:";
    cin>>x;
    for(int i=0;i<n;i++){
        tong+=a[i].heso*pow(x,a[i].somu);
    }
    return tong;

}
void cong(Dathuc a,int n1,Dathuc b,int n2){
    float k;
    vector<pair<float,int>>p1;
    vector<pair<float,int>>p2;
    vector<pair<float,int>>total;
    for(int i=0;i<n1;i++){
        p1.push_back(make_pair(a.a[i].heso,a.a[i].somu));
       
    }
    for(int i=0;i<n2;i++){
        p2.push_back(make_pair(b.a[i].heso,b.a[i].somu));
    }
    sort(p1.begin(),p1.end(),cmp2);
    sort(p2.begin(),p2.end(),cmp2);
   
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(p1[i].second==p2[j].second){
            k =p1[i].first+p2[j].first;
            total.push_back(make_pair(k,p2[i].second));
            i++;
            j++;
        }else{
            // k = (p1[i].second>p2[j].second)?(p2[j].first):(p1[i].first);
            if(p1[i].second>p2[j].second){
                total.push_back(make_pair(p2[j].first,p2[j].second));
                j++;
            }else{
                total.push_back(make_pair(p1[i].first,p1[i].second));
                i++;

            }
           
        }
    }
    while(i<n1){
        total.push_back(make_pair(p1[i].first,p1[i].second));
        i++;
    }
    while(j<n2){
        total.push_back(make_pair(p2[j].first,p2[j].second));
        j++;
    }
    for(auto x:total){
        cout<<x.first<<" "<<x.second<<endl;
    }
   
}

int main(){
    int n1,n2;
    
    cin>>n1;
    Dathuc t,p;
   cout<<"nhap da thuc 1:";
    t.nhap(t.a,n1);
    cout<<"nhap da thuc 2:";
    cin>>n2;
    p.nhap(p.a,n2);
    // t.sepxep(t.a,n);
    // cout<<cout_valuse(t.a,n);
    cong(t,n1,p,n2);

    
    
    
}