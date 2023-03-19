#include <iostream>
#include "tubes.h"

using namespace std;

int main()
{
    listPerguruanT Lp;
    listFakultas Lf;
    adr_PerguruanT x;
    adr_Fakultas y;
    adr_Relasi nr;
    int pilihan, jf;
    int n = 0;
    string pa,np;
    string a, b;
    string Kembali_ke_Menu;
    createListPerguruanT(Lp);
    createListFakultas(Lf);

    pilihan = menu();
    while (pilihan != 0){
        cout << endl;
        switch(pilihan){
            case 1:
            cout << "Jumlah perguruan yang ingin ditambahkan " << endl;
            cout << " :: ";
            cin >> n;
            while (n>0){
                cout << "Masukan nama perguruan : ";
                cin >> pa;
                x = newPerguruanT(pa);
                insertLastP(Lp,x);
                n--;
            }
            system("cls");
            break;

            case 2:
            cout << "Jumlah fakultas yang ingin ditambahkan " << endl;
            cout << " :: ";
            cin >> n;
            while (n>0){
                cout << "Masukan nama fakultas : ";
                cin >> pa;
                y = newFakultas(pa);
                insertLastF(Lf,y);
                n--;
            }
            system("cls");
            break;

            case 3:
                cout << "Masukan nama perguruan yang dicari : ";
                cin >> np;
                if (searchP(Lp,np)!= NULL){
                    cout << "data ada";
                }else{
                    cout << "tidak ada";
                }
            break;

            case 4:
                showperguruan(Lp);
                cout << "Masukan nama perguruan : ";
                cin >> a;
                cout << "Jumlah fakultas yang ingin direlasikan " << endl;
                cout << " :: ";
                cin >> n;
                showfakultas(Lf);
                while (n>0){
                    cout << "Masukan nama fakultas yang ingin direlasikan : ";
                    cin >> b;
                    insertRelasi(Lp, Lf, a, b);
                    n--;
                }
                system("cls");

            break;

            case 5:
                cout << "Masukan nama perguruan : ";
                cin >> np;
                x = searchP(Lp,np);
                if ((x)!= NULL){
                    cout << "masukan nama fakultas yang ingin dicari : ";
                    cin >> pa;
                    nr = searchR(x,pa);
                    if (y!= NULL){
                        cout << "fakultas ada pada perguruan Tinggi " << np << endl;
                    }else{
                        cout << "fakultas tidak ditemukan";
                    }

                }else{
                    cout << "Nama perguruan tidak ada";
                }
            break;

            case 6:
                showperguruan(Lp);
                cout << "Masukan nama perguruan yang ingin dihapus: ";
                cin >> np;
                x = searchP(Lp,np);
                deletePerguruanT(Lp,x,np);
                system("cls");
            break;

            case 7:
                showfakultas(Lf);
                cout << "masukan nama fakultas yang ingin dihapus : ";
                cin >> pa;
                y = searchF(Lf,pa);
                deleteFakultasP(Lf,nr,pa);
                system("cls");
            break;

            case 8:
                showAll(Lp);
            break;

            case 9:
                showperguruan(Lp);
            break;

            case 10:
                showfakultas(Lf);
            break;

            case 11:
                cout << "Masukkan nama perguruan tinggi: ";
                cin >> np;
                x = searchP(Lp, np);
                if (x != NULL){
                    jf = countFakultas(x);
                    cout << "Jumlah fakultas adalah " << jf << endl;
                } else {
                    cout << "Perguruan tinggi " << x <<  " Tidak memiliki fakultas"<<endl;
                }
            break;

            case 12:
                showMin(Lp);
            break;
        }
        cout << endl;
        cout << "kembali ke menu utama? (y/n) ";
        cin >> Kembali_ke_Menu;
        cout << endl;

        if (Kembali_ke_Menu == "y"){
            pilihan = menu();
        }else if (Kembali_ke_Menu == "n"){
            exit(0);
        }else {
            cout << "kembali ke menu utama? (y/n) ";
            cin >> Kembali_ke_Menu;
        }
    }

}
