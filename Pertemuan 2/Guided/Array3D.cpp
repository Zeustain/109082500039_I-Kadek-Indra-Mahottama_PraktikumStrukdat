#include <iostream>
using namespace std;

int main(){

    //Format array 3 dimensi : nama_array[jumlah array 2D][jumlah baris setiap array 2D][kolom baris setiap array 2D]
    int data[2][2][3] = {
        {
            {10,20,30},
            {40,50,60}
        },
        {
            {70,80,90},
            {100,110,120}
        }
    };

    cout<< data[0][1][2]<<endl;

    return 0;
}