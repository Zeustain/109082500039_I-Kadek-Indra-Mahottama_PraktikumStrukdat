# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">I Kadek Indra Mahottama - 109082500039</p>

## Dasar Teori
Golang (Go) dan C++ merupakan bahasa pemrograman kompilasi yang memiliki pendekatan manajemen memori, paradigma, dan kompleksitas sintaksis yang berbeda. Golang dikenal dengan sintaks yang lebih ringkas, kemudahan dalam menangani konkurensi, serta memiliki manajemen memori otomatis dengan fitur garbage collection yang mempermudah pengembangan sistem berskala besar [1]. Sebaliknya, bahasa C++ menuntut pengembang untuk memiliki pemahaman tingkat rendah (low-level) yang lebih mendalam karena alokasi dan dealokasi memori dilakukan secara manual. Meskipun memiliki kompleksitas penulisan yang lebih tinggi dibandingkan Golang, C++ menawarkan kontrol memori yang sangat presisi dan efisiensi waktu eksekusi yang optimal, sehingga sering digunakan pada komputasi intensif dan implementasi struktur data tingkat lanjut [2]. Bahasa C++ itu sendiri pertama kali dikembangkan sebagai ekstensi dari bahasa C yang dipercanggih dengan fasilitas pemrograman berorientasi objek (kelas) [3].

Secara garis besar, pembahasan pada Modul 01 berfokus pada pengenalan lingkungan pengembangan Code Blocks IDE serta dasar-dasar pemrograman menggunakan bahasa C++ [3]. Pembahasan diawali dengan pengenalan lingkungan perangkat lunak Code Blocks, yang mencakup cara instalasi, pembuatan proyek baru, penulisan sintaks, hingga tahapan kompilasi dan eksekusi program [3]. Selanjutnya, modul ini menguraikan secara fundamental mengenai struktur utama program C++, aturan pengenal (identifier), tipe data dasar (seperti char, int, dan float), serta panduan mendeklarasikan variabel maupun konstanta [3]. Modul ini juga memberikan penjelasan komprehensif terkait penggunaan fungsi input/output (seperti cin dan cout), implementasi berbagai jenis operator (aritmatika, penugasan, logika), instruksi kondisional (if dan switch), perulangan (for, while, do-while), hingga pembuatan tipe data bentukan atau rekaman (struct) [3].


## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float x, y;
    
    cout << "Masukkan angka pertama: ";
    cin >> x;
    cout << "Masukkan angka kedua: ";
    cin >> y;

    cout << "\n--- Hasil Operasi ---" << endl;
    cout << "Penjumlahan : " << x + y << endl;
    cout << "Pengurangan : " << x - y << endl;
    cout << "Perkalian   : " << x * y << endl;
    
    if (y == 0) {
        cout << "Pembagian   : Error (Tidak bisa dibagi nol)" << endl;
    } else {
        cout << "Pembagian   : " << x / y << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/59c53505218433d91ece893b5a6f57ae5fdb1710/Pertemuan%201/Unguided/Screenshoot%20hasil/Output%20unguided%201_1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/59c53505218433d91ece893b5a6f57ae5fdb1710/Pertemuan%201/Unguided/Screenshoot%20hasil/Output%20unguided%201_2.png)

Program ini bertujuan untuk melakukan operasi aritmatika dasar yang mencakup penjumlahan, pengurangan, perkalian, dan pembagian dari dua buah bilangan. Dalam kode yang saya buat, saya menggunakan variabel bertipe float (bilangan desimal) agar perhitungan dapat menangani angka pecahan dengan presisi. Alur logikanya dimulai dengan meminta masukan dua angka dari pengguna menggunakan sintaks cin, kemudian program akan langsung memproses dan mencetak hasil operasi tersebut menggunakan cout. Khusus untuk operasi pembagian, saya menambahkan struktur seleksi kondisi if-else untuk memvalidasi angka kedua, jika bernilai nol, program akan menampilkan pesan error untuk menghindari kesalahan pembagian dengan nol, dan jika tidak, program akan menampilkan hasil pembagian seperti biasa. 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100. Contoh: input = 79, ouput = 79: tujuh puluh sembilan.

```C++
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
```
### Output Unguided 2 :

##### Output 1 & 2
![Screenshot Output Unguided 2_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/59c53505218433d91ece893b5a6f57ae5fdb1710/Pertemuan%201/Unguided/Screenshoot%20hasil/Output%20unguided%202.png)

Program ini berfungsi untuk mengonversi nilai angka numerik bilangan bulat menjadi ejaan tulisan dalam bahasa Indonesia, dengan batasan input dari 0 hingga 100. Untuk merealisasikan hal ini, saya mendefinisikan sebuah fungsi khusus bernama tulisan(int n) yang menggunakan array of string untuk menyimpan kumpulan kata dasar dari "nol" hingga "sebelas". Logika penyusunan katanya memanfaatkan operasi aritmatika pembagian (/) dan sisa bagi atau modulo (%) di dalam blok if-else if bertingkat guna menentukan pola ejaan untuk angka belasan, puluhan, dan angka seratus. Pada fungsi main(), saya juga mengimplementasikan validasi input dengan if logika AND (&&) untuk memastikan program hanya memanggil fungsi konversi apabila pengguna memasukkan angka yang berada dalam rentang 0 sampai 100.

### 3. Buatlah program yang dapat memberikan input dan output sbb. 
output:

3 2 1 * 1 2 3
  2 1 * 1 2
    1 * 1
      *

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output:\n" << endl;

    for (int i = n; i >= 0; i--) {
        for (int s = 0; s < (n - i) * 2; s++) {
            cout << " ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*";
        
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/59c53505218433d91ece893b5a6f57ae5fdb1710/Pertemuan%201/Unguided/Screenshoot%20hasil/Output%20unguided%203_1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Zeustain/109082500039_I-Kadek-Indra-Mahottama_PraktikumStrukdat/blob/59c53505218433d91ece893b5a6f57ae5fdb1710/Pertemuan%201/Unguided/Screenshoot%20hasil/Output%20unguided%203_2.png)

Program ini bertujuan untuk mencetak pola angka simetris menyerupai cermin yang berbentuk segitiga terbalik, dengan karakter bintang (*) sebagai titik pusat sumbunya. Pada penulisan sintaksnya, saya menerapkan konsep perulangan bersarang (nested loop) dengan menggunakan instruksi for. Alur logikanya berjalan dari perulangan terluar yang mengontrol baris secara menurun (decrement). Di dalam baris tersebut, terdapat perulangan-perulangan anak: perulangan pertama bertugas mencetak spasi untuk mendorong karakter ke tengah, perulangan kedua mencetak deret angka yang menurun hingga angka 1, dilanjutkan dengan mencetak karakter pembatas *, dan ditutup oleh perulangan ketiga yang mencetak deret angka menaik. Kombinasi batas nilai pada kondisi for tersebut memastikan jarak dan angka tercetak dengan sejajar.

## Kesimpulan
Praktikum pada Modul 1 ini memberikan pemahaman fundamental yang sangat baik mengenai penggunaan lingkungan pengembangan Code Blocks IDE serta struktur dasar pemrograman menggunakan bahasa C++. Melalui serangkaian latihan yang telah dilakukan, konsep-konsep esensial seperti deklarasi tipe data, inisialisasi variabel, operasi aritmatika, dan penanganan fungsi input/output standar telah berhasil diimplementasikan dengan baik. Penguasaan dasar-dasar ini menjadi pondasi awal yang krusial untuk membangun logika algoritma yang terstruktur, terutama dalam mengelola interaksi data numerik dan teks di dalam bahasa pemrograman berbasis kompilasi.

Di samping itu, penyelesaian berbagai studi kasus pada penugasan unguided membuktikan bahwa kombinasi instruksi kondisional dan perulangan bersarang (nested loop) sangat berperan penting dalam merancang solusi komputasi yang dinamis. Penerapan struktur seleksi kondisi (seperti if-else) terbukti efektif untuk melakukan validasi aliran program, mulai dari mencegah kesalahan perhitungan pembagian dengan nol hingga menyusun logika konversi angka menjadi ejaan teks secara akurat. Pemahaman terkait logika perulangan juga berhasil diterapkan untuk memanipulasi tata letak baris dan spasi dalam membentuk pola visual yang presisi, yang secara keseluruhan sangat melatih kemampuan analisis serta penyelesaian masalah (problem solving) menggunakan C++.

## Referensi
[1] I. Plauska, A. Liutkevičius, and A. Janavičiūtė, "Performance Evaluation of C/C++, MicroPython, Rust and TinyGo Programming Languages on ESP32 Microcontroller," Electronics, vol. 12, no. 1, p. 143, Dec. 2022, doi: 10.3390/electronics12010143. 
<br>[2] R. Pereira et al., "Energy efficiency across programming languages: how do energy, time, and memory relate?," in Proceedings of the 10th ACM SIGPLAN International Conference on Software Language Engineering, 2017, pp. 256–267, doi: 10.1145/3136014.3136031.
<br>[3] Modul Praktikum, "Modul 1: CODE BLOCKS IDE & PENGENALAN BAHASA C++ (BAGIAN PERTAMA)," Modul 01 STUKDAT (1).pdf, 2024.
