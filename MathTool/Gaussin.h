#ifndef _GAUSSIN_H_
#define _GAUSSIN_H_



#include <stdio.h>
#include "mymath.h"

#define MAX_EQUA_NUM 50

void Gaussin(double param[MAX_EQUA_NUM][MAX_EQUA_NUM], double b[MAX_EQUA_NUM], int n)
{
	if(n > MAX_EQUA_NUM){
		printf("Number of equations (%d) is out of range.\n", n);
		return;
	}

/* 检查对角线上有么有0 */
	for(int i = 0; i < n; ++i)
		if(isZero(param[i][i])){
			printf("Cannot use Gaussin method.\n");
			return;
		}

/* 初等行变换 */
	double tmp[MAX_EQUA_NUM];
	for(int k = 0; k < n - 1; ++k)
	{
		for(int i = k + 1; i < n; ++i)
			tmp[i] = param[i][k] / param[k][k];

		for(int i = k + 1; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				param[i][j] = param[i][j] - tmp[i] * param[k][j];
			b[i] = b[i] - tmp[i] * b[k];
		}
	}

/* 存储解 */
	double solu[n];
	/* 最后一个解 */
	solu[n - 1] = b[n - 1] / param[n - 1][n - 1];
	for(int i = n - 2; i >= 0; --i)
	{
		double sum = 0;
		for(int j = i + 1; j < n; ++j)
			sum += param[i][j] * solu[j];
		solu[i] = (b[i] - sum) / param[i][i];
	}

	printf("The solution is (%lf", solu[0]);
	for(int i = 1; i < n; ++i)
		printf(", %lf", solu[i]);
	printf(").\n");
}


void Gaussin_test()
{
	double a[MAX_EQUA_NUM][MAX_EQUA_NUM] = {{1, 1, 1}, {0, 4, -1}, {2, -2, 1}};
	double b[MAX_EQUA_NUM] = {6, 5, 1};


	Gaussin(a, b, 3);
}


#endif