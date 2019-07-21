#include "flock.h"

struct flock* new_flock(char* id, int nodes, float weight) {
  struct flock* flock;

  flock->id = id;
  flock->nodes = nodes;
  flock->weight = weight;

  return flock;
}