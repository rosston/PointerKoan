#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	puts("This is the C++ pointer koan.");
	puts("Meant to practice pointer arithmetic");
	puts("It simply uses assert on a known data structure, and you fill in the rest");

	// Start with operations on an unsigned char - where a char is 1 byte
	unsigned char originalPointer[256];
	for(int i = 0; i < 256; i++)
		originalPointer[i] = i;

	unsigned char *p = originalPointer;

	assert(p[0] == 0);
	assert(*p == 0);

	p = p + 3;
	assert(*p == 3);

	unsigned char a = *p++;
	assert(a == 3);
	assert(*p == 4);

	unsigned char b = *(p++);
	assert(b == 4);
	assert(*p == 5);

	// Would love to deal with the 'endianness' of the memory.
	// Not sure I can
	unsigned char c = *++p;
	assert(c == 6);
	assert(*p == 6);

	// Sure you can - cast and display the hex value
	// but how would you simulate the memory?
	unsigned char *np = p + 3;
	assert(*np == 9);
	assert(*p == 6);

	//Let's setup an integer pointer
	unsigned int *intP = (unsigned int*) originalPointer;

	// Hint remember your processors Endianness
	// Also you should probably do these as hex
	assert(*intP == 0x03020100); // 50462976

	intP = intP + 3;
	assert(*intP == 0x0f0e0d0c); // 252579084

	intP = (unsigned int *)((unsigned char *) (intP) + 3);
	assert(*intP == 0x1211100f); // 303108111

	unsigned int intX = *intP--;
	assert(intX == 0x1211100f); // 303108111
	assert(*intP == 0x0e0d0c0b); // 235736075

	unsigned int *subtractedP = intP - 1;
	assert(*subtractedP == 0x0a090807); // 168364039
	assert(intP - subtractedP == 1);

	// Obscure C trick
	intP = (unsigned int*) originalPointer;
	assert(3[intP] == 0x0f0e0d0c); // 252579084

	puts("Congrats you did it!  You must know your pointers");
	return 0;
}
