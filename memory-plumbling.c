#include <stdio.h>
#include <unistd.h> // for pread
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <inttypes.h> // for uint64_t

#define BUF_SIZE 0x100000 //PAGE_SHIFT is 4KB,so BUF_SIZE should cover 4GB
unsigned long long buf[BUF_SIZE]; //uint64_t is 8 bytes

void main()
{
	int offset =0;
	int  bytes;
	int size = BUF_SIZE*8;
	int fd_kpagecount = open("/proc/kpagecount", O_RDONLY);
	assert(fd_kpagecount!=0);
	bytes = pread(fd_kpagecount, buf, size, offset);
	if(bytes == -1){
		printf("pread error \n");
		return;
	}
	printf("%s: %x\n",__func__,bytes);
	int i=0;
	for(;i<bytes/8;i++){
	 if(buf[i] !=0 && buf[i]!=-127)
	 printf("%x :  %lld \n",i,buf[i]);
	}
}
