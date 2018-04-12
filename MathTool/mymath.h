#ifndef _MY_MATH_H_
#define _MY_MATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* 最大公约数 */
int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

/* 最小公倍数 */
inline int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

/* 判断浮点数是否为0 */
int isZero(double d){
	if(d >= -DBL_EPSILON && d <= DBL_EPSILON)
		return 1;
	return 0;
}

#endif