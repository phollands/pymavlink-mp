CFLAGS = -g -Wall -Os

all: testmav1.0 testmav1.0_nonstrict testmav0.9

clean:
	rm -f *.o *~ testmav1.0 testmav1.0_nonstrict testmav0.9

testmav1.0: testmav.c
	$(CC) $(CFLAGS) -I../include_v1.0 -o $@ testmav.c

testmav1.0_nonstrict: testmav.c
	$(CC) $(CFLAGS) -DMAVLINK_STRICT_ALIASING=0 -fno-strict-aliasing -I../include_v1.0 -o $@ testmav.c

testmav0.9: testmav.c
	$(CC) $(CFLAGS) -I../include_v0.9 -o $@ testmav.c
