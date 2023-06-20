#include <iostream>
#include <malloc.h>
#include <fstream>
#define max 100
#define True 1
#define False 0
using namespace std;

typedef int typeinfo;
typedef struct typestack *stokbuku; //DEKLARASI STACK UNTUK STOK BUKU
struct typestack
{
	typeinfo info;
	stokbuku next;
};
stokbuku awalstack, akhirstack;

struct typequeue //DEKLARASI QUEUE UNTUK BUKU YANG DIPINJAM
{
	int belakang;

	int nobuku[max];
};
struct typequeue queue;

ofstream myFile;
int jmlbuku = 0;
int no_buku;
void buatstack_stok_buku();
void buatqueue_buku_dipinjam();
int stackkosong_stok_buku();
int queuekosong_buku_dipinjam();
int queuepenuh();
void push_stok_buku(typeinfo IB);
void enqueue_buku_dipinjam(int IB);
void pop_pinjam_buku();
void dequeue_kembalikan_buku();
void cetak_stok_buku();
void cetak_buku_dipinjam();

int main()
{
	 int pilih, angka;
	 buatstack_stok_buku();
	 buatqueue_buku_dipinjam();

	Mulai:
	cout << "Nama\t: Al Jauzi Abdurrohman" << endl;
	cout << "NIM\t: 123200106" << endl;
	cout << "Plug\t: IF-B" << endl << endl;
	cout << "Menu:" << endl;
	cout << "1. Tambah Stok Buku" << endl;
	cout << "2. Pinjam Buku" << endl;
	cout << "3. Lihat Daftar Stok Buku" << endl;
	cout << "4. Kembalikan Buku" << endl;
	cout << "5. Lihat Daftar Buku yang Dipinjam" << endl;
	cout << "6. Exit" << endl;
	cout << "Pilih: "; cin >> pilih;
	cout << endl;

	 switch(pilih)
	 {
	 	case 1:
	 		int banyakdata;
			cout << "Jumlah buku yang ingin diinput: "; cin >> banyakdata;

			for (int i=0; i<banyakdata; i++)
			{
				cout << "Nomor buku " << jmlbuku+1 << ": ";
			 	cin >> no_buku;
			 	push_stok_buku(no_buku);
				jmlbuku++;
			}
	 	break;

	 	case 2:
	 		pop_pinjam_buku();
	 	break;

	 	case 3:
	 		cetak_stok_buku();
	 	break;

	 	case 4:
	 		dequeue_kembalikan_buku();
	 	break;

	 	case 5:
	 		cetak_buku_dipinjam();
	 	break;

	 	case 6:
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

void buatstack_stok_buku() //BUAT STACK UNTUK STOK BUKU
{
	stokbuku NS;
	NS=NULL;
	awalstack=NS;
	akhirstack=NS;
}

void buatqueue_buku_dipinjam() //BUAT QUEUE UNTUK BUKU YANG DIPINJAM
{
	queue.belakang=0;
}

int stackkosong_stok_buku() //MENGECEK APAKAH SUDAH ADA STOK BUKU YANG DIINPUT ATAU BELUM
{
	if(awalstack==NULL)
		return(True);
	else
		return(False);
}

int queuekosong_buku_dipinjam() //MENGECEK APAKAH SUDAH MEMINJAM BUKU ATAU BELUM
{
	if(queue.belakang==0)
		return(True);
 	else
		return(False);
}

int queuepenuh() //MENGECEK APAKAH BUKU YANG DIPINJAM SUDAH MELEBIHI BATAS MAKSIMUM
{
	if(queue.belakang==max)
		return(True);
 	else
		return(False);
}

void push_stok_buku(typeinfo IB) //MEMASUKKAN STOK BUKU (MENGGUNAKAN STACK)
{
	stokbuku NS;
	NS=(typestack *) malloc(sizeof(typestack));
	NS->info=IB;

	if (awalstack==NULL)
		awalstack=NS;
	else
		akhirstack->next=NS;

	akhirstack=NS;
	akhirstack->next=NULL;
}


void enqueue_buku_dipinjam(int IB) //MEMASUKKAN BUKU YANG DIPINJAM (MENGGUNAKAN QUEUE)
{
	if(queuepenuh())
		cout << "Sudah tidak bisa meminjam buku.\n";
 	else
	{
		queue.belakang++;
		queue.nobuku[queue.belakang]=IB;
	}
}

void pop_pinjam_buku() //MEMINJAM BUKU (MENGGUNAKAN STACK)
{
	stokbuku hapus, bantu;
	//JIKA TIDAK ADA BUKU YANG BISA DIPINJAM
	if (stackkosong_stok_buku())
 	{
 		cout << "Tidak ada buku yang bisa dipinjam.\n";
	}
	//JIKA ADA BUKU YANG BISA DIPINJAM
	else
	{
	 	bantu=awalstack;
		hapus=akhirstack;
		if (hapus==awalstack)
			awalstack=NULL;
		else
		{
			while(bantu->next->next!=NULL)
				bantu=bantu->next;
			akhirstack=bantu;
			akhirstack->next=NULL;
		}
		enqueue_buku_dipinjam(hapus->info); //MEMASUKKAN BUKU YANG DIPINJAM KE DALAM DAFTAR BUKU YANG DIPINJAM (QUEUE)
		free(hapus); //MENGHAPUS BUKU YANG DIPINJAM DARI STOK BUKU
		cout << "Buku berhasil dipinjam." << endl;
	}
}

void dequeue_kembalikan_buku() //MENGEMBALIKAN BUKU (MENGGUNAKAN QUEUE)
{
	int ID, i;

	if(queuekosong_buku_dipinjam())
		cout << "Tidak ada buku yang dipinjam.\n";
	else
	{
		push_stok_buku(queue.nobuku[1]); //MENGEMBALIKAN BUKU YANG DIPINJAM KE DALAM STOK BUKU (STACK)

		for (i=1; i<queue.belakang; i++)
			queue.nobuku[i]=queue.nobuku[i+1]; //MENGHAPUS BUKU YANG DIPINJAM DARI DARI DAFTAR BUKU YANG DIPINJAM

		queue.belakang--;

		cout << "Buku berhasil dikembalikan.\n";
	}
}

void cetak_stok_buku() //MELIHAT DAFTAR STOK BUKU
{
	stokbuku bantu;

	myFile.open("123200106_Daftar stok buku.txt");
	//JIKA TIDAK ADA STOK BUKU
	if (stackkosong_stok_buku())
 	{
 		cout << "Tidak ada stok buku.\n";
 		myFile << "Tidak ada stok buku.\n";
	}
	//JIKA ADA STOK BUKU
	else
	{
		bantu=awalstack;
		cout << "Daftar Stok Buku" << endl;
		myFile << "Daftar Stok Buku" << endl;
		while(bantu!=NULL)
		{
			cout << " " << bantu->info;
			myFile << " " << bantu->info;
			bantu=bantu->next;
		}
	}
	myFile.close();
}

void cetak_buku_dipinjam() //MELIHAT DAFTAR BUKU YANG DIPINJAM
{
	int i=1;

	myFile.open("123200106_Buku yang dipinjam.txt");
	//JIKA TIDAK ADA BUKU YANG DIPINJAM
	if (queuekosong_buku_dipinjam())
	{
 		cout << "Tidak ada buku yang dipinjam" << endl;
 		myFile << "Tidak ada buku yang dipinjam" << endl;
	}
	//JIKA ADA BUKU YANG DIPINJAM
	else
	{
		cout << "Daftar Buku yang Dipinjam" << endl;
		myFile << "Daftar Buku yang Dipinjam" << endl;
		while(i<=queue.belakang)
		{
			cout << " " << queue.nobuku[i];
			myFile << " " << queue.nobuku[i];
			i++;
		}
	}
	myFile.close();
}
