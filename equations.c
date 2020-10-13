#include "header.h"

// This function makes it more efficient to open files in main
FILE* openFile(char* fileName, char* mode)
{
	FILE* file = NULL;
	file = fopen(fileName, mode);

	if (file == NULL)
	{
		printf("Error: File not found");
		return NULL;
	}
	return file;
}

