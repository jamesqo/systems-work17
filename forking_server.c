#include "pipe_networking.h"
#include <signal.h>
#include <ctype.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

int main() {
  int from_client;

  while (1) {
    from_client = server_setup();

    if (fork() == 0) {
      subserver(from_client);
    } else {
      close(from_client);
    }
  }
}

void subserver(int from_client) {
  int to_client = server_connect(from_client);
  char buf[BUFFER_SIZE];
  
  while (1) {
    read(from_client, buf, sizeof(buf));
    process(buf);
    write(to_client, buf, sizeof(buf));
  }
}

void process(char * s) {
  int i;
  for (i = 0; s[i]; i++) {
    s[i] = toupper(s[i]);
  }
}
