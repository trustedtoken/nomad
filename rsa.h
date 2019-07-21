#ifndef RSA_H
#define RSA_H

typedef struct rsa rsa;

char* rsa_public_key();
char* rsa_private_key();
char* rsa_encrypt();
char* rsa_decrypt();

#endif