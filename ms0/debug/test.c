#include <stdio.h>
#include <string.h>

int main()
{
	char dest[100] = "Pupa";
	char src[7] = "Zalupa";

	strlcpy(dest, src, 7);

	printf("%s", dest);

	return 0;
}
