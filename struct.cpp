#include<iostream>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
#define a() a
class sv{
    private:
        string name,ns;
        int ms;
        static int cnt;
    public:
        sv();
        string get_ten();
        friend istream& operator>>(istream& in,sv& a);
        friend ostream& operator<<(ostream& on,sv a); 
        friend bool operator<(sv a,sv b); 
        friend void sapxep_ns(sv a,int n);
        friend void sapxep_ten(sv a,int n);
        friend bool cmp(sv a,sv b);

};
int cnt=0;
bool cmp(sv a,sv b){
    return a.get_ten()>b.get_ten();
}
istream& operator>>(istream& in,sv& a){
    cnt++;
    a.ms =cnt;
    cout<<"nhap ten:";
    fflush(stdin);
    getline(cin,a.name);
    cout<<"nhap ngay sinh";
    fflush(stdin);
    getline(cin,a.ns);
    return in;

}
ostream& operator<<(ostream& on,sv a){
    on<<setfill('0')<<setw(5)<<a.ms<<" ";
    on<<a.name<<" "<<a.ns<<endl;
    return on;
}
sv::sv(){
    ms =0;
    ns =name ="";
}
bool operator<(sv a,sv b){
    string s1 =a.ns,s2 =b.ns;
    // int n1 =stoi(s1.substr(6)),n2 =stoi(s1.substr(3,2)),n3 =stoi(s1.substr(0,2));
    // int m1 =stoi(s2.substr(6)),m2 =stoi(s2.substr(3,2)),m3 =stoi(s2.substr(0,2));
    int n1 =stoi(s1.substr(6)),n2 =(s1[3]-'0')*10+(s1[4]-'0'),n3 =(s1[0]-'0')*10+(s1[1]-'0');
    int m1 =stoi(s2.substr(6)),m2 =(s2[3]-'0')*10+(s2[4]-'0'),m3 =(s2[0]-'0')*10+(s2[1]-'0');
    if(n1!=m1)return n1<m1;
    if(n2!=m2)return n2<m2;
    return n3<m3;
}   
void sapxep_ns(sv a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(operator<(a[i],a[j])){
                sv t =a[i];
                a[i] =a[j];
                a[j] =t;


            }
        }
    }
}
void sapxep_ten(sv a[],int n){
   sort(a,a+n,cmp);
}

string sv::get_ten(){
    string ten;
    int dem=0;
    int tinh=0;
    int len_ten =name.length();
    vector<string>mp;
    for(int i=0;i<=len_ten;i++){
        if(name[i]!=' '&& name[i]!='\0'){
            ten.insert(ten.begin()+dem,name[i]);
            dem++;

        }else{
            mp.push_back(ten);
            dem=0;
            ten="";
            tinh++;
        }   
    }
    reverse(mp.begin(),mp.end());
    for(int i=0;i<tinh;i++){
        ten.append(mp.at(i));
        ten.append(" ");
    }
    return ten;


}
int main(){
    sv a[100];
    int n;
    cout<<"nhap so luong sinh vien:";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"             CHON OPTION                  "<<endl;
    cout<<"|      ************************          |"<<endl;
    cout<<"|  1.xep sep theo ns                     |"<<endl;
    cout<<"|  2.xep sep theo ten                    |"<<endl;
    cout<<"|  3.tim kiem sinh vien theo ten         |"<<endl;
    cout<<"|  4.them sinh                           |"<<endl;
    cout<<"|  5.xoa sinh vien                       |"<<endl;
    cout<<"|  6.hien thi                            |"<<endl;
    cout<<"|  7.Thoat                               |"<<endl;
    cout<<"|****************************************|"<<endl;
    cout<<endl;
    int chose;
    
    while(true){
        cout<<"moi nhap so:";
        cin>>chose;
        if(chose==1){
            sapxep_ns(a,n);
            
        }else if(chose==2){
           sapxep_ten(a,n);

        }else if(chose==3){
            
            
        }else if(chose==4){
            cout<<"toi chua thuc hien"<<endl;
            
        }else if(chose==5){
            
        }else if(chose==6){
            for(int i=0;i<n;i++){
                cout<<a[i];
            }
            
        }else if(chose==7){
            break;
            
        }
    }
}


