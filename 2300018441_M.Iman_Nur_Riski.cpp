#include <iostream>
#include <cstdlib> // For system("cls") replacement

using namespace std;

char angka[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int cetak_hasil();
void papan_permainan();
void clear_screen();

int main()
{
    int pemain = 1, i, pilih;
    char simbol;

    do
    {
        papan_permainan();
        pemain = (pemain % 2) ? 1 : 2;
        cout << "Pemain " << pemain << ", Masukan angka: ";
        cin >> pilih;
        simbol = (pemain == 1) ? 'X' : 'O';

        if (pilih >= 1 && pilih <= 9 && angka[pilih] == '1' + pilih)
        {
            angka[pilih] = simbol;
        }
        else
        {
            cout << "Jawaban tidak valid ";
            pemain--;
            cin.ignore();
            cin.get();
        }

        i = cetak_hasil();
        pemain++;

    } while (i == -1);

    papan_permainan();

    if (i == 1)
        cout << "==>\aPemain " << --pemain << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
    return 0;
}

int cetak_hasil()
{
    if (angka[1] == angka[2] && angka[2] == angka[3])
        return 1;
    else if (angka[4] == angka[5] && angka[5] == angka[6])
        return 1;
    else if (angka[7] == angka[8] && angka[8] == angka[9])
        return 1;
    else if (angka[1] == angka[4] && angka[4] == angka[7])
        return 1;
    else if (angka[2] == angka[5] && angka[5] == angka[8])
        return 1;
    else if (angka[3] == angka[6] && angka[6] == angka[9])
        return 1;
    else if (angka[1] == angka[5] && angka[5] == angka[9])
        return 1;
    else if (angka[3] == angka[5] && angka[5] == angka[7])
        return 1;
    else if (angka[1] != '1' && angka[2] != '2' && angka[3] != '3' && angka[4] != '4' && angka[5] != '5' && angka[6] != '6' && angka[7] != '7' && angka[8] != '8' && angka[9] != '9')
        return 0;
    else
        return -1;
}

void papan_permainan()
{
    clear_screen();
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Pemain 1 (X)  -  Pemain 2 (O)" << endl
         << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << angka[1] << "  |  " << angka[2] << "  |  " << angka[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << angka[4] << "  |  " << angka[5] << "  |  " << angka[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << angka[7] << "  |  " << angka[8] << "  |  " << angka[9] << endl;
    cout << "     |     |     " << endl
         << endl;
}

void clear_screen()
{
    system("cls"); 
}
