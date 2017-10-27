#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

#define KEY_LENGTH 1024
#define PUB_EXP 3

RSA *keypair = RSA_getnerate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);

BIO *pir = BIO_new(BIO_s_mem());
BIO *pub = BIO_new(BIO_s_mem());

PEM_write_bio_RSAPrivateKey(pri, keypari, NULL, NULL, 0, NULL, NULL);
PEM_write_bio_RSApublicKey(pub, keypair);

pri_len = BIO_pending(pri);
pub_len = BIO_pending(pub);

pri_key = malloc(pri_len + 1);
pub_key = malloc(pub_len + 1);

BIO_read(pri, pri_key, pri_len);
BIO_read(pub, pub_key, pub_len);

pri_key[pri_len] = '\0';
pub_key[pri_len] = '\0';

FILE *key_file;
key_file = fopen("prikey.pem", "w");
fprintf(key_file, "%s", pri_key);
fclose(key_file);
key_file = fopen("pubkey.pem", "w");
fprintf(key_file, "%s", pub_key);
fclose(key_file);

key_file = fopen("rsa.key", "w");
RSA_print_fp(key_file, keypair, 0);
fclose(key_file);
