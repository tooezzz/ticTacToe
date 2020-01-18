// Tic_Tac_Toe.cpp

#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

const int fieldSize = 3;
char gameField[fieldSize][fieldSize];

void startField();
void playerMove();
void pcMove();
void showField();
char winCheck();

//Пустое поле
void startField() {
    //Заполнение массива "*"
    for (int i = 0; i < fieldSize; ++i) {
        for (int j = 0; j < fieldSize; ++j) {
            gameField[i][j] = '*';
        }
    }
    //Вывод массива
    showField();
}

//Вывод игрового поля
void showField() {
    for (int i = 0; i < fieldSize; ++i) {
        for (int j = 0; j < fieldSize; ++j) {
            cout << gameField[i][j];
        }
        cout << endl;
    }
}

//Ход игрока
void playerMove() {
    int i;
    int j;
    cout << "Your turn: ";
    cin >> i >> j;  
    gameField[i - 1][j - 1] = 'x'; //-1 для ввода "1 1", "2 2" и т.д.
}

//Генерация хода ПК
void pcMove() {
    int i = 0;
    int j = 0;

    for (int q = 0; q < fieldSize * 2; ++q) {
        
        //Проверка на пустую ячейку
        if (gameField[i][j] == '*' && gameField[i][j] != 'x' && gameField[i][j] != 'o') {
            i = 0 + rand() % 3;
            j = 0 + rand() % 3;
            gameField[i][j] = 'o';
            break;
        }
        i++;
        j++;
    }
}

//Проверка на победу
char winCheck(){
    int i;
    char* check;
    for (i = 0; i < fieldSize; i++) {
        check = &gameField[i][0];
        if (*check == *(check + 1) && *(check + 1) == *(check + 2))
            return *check;
    }

    for (i = 0; i < fieldSize; i++) {
        check = &gameField[0][i];
        if (*check == *(check + 3) && *(check + 3) == *(check + 6))
            return *check;
    }
}

int main()
{
    char result = '*';

    srand(time(NULL));

    //Стартовое поле
    startField();

    //Ход игры
    do {
        //Ход игрока
        playerMove();
        system("cls");
        //Проверка на победу
        result = winCheck();
        if (result != '*' && result != 'o')
            break;

        //Генерация хода ПК
        pcMove();
        //Проверка на победу
        result = winCheck();
        if (result != '*' && result != 'x')
            break;

        //Вывод массива
        showField();
    } while (result == '*');

    if (result == 'o') {
        system("cls");
        cout << "PC won" << endl;
    }
    else {
        system("cls");
        cout << "Player won" << endl;
    }

    showField();

    system("pause");
    return 0;
}