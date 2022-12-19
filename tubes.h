#ifndef HEADER_H_tubes.h
#define HEADER_H_tubes.h

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define nextDepartment(P) P->nextDepartment
#define info(P) P->info

struct department{
    string nama;
    string kode;
    int jumlahPegawai;
};

struct pegawai{
    string nama;
    string nip;
    string jabatan;
    string golongan;
    int gaji;
};

typedef struct department infotypeDepartmen;
typedef struct pegawai infotypePegawai;

typedef struct elmPegawai *alamatPegawai;
typedef struct elmDepartmen *alamatDepartmen;
struct elmDepartmen{
    alamatDepartmen next;
    infotypeDepartmen info;
};

struct elmPegawai{
    alamatPegawai next;
    alamatDepartmen nextDepartment;
    infotypePegawai info;
};

struct listPegawai{
    alamatPegawai first;
    alamatPegawai last;
};

struct listDepartmen{
    alamatDepartmen first;
    alamatDepartmen last;
};

void createListPegawai(listPegawai &L);
void createListDepartmen(listDepartmen &L);
void createElmDepartmen(infotypeDepartmen x, alamatDepartmen &p);
void createElmPegawai(infotypePegawai x, alamatPegawai &p);
void insertLastPegawai(listPegawai &L, alamatPegawai p);
void insertLastDepartmen(listDepartmen &L, alamatDepartmen p);

#endif