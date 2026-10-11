# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">I Kadek Indra Mahottama - 109082500039</p>

## Dasar Teori
Abstract Data Type (ADT) merupakan sebuah definisi statik yang terdiri dari suatu tipe data (TYPE) beserta sekumpulan operasi dasar (PRIMITIF) yang bekerja terhadap tipe tersebut [1]. Dalam sebuah struktur ADT yang utuh, disertakan pula definisi invarian dari tipe serta aksioma yang berlaku [1]. Sebuah definisi tipe dari ADT juga dapat memuat definisi ADT lainnya, seperti ADT Waktu yang tersusun atas ADT JAM dan ADT DATE, ataupun ADT Garis yang dibentuk dari dua buah ADT POINT [1]. Dalam bahasa pemrograman prosedural seperti C dan C++, tipe data dari ADT diterjemahkan menggunakan struktur rekaman (`struct`), sedangkan operasi primitifnya diwujudkan ke dalam bentuk fungsi atau prosedur [1, 2].

Operasi-operasi primitif di dalam ADT dikelompokkan berdasarkan fungsinya masing-masing [1]. Kelompok tersebut meliputi Konstruktor atau Kreator sebagai pembentuk nilai tipe (biasanya diawali kata *Make*), *Selector* untuk mengakses komponen tipe (biasanya diawali kata *Get*), prosedur pengubah nilai komponen, serta tipe validator untuk menguji apakah nilai komponen memenuhi batasan yang ditentukan [1]. Selain itu, terdapat pula Destruktor atau Dealokator untuk menghancurkan objek beserta alokasi memorinya, primitif Baca/Tulis sebagai antarmuka *input/output*, operator relasional, operasi aritmatika khusus, hingga fungsi konversi ke tipe data dasar maupun sebaliknya [1].

Dalam implementasinya menggunakan bahasa C++, konsep ADT dibagi menjadi dua buah modul utama dan satu modul antarmuka program utama (*driver*) agar struktur kode lebih modular dan terorganisir [1, 3]:
1. **Modul Definisi/Spesifikasi Type dan Primitif (`.h`)**: File *header* yang menyimpan deklarasi tipe data (`struct`) serta prototipe dari fungsi dan prosedur yang dilengkapi dengan *header guard* (`#ifndef`, `#define`, `#endif`) agar terhindar dari duplikasi pemanggilan [1].
2. **Modul Body/Realisasi dari Primitif (`.cpp`)**: File implementasi yang berisi barisan kode program nyata untuk merealisasikan logika dari setiap fungsi dan prosedur yang telah dideklarasikan pada file *header* [1].
3. **Modul Antarmuka Program Utama (`main.cpp`)**: File *driver* yang bertugas memanggil file *header* (`.h`) dan mengeksekusi alur program utama tanpa perlu menuliskan ulang rincian logika fungsi di dalamnya [1].

## Guided 

### 1. Implementasi ADT Mahasiswa

#### File `mahasiswa.h`
```C++
#ifndef MAHASISWA_H_INCLUDE
#define MAHASISWA_H_INCLUDE

struct mahasiswa{
    char nim[10];
    int nilai1,nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);

#endif //MAHASISWA_H_INCLUDE
```

#### File `mahasiswa.cpp`
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout<<"input nim = ";
    cin>>(m).nim;
    cout<<"input nilai 1 = ";
    cin>>(m).nilai1;
    cout<<"input nilai 2 = ";
    cin>>(m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}
```

#### File `main.cpp`
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs (mhs);
    cout<<"Rata-rata = "<< rata2 (mhs);
    return 0;
};
```
Program di atas mendemonstrasikan penerapan dasar konsep Abstract Data Type (ADT) pada C++ dengan memisahkan kode ke dalam tiga file berbeda. File `mahasiswa.h` berfungsi sebagai spesifikasi yang mendeklarasikan `struct mahasiswa` beserta prototipe prosedur `inputMhs` dan fungsi `rata2`. Selanjutnya, file `mahasiswa.cpp` memuat realisasi logika untuk menerima input NIM serta dua nilai mahasiswa (menggunakan parameter *pass by reference* `&m`), sekaligus menghitung nilai rata-ratanya. Terakhir, file `main.cpp` bertindak sebagai program utama (*driver*) yang menginisialisasi objek `mhs` dan memanggil kedua primitif tersebut untuk menampilkan hasil rata-rata ke layar.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

#### File `mahasiswa.h`
```C++
#ifndef MAHASISWA_H_INCLUDE
#define MAHASISWA_H_INCLUDE

using namespace std;
#include <string>

struct mahasiswa{
    char nim[10];
    string nama;
    int uts,uas,tugas,nilai_akhir;
};

void inputdataMhs (mahasiswa &m);
float nilai (mahasiswa m);

#endif //MAHASISWA_H_INCLUDED
```

#### File `mahasiswa.cpp`
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int max = 10;
void inputdataMhs(mahasiswa &m) {
    cout<<"input nama = ";
    cin>>(m).nama;
    cout<<"input nim = ";
    cin>>(m).nim;
    cout<<"input nilai uts = ";
    cin>>(m).uts;
    cout<<"input nilai uas = ";
    cin>>(m).uas;
    cout<<"input nilai tugas = ";
    cin>>(m).tugas;

}

float nilai(mahasiswa m) {
    return float(0.3*m.uts+0.4*m.uas+0.3*m.tugas);
}
```

#### File `main.cpp`
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    int max=10;
    int n;
    mahasiswa mhs[max];
    cout<<"Masukan jumlah data yang ingin di input (max 10): "<<endl;
    cin>>n;
    if (n<1||n>10){
        cout<<"Jumlah tidak valid"<<endl;
    } else {
        for (int i = 0;i<n;i++){
        cout<<"Data Mahasiswa ke-"<<i+1<<endl;
        inputdataMhs (mhs[i]);
        cout<<"Nilai Akhir = "<< nilai (mhs[i]);
        cout<<endl;
    }
    }
    
    return 0;
};
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/cb04b2bf89ebfc1db2123d5814376eaf373cb4fa/Pertemuan%203/screenshot%20output/unguided/Screenshot%20output%20soal%201.png)


Program ini bertujuan untuk mengelola dan menyimpan data nilai akademik dari maksimal 10 orang mahasiswa menggunakan struktur array dari ADT `mahasiswa`, sekaligus menghitung nilai akhir berdasarkan bobot persentase komponen penilaian. Dalam kode yang saya buat, arsitektur program dibagi menjadi tiga file utama sesuai kaidah ADT. Pada file `mahasiswa.h`, saya mendefinisikan tipe bentukan `struct mahasiswa` yang menyimpan atribut `nim`, `nama`, `uts`, `uas`, `tugas`, dan `nilai_akhir`, beserta deklarasi prototipe prosedur `inputdataMhs` dan fungsi `nilai`.

Alur logika dari primitif tersebut kemudian saya realisasikan di dalam file `mahasiswa.cpp`, di mana prosedur `inputdataMhs` meminta masukan data dari pengguna menggunakan parameter *reference* (`&m`), sedangkan fungsi `nilai` mengembalikan hasil kalkulasi rumus `0.3*uts + 0.4*uas + 0.3*tugas` bertipe `float`. Pada file `main.cpp`, saya mendeklarasikan array `mhs` berkapasitas 10 elemen dan menerapkan seleksi kondisi `if-else` untuk memvalidasi agar jumlah input (`n`) tidak kurang dari 1 ataupun melebihi 10. Apabila jumlahnya valid, perulangan `for` akan berjalan untuk memanggil prosedur input dan mencetak hasil fungsi nilai akhir untuk masing-masing indeks mahasiswa secara berurutan.

### 2. Buatlah ADT pelajaran di dalam file "pelajaran.h", buatlah implementasi ADT pelajaran pada file "pelajaran.cpp", dan cobalah hasil implementasi ADT pada file "main.cpp".

#### File `pelajaran.h`
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>

using namespace std;

struct pelajaran {
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif // PELAJARAN_H_INCLUDED
```

#### File `pelajaran.cpp`
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namamapel = namapel;
    pel.kodemapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran: " << pel.namamapel << endl;
    cout << "nilai: " << pel.kodemapel << endl; 
}
```

#### File `main.cpp`
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/cb04b2bf89ebfc1db2123d5814376eaf373cb4fa/Pertemuan%203/screenshot%20output/unguided/Screenshot%20output%20soal%202.png)

Program ini berfungsi untuk mengimplementasikan struktur ADT `pelajaran` yang memanfaatkan primitif konstruktor (kreator) untuk membentuk objek mata pelajaran baru dan prosedur *tampil* untuk mencetak informasinya ke layar. Pada file spesifikasi `pelajaran.h`, saya mendefinisikan `struct pelajaran` yang memiliki dua komponen bertipe `string`, yaitu `namamapel` dan `kodemapel`, diikuti dengan deklarasi fungsi konstruktor `create_pelajaran` serta prosedur `tampil_pelajaran`.

Selanjutnya, di dalam file `pelajaran.cpp`, saya merealisasikan fungsi `create_pelajaran` yang menerima argumen nama serta kode pelajaran, memasukkannya ke dalam objek lokal bertipe `pelajaran`, lalu mengembalikan (*return*) objek tersebut. Prosedur `tampil_pelajaran` saya rancang untuk mencetak isi atribut dari objek yang telah dibuat menggunakan perintah `cout`. Pada file *driver* `main.cpp`, saya menginisialisasi variabel teks `"Struktur Data"` dan `"STD"`, kemudian memanggil fungsi `create_pelajaran` untuk menyimpannya ke dalam variabel objek `pel` dan langsung menampilkannya melalui prosedur `tampil_pelajaran`.

### 3. Buatlah program dengan ketentuan: 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer, fungsi/prosedur yang menampilkan isi sebuah array integer 2D, fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu, serta fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer.

#### File `operasi.h`
```C++
#ifndef OPERASI_H_INCLUDED
#define OPERASI_H_INCLUDED

void tampilArray(int arr[3][3]);

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom);

void tukarPointer(int *ptr1, int *ptr2);

#endif // OPERASI_H_INCLUDED
```

#### File `operasi.cpp`
```C++
#include <iostream>
#include "operasi.h"

using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
    } else {
        cout << "Posisi tidak valid!" << endl;
    }
}

void tukarPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

#### File `main.cpp`
```C++
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
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/cb04b2bf89ebfc1db2123d5814376eaf373cb4fa/Pertemuan%203/screenshot%20output/unguided/Screenshot%20output%20soal%203.png)

Program ini bertujuan untuk memanipulasi dan menukarkan elemen pada dua buah matriks (array 2 dimensi berukuran 3x3) pada koordinat indeks tertentu, serta menukarkan nilai dari dua variabel integer melalui perantara pointer yang dikemas secara modular menggunakan konsep ADT. Di dalam file `operasi.h`, saya mendeklarasikan tiga buah prototipe prosedur, yaitu `tampilArray`, `tukarIsiArray`, dan `tukarPointer`. 

Realisasi kode pada file `operasi.cpp` menggunakan perulangan bersarang (*nested loop*) pada prosedur `tampilArray` untuk mencetak matriks. Pada prosedur `tukarIsiArray`, saya menerapkan pengkondisian `if-else` guna memastikan indeks baris dan kolom yang dimasukkan berada pada rentang valid (0 hingga 2) sebelum menukar elemen kedua matriks menggunakan variabel bantuan `temp`. Sementara itu, prosedur `tukarPointer` memanfaatkan proses *dereferencing* (`*ptr1` dan `*ptr2`) untuk menukar langsung nilai pada alamat memori yang ditunjuk. Di dalam `main.cpp`, program menampilkan kondisi awal matriks, meminta input koordinat baris dan kolom dari pengguna untuk ditukar, menampilkan hasil matriks setelah pertukaran, lalu meminta input dua nilai integer untuk didemonstrasikan proses pertukaran nilainya menggunakan pointer `p1` dan `p2`.

## Kesimpulan
Praktikum pada Modul 3 ini memberikan pemahaman komprehensif mengenai perancangan dan pengimplementasian konsep Abstract Data Type (ADT) di dalam bahasa pemrograman C++. Melalui pemisahan kode program ke dalam tiga komponen file utama—yakni file *header* (`.h`) sebagai spesifikasi tipe dan prototipe primitif, file `.cpp` sebagai wadah realisasi logika fungsi/prosedur, serta file `main.cpp` sebagai modul *driver*—struktur program yang dihasilkan menjadi jauh lebih terorganisir, modular, dan mudah untuk dikembangkan maupun dipelihara (*maintainable*). Penggunaan *header guard* juga terbukti krusial dalam menjaga integritas kompilasi saat banyak modul saling terhubung.

Selain itu, penyelesaian studi kasus pada bagian *unguided* membuktikan bahwa konsep ADT sangat fleksibel untuk dipadukan dengan berbagai konsep fundamental C++ lainnya, seperti array dari `struct`, konstruktor objek, array dua dimensi, hingga manipulasi memori menggunakan pointer. Pembuatan fungsi konstruktor seperti pada ADT pelajaran serta prosedur pertukaran elemen matriks dan pointer melatih kemampuan abstraksi dalam membungkus proses logika yang kompleks ke dalam primitif-primitif yang sederhana dan siap pakai saat dipanggil di program utama.

## Referensi
[1] Modul Praktikum, "Modul 3: ABSTRACT DATA TYPE (ADT)," Modul 03 STUKDAT.pdf, 2024.
<br>[2] Triase. (2020). *Diktat Edisi Revisi : STRUKTUR DATA*. Medan: UNIVERSITAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[3] Indahyati, Uce., Rahmawati Yunianita. (2020). *BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++*. Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.