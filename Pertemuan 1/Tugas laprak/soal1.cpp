#include <iostream>
using namespace std;

int main() {
    float x, y;
    
    cout << "Masukkan angka pertama: ";
    cin >> x;
    cout << "Masukkan angka kedua: ";
    cin >> y;

    cout << "\n--- Hasil Operasi ---" << endl;
    cout << "Penjumlahan : " << x + y << endl;
    cout << "Pengurangan : " << x - y << endl;
    cout << "Perkalian   : " << x * y << endl;
    
    if (y == 0) {
        cout << "Pembagian   : Error (Tidak bisa dibagi nol)" << endl;
    } else {
        cout << "Pembagian   : " << x / y << endl;
    }

    return 0;
}