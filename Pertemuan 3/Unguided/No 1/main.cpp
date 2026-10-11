#include <iostream>
#include "mahasiswa.h"

using namespace std;



int main(){
    int max=10;
    int n;
    mahasiswa mhs[max];
    cout<<"Masukan jumlah data yang ingin di input (max 10): "<<endl;
    cin>>n;
    if (n<1||n>10){
        cout<<"Jumlah tidak valid"<<endl;
    } else {
        for (int i = 0;i<n;i++){
        cout<<"Data Mahasiswa ke-"<<i+1<<endl;
        inputdataMhs (mhs[i]);
        cout<<"Nilai Akhir = "<< nilai (mhs[i]);
        cout<<endl;
    }
    }
    
    
    return 0;
};