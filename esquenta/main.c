#include<stdio.h>
#include<stdlib.h>
int main() {
	int n,i=-1, p=1;
	scanf_s("%d", &n);
	char *c = (char*)malloc(sizeof(char)*((size_t)n+1));
	scanf_s("%s", c, n+1);
	for (i = 0; (i < n / 2)&& (p!=0); i++)
		if (c!=NULL && c[i] != c[n - 1 - i])
			p = 0;
	printf("%d", p);
	free(c);
	return 0;
}
/*int n = -1;
	scanf_s("%d", &n);
	printf("ESQEUNTA UBERLANDIA 2026\nEquipes confirmadas: %d",n);*/
/*char s[500];
	int i = -1;
	scanf_s("%s", s,500);
	char c[] = strlen();
	for(i=0; s[i] !='\0';i++)
		printf("%c",s[i]);*/