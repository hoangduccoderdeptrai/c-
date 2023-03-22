#include"class.h"
void ns::nhap(){
    do{
        
        cin>>days>>months>>years;

    }while(!valid_day());
}
void ns::hienthi(){
    cout<<days<<" "<<months<<" "<<years<<endl;

}
bool ns::check_namnhuan(){
    string name =to_string(years);
    int len =name.length();
    if(name[len-1]==0 && name[len-2]==0){
        if(years%400!=0)return false;
    }else{
        if(years%4!=0)return false;

    }
    return true;
}

void person::nhap(){
    cout<<"nhap ten:";
    fflush(stdin);
    getline(cin,name);
    cout<<"nhap nam sinh:";
    ns::nhap();
    
}
void person::hienthi(){
    cout<<name<<" ";
    ns::hienthi();
    cout<<endl;
}
void nvvp::nhap(){
    fflush(stdin);
    person::nhap();
    cout<<"nhap so ngay lam viec:";
    cin>>work_day;
    
   
}
void nvvp::hienthi(){
    person::hienthi();
    cout<<salary()<<endl;

}
long nvvp::salary(){
   long sala =work_day*100000;
    return sala;

}