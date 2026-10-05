# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)
<p align="center">I Kadek Indra Mahottama - 109082500039</p>

## Dasar Teori
Array merupakan kumpulan data yang setiap elemennya memiliki tipe data yang sama dan dapat diakses menggunakan nama variabel yang sama. Elemen-elemen ini dialokasikan pada lokasi memori yang berurutan, di mana elemen pertama selalu dimulai dari indeks 0 [1]. Array dapat berupa satu dimensi (sebuah larik tunggal), dua dimensi (berbentuk tabel dengan baris dan kolom), hingga multi-dimensi (lebih dari dua indeks) [1]. Penggunaan array, terutama dua dimensi, sering diimplementasikan untuk merepresentasikan struktur data kompleks seperti tabel atau matriks [1].

Pointer adalah tipe variabel khusus yang menyimpan alamat memori (dalam format heksadesimal) dari suatu data alih-alih menyimpan nilai datanya secara langsung [1]. Penggunaan pointer, ditandai dengan operator bintang (`*`), memungkinkan akses dan modifikasi langsung ke ruang memori suatu variabel yang alamatnya didapatkan menggunakan operator ampersand (`&`) [1]. Pointer memiliki keterikatan yang erat dengan array, di mana notasi nama array tanpa indeks pada dasarnya merujuk ke alamat memori elemen ke-0 dari array tersebut [1].

Dalam C++, instruksi program dapat dikelompokkan ke dalam blok modular yang disebut Fungsi dan Prosedur. Fungsi dirancang untuk menerima input (*parameter*), memproses data, dan mengembalikan hasil (*return value*). Di sisi lain, Prosedur (sering dideklarasikan dengan tipe `void`) melakukan serangkaian tugas tanpa mengembalikan nilai akhir kepada pemanggilnya [1]. Terdapat tiga metode pengiriman parameter (argumen) dari fungsi utama ke subprogram: *Call by Value* yang hanya mengirimkan salinan nilai (sehingga variabel asli tidak berubah), *Call by Pointer* yang mengirimkan alamat memori melalui variabel pointer, dan *Call by Reference* yang mengirimkan alias dari variabel asli tanpa memerlukan operator khusus pada saat pemanggilan fungsi [1]. Baik *Pointer* maupun *Reference* memungkinkan subprogram untuk memanipulasi dan mengubah nilai variabel asli yang berada di luar ruang lingkup (scope) fungsi tersebut [1].

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[5];

    nilai[0]= 80;
    nilai[1]= 75;
    nilai[2]= 90;
    nilai[3]= 85;
    nilai[4]= 95;

    for (int i = 0;i<5;i++) {
        cout<<"Nilai ke-"<< i+1<<" = "<<nilai[i]<<endl;
    }

    return 0;
}
```
Program di atas mendemonstrasikan deklarasi dan inisialisasi array 1 dimensi bertipe `int` dengan ukuran 5 elemen. Data diisi secara manual pada setiap indeks (0 hingga 4), lalu ditampilkan secara berurutan menggunakan struktur perulangan `for`.

### 2. Array 2D

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[3][3] = {
        {80,75,90},
        {85,90,88},
        {70,80,85}
    };
        // Print array 2 dimensi
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << nilai [i][j]<<" ";
        }

        cout << endl;
    }
    cout<<endl;
    cout<<nilai[1][2]<<endl; // menghasilkan baris ke 1, kolom ke 2 = 88 (ingat baris dan kolom dimulai dari 0)
    return 0;
}
```
Program ini menunjukkan penggunaan array 2 dimensi (matriks ordo 3x3). Pencetakan elemen ke layar dilakukan melalui perulangan bersarang (*nested loop*), di mana perulangan luar mengontrol baris dan perulangan dalam mengontrol kolom.

### 3. Array 3D

```C++
#include <iostream>
using namespace std;

int main(){

    //Format array 3 dimensi : nama_array[jumlah array 2D][jumlah baris setiap array 2D][kolom baris setiap array 2D]
    int data[2][2][3] = {
        {
            {10,20,30},
            {40,50,60}
        },
        {
            {70,80,90},
            {100,110,120}
        }
    };

    cout<< data[0][1][2]<<endl;

    return 0;
}
```
Program ini membuat array 3 dimensi yang menyimpan kumpulan matriks 2 dimensi. Kode tersebut mendemonstrasikan cara mengakses elemen tunggal secara spesifik dengan memanggil indeks *layer*, baris, dan kolom (`data[0][1][2]`).

### 4. function

```C++
#include <iostream>
using namespace std;

int maks3(int a,int b,int c) {
    int temp_max = a;

    if (b>temp_max) {
        temp_max = b;
    }
    if (c>temp_max) {
        temp_max = c;
    }

    return temp_max;
}

int main(){
    int x,y,z;

    cout<<"Masukan nilai 1 : ";
    cin>>x;

    cout<<"Masukan nilai 2 : ";
    cin>>y;

    cout<<"Masukan nilai 3 : ";
    cin>>z;

    cout<<"Nilai Maksimum: "<< maks3(x,y,z);

    return 0;
}
```
Program ini menggunakan sebuah fungsi bernama `maks3` bertipe `int` untuk mencari nilai terbesar di antara tiga bilangan. Fungsi ini membandingkan input yang diterima melalui argumen, lalu mengembalikan (`return`) nilai tertinggi untuk dicetak pada fungsi utama (`main`).

### 5. procedure

```C++
#include <iostream>
using namespace std;

void sapa(){
    cout<<"Selamat datang di Praktikum Struktur data" << endl;
}

int main(){
    sapa();
    return 0;
}
```
Kode ini merupakan contoh sederhana penggunaan prosedur yang ditandai dengan *keyword* `void`. Prosedur `sapa()` hanya menjalankan instruksi mencetak teks ke layar dan tidak mengembalikan nilai apapun saat dipanggil di dalam fungsi `main()`.

### 6. pointer 1

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    cout<<"Nilai variabel angka: "<< angka << endl;
    cout<<"Alamat variabel angka: "<< &angka << endl;

    return 0;
}
```
Program ini mendemonstrasikan cara mengetahui alamat memori asli dari suatu variabel. Dengan menambahkan operator *ampersand* (`&`) di depan nama variabel, program tidak akan menampilkan nilainya (100), melainkan menampilkan alamat heksadesimal di mana data tersebut disimpan di RAM.

### 7. Pointer2

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout<<"Nilai angka  : "<<angka<<endl; //Nilai dari variabel angka yaitu 100
    cout<<"Alamat angka  : "<<&angka<<endl; //Alamat dari variabel angka
    cout<<"isi variabel pointer  : "<<pointer<<endl; //Alamat dari variabel angka
    cout<<"Nilai dari variabel pointer  : "<<*pointer<<endl;//Value dari variabel angka yaitu 100
}
```
Program ini menggunakan variabel pointer (dengan operator `*`) yang menyimpan alamat memori dari variabel `angka`. Kode ini mengilustrasikan perbedaan antara menampilkan isi pointer (alamat memori) dan melakukan *dereferencing* (`*pointer`) untuk melihat nilai dari alamat yang ditunjuk.

### 8. Pointer Array

```C++
#include <iostream>
using namespace std;

int main(){
    char arr[6];

    arr[0]='a';
    arr[1]='b';
    arr[2]='c';
    arr[3]='b';
    arr[4]='d';
    arr[5]='e';

    cout<< arr[3]<<endl; //menampilkan value
    cout<< &(arr[4])<<endl; //menampilkan alamat value
}
```
Kode ini menggabungkan konsep array karakter dengan pointer. Selain mencetak nilai elemen pada indeks ke-3 secara normal, program ini juga mencetak alamat memori dari elemen indeks ke-4 menggunakan sintaks `&(arr[4])`.

### 9. CallByPointerRefrenceValue

```C++
#include <iostream>
using namespace std;

//BY POINTER
void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
```
Program ini menunjukkan penerapan *Call by Pointer, Reference, Value* untuk menukar dua nilai. Dengan meneruskan alamat memori (menggunakan `&a`, `&b`) ke fungsi yang memiliki parameter pointer (`*x`, `*y`), perubahan yang terjadi di dalam fungsi `tukar` akan langsung berdampak pada variabel asli `a` dan `b` di fungsi `main`.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
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

    // 3. Perkalian Matriks
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/eae64ac98089c7f6dca90b0ea152a9ea849d380e/Pertemuan%202/Unguide/Screenshoot%20hasil/Unguided/unguided%201_1.png)

![Screenshot Output Unguided 1_2](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/eae64ac98089c7f6dca90b0ea152a9ea849d380e/Pertemuan%202/Unguide/Screenshoot%20hasil/Unguided/unguided%201_2.png)

Program ini bertujuan untuk mensimulasikan kalkulator matriks sederhana yang mampu melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks berukuran 3x3. Dalam kode yang saya buat, program pertama-tama akan meminta pengguna untuk menginputkan nilai secara manual untuk setiap elemen baris dan kolom pada Matriks 1 dan Matriks 2 dengan bantuan *nested loop*. Setelah matriks berhasil disusun dan dicetak ke layar, alur logika dilanjutkan dengan menghitung operasi matematisnya. Untuk penjumlahan dan pengurangan, saya memproses elemen-elemen yang berada pada posisi indeks yang sama secara langsung di dalam perintah `cout`. Khusus untuk operasi perkalian, saya menambahkan tingkat perulangan ketiga (variabel `k`) untuk menjalankan rumus aljabar linear yaitu mengalikan setiap elemen baris dari matriks pertama dengan elemen kolom dari matriks kedua, lalu menjumlahkan dan mencetak hasil kalinya.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/eae64ac98089c7f6dca90b0ea152a9ea849d380e/Pertemuan%202/Unguide/Screenshoot%20hasil/Unguided/unguidedd%202.png)

Program ini berfungsi untuk menukar (menggeser secara memutar) nilai dari tiga variabel yang berbeda dengan mengimplementasikan metode manipulasi alamat memori atau *Call by Pointer*. Dalam kode ini, saya merancang fungsi `tukarTigaPointer` yang menerima parameter bertipe pointer (`*x`, `*y`, `*z`). Di dalam fungsi tersebut, saya mendefinisikan sebuah variabel penyimpan sementara (`temp`) untuk mengamankan nilai awal, sehingga setiap nilai variabel dapat digeser dan ditimpa secara berurutan. Saat fungsi ini dipanggil di dalam fungsi `main`, saya harus melampirkan operator ampersand (`&`) di depan variabel asli (`&a, &b, &c`) agar program mengirimkan referensi alamat memorinya, bukan sekadar salinan nilainya. Hal ini menjamin nilai asli di dalam fungsi `main` ikut berubah dan tertukar setelah eksekusi fungsi selesai.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut: arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitung RataRata() untuk menghitung nilai rata-rata! Buat program menggunakan menu switch-case seperti berikut ini: Menu Program Array, Tampilkan isi array, cari nilai maksimum, cari nilai minimum, Hitung nilai rata - rata

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/eae64ac98089c7f6dca90b0ea152a9ea849d380e/Pertemuan%202/Unguide/Screenshoot%20hasil/Unguided/unguided%203_1.png)

![Screenshot Output Unguided 3_2](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/eae64ac98089c7f6dca90b0ea152a9ea849d380e/Pertemuan%202/Unguide/Screenshoot%20hasil/Unguided/unguided%203_2.png)

Program ini bertujuan untuk membangun sebuah sistem menu interaktif yang dapat memproses dan mengekstraksi informasi matematis dasar dari sebuah array satu dimensi yang bersifat statis. Untuk menyusun program secara terstruktur (modular), saya memisahkan logika pencarian batas nilai ke dalam dua fungsi bertipe `int` yaitu `cariMinimum()` dan `cariMaksimum()` yang akan mengembalikan nilai, serta mendefinisikan sebuah prosedur (fungsi bertipe `void`) bernama `hitungRataRata()` yang akan mengakumulasi total elemen dan langsung mencetak nilai rata-ratanya ke layar. Pada bagian fungsi utama (`main`), saya menggunakan perulangan `do-while` bersama dengan instruksi pemilihan `switch-case` agar program dapat terus menampilkan antar-muka (*interface*) menu dan mengeksekusi pilihan pengguna selama mereka tidak memasukkan angka 0 sebagai perintah keluar.

## Kesimpulan
Praktikum pada Modul 2 ini memberikan pemahaman lanjutan mengenai pengorganisasian data melalui Array serta pengelompokan intruksi program menggunakan Fungsi dan Prosedur di dalam bahasa C++. Melalui studi kasus operasi array (1D, 2D, 3D), telah dibuktikan bahwa array dipadukan dengan perulangan bersarang sangat efektif untuk memetakan logika matriks dan melakukan perhitungan aljabar yang sistematis. Di sisi lain, pemecahan subprogram dengan menggunakan fungsi (*return value*) dan prosedur (`void`) membuat struktur sintaks menjadi jauh lebih rapi, terisolasi dengan baik secara modular, dan mudah di-*maintenance* ulang tanpa harus menumpuk kode di fungsi utama.

Selain itu, eksplorasi terhadap tipe variabel khusus Pointer dan cara pengiriman parameter *Call by Reference* memberikan gambaran yang lebih transparan tentang hierarki alokasi memori komputer. Pemahaman terhadap metode pengiriman parameter ini sangat krusial, mengingat ketepatan dalam membedakan manipulasi nilai salinan dengan manipulasi memori asli (*addressing*) merupakan kunci utama untuk menghindari *bug* serta mencegah kebocoran memori saat mengembangkan struktur data skala besar yang dinamis. 

## Referensi
[1] Modul Praktikum, "Modul 2: PENGENALAN BAHASA C++ (BAGIAN KEDUA)," Modul 02 STUKDAT.pdf, 2024.