#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define nextf(p) (p)->nextf
#define first(L) ((L).first)
#define last(L) ((L).last)
#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define child(p) (p)->child
#define relasi(p) (p)->relasi

typedef string infotypePerguruanT;
typedef string infotypeFakultas;
typedef struct elemenPerguruanT *adr_PerguruanT;
typedef struct elemenFakultas *adr_Fakultas;
typedef struct elemenRelasi *adr_Relasi;

/*PARENT (PERGURUAN TINGGI)*/
struct elemenPerguruanT{
    infotypePerguruanT info;
    adr_Relasi child;
    adr_PerguruanT next;
    adr_PerguruanT prev;
};

struct listPerguruanT{
    adr_PerguruanT first;
    adr_PerguruanT last;
};

/*CHILD (FAKULTAS)*/
struct elemenFakultas{
    infotypeFakultas info;
    adr_Fakultas next;
};

struct listFakultas{
    adr_Fakultas first;
};

/*RELASI*/
struct elemenRelasi{
    adr_Relasi relasi;
    adr_Fakultas nextf;
};

/*PRIMITIF*/
void createListPerguruanT(listPerguruanT &LP);
void createListFakultas(listFakultas &LF);
adr_PerguruanT newPerguruanT(infotypePerguruanT x);
adr_Fakultas newFakultas(infotypeFakultas x);
adr_Relasi newrelasi(adr_Fakultas x);
void insertLastP(listPerguruanT &LP, adr_PerguruanT p);//a
void insertLastF(listFakultas &LF, adr_Fakultas p);//b
adr_PerguruanT searchP(listPerguruanT LP, string kampus);//c
void insertRelasi(listPerguruanT &LP, listFakultas &LF, string a, string b);//d
adr_Relasi searchR(adr_PerguruanT p, string fakultas);
adr_PerguruanT searchP(listPerguruanT LP, string kampus);//e
adr_Fakultas searchF(listFakultas LF, string nama);
void deletePerguruanT(listPerguruanT &LP, adr_PerguruanT &p,string kampus);//f
void deleteFakultasP(listFakultas &LF, adr_Relasi &p, string nama);//
void showperguruan(listPerguruanT LP);
void showfakultas(listFakultas LF);
void showAll(listPerguruanT LP);//h
int countFakultas(adr_PerguruanT LP);//i
void showMin(listPerguruanT LP);//j
int menu();


#endif // TUBES_H_INCLUDED
