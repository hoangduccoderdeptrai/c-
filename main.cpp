#include <cmath>
#include"class.cpp"
int main(){
    nvvp sv[100];
    int n;
    cout<<"nhap so luong nhan vien van phong:";
    cin>>n;
    for(int i=0;i<n;i++){
        sv[i].nhap();
        // sv[i].salary();
    }
    for(int i=0;i<n;i++){
        sv[i].hienthi();
    }
}

