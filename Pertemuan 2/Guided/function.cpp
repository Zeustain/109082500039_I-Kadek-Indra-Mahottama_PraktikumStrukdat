#include <iostream>
using namespace std;

int maks3(int a,int b,int c) {
    int temp_max = a;

    if (b>temp_max) {
        temp_max = b;
    }
    if (c>temp_max) {
        temp_max = c;
    }

    return temp_max;
}

int main(){
    int x,y,z;

    cout<<"Masukan nilai 1 : ";
    cin>>x;

    cout<<"Masukan nilai 2 : ";
    cin>>y;

    cout<<"Masukan nilai 3 : ";
    cin>>z;

    cout<<"Nilai Maksimum: "<< maks3(x,y,z);

    return 0;
}