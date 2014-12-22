#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
// for pread

typedef unsigned long uint64_t;
uint64_t buf[0x10000];

void main()
{
int offset =0;
int size = 0x10000;
long  bytes;
int fd_kpagecount = open("/proc/kpagecount", O_RDONLY);
assert(fd_kpagecount!=0);
bytes = pread(fd_kpagecount, buf, size, offset);
int i =0;
printf("%lx",bytes);
//for(i=0;i<bytes;i++);
//printf("%lx\n",buf[i]);
}
