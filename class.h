#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
// khai bao class
class Point{
    private:
        int x;
        int y;
    public:
    static float distance(Point a,Point b);
    
    int get_x(){
        return x;
    }
    int get_Y(){
        return y;
    }
    
    void Nhap();

};
class tuGiac{
    private:
        
    public:
        Point d[4];
        
       
        void Nhap();
        bool Check();
        void hienthi();


};
class hingthang:public tuGiac{
    private:
    public:
        bool Check();
        void Nhap();
        void hienthi();


};

