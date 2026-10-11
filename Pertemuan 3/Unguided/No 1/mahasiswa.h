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