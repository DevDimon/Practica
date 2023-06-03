#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

double getValue(int s, int c, int n, double *m)
{
    return m[s * (n + 1) + c];
}

void setValue(double v, int s, int c, int n, double *m)
{
    m[s * (n + 1) + c] = v;
}

void printMatrix(int n, double *m)
{
    for (int s = 0; s < n; s++)
    {
        for (int c = 0; c < n + 1; c++)
        {
            cout << getValue(s, c, n, &m[0]) << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void setLine(int s, int n, double *m)
{
    double tmp;

    for (int i = 0; i < n; i++)
    {
        if (getValue(i, s, n, m) != 0)
        {
            if (i != 0)
            {
                for (int j = s; j < n + 1; j++)
                {
                    tmp = getValue(s, j, n, m);
                    setValue(getValue(i, j, n, m), s, j, n, m);
                    setValue(tmp, i, j, n, m);
                }
            }
            break;
        }
    }
}

void makeLine(int s, int n, double *m)
{
    double k = getValue(s, s, n, m);
    for (int i = s; i < n + 1; i++)
    {
        setValue(getValue(s, i, n, m) / k, s, i, n, m);
    }
}

void setZeroLeftBottom(int s, int n, double *m)
{
    double tmp, tmp1, k;
    for (int i = s + 1; i < n; i++)
    {
        k = getValue(i, s, n, m);
        for (int j = s; j < n + 1; j++)
        {
            tmp = getValue(s, j, n, m);
            tmp1 = getValue(i, j, n, m);
            setValue(tmp * (-k) + tmp1, i, j, n, m);
        }
    }
}

void setZeroRightTop(int s, int n, double *m)
{
    double tmp, tmp1, k;
    for (int i = s - 1; i >= 0; i--)
    {
        k = getValue(i, s, n, m);
        for (int j = s; j < n + 1; j++)
        {
            tmp = getValue(s, j, n, m);
            tmp1 = getValue(i, j, n, m);
            setValue(tmp * (-k) + tmp1, i, j, n, m);
        }
    }
}

// bool isValid(int n, double *m)
// {
//     return getValue(n - 1, n - 1, n, m) == 1.0;
// }

// bool isInfinity(int n, double *m)
// {
//     return std::round(getValue(n - 1, n, n, m)) == 0;
// }

int main(void)
{
    int n, s, c;

    cout << "Размерность = ";
    cin >> n;

    double matrix[n][n + 1];

    for (s = 0; s < n; s++)
    {
        cout << "\n";
        for (c = 0; c < n + 1; c++)
        {
            cout << "a[" << s << "][" << c << "] = ";
            cin >> matrix[s][c];
        }
    }
    cout << "\n";
    printMatrix(n, &matrix[0][0]);

    cout << "Левый угол\n";

    for (int s = 0; s < n; s++)
    {
        setLine(s, n, &matrix[0][0]);

        if (std::round(getValue(s, s, n, &matrix[0][0])) == 0.0)
        {
            if (std::round(getValue(s, n, n, &matrix[0][0])) == 0)
            {
                cout << "Бесконечное количество решений";
            }
            else
            {
                cout << "Решений нет";
            }
            return 0;
        }

        makeLine(s, n, &matrix[0][0]);

        setZeroLeftBottom(s, n, &matrix[0][0]);

        printMatrix(n, &matrix[0][0]);
    }

    cout << "Правый угол\n";

    for (int s = n - 1; s >= 0; s--)
    {
        setZeroRightTop(s, n, &matrix[0][0]);
        printMatrix(n, &matrix[0][0]);
    }

    cout << "Решение уравнения\n";
    for (int i = 0; i < n; i++)
    {
        cout << "X["<< i+1 << "] = " << getValue(i, n, n, &matrix[0][0]) << "\n";
    }
}