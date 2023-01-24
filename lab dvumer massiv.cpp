#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(0, "");
    int m, n, a, max = INT16_MIN;
    cout << "Введите целое положительное число M (число строк матрицы): ";
    cin >> m;
    cout << "Введите целое положительное число N (число cтолбцов матрицы матрицы): ";
    cin >> n;
    if (m > 0 && n > 0)
    {
        int* maximum = new int[m];
        // объявление двумерного динамического массива :
        int** tabl = new int* [m]; //строки
        for (int count = 0; count < m; count++)
            tabl[count] = new int[n]; //столбцы


        for (int stolbec = 0; stolbec < m; stolbec++) // заполняем таблицу
        {
            for (int stroka = 0; stroka < n; stroka++)
            {
                cout << "Введите " << stolbec + 1 << " элемент для " << stolbec + 1 << " столбца : ";
                cin >> a;
                tabl[stolbec][stroka] = a; //Заполняем все столбцы с соответствующими строками
            }
        }

        cout << "\nПолучена следующая таблица:\n";
        for (int stolbec = 0; stolbec < m; stolbec++)
        {

            for (int stroka = 0; stroka < n; stroka++)
            {
                cout << " " << tabl[stolbec][stroka] << "  ";
            }
            cout << endl;
        }

        for (int stolbec = 0; stolbec < m; stolbec++)
        {
            for (int stroka = 0; stroka < n; stroka++)
            {
                if (tabl[stolbec][stroka] > max)
                {
                    maximum[stolbec] = tabl[stolbec][stroka];
                    max = tabl[stolbec][stroka];
                }
            }
            max = INT16_MIN;
        }
        for (int stolbec = 0; stolbec < m; stolbec++)
        {
            cout << "\nМаксимальный элемент в " << stolbec + 1 << " столбце: " << maximum[stolbec];
        }
        int min = INT16_MAX;
        for (int stolbec = 0; stolbec < m; stolbec++)
        {
            if (maximum[stolbec] < min)
            {
                min = maximum[stolbec];
            }
        }
        cout << "\n\nМинимальный из максимальных элементов: " << min << endl;
        for (int count = 0; count < m; count++)
            delete[] tabl[count];

    }
    else cout << "Одно число, или оба числа не соответствуют параметрам (>0)";
    system("pause");
    return 0;
}
