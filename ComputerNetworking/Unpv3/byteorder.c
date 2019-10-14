#include "unp/unp.h"
#include <arpa/inet.h>
int main(int argc, char * argv[])
{
	union
	{
		short s;
		char c[sizeof(short)];
	} un;
	un.s = 0x2102; // 0010 0001 0000 0010 //<--------高---------低
	//0x0201 0000 0010 0000 0001 <-------------高-------------低
	//0x0221 0000 0010 0010 0001
	printf("%s: ", CPU_VENDOR_OS);
	un.s = htons(un.s);
	if (sizeof(short) == 2)
	{
		if (un.c[0] == 1 && un.c[1] == 2)
			printf("big-endian\n");
		else if (un.c[0] == 2 && un.c[1] == 1)
			printf("little-endian\n");
		else
			printf("unknown : %#x\n", un.s);
	}
	else
	{
		printf("sizeof(short) =  %u\n", sizeof(short));
	}
	return 0;
}