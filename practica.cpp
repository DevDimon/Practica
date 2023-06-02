#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

float getValue(int s, int c, int n, float *m)
{
    return  m[s*(n+1)+c];
}

void printMatrix(int n, float *m)
{
    for (int s = 0; s < n; s++)
    {
        for (int c = 0; c < n + 1; c++)
        {
            cout << getValue(s, c, n, &m[0]) << " ";
        }
        cout << "\n";
    }
}

void setFirstLine(int n, float *m)
{
    
}

int main(void)
{
    int n, s, c;

    cout << "Размерность = ";
    cin >> n;

    float matrix[n][n + 1];

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
}


