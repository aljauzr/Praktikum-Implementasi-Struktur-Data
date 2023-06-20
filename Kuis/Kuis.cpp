//AL JAUZI ABDURROHMAN
//123200106, IF-B

#include <iostream>
using namespace std;

typedef struct datavaksin{
    string nama, nik, jenisvaksin;
    int statusvaksin, umur, suhu, sistol, diastol;
}datavaksin;

datavaksin vaksin[99];

int jumlahdata = 0;
char kembali;
void buatlist();
void inputdata();
void lihatdata();
void cekdata();
void hapusdata();
bool found;

int main()
{
    int pilih;

    cout << "--PROGRAM VAKSINASI--" << endl;
    cout << "Data Vaksinasi Jawa Tengah" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Lihat Peserta Vaksinasi" << endl;
    cout << "3. Cek Status Vaksinasi" << endl;
    cout << "4. Hapus Data Vaksinasi" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih: "; cin >> pilih;

    switch(pilih)
    {
    case 1:
        inputdata();
    break;

    case 2:
        lihatdata();
    break;

    case 3:
        cekdata();
    break;

    case 4:
        hapusdata();
    break;

    case 5:
        return 0;
    break;

    default:
        cout << "\nInput salah!" << endl;
        system("pause");
        system("cls");
        main();
    break;
    }
}

void inputdata()
{
    int pilvak, input;

    cout << "\nMasukkan banyak data yg ingin diinput: "; cin >> input;
    jumlahdata = jumlahdata + input;

    for(int i=0; i<jumlahdata; i++)
    {
        cout << endl;
        cout << "Screening tahap 1" << endl;
        cout << "Nama\t\t: ";
        getline (cin, vaksin[i].nama);
		getline (cin, vaksin[i].nama);
        cout << "Umur\t\t: "; cin >> vaksin[i].umur;
        cout << "NIK\t\t: "; cin >> vaksin[i].nik;
        cout << "Dosis Vaksin Ke-1" << endl << endl;

        cout << "Screening tahap 2" << endl;
        cout << "Suhu Badan\t: "; cin >> vaksin[i].suhu;
        cout << "Tekanan Darah\t: "; cin >> vaksin[i].sistol >> vaksin[i].diastol;
        cout << endl;

        if((vaksin[i].umur > 12) && (vaksin[i].suhu < 37) && (vaksin[i].sistol > 100) && (vaksin[i].sistol < 120) && (vaksin[i].diastol > 60) && (vaksin[i].diastol < 90))
        {
            cout << "Screening Tahap 3" << endl;
            cout << "Daftar Vaksin yang Tersedia" << endl;
            cout << "1. Sinovac" << endl;
            cout << "2. Astrazeneca" << endl;
            cout << "3. Moderna" << endl;
            cout << "Pilih vaksin: "; cin >> pilvak;
            switch(pilvak)
            {
            case 1:
               vaksin[i].jenisvaksin = "Sinovac";
            break;

            case 2:
                vaksin[i].jenisvaksin = "Astrazeneca";
            break;

            case 3:
                vaksin[i].jenisvaksin = "Moderna";
            break;
            }
        }
        else //JIKA TIDAK MEMENUHI SYARAT VAKSINASI
        {
            cout << "Mohon maaf anda belum dapat melakukan vaksinasi." << endl << endl;
            cout << "Kembali ke menu? (y/n):"; cin >> kembali;
            if(kembali == 'y')
            {
                system("cls");
                main();
            }
        }
        vaksin[i].statusvaksin = 0; //MENUNJUKKAN BELUM PERNAH VAKSIN
    }
    cout << "Penginputan data selesai." << endl << endl;
    cout << "Kembali ke menu? (y/n):"; cin >> kembali;
    if(kembali == 'y')
    {
        system("cls");
        main();
    }
}

void lihatdata()
{
    cout << "\nLihat data vaksinasi" << endl;

    for (int i=0; i<jumlahdata; i++)
    {
        cout << i+1 << ". " << vaksin[i].nama << " (" << vaksin[i].umur << ")" << endl;
    }

    cout << "\nKembali ke menu? (y/n):"; cin >> kembali;
    if(kembali == 'y')
    {
        system("cls");
        main();
    }
}

void cekdata()
{
    string ceknik;
    char lakukan;

    cout << "\nSilahkan masukkan NIK yang ingin anda cek: ";
    cin >> ceknik;

    found = false;

    int i = 0;
		while ((i < jumlahdata) && (!found))
        {
            if (vaksin[i].nik == ceknik) //JIKA DATA YANG DICARI KETEMU
            {
                found = true;
                cout << "Nama\t\t\t: " << vaksin[i].nama << endl;
                cout << "Umur\t\t\t: " << vaksin[i].umur << endl;
                cout << "NIK\t\t\t: " << vaksin[i].nik << endl;
                cout << "Suhu\t\t\t: " << vaksin[i].suhu << endl;
                cout << "Tekanan darah\t\t: " << vaksin[i].sistol << "/" << vaksin[i].diastol << endl;
                cout << "Vaksin yang diambil\t: " << vaksin[i].jenisvaksin << endl;
                //------------------------------------------------------------PENGECEKAN STATUS VAKSIN
                if(vaksin[i].statusvaksin == 0) //JIKA BELUM PERNAH VAKSIN SAMA SEKALI
                {
                    cout << "Status vaksinasi\t: Belum melakukan vaksinasi" << endl;

                    cout << "Lakukan vaksinasi? (y/n)"; cin >> lakukan;
                    if(lakukan == 'y')
                    {
                        vaksin[i].statusvaksin++;
                    }
                    else
                    {
                        cout << "Okelah kalo begitu";
                    }
                }
                else if(vaksin[i].statusvaksin == 1) //JIKA SUDAH VAKSIN SEKALI
                {
                    cout << "Status vaksinasi\t: Sudah melakukan vaksinasi pertama" << endl;
                    cout << "Lakukan vaksinasi? (y/n)"; cin >> lakukan;
                    if(lakukan == 'y')
                    {
                        vaksin[i].statusvaksin++;
                    }
                    else
                    {
                        cout << "Okelah kalo begitu";
                    }
                }
                else if (vaksin[i].statusvaksin == 2) //JIKA SUDAH VAKSIN 2 KALI
                {
                    cout << "Status vaksinasi\t: Proses vaksinasi anda sudah selesai" << endl;
                }
            }
            else //JIKA DATA YANG DICARI MASIH BELUM KETEMU
            {
                i++;
            }

            if(found)
            {
                cout << "\nKembali ke menu? (y/n): ";
                cin >> kembali;

                if (kembali == 'y')
                {
                    system("cls");
                    main();
                }
            }
            else //JIKA DATA YANG DICARI TIDAK ADA
            {
                cout << "Data tidak ditemukan" << endl << endl;
                cout << "\nKembali ke menu? (y/n): ";
                cin >> kembali;

                if (kembali == 'y')
                {
                    system("cls");
                    main();
                }
            }
    }
}

void hapusdata()
{
    cout << "\nGa paham kak hehe, ini aja pake struct biasa, ga pake linked list :(" << endl << endl; //BENERAN GA PAHAM KAK :(
    cout << "Kembali ke menu? (y/n):"; cin >> kembali;
    if(kembali == 'y')
    {
        system("cls");
        main();
    }
}
