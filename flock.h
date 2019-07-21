#ifndef FLOCK_H
#define FLOCK_H

struct flock {
  char* id;
  int nodes;
  float weight; 
};

struct flock* new_flock(char* id, int nodes, float weight);

char* get_id();

int get_nodes();

float get_weight();

#endif