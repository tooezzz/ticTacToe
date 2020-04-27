#include <iostream>
#include <Windows.h>


const int W = 19, H = 11;
char field[W][H];

using namespace std;

void draw_x(int i, int j);

void draw_x(int i, int j) {
    int ii = i * 4;
    int jj = j * 7;

    field[ii][jj] = 'x';
    field[ii + 1][jj + 2] = 'x';
    field[ii + 2][jj + 4] = 'x';
    field[ii][jj + 4] = 'x';
    field[ii + 2][jj] = 'x';
}

int main()
{
    

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            field[i][j] = '-';
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << field[i][j];
        }

        cout << endl;
    }

    system("cls");

    int iMove = 0, jMove = 0;
    int counter = 0;
    do {

        /*cout << "type: ";
        cin >> iMove >> jMove;*/

        draw_x(0, 0);
        draw_x(0, 1);
        system("cls");
        draw_x(1, 0);
               
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cout << field[i][j];
            }
            cout << endl;
        }

        counter++;
    } while (counter != 3);

    system("pause");
    return 0;
}