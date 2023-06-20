/*      NAMA    : AL JAUZI ABDURROHMAN
        NIM     : 123200106         */
#include <iostream>
#include <string.h>

using namespace std;

int x[10] = {2,3,4,5,6,7,8,9,10,11};
int cari;
bool found;
int fungsicari();

int main()
{
    cout << endl << "x[10] = [2,3,4,5,6,7,8,9,10,11]" << endl << endl;
    cout << "Yang dicari: ";
    cin >> cari;

    fungsicari();

    return 0;
}

int fungsicari()
{
    char lagi;
    found = false;

    int i = 0;
		while ((i < 10) && (!found))
        {
            if (x[i] == cari)
            {
                found = true;
                cout << "Ketemu di array " << i << endl;
            }
            else
            {
                i++;
            }
        }

        if(found)
        {
            cout << "\nCari lagi (y/n): ";
            cin >> lagi;

            if (lagi == 'y')
            {
                system("cls");
                main();
            }
            else if (lagi == 'n')
            {
                return 0;
            }
            else
            {
                cout << "\nInput salah!" << endl;
                system("pause");
                system("cls");
                main();
            }
        }

        else
        {
            cout << "Data tidak ditemukan" << endl;
            kembali2:
            cout << "\nCari lagi? (y/n): ";
            cin >> lagi;

            if (lagi == 'y')
            {
                system("cls");
                main();
            }
            else if (lagi == 'n')
            {
                return 0;
            }
            else
            {
                cout << "\nInput salah!" << endl;
                system("pause");
                system("cls");
                main();
            }
        }

    return 0;
}
