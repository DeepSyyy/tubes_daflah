#include "D:\Kuliah\Tingkat 2\SMT 3\STD\Tubes\tubes.h"

int main()
{
    listPegawai LP;
    listDepartmen LD;
    createListPegawai(LP);
    createListDepartmen(LD);
    infotypeDepartmen x;
    x.nama = "Keuangan";
    x.kode = "K";
    x.jumlahPegawai = 0;
    alamatDepartmen p;
    createElmDepartmen(x, p);
    insertLastDepartmen(LD, p);
    infotypePegawai y;
    y.nama = "Rizki";
    y.nip = "123";
    y.jabatan = "Manager";
    y.golongan = "A";
    y.gaji = 1000000;
    alamatPegawai q;
    createElmPegawai(y, q);
    insertLastPegawai(LP, q);
    memasangkanPegawai(LP, LD,"Rizki" ,"123", "Keuangan");
    printPegawai(LP);
    printDepartmen(LD);
    printDepartmenbyPegawai(LP, "Rizki", "123");
    return 0;
}