CFLAGS := -Wall --std=gnu99 -g

default: transferserver transferclient
transferserver: $(LDFLAGS) transferserver.o
transferclient: $(LDFLAGS) transferclient.o

.PHONY: clean

clean:
	rm -fr *.o transferserver transferclient
