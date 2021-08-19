#include <iostream>
using namespace std;

int getval(int (*A)[5], int i, int j, int L, int H)
{

    if (i < 0 || i >= L || j < 0 || j >= H)
    {
        return 0;
    }
    else
    {

        return A[i][j];
    }
}

void findMAxBlock(int (*A)[5], int r, int c, int L, int H, int size, bool **cntarr, int &maxsize)
{

    if (r >= L | c >= H)
    {
        return;
    }
    cntarr[r][c] = true;
    size++;

    if (size > maxsize)
    {
        maxsize = size;
    }

    // Search in 8 directions

    int direction[][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

    for (int i = 0; i < 8; i++)
    {
        int newi = r + direction[i][0];
        int newj = c + direction[i][1];
        int val = getval(A, newi, newj, L, H);
        if (val > 0 && (cntarr[newi][newj] == false))
        {
            findMAxBlock(A, newi, newj, L, H, size, cntarr, maxsize);
        }
    }

    cntarr[r][c] = false;
}

int getMaxOnes(int (*A)[5], int rmax, int colmax)
{

    int maxsize = 0;
    int size = 0;
    bool **cntarr = create2darr(rmax, colmax);

    for (int i = 0; i < rmax; i++)
    {
        for (int j = 0; j < colmax; j++)
        {
            if (A[i][j] == 1)
            {
                findMAxBlock(A, i, j, rmax, colmax, 0, cntarr, maxsize);
            }
        }
    }
    return maxsize;
}
int main()
{

    return 0;
}