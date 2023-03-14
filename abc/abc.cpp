#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class sv{
	private:
		string name,mssv,ns;
		double point;
		static int dem;
		

	public:
		// string name,mssv,ns;
		// double point;
		void nhap();
		void hienthi();
		double getGPA();
		int getdem();
		int showdem();
		friend void inthongtin(sv&);
		friend void hamchuanhoa(sv&);
		friend class gv;
		friend istream& operator>>(istream& in,sv&a);
		friend ostream& operator<<(ostream& out,sv a);
		friend bool operator<(sv a,sv b);
		
		
		

};
class gv{
	private:
		string khoa;
	public:
		void update(sv&);
		void show(sv&);

};
istream& operator>>(istream& in,sv&a){
	cout<<"nhap ten:";
	fflush(stdin);
	getline(in,a.name);
	cout<<"nhap mssv:";
	in>>a.mssv;
	cout<<"nhap nam sinh:";
	in>>a.ns;
	cout<<"nhap diem:";
	in>>a.point;
	return in;
}
ostream& operator<<(ostream& out,sv a){
	out<<a.name<<" "<<a.mssv<<" "<<a.ns<<" "<<a.point<<endl;
}
bool operator<(sv a,sv b){
	return a.point>b.point;
}
void gv::update(sv&x){
	x.point=3.4;
	

}
void gv::show(sv&x){
	cout<<x.name;
}

int sv::dem=0;
void inthongtin(sv &a){
	cout<<a.name;
}

void hamchuanhoa(sv&a){
	int n=a.name.length();
	for(int i=0;i<n;i++){
		if(a.name[i]==' '&&a.name[i+1]!=' '&&i!=0){
			continue;
		}
		else if(a.name[i]==' '){
			for(int j=i;j<n;j++){
				a.name[j]=a.name[j+1];

			}
			i--;
			n--;
		}
	}
	a.name[n]='\0';
	a.name[0] =toupper(a.name[0]);
	for(int i=1;i<n;i++){
		if(a.name[i]==' '){
			a.name[i+1] =toupper(a.name[i+1]);
			i++;
		}
		else if(a.name[i]>='A'&&a.name[i]<='Z')a.name[i]=a.name[i]+32;
		

	}

}


void sv::nhap(){
	dem++;
	cout<<"nhap name:";
	fflush(stdin);
	getline(cin,name);
	this->mssv ="SV"+string(3- to_string(dem).length(),'0')+to_string(dem);
	cout<<"nhap ns:";cin>>ns;
	cout<<"nhap diem:";cin>>point;

}
double sv::getGPA(){
	return this->point;
}





void sv::hienthi(){
	cout<<this->name<<" "<<this->mssv<<" "<<this->ns<<" "<<this->point;
}
bool cmp(sv a,sv b){
	return a.getGPA()>b.getGPA();
}




int main(){
	sv arr[100];
	sv ar[100];
	vector<sv>mp;
	
	for(int i=0;i<3;i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<3;i++){
		
		for(int j=i+1;j<3;j++){
			operator<(arr[i],arr[j]);
				ar[0] =arr[i];
				arr[i]=arr[j];
				arr[j]=ar[0];
				

				

			
		}
	}
	// sort(arr,arr + 3);

	for(int i=0;i<3;i++){
		arr[i].hienthi();
	}
	
	
	
	
	
}
