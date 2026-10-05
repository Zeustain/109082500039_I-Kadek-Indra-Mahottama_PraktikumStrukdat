#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout<<"Nilai angka  : "<<angka<<endl; //Nilai dari variabel angka yaitu 100
    cout<<"Alamat angka  : "<<&angka<<endl; //Alamat dari variabel angka
    cout<<"isi variabel pointer  : "<<pointer<<endl; //Alamat dari variabel angka
    cout<<"Nilai dari variabel pointer  : "<<*pointer<<endl;//Value dari variabel angka yaitu 100
}