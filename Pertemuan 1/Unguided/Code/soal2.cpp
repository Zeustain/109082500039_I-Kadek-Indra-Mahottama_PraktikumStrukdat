#include <iostream>
#include <string>
using namespace std;

string tulisan(int n) {
    string huruf[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
    
    if (n < 12) {
        return huruf[n];
    } else if (n < 20) {
        return huruf[n % 10] + " belas";
    } else if (n < 100) {
        if (n % 10 == 0) {
            return huruf[n / 10] + " puluh";
        } 
        else {
            return huruf[n / 10] + " puluh " + huruf[n % 10];
        }
    } else if (n == 100) {
        return "seratus";
    }
    
    return 0;
}

int main() {
    int angka;
    cout << "Masukkan angka (0 s.d 100): ";
    cin >> angka;

    if (angka >= 0 && angka <= 100) {
        cout << angka << " : " << tulisan(angka) << endl;
    } else {
        cout << "Harap masukkan angka antara 0 sampai 100." << endl;
    }

    return 0;
}