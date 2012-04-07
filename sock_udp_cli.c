/********************************************************

  sock_udp_cli.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  int client_d;                    /* ソケットディスクリプタ */
  struct sockaddr_in server_addr;  /* サーバのアドレス */
  char send_msg[BUFSIZ];           /* 送信メッセージ */

  if(argc != 4){
    fprintf(stderr,"Usage: %s server-address server-port message\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  /* アドレスの初期化 */
  /* サーバのアドレス */
  server_addr.sin_family = AF_INET;
  if(inet_aton(argv[1], &(server_addr.sin_addr)) == 0){
    fprintf(stderr,"invalid address: %s\n",argv[1]);
    exit(EXIT_FAILURE);
  }
  server_addr.sin_port = htons(atoi(argv[2]));

  strcpy(send_msg, argv[3]);

  /* ソケットの作成 */
  errno = 0;
  if((client_d = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
    perror("socket failure");
    exit(EXIT_FAILURE);
  }

  /* 送信 */
  errno = 0;
  if(sendto(client_d,                        /* ソケットディスクリプタ */
	    send_msg,                        /* 送信メッセージ */
	    strlen(send_msg),                /* 上のサイズ */
	    MSG_NOSIGNAL,                    /* オプション */
	    (struct sockaddr *)&server_addr, /* サーバのアドレス */
	    sizeof(server_addr)              /* 上のサイズ */
	    ) == -1){
    perror("sendto failure");
    exit(EXIT_FAILURE);
  }

  /* ソケットのclose */
  close(client_d);

  exit(EXIT_SUCCESS);

}
