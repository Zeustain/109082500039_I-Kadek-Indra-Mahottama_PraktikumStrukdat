# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST</h1>
<p align="center">I Kadek Indra Mahottama - 109082500039</p>

## Dasar Teori
*Linked list* (senarai berantai) merupakan salah satu bentuk representasi penyimpanan berupa serangkaian elemen data yang saling berhubungan [1]. Struktur data ini bersifat sangat fleksibel karena ukurannya dapat bertambah atau berkurang secara dinamis sesuai kebutuhan eksekusi program [1]. Implementasi *linked list* pada praktikum ini menggunakan *pointer* dibandingkan *array* karena beberapa alasan: *pointer* bersifat dinamis, sangat cocok dengan sifat *linked list* yang bentuk datanya saling bergandengan, serta lebih efisien dibandingkan *array* yang mengharuskan pendefinisian kapasitas maksimal elemen sejak awal [1]. 

Dalam model *Singly Linked List*, struktur data ini hanya memiliki satu arah penunjuk (*pointer*) sehingga penelusuran data (pembacaan) hanya dapat dilakukan secara maju (sekuensial) [1]. Setiap komponen (*node* atau elemen) di dalam *Singly Linked List* terdiri dari dua bagian utama, yaitu *Data* (informasi utama yang disimpan) dan *Successor* atau *next* (penunjuk alamat elemen di depannya) [1]. Selain itu, terdapat istilah `first` atau `head` yang merupakan pointer penunjuk alamat elemen pertama, serta `NULL` atau `Nil` yang berada pada *node* terakhir sebagai penanda bahwa *pointer* tidak mengacu ke mana pun [1].

Operasi-operasi dasar (primitif) pada *linked list* berbasis ADT (*Abstract Data Type*) meliputi penciptaan list (`Create List`), penyisipan elemen (`Insert First`, `Insert After`, `Insert Last`), penghapusan elemen (`Delete First`, `Delete After`, `Delete Last`), hingga penelusuran dan penampilan elemen (`View`) [1]. Sebelum operasi penyisipan dilakukan, program diwajibkan untuk mengalokasikan memori terlebih dahulu guna menampung *node* baru (menggunakan sintaks `new` pada C++) [1]. Sebaliknya, saat operasi penghapusan, memori dari *node* yang dihapus harus dikembalikan ke sistem melalui proses dealokasi (menggunakan sintaks `delete` pada C++) agar tidak terjadi kebocoran memori [1].

## Guided 

### 1. Implementasi ADT Singly Linked List untuk Data Mahasiswa

#### File `list.h`
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct LinkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(LinkedList List);
void createList(LinkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList List);
void insertFirst(LinkedList &List, address nodeBaru);
void insertAfter(LinkedList &List, address nodeBaru, address Prev);
void insertLast(LinkedList &List, address nodeBaru);

void delFirst(LinkedList &List);
void delLast(LinkedList &List);
void delAfter(LinkedList &List, address nodeHapus, address nodePrev);
int nbList(LinkedList List);
void deleteList(LinkedList &List);

#endif
```

#### File `list.cpp`
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(LinkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(LinkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(LinkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(LinkedList List) {
    /* I.S. list sudah ada
       F.S. Menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(LinkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

#### File `main.cpp`
```C++
#include "list.h"

#include <iostream>
using namespace std;

int main(){
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Penulisan kode pada bagian *guided* ini mendemonstrasikan perancangan arsitektur *Singly Linked List* yang kompleks berbasis *Abstract Data Type* (ADT) menggunakan tiga buah file modular (`list.h`, `list.cpp`, dan `main.cpp`). Deklarasi file spesifikasi di `list.h` tidak hanya menyimpan `struct node` yang menampung data mahasiswa komposit dan pointer penunjuk (`next`), melainkan mencakup 13 prototipe primitif. Operasi pengelolaan *node* yang diwujudkan di `list.cpp` secara rinci menangani fungsi pendukung, *insert* (depan, tengah, belakang), serta operasi dinamis *delete* (depan, tengah, belakang, dan total seluruh *list*). Pada `main.cpp`, kode dijalankan dengan membangun untaian 5 *node* secara spesifik, kemudian dipangkas satu per satu melalui kombinasi prosedur penghapusan *node* hingga ruang memori akhirnya bersih sepenuhnya berkat eksekusi `deleteList`.

## Unguided 

### 1. Buatlah ADT Singly Linked list di dalam file "Singlylist.h", implementasi di "Singlylist.cpp", dan panggil di "main.cpp" sesuai instruksi alokasi 5 node dengan insertFirst.

#### File `Singlylist.h`
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif // SINGLYLIST_H_INCLUDED
```

#### File `Singlylist.cpp`
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// ... (Primitif lainnya digunakan untuk Unguided 2)
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        L.First = L.First->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        if (L.First->next == NULL) { 
            deleteFirst(L, P);
        } else {
            address Prec = NULL;
            P = L.First;
            while (P->next != NULL) {
                Prec = P;
                P = P->next;
            }
            Prec->next = NULL;
        }
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.First != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}
```

#### File `main.cpp`
```C++
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
    
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/main/Pertemuan%204/Screenshoot%20output/Screenshot%202026-10-18%20191215.png?raw=true)

Program `main.cpp` di atas merupakan eksekusi dasar (implementasi pertama) dari *Singly Linked List* statik yang secara khusus mendemonstrasikan pengoperasian primitif `insertFirst`. Karena penambahan node *selalu* ditempatkan pada posisi terdepan (sisi *head* / `First`), nilai-nilai (2, 0, 8, 12, dan 9) yang diinputkan akan tersusun ke dalam *list* dalam urutan yang terbalik dari kronologi penyisipannya. Oleh karena itu, ketika prosedur `printInfo` berjalan untuk menelusuri penunjuk dari ujung depan (*First*) hingga bertemu akhiran `NULL`, program mencetak *output* akhir berurutan menjadi "9 12 8 0 2" ke layar. 

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan dan lakukan penghapusan seluruh node.

*(Catatan: File `Singlylist.h` dan `Singlylist.cpp` yang digunakan sama persis dengan Unguided 1)*

#### File `no2.cpp`
```C++
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
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/main/Pertemuan%204/Screenshoot%20output/Screenshot%202026-10-18%20191238.png?raw=true)

Kode implementasi *unguided* kedua ini (`no2.cpp`) merupakan skenario pelengkap untuk mendemonstrasikan penghancuran (*delete*) suatu hierarki data yang sudah dibangun, sembari memantau sisa ruang memorinya. Logika berjalan dengan memanfaatkan `P_Hapus` sebagai *pointer* bantu tempat menampung relokasi node yang dibuang, sehingga instruksi `delete` (`dealokasi`) tidak menyebabkan *memory crash*. Node 9 dibuang lewat `deleteFirst`, dilanjutkan node 2 yang ditumpas oleh iterasi panjang `deleteLast`. Karena sisa rantainya berupa "12 -> 8 -> 0", pemanggilan prosedur `deleteAfter` menggunakan *pointer precursor* (`Prec = L.First`) mampu membidik node di urutan kedua (yaitu angka 8) secara akurat. Prosedur `nbList` membuktikan algoritma perulangan traversal berfungsi dengan baik dengan menampilkan sisa "2" node, sebelum seluruh struktur tersebut direset paksa hingga berjumlah "0" melalui fungsi `deleteList`.

## Kesimpulan
Praktikum Modul 4 ini memberikan pendalaman materi yang sangat signifikan terhadap mekanisme struktural memori dinamis komputer melalui implementasi struktur *Singly Linked List* menggunakan *pointer*. Apabila dibandingkan dengan *array* statik, terbukti bahwa pemanfaatan simpul (*node*) dan penunjuk (*next*) mampu menyingkirkan batasan kapasitas ukuran data awal, sehingga memberikan skalabilitas alokasi maupun pemangkasan data yang sangat adaptif. Penggunaan struktur ADT (*Abstract Data Type*) semakin memperjelas fungsi-fungsi primitif karena setiap logika terisolasi di dalam *file* yang berbeda, mulai dari pembentukan simpul awal, modifikasi alur sisipan (depan, tengah, belakang), hingga pembersihan menyeluruh (*dealokasi*). Melalui serangkaian *Guided* dan *Unguided*, logika pergeseran alamat *pointer* telah disimulasikan dengan sangat baik; di mana satu keteledoran kecil dalam memutus atau menyambung *link* dapat merusak integritas *list* secara keseluruhan.

## Referensi
[1] Modul Praktikum, "Modul 4: SINGLY LINKED LIST (BAGIAN PERTAMA)," Modul 04 STUKDAT (1).pdf, 2024.
<br>[2] Triase. (2020). *Diktat Edisi Revisi : STRUKTUR DATA*. Medan: UNIVERSITAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[3] Indahyati, Uce., Rahmawati Yunianita. (2020). *BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++*. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.