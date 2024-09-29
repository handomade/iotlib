#include <stdio.h>
#include <stdlib.h>
/*#include <string.h>*/
/*#include <conio.h>*/
#ifndef HEADERtype
#include <type.h>
#endif

#define PORT 	0x58

int iotgti(device_path)
TINY* device_path;
{
	TINY	r[2];
	size_t l;
	int i;

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x53);
	outp(PORT,(TINY)0xC0);
	l = strlen(device_path);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)device_path[i]);
	};
	outp(PORT, (TINY)0x00);

	r[0] = inp(PORT);

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x80);

	r[0] = inp(PORT);
	r[0] = inp(PORT);
	r[1] = inp(PORT);
	return *((int*)r);
}
	
int iotgts(device_path,result)
TINY* device_path;
TINY* result;
{
	size_t l;
	int i;

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x53);
	outp(PORT,(TINY)0xC0);
	l = strlen(device_path);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)device_path[i]);
	};
	outp(PORT, (TINY)0