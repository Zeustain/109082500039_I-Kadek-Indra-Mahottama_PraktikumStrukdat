#include <iostream>
using namespace std;

int main(){
    int matriks1[3][3] = {

    };

    int matriks2[3][3] = {

    };

    cout<<"Masukan nilai Matriks 1"<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout<<"Masukan isi Matriks baris-"<<i+1<<" dan kolom-"<<j+1<<" : ";
            cin >> matriks1 [i][j];
        }
    }


    cout<<"Masukan nilai Matriks 2"<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout<<"Masukan isi Matriks baris-"<<i+1<<" dan kolom-"<<j+1<<" : ";
            cin >> matriks2 [i][j];
        }
    }


    cout<<"=== Hasil Matriks 1 ==="<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << matriks1 [i][j]<<" ";
        }
        cout << endl;
    }

    cout<<"=== Hasil Matriks 2 ==="<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << matriks2 [i][j]<<" ";
        }
        cout << endl;
    }

    cout<<endl;

    cout << "=== Operasi matriks ===" << endl;
    
    // 1. Penjumlahan Matriks
    cout << "Penjumlahan matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks1[i][j] + matriks2[i][j] << " ";
        }
        cout << endl;
    }

    // 2. Pengurangan Matriks
    cout << "\nPengurangan matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks1[i][j] - matriks2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPerkalian matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hasilKali = 0;
            for (int k = 0; k < 3; k++) {
                hasilKali += matriks1[i][k] * matriks2[k][j];
            }
            cout << hasilKali << " ";
        }
        cout << endl;
    }


}