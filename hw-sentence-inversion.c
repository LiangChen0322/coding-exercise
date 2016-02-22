/*
 * 句子逆序
 * 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
 * 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
 */
#include <stdio.h>

#define MAX_LEN		1000

int main(void)
{
	char in[MAX_LEN];
	char *p = in;
	char *q;
	int i = 0;

	while ((in[i] = getchar()) != EOF && (in[i] != '\n') && i < MAX_LEN)
		i++;
	if (i == 0)
		return 0;
	in[i] = '\0';

	p = in + i;
	q = p - 1;
	while (q > in) {
		if (*q == ' '){
			printf("%s ", q + 1);
			*q = '\0';
			p = q;
		}
		--q;
	}
	printf("%s\n", q);

	return 0;
}
