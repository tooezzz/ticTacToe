// Tic_Tac_Toe.cpp

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <math.h>

using namespace std;

const int fieldSize = 3;
char gameField[fieldSize][fieldSize];

void startField();
void playerMove();
void pcMove();
void showField();
char winCheck(char check);
bool drawCheck();

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
    int i = 1;
    int j = 1;
     
    cout << "Your turn: ";
    cin >> i >> j;

    if (gameField[i - 1][j - 1] == '*') {        
        gameField[i - 1][j - 1] = 'x'; //-1 для ввода "1 1", "2 2" и т.д.
    }
    else if (gameField[i - 1][j - 1] != '*') {        //Если ячейка не пустая (не равна *), то ход повторить
        cout << "Not empty slot! Repeat your turn: ";
        playerMove();        
    }
}

//Генерация хода ПК
void pcMove() {
    int i = 0;
    int j = 0;

    for (;;) {

        //Рандомные значения для хода ПК
        i = 0 + rand() % fieldSize;
        j = 0 + rand() % fieldSize;

        //Проверка на пустую ячейку
        if (gameField[i][j] == '*') {
            gameField[i][j] = 'o';
            break;
        }
        else if (drawCheck() == true) { //Если пустых клеток нет, то объявление ничьей и выход из цикла
            cout << "Draw" << endl;
            break;
        }
    }
}

//Проверка на ничью
bool drawCheck() {
    int i = 0;
    int j = 0;
    char check = '*';
    int counter = 0;

    for (i; i < pow(fieldSize, 2); i++) {       //Проверяются все ячейки
        for (j; j < pow(fieldSize, 2); j++) {
            if (gameField[i][j] == check)       //Если в поле есть *, то counter + 1
                counter++;
        }
    }

    if (counter == 0) return true;              //Если counter = 0, значит, на поле нет пустых клеток

    return false;
}

//Проверка на победу
char winCheck(char check){
    int i, j;
    bool result = true; //Переменная для проверки истиности заполнения линий

    //Проверка строк
    for (i = 0; i < fieldSize; i++) {
        result = true;

        for (j = 0; j < fieldSize; j++) {
            if (gameField[i][j] != check) {
                result = false;
                break;
            }
        }
        if (result) return true;
    }

    //Проверка столбцов
    for (j = 0; j < fieldSize; ++j) {
        result = true;
        for (i = 0; i < fieldSize; ++i) {
            if (gameField[i][j] != check) {
                result = false;
                break;
            }
        }
        if (result) return true;
    }

    //Проверка первой диагонали
    for (i = 0; i < fieldSize; ++i) {
        result = true;

        if (gameField[i][i] != check) {
            result = false;
            break;
        }
    }
    if (result) return true;

    //Проверка второй диагонали
    for (i = 0; i < fieldSize; ++i) {
        result = true;

        if (gameField[i][fieldSize - i - 1] != check) {
            result = false;
            break;
        }
    }
    if (result) return true;

    return false;
}

int main()
{
    srand(time(NULL));

    char result = '*';    
    bool win = true;
    bool draw = true;

    //Стартовое поле
    startField();

    //Ход игры
    do {
        //Проверка на ничью
        if (draw == drawCheck())
            break;

        //Ход игрока
        playerMove();
        system("cls");
        //Проверка на победу
        if (win == winCheck('x')) {
            result = 'x';
            break;
        }

        //Генерация хода ПК
        pcMove();
        //Проверка на победу
        if (win == winCheck('o')) {
            result = 'o';
            break;
        }

        //Вывод массива
        showField();
    } while (1);

    system("cls");
    showField();

    if (result == 'o')        
        cout << "PC won" << endl;
    else if (drawCheck() == true)        
        cout << "Draw" << endl;
    else        
        cout << "Player won" << endl;

    system("pause");
    return 0;
}