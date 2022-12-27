#include "D:\Kuliah\Tingkat 2\SMT 3\STD\Tubes\tubes.h"

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

alamatPegawai searchPegawai(listPegawai L, string nip){
	alamatPegawai p = first(L);
	while (p != NULL){
		if (info(p).nip == nip){
			return p;
		}
		p = next(p);
	} 
	return NULL;
}

alamatDepartmen searchDepartmen(listDepartmen L, string nama){
	alamatDepartmen p = first(L);
	while (p != NULL){
		if (info(p).nama == nama){
			return p;
		}
		p = next(p);
	}
	return NULL;
}

void printPegawai(listPegawai L){
	if (first(L) == NULL){
		cout << "list kosong" << endl;
	} else {
		alamatPegawai p = first(L);
		while (p != NULL){
			cout << "nama : " << info(p).nama << endl;
			cout << "nip : " << info(p).nip << endl;
			cout << "jabatan : " <<  info(p).jabatan << endl;
			cout << "golongan : " << info(p).golongan << endl;
			cout << "gaji : " << info(p).gaji << endl;
			
			p = next(p);
		}
	}
}

void printDepartmen(listDepartmen L){
	if (first(L) == NULL){
		cout << "list kosong" << endl;
	} else {
		alamatDepartmen p = first(L);
		while (p != NULL){
			cout << "nama : " << info(p).nama << endl;
			cout << "kode departemen : " << info(p).kode << endl;
			cout << "jumlah pegawai : " << info(p).jumlahPegawai << endl;
			
			p = next(p);
		}
	}
}

void printDepartmenbyPegawai(listPegawai L, string nama, string nip){
	alamatPegawai p = first(L);
	alamatDepartmen d;
	while ((info(p).nama != nama) && (info(p).nip != nip) && (p != NULL)){
		p = next(p);
	}
    cout<<"Test"<<endl;
	cout << "departmen milik " << nama << " dengan " << nip << " adalah : "<< endl;
	cout << "nama : " << info(nextDepartment(p)).nama << endl;
	cout << "kode departemen : " << info(nextDepartment(p)).kode << endl;
	cout << "jumlah pegawai : " << info(nextDepartment(p)).jumlahPegawai << endl;
}

void memasangkanPegawai(listPegawai &L, listDepartmen &D, string nama, string nip, string namaDepartmen){
    alamatPegawai p = searchPegawai(L, nip);
    alamatDepartmen d = searchDepartmen(D, namaDepartmen);
    if ((p != NULL) && (d != NULL)){
        nextDepartment(p) = d;
        info(d).jumlahPegawai = info(d).jumlahPegawai + 1;
    } else {
        cout << "data tidak ditemukan" << endl;
    }
}