#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n,
    const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < k )
        Create(a, k, n, Low, High, i, j + 1);
    else
        if (i < n )
            Create(a, k, n, Low, High, i + 1, 0);
}
void Print(int** a, const int k, const int n, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < n - 1)
        Print(a, k, n, i, j + 1);
    else
        if (i < k - 1)
        {
            cout << endl;
            Print(a, k, n, i + 1, 0);
        }
        else
            cout << endl << endl;
}


void MinRow(int** a, const int rowNo, const int k, int colNo, int& min) {
    if ( a[rowNo][colNo] < min )
        min = a[rowNo][colNo];
if ( colNo < k-1 )
MinRow(a, rowNo, k, colNo+1, min);
}
    
void MaxMin(int** a, const int k, const int n, int rowNo, int& max)
{
    int min = a[rowNo][0];
    MinRow(a, rowNo, n, 1, min);
    if ( rowNo == 0 )
        max = min;
    if ( min > max )
        max = min;
    if ( rowNo < k-1 )
        MaxMin(a, k, n, rowNo+1, max);
}

int main()
{
    srand((unsigned)time(NULL));
        
        const int Low = -100, High = 100;
        
        int i, j, k, n;
        cout << "k = "; cin >> k;
        cout << "n = "; cin >> n;
        int **a = new int*[k];
            for (int i = 0; i < k; i++)
              a[i]=new int[n];
    Create(a, k, n, Low, High, 0, 0);
        Print(a, k, n, 0, 0);
        
    int max =0;
    MaxMin(a, k, n, 0, max);
    cout << "MaxMin = "<< max<< endl;
        
    for (int i=0; i<k; i++)
            delete [] a[i];
        delete []a;
        return 0;

}
