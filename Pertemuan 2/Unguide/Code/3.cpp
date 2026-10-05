#include <iostream>
using namespace std;

int cariMinimum(int arr[], int ukuran) {
    int min = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int ukuran) {
    int max = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void hitungRataRata(int arr[], int ukuran) {
    float total = 0;
    for(int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    cout << "Nilai rata-rata array adalah: " << total / ukuran << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]); 
    int pilihan;

    do {
        cout << "\n=== Menu Program Array ===" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar program" << endl;
        cout << "Masukkan pilihan menu Anda: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Isi array arrA: { ";
                for(int i = 0; i < ukuran; i++) {
                    cout << arrA[i] << " ";
                }
                cout << "}" << endl;
                break;
            case 2:
                cout << "Nilai maksimum array adalah: " << cariMaksimum(arrA, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai minimum array adalah: " << cariMinimum(arrA, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
            case 0:
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while(pilihan != 0);

    return 0;
}