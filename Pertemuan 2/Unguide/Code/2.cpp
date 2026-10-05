#include <iostream>
using namespace std;

// Fungsi menukar 3 variabel dengan Pointer
void tukarTigaPointer(int *x, int *y, int *z) {
    int temp;
    
    temp = *x;
    *x = *y;  
    *y = *z;   
    *z = temp; 
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    cout << "=== CALL BY POINTER ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarTigaPointer(&a, &b, &c);

    cout << "\nHasil: " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}