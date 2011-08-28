CFLAGS = -g -Wall -Os
TESTPROTOCOL = common
ALLPROTOCOLS = minimal test common pixhawk ardupilotmega slugs ualberta

all: 
	for p in ${ALLPROTOCOLS}; do make -f Makefile build TESTPROTOCOL=$$p; done

test:
	for p in ${ALLPROTOCOLS}; do make -f Makefile testprogs TESTPROTOCOL=$$p || exit 1; done

build: testmav0.9_${TESTPROTOCOL} testmav1.0_${TESTPROTOCOL} testmav1.0_${TESTPROTOCOL}_stackbuffer

testprogs: testmav0.9_${TESTPROTOCOL} testmav1.0_${TESTPROTOCOL} testmav1.0_${TESTPROTOCOL}_stackbuffer
	./testmav0.9_${TESTPROTOCOL}
	./testmav1.0_${TESTPROTOCOL}
	./testmav1.0_${TESTPROTOCOL}_stackbuffer

clean:
	rm -f *.o *~ testmav1.0* testmav0.9*

testmav1.0_${TESTPROTOCOL}: testmav.c
	$(CC) $(CFLAGS) -I../include_v1.0 -I../include_v1.0/${TESTPROTOCOL} -o $@ testmav.c

testmav1.0_${TESTPROTOCOL}_stackbuffer: testmav.c
	$(CC) $(CFLAGS) -DMAVLINK_STACK_BUFFER=1 -fno-strict-aliasing -I../include_v1.0 -I../include_v1.0/${TESTPROTOCOL} -o $@ testmav.c

testmav0.9_${TESTPROTOCOL}: testmav.c
	$(CC) $(CFLAGS) -I../include_v0.9 -I../include_v0.9/${TESTPROTOCOL} -o $@ testmav.c
