/*Program List Dengan Array*/
#include <iostream>
#define max 12
#define true 1
#define false 0
using namespace std;

typedef struct {int info; int next; }typenode;
typenode elemen[max];
int list,akhirlist,kosong,akhirkosong;
int listkosong();
void buatlist();
void sisipnode(int IB);
void hapusnode(int IH);
void cetaklist();

int main()
{
    int angka;
    buatlist();
 cetaklist();
 sisipnode(7);
 cout << "\n\n Sisip 7 \n\n";
 cetaklist();
 sisipnode(30);
 cout << "\n\n sisip 30 \n\n";
 cetaklist();
 hapusnode(7);
 cout << "\n\n hapus 7 \n\n";
 cetaklist();

 cout << "\n\nMasukkan list yang ingin dihapus: ";
 cin >> angka;
 hapusnode(angka);
 cetaklist();
}
void buatlist()
{ list=5;
kosong=3;
akhirlist=10;
akhirkosong=4;
elemen[1].info=25; elemen[1].next=8;
elemen[2].info=0 ; elemen[2].next=9;
elemen[3].info=0; elemen[3].next=6;
elemen[4].info=0; elemen[4].next=0;
elemen[5].info=10; elemen[5].next=7;
elemen[6].info=0; elemen[6].next=2;
elemen[7].info=15; elemen[7].next=1;
elemen[8].info=40; elemen[8].next=10;
elemen[9].info=0; elemen[9].next=4;
elemen[10].info=60; elemen[10].next=0;
}
int listkosong()
{ if (list==0)
 return(true);
 else
 return(false);
}
void sisipnode(int IB)
{ int listbaru,k,m,n,x;
//-------------------------- sisip di awal
 if(IB<elemen[list].info)
 {listbaru=kosong;
kosong=elemen[kosong].next;
elemen[listbaru].info=IB;
elemen[listbaru].next=list;
list=listbaru;
 }

 else
 //-------------------------sisip di akhir
 if(IB>elemen[akhirlist].info)
 {listbaru=kosong;
kosong=elemen[kosong].next;
elemen[listbaru].info=IB;
elemen[listbaru].next=0;
elemen[akhirlist].next=listbaru;
akhirlist=listbaru;
 }
 else
 //--------------------------sisip di tengah
 {n=list;//5
x=elemen[n].info;//10
while(IB>x)//30>30
{m=n;//1
n=elemen[n].next;//6
x=elemen[n].info;//30
}
k=elemen[kosong].next;
elemen[m].next=kosong;
elemen[kosong].info=IB;
elemen[kosong].next=n;
kosong=k;
}
 }
void cetaklist()
{ int n,m;
 n=list;
 m=kosong;
 cout << "isi list : \n";
do{
 cout << elemen[n].info << " ";
 n=elemen[n].next;
 }while (elemen[n].next!=0);
 cout << " "<< elemen[akhirlist].info <<endl ;
 cout << "\nIndex tempat-tempat kosong: \n";
 do
 {cout << m << " ";
m=elemen[m].next;
 }while(elemen[m].next!=0);
 cout << " " << akhirkosong;
}
void hapusnode(int IH)
{
    int listbaru,k;
    int bantu, hapus;
    //------------------------ hapus di awal
    if(IH==elemen[list].info)
    {
        listbaru=elemen[list].next;//7
        k=kosong;//3
        kosong=list;//5
        list=listbaru;//7
        elemen[kosong].next=k;//3
    }
     //------------------------ hapus di akhir
    else if (IH == elemen[akhirlist].info)
    {
        bantu = list;//5
        k = kosong;//3
        kosong = akhirlist;//10

        do{
            bantu = elemen[bantu].next;//8
       }while(elemen[bantu].next != akhirlist);

        akhirlist = bantu;//8
        elemen[akhirlist].next = 0;
		elemen[kosong].next = k;//3
    }
    //------------------------ hapus di tengah
    else//misal hapus 15
    {
        bantu = list;//5
        k = elemen[bantu].next;//7
        while (elemen[k].info != IH and elemen[k].next!=0)
        {
            bantu = k;
            k = elemen[bantu].next;
        }
        if(elemen[k].info == IH)
        {
            hapus = k;//7
            elemen[bantu].next = elemen[hapus].next;//1
            elemen[hapus].info = 0;
            elemen[hapus].next = kosong;//3
            kosong = hapus;//7
        }
    }
}
