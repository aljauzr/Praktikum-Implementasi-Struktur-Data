/* Implementasi queue menggunakan Array */
#include <iostream>
#include <malloc.h>
#define max 50
#define True 1
#define False 0
using namespace std;

struct typequeue
{
	int belakang;

	string nama[max], alamat[max];
	int jarak[max];
};
struct typequeue queue;

string nama, alamat;
int jarak;

int jmlpaket = 0;
int jaraktempuh = 0, isibensin;
char antar;
void buatqueue();
int queuekosong();
int queuepenuh();
void inputpaket();
void enqueue(string nama, string alamat, int jarak);
void dequeue();
void antarpaket();
void cetakqueue();

int main()
{
	int pilih;
	buatqueue();

	Mulai:
	cout << "Nama\t: Al Jauzi Abdurrohman" << endl;
	cout << "NIM\t: 123200106" << endl;
	cout << "Plug\t: IF-B" << endl << endl;
	cout << "Jasa Pengiriman Paket COD" << endl;
	cout << "1. Admin" << endl;
	cout << "2. Kurir" << endl;
	cout << "0. Keluar" << endl;
	cout << "Pilih: "; cin >> pilih;
	cout << endl;

	switch(pilih)
	{
		case 1:
			cout << "MENU ADMIN" << endl;
			cout << "1. Input Data Penerima Paket" << endl;
			cout << "2. Lihat Data" << endl;
			cout << "0. Keluar" << endl;
			cout << "Pilih: "; cin >> pilih;
			cout << endl;
			switch(pilih)
			{
				case 1:
					inputpaket();
				break;

				case 2:
					cetakqueue();
				break;

				case 0:
					system("cls");
					goto Mulai;
				break;

				default:
	 				cout << "Salah input." << endl;
	 			break;
			}
		break;

		case 2:
			cout << "MENU KURIR" << endl;
			cout << "1. Isi Bensin" << endl;
			cout << "2. Antarkan Paket" << endl;
			cout << "3. Lihat Paket" << endl;
			cout << "0. Keluar" << endl;
			cout << "Pilih: "; cin >> pilih;
			cout << endl;
			switch(pilih)
			{
				case 1:
					cout << "Banyak isi bensin: "; cin >> isibensin;
					jaraktempuh = jaraktempuh + (isibensin*11);
					cout << "Jarak tempuh\t: " << jaraktempuh << " km" << endl;
				break;

				case 2:
					antarpaket();
				break;

				case 3:
					cetakqueue();
				break;

				case 0:
					system("cls");
					goto Mulai;
				break;

				default:
	 				cout << "Salah input." << endl;
	 			break;
			}
		break;

		case 0:
			return 0;
		break;

		default:
	 		cout << "Salah input." << endl;
	 	break;
	}
	cout << endl;
	system("pause");
	system("cls");
	goto Mulai;
}

void buatqueue()
{
	queue.belakang=0;
}

int queuekosong()
{
	if(queue.belakang==0)
		return(True);
 	else
		return(False);
}

int queuepenuh()
{
	if(queue.belakang==max)
		return(True);
 	else
		return(False);
}

void inputpaket()
{
	int banyakdata;

	cout << "Masukkan banyak data penerima: ";
	cin >> banyakdata;
	cout << endl;

	for (int i=0; i<banyakdata; i++)
	{
		cout << "Penerima " << i+1 << endl;
		cout << "Nama Penerima\t\t: "; getline(cin,nama); getline(cin,nama);
		cout << "Alamat Penerima\t\t: "; getline(cin,alamat);
		cout << "Jarak dari Kantor (km)\t: "; cin >> jarak;
		cout << endl;
		jmlpaket++;
		enqueue(nama, alamat, jarak);
	}
}

void enqueue(string nama, string alamat, int jarak)
{
	if(queuepenuh())
		cout << "Queue masih kosong!";
 	else
	{
		queue.belakang++;
		queue.nama[queue.belakang] = nama;
		queue.alamat[queue.belakang] = alamat;
		queue.jarak[queue.belakang] = jarak;
	}
}

void antarpaket()
{
	if(queuekosong())
		cout << "Queue masih kosong!";
 	else
	{
		if (queue.jarak[1] <= jaraktempuh)
		{
			jaraktempuh = jaraktempuh - queue.jarak[1];

			cout << "Paket " << queue.nama[1] << " sudah diterima? (y/n): ";
			cin >> antar;
			if (antar == 'y')
			{
				cout << "Paket yang telah diantarkan, data paket: " << endl;
				cout << "\tNama\t: " << queue.nama[1] << endl;
				cout << "\tAlamat\t: " << queue.alamat[1] << endl;
				cout << "\tJarak\t: " << queue.jarak[1] << endl;
			 	for (int i=1; i<queue.belakang; i++)
			 	{
				 	queue.nama[i]=queue.nama[i+1];
					queue.alamat[i]=queue.alamat[i+1];
					queue.jarak[i]=queue.jarak[i+1];
				}
				queue.belakang--;
				jmlpaket--;
				cout << endl;
				cout << "Tersisa " << jmlpaket << " paket yang belum diantar." << endl;
			}
			else
			{
				cout << endl;
				cout << "Paket belum dtierima." << endl;
			}
		}
		else
		{
			cout << "Bensin habis, sisa bensin hanya cukup untuk " << jaraktempuh << " km." << endl;
		}
 	}
}

void cetakqueue()
{
 	int i=1;

	if (queuekosong())
 		cout << "Queue masih kosong!";
 	else
 	{
	 	do
	 	{
	 		cout << "Penerima ke-" << i << endl;
	 		cout << "\tNama\t: " << queue.nama[i] << endl;
	 		cout << "\tAlamat\t: " << queue.alamat[i] << endl;
	 		cout << "\tJarak\t: " << queue.jarak[i] << endl;
	 		i++;
	 	}while (i<=queue.belakang);
 	}
}
