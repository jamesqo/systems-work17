#include "pipe_networking.h"
#include <signal.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

int main() {
  int to_client;
  int from_client;

  from_client = server_setup();

  if (fork() == 0) {
    server_connect(from_client);
  } else {
    
  }
}

void subserver(int from_client) {
}

void process(char * s) {
}
