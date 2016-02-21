/*
 * 明明的随机数
 * 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，
 * 他先用计算机生成了N个1到1000之间的随机整数（N≤100），对于其中重复的数字，
 * 只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。
 * 然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
 * 请你协助明明完成“去重”与“排序”的工作。
 */

#include <stdio.h>

void sort(int *in, int start, int end)
{
	int i = start, j = end;
	int temp = in[start];

	if (i >= j)
		return;

	while (i < j) {
		while (in[j] >= temp && i < j)
			j--;
		in[i] = in[j];
		while (in[i] <= temp && i < j)
			i++;
		in[j] = in[i];
	}
	in[i] = temp;
	
	sort(in, start, i - 1);
	sort(in, i + 1, end);
}

int main(void)
{
	int num;
	int in[1000];
	int outl, i;

	//scanf("%d", &num);
	while (scanf("%d", &num) != EOF) {
		for (i = 0; i < num; i++)
			scanf("%d", &in[i]);
		sort(in, 0, num - 1);

		printf("%d\n", in[0]);
		for (i = 1; i < num; i++) {
			if (in[i] == in[i - 1])
				continue;
			printf("%d\n", in[i]);
		}
	}

	return 0;
}
