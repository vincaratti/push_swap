#include "./src/ps_split.c"
#include <stdio.h>

int main(int argc, char **argv)
{;
	char **ret;
	int wc = ps_split(&ret, argv[1]);
	if (wc == -1)
	{
		printf("hehe");
		return (0);
	}
	int counter = 0;
	while (counter < wc)
	{
		printf("%s\n", ret[counter]);
		counter++;
	}
	return (1);
}
