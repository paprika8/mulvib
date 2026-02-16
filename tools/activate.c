#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(){
	char* infile_name = getenv("SRCIN");
	char* outfile_name = getenv("CODEOUT");
	char* machin = getenv("MACHIN");

	printf("activate %s with %s output %s\n", infile_name, machin, outfile_name);

	FILE* infile = fopen(infile_name, "r");
	FILE* outfile = fopen(outfile_name, "w");

	if(infile == 0) {
		printf("activate failed\nERR no exist %s\n", infile_name);
		return -1;
	}

	

	char* line = malloc(MAX_LINE_SIZE);
	while(fgets(line, MAX_LINE_SIZE, infile)){
		if(strncmp(machin, line, strlen(machin)) == 0){
			for(int i = 0; i < strlen(machin); i++)
				line[i] = ' ';
		}
		fprintf(outfile, "%s", line);
		//printf("process %s\n", line);
	}

	fclose(outfile);
	fclose(infile);

	printf("activate complete");

	return 0;
}