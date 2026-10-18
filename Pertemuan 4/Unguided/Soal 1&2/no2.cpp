#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {

    List L;
    address P1, P2, P3, P4, P5 = NULL;
    
    createList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    printInfo(L);
    cout << endl;

    address P_Hapus;

    deleteFirst(L, P_Hapus);
    dealokasi(P_Hapus);

    deleteLast(L, P_Hapus);
    dealokasi(P_Hapus);

    address Prec = L.First; 
    deleteAfter(L, P_Hapus, Prec);
    dealokasi(P_Hapus);

    printInfo(L);
    cout << endl;

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);

    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}
