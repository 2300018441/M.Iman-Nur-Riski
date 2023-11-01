#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int a, b;
	cout<< "Masukkan kolom \t: ";
	cin>>a;
	cout<< "Masukkan baris \t: ";
	cin>>b;
	cout<<"- - -\n ";
	
	for(int c = 1; c <= a; c++){
		for (int d = 1; d < b; d++){
			cout<<"|_|";
		}	
		cout<<"|_|"<<endl;
	}
}