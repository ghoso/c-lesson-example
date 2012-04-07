#Makefile

CC	=	gcc
OBJS1	=	hello.o
CMD1	=	hello
OBJS2	=	if-ctl.o
CMD2	=	if-ctl
OBJS3	=	switch-ctl.o
CMD3	=	switch-ctl
OBJS4	=	for-ctl.o
CMD4	=	for-ctl
OBJS5	=	while-ctl.o
CMD5	=	while-ctl
OBJS6	=	type.o
CMD6	=	type
OBJS7	=	function.o
CMD7	=	function
OBJS8	=	pointer.o
CMD8	=	pointer
OBJS9	=	data_struct.o
CMD9	=	data_struct
OBJS10	=	data_struct2.o
CMD10	=	data_struct2
OBJS11	=	scope.o
CMD11	=	scope
OBJS12	=	file-read.o
CMD12	=	file-read
OBJS13	=	file-write.o
CMD13	=	file-write
OBJS14	=	sock_udp_svr.o
CMD14	=	sock_udp_svr
OBJS15	=	sock_udp_cli.o
CMD15	=	sock_udp_cli
OBJS16	=	sock_tcp_svr.o
CMD16	=	sock_tcp_svr
OBJS17	=	child.o
CMD17	=	child
OBJS18	=	linklist.o
CMD18	=	linklist


all: $(CMD1) $(CMD2) $(CMD3) $(CMD4) $(CMD5) $(CMD6) $(CMD7) $(CMD8) $(CMD9) $(CMD10) $(CMD11) $(CMD12) $(CMD13) $(CMD14) $(CMD15) $(CMD16) $(CMD17) $(CMD18)

$(CMD1):$(OBJS1)
	$(CC) -o $@ $(OBJS1)

$(CMD2):$(OBJS2)
	$(CC) -o $@ $(OBJS2)

$(CMD3):$(OBJS3)
	$(CC) -o $@ $(OBJS3)

$(CMD4):$(OBJS4)
	$(CC) -o $@ $(OBJS4)

$(CMD5):$(OBJS5)
	$(CC) -o $@ $(OBJS5)

$(CMD6):$(OBJS6)
	$(CC) -o $@ $(OBJS6)

$(CMD7):$(OBJS7)
	$(CC) -o $@ $(OBJS7)

$(CMD8):$(OBJS8)
	$(CC) -o $@ $(OBJS8)

$(CMD9):$(OBJS9)
	$(CC) -o $@ $(OBJS9)

$(CMD10):$(OBJS10)
	$(CC) -o $@ $(OBJS10)

$(CMD11):$(OBJS11)
	$(CC) -o $@ $(OBJS11)

$(CMD12):$(OBJS12)
	$(CC) -o $@ $(OBJS12)

$(CMD13):$(OBJS13)
	$(CC) -o $@ $(OBJS13)

$(CMD14):$(OBJS14)
	$(CC) -o $@ $(OBJS14)

$(CMD15):$(OBJS15)
	$(CC) -o $@ $(OBJS15)

$(CMD16):$(OBJS16)
	$(CC) -o $@ $(OBJS16)

$(CMD17):$(OBJS17)
	$(CC) -o $@ $(OBJS17)

$(CMD18):$(OBJS17)
	$(CC) -o $@ $(OBJS17)

.c.o:
	$(CC) -c $<
clean:
	$(RM) $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(OBJS8) $(OBJS9) $(OBJS10) $(OBJS11) $(OBJS12) $(OBJS13) $(OBJS14) $(OBJS15) $(OBJS16) $(OBJS17) $(OBJS18) $(CMD1) $(CMD2) $(CMD3) $(CMD4) $(CMD5) $(CMD6) $(CMD7) $(CMD8) $(CMD9) $(OBJS10) $(CMD10) $(CMD11) $(CMD12) $(CMD13) $(CMD14) $(CMD15) $(CMD16) $(CMD17) $(CMD18)
