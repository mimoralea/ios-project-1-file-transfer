#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>


#define BUFSIZE 4096

#define USAGE							\
     "usage:\n"							\
     "  transferserver [options]\n"				\
     "options:\n"						\
     "  -p                  Port (Default: 8888)\n"		\
     "  -f                  Filename (Default: bar.txt)\n"	\
     "  -h                  Show this help message\n"

int main(int argc, char **argv) {
     int option_char;
     int portno = 8888; /* port to listen on */
     char *filename = "bar.txt"; /* file to transfer */

     // Parse and set command line arguments
     while ((option_char = getopt(argc, argv, "p:f:h")) != -1){
	  switch (option_char) {
	  case 'p': // listen-port
	       portno = atoi(optarg);
	       break;
	  case 'f': // listen-port
	       filename = optarg;
	       break;
	  case 'h': // help
	       fprintf(stdout, "%s", USAGE);
	       exit(0);
	       break;
	  default:
	       fprintf(stderr, "%s", USAGE);
	       exit(1);
	  }
     }

     /* Socket Code Here */
}
