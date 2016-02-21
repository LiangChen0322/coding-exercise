/*
 * 快速排序的递归实现
 */ 
#include <stdio.h>

void print_result(int *in, int len)
{
	int i;

	for (i = 0; i < len; i++) {
		printf("%d\t", in[i]);
	}
	printf("\n");
}

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
	int i;
	int in[] = {56, 35, 23, 120, 29, 22};
	int n = 6;

	sort(in, 0, n - 1);
	print_result(in, n);

	return 0;
}