#include <iostream>
#include "operasi.h"

using namespace std;

int main() {
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "=== Array(awal) ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B:" << endl;
    tampilArray(arrayB);

    int baris, kolom;
    cout << "\n=== Menukar array ===" << endl;
    cout << "Masukkan indeks baris yang ingin ditukar (0-2): ";
    cin >> baris;
    cout << "Masukkan indeks kolom yang ingin ditukar (0-2): ";
    cin >> kolom;

    cout << "\nMenukar posisi [" << baris << "][" << kolom << "]" << endl;
    tukarIsiArray(arrayA, arrayB, baris, kolom);
    
    cout << "\nArray A (Setelah ditukar):" << endl;
    tampilArray(arrayA);
    cout << "\nArray B (Setelah ditukar):" << endl;
    tampilArray(arrayB);

    cout << "\n=== Menukar dengan Pointer ===" << endl;
    int var1, var2;
    cout << "Masukkan nilai variabel 1: ";
    cin >> var1;
    cout << "Masukkan nilai variabel 2: ";
    cin >> var2;

    int *p1 = &var1;
    int *p2 = &var2;

    cout << "Sebelum ditukar = var1: " << *p1 << ", var2: " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Setelah ditukar = var1: " << *p1 << ", var2: " << *p2 << endl;

    return 0;
}