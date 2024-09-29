#include <stdio.h>
#include <stdlib.h>
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
	outp(PORT, (TINY)0x00);

	result[0] = inp(PORT);
	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x03);
	outp(PORT,(TINY)0x80);
	l = inp(PORT);
	for(i = 0;i < l;++i){
	 result[i] = inp(PORT);
	}
	result[l] = 0;
	return l;
}

iotpti(device_path,value)
TINY* 	device_path;
int 	value;
{
	size_t l;
	int i,r;

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x53);
	outp(PORT,(TINY)0xC0);
	l = strlen(device_path);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)*device_path);
 	 device_path++;
	};
	outp(PORT, (TINY)0x00);
	
	r = inp(PORT);
	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x41);
	outp(PORT,(TINY)0xC0);
	outp(PORT,(TINY)0x02);
	outp(PORT,(TINY)(value & 0x00ff));
	outp(PORT,(TINY)((value & 0xff00)>>8));
}

iotpts(device_path,value)
TINY*	device_path;
TINY*	value;
{
	size_t l;
	int i,r;

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x53);
	outp(PORT,(TINY)0xC0);
	l = strlen(device_path);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)*device_path);
 	 device_path++;
	};
	outp(PORT, (TINY)0x00);
	r = inp(PORT);	
	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x43);
	outp(PORT,(TINY)0xC0);
	l = strlen(value);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)*value);
	 value++;
	}
	outp(PORT,(TINY)0x00);
	r = inp(PORT);
}

int iotfdi(device_path)
char* 	device_path;
{
	size_t l;
	int i;
	TINY r[2];

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x53);
	outp(PORT,(TINY)0xC0);
	l = strlen(device_path);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)*device_path);
 	 device_path++;
	};
	outp(PORT, (TINY)0x00);

	r[0] = inp(PORT);
	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x11);
	outp(PORT,(TINY)0x80);
	r[0] = inp(PORT);
	r[0] = inp(PORT);
	r[1] = inp(PORT);
	return *((int*)r);
}

int iotfds(device_path,result)
TINY* 	device_path;
TINY**	result;
{
	size_t l;
	int i,j,r,num;
	num = iotfdi(device_path);

	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x53);
	outp(PORT,(TINY)0xC0);
	l = strlen(device_path);
	outp(PORT,(TINY)l);
	for(i = 0;i < l;++i){
	 outp(PORT,(TINY)*device_path);
 	 device_path++;
	};
	outp(PORT, (TINY)0x00);
	r = inp(PORT);
	outp(PORT,(TINY)0xE0);
	outp(PORT,(TINY)0x01);
	outp(PORT,(TINY)0x13);
	outp(PORT,(TINY)0x80);
	for(i = 0;i < num; ++i){
	 	l = inp(PORT);
		result[i] = alloc(l + 1);
	 	for(j = 0;j < l;++j){
	 		 result[i][j] = inp(PORT);
	 	}
	 	result[i][j] = 0;
	}
	return num;
}
