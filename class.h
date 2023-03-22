#include<iostream>
#include<string>
using namespace std;
class ns{
    private:
        int days;
        int months;
        int years;
    public:
        void nhap();
        void hienthi();
    protected:
        bool check_namnhuan();
        bool valid_day(){
            if(months<0||months>12){
                cout<<"nhap sai thang vui long nhap lai";
                return false;
            }
            int day_max[11]={31,28,31,30,31,30,31,31,30,31,30};
            for(int i=1;i<=12;i++){
                if(months==2){
                    if(check_namnhuan()){
                        if(days<0||days>29){
                            cout<<"nhap ngay sai vui long nhap lai";
                            return false;
                        }
                    }else{
                        if(days<0||days>28){
                            cout<<"nhap ngay sai vui long nhap lai";
                            return false;
                        }
                    }
                    break;
                }
                if(months==i){
                    if(days>day_max[i-1]||days<0){
                        cout<<"nhap lai sai ngay";
                        return false;
                    }
                    break;
                }

            }
            return true;
           
           
        }
    




};
class person:public ns{
    private:
        string name;
        
    public:
        long luong;
        void nhap();
        void hienthi();


};
class nvvp:public person{
    private:
        int  work_day;
       
    public:
       
        long salary();
        void nhap();
        void hienthi();


};
