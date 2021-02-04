/*
 * Copyright (c) 2014 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define RECV_BUF_LEN 2048+8
typedef void (*tcmd_rx_cb)(void *buf);

static int sock;
static unsigned char responseBuf[RECV_BUF_LEN];
static fd_set fds;
static tcmd_rx_cb g_rx_cb;

int utf_rfsim_init(char* ip_port)
{
#ifndef MAX_IP4_LEN
#define MAX_IP4_LEN 16
#endif
	struct sockaddr_in serv_addr;
	char ip_addr[MAX_IP4_LEN+1] = {0};
	char *temp;
	uint16_t port;

	if (!ip_port) {
		return -1;
	}

	temp = strchr(ip_port, ':');
	port = (uint16_t) atol(temp + 1);
	strncpy(ip_addr, ip_port, (size_t)(temp - ip_port));

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0) {
		printf("Socket creation failed!!\n");
		return -1;
	}

	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//inet_addr(ip_addr);

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <0)
	{
		printf("Connection failed!!\n");
		return -1;
	}

	return 0;
}

int cmd_init_sim(void (*rx_cb)(void *buf))
{
	g_rx_cb = rx_cb;

	return 0;
}

void cmd_send_sim(void *buf, int len, unsigned char responseNeeded)
{
	ssize_t n_write, n_read;
	struct timeval timeout;
	int rc, maxfd;

	/* write to socket */
	n_write = write(sock, buf, len);
	if (n_write != len) {
		if (n_write < 0) {
			printf("cmd_send_sim error: %d\n", errno);
		} else {
			printf("cmd_send_sim: %zu only\n", n_write);
		}
	}

	if (responseNeeded) {
		FD_ZERO(&fds);
		FD_SET(sock,&fds);
		timeout.tv_sec  = 5;
		timeout.tv_usec = 0;
		maxfd = sock + 1;

		do {
			timeout.tv_sec  = 5;
			timeout.tv_usec = 0;
			rc = select(maxfd, &fds, (fd_set *) 0, (fd_set *) 0, &timeout);
			if (rc < 0)
			{
				printf("select() failed");
				break;
			}
			if (rc == 0)
			{
				printf("select() timed out\n");
				FD_ZERO(&fds);
				FD_SET(sock,&fds);
				continue;
			}
			if(FD_ISSET(sock, &fds)) {
				n_read = read(sock, responseBuf, RECV_BUF_LEN);
				if (n_read > 0) {
					g_rx_cb(responseBuf);
				} else if (n_read < 0) {
					printf("rfsim_recv error: %d\n", errno);
				} else {
					printf("rfsim_recv: 0\n");
				}
				break;
			}
		} while(1);
	}
}
