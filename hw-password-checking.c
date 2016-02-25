/*
 * 密码验证合格程序
 * 密码要求:
 * 1.长度超过8位
 * 2.包括大小写字母.数字.其它符号,以上四种至少三种
 * 3.不能有相同长度超2的子串重复
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PRINT_NG	puts("NG")
#define PRINT_OK	puts("OK")

bool password_check(char *str)
{
	int len;
	int flag[4] = {0, 0, 0, 0};
	int i, j;

	len = strlen(str);
	if (len <= 8)
		return false;

	for (i = 0; i < len; i++) {
		if(str[i] >= 'A' && str[i]<='Z')
			flag[0] = 1;
		else if(str[i] >= 'a' && str[i] <= 'z')
			flag[1] = 1;
		else if(str[i] >= '0' && str[i] <= '9')
			flag[2] = 1;
		else
			flag[3] = 1;

		for (j = i + 1; j < len; j++)
			if (str[i] == str[j]
				&& str[i + 1] == str[j + 1]
				&& str[i + 2] == str[j + 2])
				return false;
	}
	if (flag[0] + flag[1] + flag[2] + flag[3] < 3)
		return false;
	else
		return true;
}

int main(void)
{
	char in[10000];

	while (scanf("%s", in) != EOF) {
		if (password_check(in))
			PRINT_OK;
		else
			PRINT_NG;
	}

	return 0;
}
