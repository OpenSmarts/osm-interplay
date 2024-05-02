#include <osm/discover.h>

#include <stddef.h>
#include <stdio.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	// connect to socket
	int fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	struct sockaddr_un addr = {0};
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, "/run/osm/onboard/0");

	int ret = connect(fd, (struct sockaddr *) &addr, sizeof(addr));
	if (ret == -1)
	{
		perror("connect");
		return 1;
	}
	
	double temp = 0;
	read(fd, &temp, sizeof(temp));

	close(fd);

	printf("%f\n", temp);

	return 0;
}


