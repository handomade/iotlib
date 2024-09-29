#include <stdio.h>
#include "iotlib.h"

main ()
{
	int bl,i;
	TINY st[32];
	TINY* file[32];

	bl = iotgti("host/battery/level");
	printf("Battery Level:%u\n",bl);

	bl = iotgti("msx/me/id");
	printf("UnitID:%u\n",bl);

	bl = iotgts("host/ip",st);
	printf("HostIP:%s\n",st); 

	iotpti("msx/me/pm/cpu/percent",255);
	bl = iotgti("msx/me/pm/cpu/percent");
	printf("CPU PERCENT:%u\n",bl);	

	printf("iotpts(\"conf/wifi/list/3/ssid\",\"testSSID\"\n");
	iotpts("conf/wifi/list/3/ssid","testSSID");
	iotgts("conf/wifi/list/3/ssid",st);
	printf("list3 SSID:%s\n",st);

	bl = iotfds("host/media/dsk",file);
	for(i = 0 ; i < bl ;++i){
		printf("%u:%s\n",i,file[i]);
		free(file[i]);
	}

}
