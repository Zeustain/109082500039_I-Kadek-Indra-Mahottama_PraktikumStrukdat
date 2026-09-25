#include <iostream>
using namespace std;

int main(){
    cout<<"Hello World!"<<endl;

    int a;
    cout<<"Masukan sebuah angka: ";
    cin>>a;
    cout<<"kamu memasukan angka: "<<a<<endl;

    if (a>0) {
        cout<<"angka mu positif"<<endl;
    } else if (a<0) {
        cout<<"angka mu negatif"<<endl;
    } else {
        cout<<"angka mu adalah NOL"<<endl;
    }

    return 0;
}