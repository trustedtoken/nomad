#include <sys/types.h>
#include <unistd.h>

/*
 * s_fork implements a secure child process
 * nomad uses those secure processes to distribute them
 * inside the os, killing the original ones.
 */
pid_t s_fork(void) {
  pid_t childpid;

  if((childpid = fork()) == -1) return -1;

  if(childpid != 0) return childpid;
}