/********************************************************

  sock_udv_svr.c

  Copyright (c) 2011 Go Hosohara.  All rights reserved.

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

void main(int argc,char** argv){

  int server_d;                                 /* ソケットディスクリプタ */
  struct sockaddr_in server_addr;               /* サーバのアドレス */
  struct sockaddr_in client_addr;               /* クライアントのアドレス */
  int client_len = sizeof(struct sockaddr_in);  /* 上の長さ */
  char recv_buf[BUFSIZ];                        /* 受信バッファ */

  if(argc != 2){
    fprintf(stderr,"Usage: %s server-port\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  /* アドレスの初期化 */
  /* サーバのアドレス */
  server_addr.sin_family = AF_INET;
  /* 接続を受け付けるアドレス(つまりどのNICで接続を受け付けるか)
     ここでは全てのアドレスでの接続を受け付けている */
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(atoi(argv[1]));

  /* ソケットの作成 */
  errno = 0;
  if((server_d = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
    perror("socket failure");
    exit(EXIT_FAILURE);
  }

  /* ソケットのbind */
  errno = 0;
  if(bind(server_d, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
    perror("bind failure");
    exit(EXIT_FAILURE);
  }

  fprintf(stdout,"starting server: port = %d\n", ntohs(server_addr.sin_port));

  /* 受信 */
  while(1){
    errno = 0;
    if(recvfrom(server_d,                        /* ソケットディスクリプタ */
		recv_buf,                        /* 受信バッファ */
		BUFSIZ,                          /* 受信バッファサイズ */
		MSG_NOSIGNAL,                    /* オプション */
		(struct sockaddr *)&client_addr, /* クライアントのアドレス */
		&client_len                      /* 上のサイズ */
		) == -1){
      perror("recvform failure");
      exit(EXIT_FAILURE);
    }
    
    /* サーバ処理 */
    fprintf(stdout, "recved msg from %s:%d\n",
	    inet_ntoa(client_addr.sin_addr),
	    ntohs(client_addr.sin_port));
    fprintf(stdout,"recv msg: \"%s\"\n",recv_buf);
    if(strcmp(recv_buf, "exit") == 0){
      break;
    }else{
      memset(recv_buf, '\0', BUFSIZ);
    }
  } 

  /* ソケットのclose */
  close(server_d);
 
  exit(EXIT_SUCCESS);

}
