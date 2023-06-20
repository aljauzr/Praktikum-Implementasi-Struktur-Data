// AL JAUZI ABDURROHMAN
// 123200106, IF-B

#include <iostream>
#include <string.h>
using namespace std;

typedef struct  //STRUCT PEMINJAM
	{
		int noUrut, lamaP;
		string namaP, kaset, swap;
	} peminjam;
	peminjam pinjam[99];

int banyakdata;
char kembali;
bool found;

void inputpeminjam();
void caripeminjam();
void pembayaran();

int main()
{
    int pilih;

    cout << "\nData Sewa Kaset\n";
    cout << "1. Input Nama Peminjam\n";
    cout << "2. Cari Peminjam\n";
    cout << "3. Pembayaran\n";
    cout << "Pilih: "; cin >> pilih;

    switch (pilih)
    {
        case 1:
            system("cls");
            inputpeminjam();
        break;

        case 2:
            system("cls");
            caripeminjam();
        break;

        case 3:
            system("cls");
            pembayaran();
        break;

        default:
            cout << "\n\nInput salah1";
            system("pause"); system("cls");
            main();
        break;
    }
}

void inputpeminjam()
{
    START:

    cout << "\nBanyak Data: ";
    cin >> banyakdata;

    for (int i = 0; i < banyakdata; i++)
    {
        cout << "\nNomor Urut Pelanggan\t: ";
        cin >> pinjam[i].noUrut;
        cout << "Nama Pelanggan\t\t: ";
        getline(cin, pinjam[i].namaP);
        getline(cin, pinjam[i].namaP);
        cout << "Kaset yang Dipinjam\t: ";
        getline(cin, pinjam[i].kaset);
        cout << "Lama Pinjam\t\t: ";
        cin >> pinjam[i].lamaP;
    }

    kembali:
    cout << "\nKembali ke menu? (y/n): ";
    cin >> kembali;

    if (kembali == 'y')
    {
        system("cls");
        main();
    }
    else if (kembali == 'n')
    {
        goto START;
    }
    else
    {
        cout << "\nInput salah!" << endl;
        system("pause");
        goto kembali;
    }
}

void caripeminjam()
{
    START:
    string namakaset;
    int jumlah;

    cout << "\nMasukkan Nama Kaset : ";
    getline(cin, namakaset);
    getline(cin, namakaset);

    found = false;
    cout << endl;

    int i = 0;
		while ((i < banyakdata) && (!found))
        {
            if (pinjam[i].kaset == namakaset)
            {
                found = true;
                cout << "Nomor Urut\t: " << pinjam[i].noUrut << endl;
                cout << "Nama Peminjam\t: " << pinjam[i].namaP << endl;
                cout << "Nama Kaset\t: " << pinjam[i].kaset << endl;
            }
            else
            {
                i++;
            }
        }

        if(found)
        {
            kembali:
            cout << "\nKembali ke menu? (y/n): ";
            cin >> kembali;

            if (kembali == 'y')
            {
                system("cls");
                main();
            }
            else if (kembali == 'n')
            {
                system("cls");
                goto START;
            }
            else
            {
                cout << "\nInput salah!" << endl;
                system("pause");
                goto kembali;
            }
        }

        else
        {
            cout << "Data tidak ditemukan" << endl;
            kembali2:
            cout << "\nKembali ke menu? (y/n): ";
            cin >> kembali;

            if (kembali == 'y')
            {
                system("cls");
                main();
            }
            else if (kembali == 'n')
            {
                system("cls");
                goto START;
            }
            else
            {
                cout << "\nInput salah!" << endl;
                system("pause");
                goto kembali2;
            }
        }
    }

void pembayaran()
{
    START:
    string namapelanggan;

    cout << "\nMasukkan Nama Pelanggan : ";
    getline(cin, namapelanggan);
    getline(cin, namapelanggan);

    found = false;
    cout << endl;

    int i = 0;
		while ((i < banyakdata) && (!found))
        {
            if (pinjam[i].namaP == namapelanggan)
            {
                found = true;
                cout << "Nomor Urut Pelanggan\t: " << pinjam[i].noUrut << endl;
                cout << "Nama Pelanggan\t\t: " << pinjam[i].namaP << endl;
                cout << "Kaset yang Dipinjam\t: " << pinjam[i].kaset << endl;
                cout << "Lama Pinjam\t\t: " << pinjam[i].lamaP << endl;
                cout << "Total Bayar\t\t: " << pinjam[i].lamaP * 10000 << endl;
            }
            else
            {
                i++;
            }
        }

        if(found)
        {
            kembali:
            cout << "\nKembali ke menu? (y/n): ";
            cin >> kembali;

            if (kembali == 'y')
            {
                system("cls");
                main();
            }
            else if (kembali == 'n')
            {
                system("cls");
                goto START;
            }
            else
            {
                cout << "\nInput salah!" << endl;
                system("pause");
                goto kembali;
            }
        }

        else
        {
            cout << "Data tidak ditemukan" << endl;
            kembali2:
            cout << "\nKembali ke menu? (y/n): ";
            cin >> kembali;

            if (kembali == 'y')
            {
                system("cls");
                main();
            }
            else if (kembali == 'n')
            {
                system("cls");
                goto START;
            }
            else
            {
                cout << "\nInput salah!" << endl;
                system("pause");
                goto kembali2;
            }
        }
}
