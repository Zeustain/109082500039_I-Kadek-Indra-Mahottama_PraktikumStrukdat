#include <iostream>
#include "Doublylist.h"

using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1\n" << endl; 
    printInfo(L); 
    // nomor 2
    string Caripol;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> Caripol; 
    
    P = findElm(L, Caripol); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << Caripol << " tidak ditemukan." << endl;
    }
    // nomor 3
    string hapurNomor;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapurNomor;

    deleteElm(L, hapurNomor, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << hapurNomor << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << hapurNomor << " tidak ditemukan." << endl;
    }
    
    cout << "\nDATA LIST 1\n" << endl; 
    printInfo(L); 

    return 0;
}