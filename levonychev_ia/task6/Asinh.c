#include "MyFunc.h"
#include <math.h>


double my_asinh(double x, double precision, int N, int* pcount)
{
    double result = x;
    double temp = x;
    double present;
    int i = 1;
    while (i < N && (fabs(asinh(x) - result) >= precision))
    {
        present = -temp * x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i) * (2 * i + 1));
        result += present;
        temp = present;
        i++;
    }
    *pcount = i;
    return result;
}