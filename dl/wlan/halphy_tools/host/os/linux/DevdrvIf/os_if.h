#ifndef _OSIF_H_
#define _OSIF_H_

#ifndef UTFSIM
int cmd_init (char *ifname, void (*rx_cb)(void *buf));
int cmd_end();
void cmd_send (void *buf, int len, unsigned char responseNeeded );

#define UTF_CMD_INIT(ifname, rx_cb) cmd_init(ifname, rx_cb);
#define UTF_CMD_SEND(buf, len, responseNeeded) cmd_send(buf, len, responseNeeded)
#define UTF_RFSIM_INIT(ip_port)

#else
int cmd_init_sim(void (*rx_cb)(void *buf));
void cmd_send_sim(void *buf, int len, unsigned char responseNeeded);
int utf_rfsim_init(char* ip_port);

#define UTF_RFSIM_INIT(ip_port) utf_rfsim_init(ip_port)
#define UTF_CMD_INIT(ifname, rx_cb) cmd_init_sim(rx_cb)
#define UTF_CMD_SEND(buf, len, responseNeeded) cmd_send_sim(buf + 8, len, responseNeeded)

#endif

unsigned int cmd_Art2ReadPciConfigSpace (unsigned int offset);
int cmd_Art2WritePciConfigSpace(unsigned int offset, unsigned int data);

#endif /* _OSIF_H_ */
