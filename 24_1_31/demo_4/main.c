#include <stdio.h>

int main() {
	int charCount;
	printf("Hello,%nWorld!\n", &charCount);
	
	printf("Number of characters printed: %d\n", charCount);
	
	return 0;
}

