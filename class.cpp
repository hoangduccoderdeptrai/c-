#include<iostream>
#include "class.h"
#include<string.h>
#include<string>
using namespace std;
void Point::Nhap(){
    cin>>x>>y;
}

void tuGiac::Nhap(){
    char ch[]={"ABCD"};
    for(int i=0;i<4;i++){
        cout<<"nhap toa do oxy cua diem: "<<ch[i]<<endl;
        d[i].Nhap();
    }
}

float distance(Point a,Point b){
    float distan =0;
    distan =sqrt(pow(float(a.get_x())-float(b.get_x()),2)+pow(float(a.get_Y())-float(b.get_Y()),2));
    return distan;
}
bool tuGiac::Check(){
    float AB =distance(d[0],d[1]);
    float AD =distance(d[0],d[3]);
    float CD =distance(d[2],d[3]);
    float BC=distance(d[2],d[1]);
    float AC =distance(d[0],d[2]);
    float BD =distance(d[1],d[3]);
    if(AB==0||AD==0||CD==0||BC==0||AC==0||BD==0)return false;
    if(AB+BC==AC||AC+BC==AB||AC+AB==BC)return false;
    if(BD+CD==BC||BC+CD==BD||BD+BC==CD)return false;
    if (AD+AC==CD||CD+AC==AD||AD+CD==AC)return false;
    if(AD+AB==BD||AD+BD==AB||BD+AB==AD)return false;
    return true;
  

}
void hingthang::Nhap(){
    tuGiac::Nhap();
}
bool hingthang::Check(){
    // thiếu trường hợp mới chỉ xét là cùng tọa độ còn truoengf hợp khác tọa độ mà ss với nhau
    bool dem=false;
    int a,b;
    if(tuGiac::d[0].get_x()==tuGiac::d[1].get_x()){
        if(tuGiac::d[2].get_x()==tuGiac::d[3].get_x())dem=true;
    }
    for(int i=1;i<4;i++){
       if(tuGiac::d[0].get_x()==tuGiac::d[i].get_x()){
            a =i+1;
            b=i+2;
            if(i==2){
                a=1;
                b=3;
            }
            if(i==3){
                a =1;
                b=2;
            }
            if(tuGiac::d[a].get_x()==tuGiac::d[b].get_x())dem=true;
       }
    }
    for(int i=1;i<4;i++){
       if(tuGiac::d[0].get_Y()==tuGiac::d[i].get_Y()){
            a =i+1;
            b=i+2;
            if(i==2){
                a=1;
                b=3;
            }
            if(i==3){
                a =1;
                b=2;
            }
            if(tuGiac::d[a].get_Y()==tuGiac::d[b].get_Y())dem=true;
       }
    }



    if(tuGiac::Check()&& dem ){
        return true;
    }
    return false;
}
void tuGiac::hienthi(){
    cout<<"day la hinh tu giac"<<endl;
}
void hingthang::hienthi(){
    cout<<"day la hinh thang"<<endl;

}
int main(){
    tuGiac t;
    hingthang a;
    a.Nhap();
    if(a.Check()){
        a.hienthi();
    }else if(a.tuGiac::Check()){
        a.tuGiac::hienthi();
    }else{
        cout<<"khong phai tu giac";
    }
    
    
}

