#include <stdio.h>
#include <stdlib.h>

void defang(char *target, char *ip);

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <ip address>\n", argv[0]);
		return 1;
	}

	char *ip = argv[1];
	char *defanged = malloc(1024);

	defang(defanged, ip);
	printf("%s\n", defanged);

	free(defanged);
	return 0;
}

void defang(char *target, char *ip)
{
	int i = 0;
	int j = 0;

	do
	{
		target[i] = ip[j];

		if (ip[j] == '.')
		{
			target[i] = '[';
			target[i + 1] = '.';
			target[i + 2] = ']';
			i += 2;
		}

		j++;
		i++;
	} while (ip[j] != 0);
}
