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