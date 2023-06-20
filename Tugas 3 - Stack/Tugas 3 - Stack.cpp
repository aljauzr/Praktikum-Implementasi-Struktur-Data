#include <iostream>
#include <malloc.h>
#define True 1
#define False 0
using namespace std;

typedef int typeinfo;
typedef struct typestack *typeptr, *stacksampah;
struct typestack
{
	typeinfo info;
	typeptr next;
};
typeptr awalstack, akhirstack;
stacksampah awal, akhir;

void buat_stack();
void buat_stack_sampah();
int stack_kosong();
int stack_kosong_sampah();
void push(typeinfo IB);
void push_sampah(typeinfo IB);
void pop();
void cetak_stack();
void cetak_stack_sampah();

int main()
{
	 int pilih, angka;
	 buat_stack();
	 buat_stack_sampah();

	 Mulai:
	 cout << "Nama\t: Al Jauzi Abdurrohman" << endl;
	 cout << "NIM\t: 123200106" << endl;
	 cout << "Plug\t: IF-B" << endl << endl;
	 cout << "Menu:" << endl;
	 cout << "1. Push" << endl;
	 cout << "2. Lihat" << endl;
	 cout << "3. Pop" << endl;
	 cout << "4. Tumpukan sampah" << endl;
	 cout << "0. Exit" << endl;
	 cout << "Pilih: "; cin >> pilih;
	 cout << endl;

	 switch(pilih)
	 {
	 	case 1:
	 		cout << "Masukkan angka yang ingin dimasukkan ke dalam stack: ";
	 		cin >> angka;
	 		push(angka);
	 	break;

	 	case 2:
	 		cetak_stack();
	 	break;

	 	case 3:
	 		pop();
	 	break;

	 	case 4:
	 		cetak_stack_sampah();
	 		cout << endl;
	 	break;

	 	case 0:
            return 0;
        break;

	 	default:
	 		cout << "Salah input." << endl;
	 	break;
	 }
	system("pause");
	system("cls");
	goto Mulai;
}

void buat_stack()
{
	typeptr NS;
	NS=NULL;
	awalstack=NS;
	akhirstack=NS;
}

void buat_stack_sampah()
{
	stacksampah NS;
	NS=NULL;
	awalstack=NS;
	akhirstack=NS;
}

int stack_kosong()
{
	if(awalstack==NULL)
		return(True);
	else
		return(False);
}

int stack_kosong_sampah()
{
	if(awal==NULL)
		return(True);
	else
		return(False);
}

void push(typeinfo IB)
{
	typeptr NS;
	NS=(typestack *) malloc(sizeof(typestack));
	NS->info=IB;

	if (awalstack==NULL)
		awalstack=NS;
	else
		akhirstack->next=NS;

	akhirstack=NS;
	akhirstack->next=NULL;
}

void push_sampah(typeinfo IB)
{
	stacksampah NS;
	NS=(typestack *) malloc(sizeof(typestack));
	NS->info=IB;

	if (awal==NULL)
		awal=NS;
	else
		akhir->next=NS;

	akhir=NS;
	akhir->next=NULL;
}

void pop()
{
	typeptr hapus, bantu;
	if (stack_kosong())
 	{
 		cout << "Stack kosong !\n";
	}
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
		push_sampah(hapus->info);
		free(hapus);
		cout << "Berhasil menghapus 1 elemen terakhir." << endl;
	}
}

void cetak_stack()
{
	typeptr bantu;

	if (stack_kosong())
 	{
 		cout << "Stack kosong !\n";
	}
	else
	{
		bantu=awalstack;
		while(bantu!=NULL)
		{
			cout << " " << bantu->info;
			bantu=bantu->next;
		}
	}
}

void cetak_stack_sampah()
{
	stacksampah bantu;

	if (stack_kosong_sampah())
 	{
 		cout << "Stack kosong !\n";
	}
	else
	{
		bantu=awal;
		while(bantu!=NULL)
		{
			cout << " " << bantu->info;
			bantu=bantu->next;
		}
	}
}
