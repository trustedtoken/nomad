#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[argc + 1]) {
  printf("Hello, Nomad\n");

  // Two random prime numbers 
    double p = 3; 
    double q = 7; 
  
    // First part of public key: 
    double n = p*q; 
  
    // Finding other part of public key. 
    // e stands for encrypt 
    double e = 2; 
    double phi = (p-1)*(q-1); 
    while (e < phi) 
    { 
        // e must be co-prime to phi and 
        // smaller than phi. 
        if (gcd(e, phi)==1) 
            break; 
        else
            e++; 
    } 
  
    // Private key (d stands for decrypt) 
    // choosing d such that it satisfies 
    // d*e = 1 + k * totient 
    int k = 2;  // A constant value 
    double d = (1 + (k*phi))/e; 
  
    // Message to be encrypted 
    double msg = 20; 
  
    printf("Message data = %lf", msg); 
  
    // Encryption c = (msg ^ e) % n 
    double c = pow(msg, e); 
    c = fmod(c, n); 
    printf("\nEncrypted data = %lf", c); 
  
    // Decryption m = (c ^ d) % n 
    double m = pow(c, d); 
    m = fmod(m, n); 
    printf("\nOriginal Message Sent = %lf", m); 

  pid_t child = fork();
  // char *newargv[4] = { "hi mom!", "-d", "60", NULL };
  // execv("/usr/bin/top", newargv);

 if (child == 0) {
    printf("Hello from the child!\n");
  } else {
    printf("Hello from the parent!\n");
  }

  for (;;) {
    // run forever
  }

  return EXIT_SUCCESS;
}