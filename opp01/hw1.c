#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s[100];
	printf("문자를 입력하세요(100자 이내).\n");
	scanf("%s", s);
	printf("입력된 문자는 %s입니다.\n", s);

	//system ("pause");

	return 0;
}