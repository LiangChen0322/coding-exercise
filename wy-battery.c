/*
 * 炮台攻击
 * 黑默丁格有三个炮台,炮台能攻击到距离它R的敌人
 * (两点之间的距离为两点连续的距离,例如(3,0),(0,4)之间的距离是5),
 * 如果一个炮台能攻击 到敌人,那么就会对敌人造成1×的伤害.
 * 黑默丁格将三个炮台放在N*M方格中的点上,并且给出敌人 的坐标.
 * 问:那么敌人受到伤害会是多大?
 * gcc -o run.o wy-battery.c -lm -I/usr/include
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	double r;
	double x[4], y[4];
	double d;
	int hurt;
	int i;

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",
				&r, x + 1, y + 1, x + 2, y +2,
				x + 3, y + 3, x, y) != EOF) {
		hurt = 0;
		r = pow(r, 2);
		for (i = 1; i <= 3; i++) {
			d = pow(x[i] - x[0], 2) + pow(y[i] - y[0], 2);
			if (d <= r)
				hurt++;
		}
		printf("%dx\n", hurt);
	}
}
