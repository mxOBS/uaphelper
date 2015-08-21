#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	// update-alternatives <arguments> <nullterminator>
	size_t cmdlen = 19;
	// arguments
	for(int i = 1; i < argc; i++) {
		// space
		cmdlen += 1;

		// argument
		cmdlen += strlen(argv[i]);
	}
	// null-terminator
	cmdlen += 1;
	char *cmd = malloc(sizeof(char)*cmdlen);

	char *cmditr = cmd;
	sprintf(cmditr, "update-alternatives");
	cmditr += sizeof(char)*19;
	for(int i = 1; i < argc; i++) {
		cmditr[0] = ' ';
		cmditr += sizeof(char);
		size_t l = strlen(argv[i]);
		memcpy(cmditr, argv[i], l);
		cmditr += sizeof(char)*l;
	}
	cmditr[0] = 0;
	cmditr += sizeof(char);

	int s = system(cmd);

	free(cmd);

	return s;
}
