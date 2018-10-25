#include <stdio.h>

int main(int arg, char* argc[]) {
	int integer;
	int *integerp;
	long loong;
	double *dooublep;
	char **characterpp;
	printf("%d\n %d\n %d\n %d\n %d\n", sizeof(integer), sizeof(integerp), sizeof(loong), sizeof(dooublep), sizeof(characterpp));
	return 0;
}
