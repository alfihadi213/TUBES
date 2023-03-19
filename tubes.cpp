#include "tubes.h"

void createListPerguruanT(listPerguruanT &LP){
    first(LP) = NULL;
    last(LP) = NULL;
}

void createListFakultas(listFakultas &LF){
    first(LF) = NULL;
}

adr_Relasi newrelasi(adr_Fakultas x){
    adr_Relasi p;
	p = new elemenRelasi;
	nextf(p) = x;
	relasi(p) = NULL;
	return p;
}

void insertRelasi(listPerguruanT &LP, listFakultas &LF, string a, string b){
    adr_PerguruanT P = searchP(LP, a);
    adr_Fakultas Q = searchF(LF, b);

    if (P != NULL & Q != NULL) {
        if (child(P) == NULL) {
            adr_Relasi R = newrelasi(Q);
            child(P) = R;
        } else {
            adr_Relasi R = child(P);
            adr_Relasi R1 = newrelasi(Q);
            while(relasi(R) != NULL) {
                R = relasi(R);
            }
            relasi(R) = R1;
            cout << "Relasi berhasil ditambah" << endl;
        }
    }else if (P != NULL & Q == NULL){
        cout << "Relasi Gagal ditambahkan Data Fakultas tidak ada " << endl;
    }else{
        cout << "Relasi Gagal ditambahkan Data perguruan tidak ada " << endl;
    }
}

adr_PerguruanT newPerguruanT(infotypePerguruanT x){
    adr_PerguruanT p;
	p = new elemenPerguruanT;
	info(p) = x;
	child(p) = NULL;
	next(p) = NULL;
	prev(p) = NULL;
	return p;
}

adr_Fakultas newFakultas(infotypeFakultas x){
    adr_Fakultas p;
	p = new elemenFakultas;
	info(p) = x;
	next(p) = NULL;
	return p;
}

void insertLastP(listPerguruanT &LP, adr_PerguruanT p){
    if (first(LP) != NULL){
		adr_PerguruanT t = first(LP);
		while (next(t) != NULL){
			t = next(t);
		}
		next(t) = p;
	}else{
		first(LP) = p;
	}
}

void insertLastF(listFakultas &LF, adr_Fakultas p){
    if (first(LF) != NULL){
        adr_Fakultas f = first(LF);
        while (next(f) != NULL){
            f = next(f);
        }
        next(f) = p;
    }else{
        first(LF) = p;
    }
}

adr_PerguruanT searchP(listPerguruanT LP, string kampus){
    adr_PerguruanT t = first(LP);
	while (t != NULL){
		if (info(t) == kampus){
			return t;
		}
		t = next(t);
	}
	return NULL;
}

adr_Fakultas searchF(listFakultas LF, string nama){
    adr_Fakultas t = first(LF);
	while (t != NULL){
		if (info(t) == nama){
			return t;
		}
		t = next(t);
	}
	return NULL;
}

adr_Relasi searchR(adr_PerguruanT P, string fakultas){
    adr_Relasi R = child(P);
    while(R != NULL && info(nextf(R)) != fakultas){
        R = relasi(R);
    }
    return R;
}

void deletePerguruanT(listPerguruanT &LP, adr_PerguruanT &p, string kampus){
    adr_PerguruanT W = searchP(LP,kampus);
    adr_PerguruanT Q = prev(W);
    if (next(W)== NULL){
        prev(W) = NULL;
        next(Q) = NULL;
        W = NULL;
    }else if (prev(W) == NULL){
        first(LP) = next(W);
        next(W) = NULL;
        prev(first(LP)) = NULL;
        W = NULL;
    }else{
        next(Q) = next(W);
        prev(next(W)) = Q;
        prev(W) = NULL;
        next(W) = NULL;
        W = NULL;
    }


}
void deleteFakultasP(listFakultas &LF, adr_Relasi &p, string nama){
    adr_Fakultas W = searchF(LF,nama);
    adr_Fakultas Q = first(LF);
    if (next(W)== first(LF)){
        while (next(Q) != W){
            Q = next(Q);
        }
        next(Q) = first(LF);
        next(W) = NULL;
        W = NULL;
    }else if ((W) == first(LF)){
        while (next(Q)!= W){
            Q = next(Q);
        }
        first(LF) = next(W);
        next(Q) = first(LF);
        next(W) = NULL;
        W = NULL;
    }else{
        while (next(Q) != W ){
            Q = next(Q);
        }
        next(Q) = next(W);
        next(W) = NULL;
        W = NULL;
    }
}

void showperguruan(listPerguruanT LP){
adr_PerguruanT P = first(LP);
    if (P == NULL){
        cout << "Belum ada data Perguruan tinggi yang ditambahkan" << endl;
    }else{
        int i = 1;
        while(P != NULL){
            cout << "data ke Perguruan Tinggi : " << i << endl;
            cout << "Nama Perguruan Tinggi : " << info(P) << endl;
            cout << endl;
            P = next(P);
            i++;
        }
    }
}

void showfakultas(listFakultas LF){
adr_Fakultas P = first(LF);
    if (P == NULL){
        cout << "Belum ada data Fakultas yang ditambahkan" << endl;
    }else{
        int i = 1;
        while(P != NULL){
            cout << "data  Fakultas ke : " << i << endl;
            cout << "Nama Fakultas : " << info(P) << endl;
            cout << endl;
            P = next(P);
            i++;
        }
    }
}

void showAll(listPerguruanT LP){
    adr_PerguruanT P = first(LP);
    if (P == NULL){
        cout << "Belum ada data yang ditambahkan" << endl;
    }else{
        int i = 1;
        while(P != NULL){
            cout << "data ke : " << i << endl;
            cout << "Nama Perguruan Tinggi : " << info(P) << endl;
            cout << "Fakultas yang dimiliki : " << endl;
            if(child(P) != NULL){
                adr_Relasi Q = child(P);
                while(Q != NULL) {
                    cout << "Fakultas " << info(nextf(Q)) << endl;
                    Q = relasi(Q);
                }
            }
            cout << endl;
            P = next(P);
            i++;
        }
    }
}
int countFakultas(adr_PerguruanT LP){
    int count = 0;
    adr_Relasi P = child(LP);
    while(P != NULL){
        count = count + 1;
        P = relasi(P);
    }
    return count;
}

void showMin(listPerguruanT LP){
    adr_PerguruanT P = first(LP);
    adr_PerguruanT min = P;
    while(P != NULL){
        if(countFakultas(P) < countFakultas(min)){
            min = P;
        }
        P = next(P);
    }
    cout << " Perguruan Tinggi yang fakultas paling sedikit adalah " << info(min) << endl;
}
int menu(){
    cout << endl;
    cout << "=======================================================" << endl;
    cout << "         PROGRAM PERGURUAN TINGGI DAN FAKULTAS         " << endl;
    cout << "=======================================================" << endl;
    cout << "Dibuat oleh :" << endl;
    cout << "Alfi Hadi Maulana (1303210027) " << endl;
    cout << "Disca Safa Kirana (1303213052) " << endl;
    cout << "========================== MENU =======================" << endl;
    cout << "1. Tambahkan data perguruan" << endl;
    cout << "2. Tambahkan data fakultas" << endl;
    cout << "3. Cari data perguruan" << endl;
    cout << "4. Tambah relasi perguruan dengan fakultas" << endl;
    cout << "5. Cari data fakultas dalam data perguruan" << endl;
    cout << "6. Hapus data perguruan beserta relasinya" << endl;
    cout << "7. Hapus data fakultas pada perguruan" << endl;
    cout << "8. Tampilkan seluruh data perguruan beserta fakultas" << endl;
    cout << "9. Tampilkan seluruh data perguruan " << endl;
    cout << "10. Tampilkan seluruh data fakultas " << endl;
    cout << "11. Tampilkan Jumlah fakultas pada perguruan tinggi" << endl;
    cout << "12. Tampilkan data perguruan yang paling sedikit" << endl;
    cout << "========================================================" << endl;

    int input = 0;
    cout << endl;
    cout << " Pilih aktivitas yang ingin dilakukan " << endl;
    cout << " >> ";
    cin >> input;
    return input;
}
