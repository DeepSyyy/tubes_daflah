#include "tubes.h"

void createListPegawai(listPegawai &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createListDepartmen(listDepartmen &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createElmDepartmen(infotypeDepartmen x, alamatDepartmen &p){
    p = new elmDepartmen;
    info(p) = x;
    next(p) = NULL;
}

void createElmPegawai(infotypePegawai x, alamatPegawai &p){
    p = new elmPegawai;
    info(p) = x;
    next(p) = NULL;
    nextDepartment(p) = NULL;
}

void insertLastPegawai(listPegawai &L, alamatPegawai p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else{
        next(last(L)) = p;
        last(L) = p;
    }
}

void insertLastDepartmen(listDepartmen &L, alamatDepartmen p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else{
        next(last(L)) = p;
        last(L) = p;
    }
}