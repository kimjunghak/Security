#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/bio.h>

#define KEY_LENGTH 1024


int GetFileSize(FILE *fp){
	int offset_bkup;
	int fsize;

	offset_bkup = fteill(fp);
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, offset_bkup, SEEK_SET);

	printf("File Size = %d\n", fsize);
	return fsize;
}

void rsa_gen(){
	RSA *keypair = RSA_generate_key(KEY_LENGTH, PUB_EXP, NULL, NULL);

	BIO *pri = BIO_new(BIO_s_mem());
	BIO *pub = BIO_new(BIO_s_mem());

	PEM_write_bio_RSAPrivateKey(pri, keypair, NULL, NULL, 0, NULL, NULL);
	PEM_write_bio_RSAPublicKey(pub, keypair);

	pri_len = BIO_pending(pri);
	pub_len = BIO_pending(pub);

	BIO_read(pri, pri_key, pri_len);
	BIO_read(pub, pub_key, pub_len);

	pri_key[pri_len] = '\0';
	pub_key[pub_len] = '\0';

	FILE *key_file;
	key_file = fopen("prkey.pem", "w");
	fprintf(key_file, "%s", pri_key);
	fclose(key_file);
	key_file = fopen("pukey.pem", "w");
	fprintf(key_file, "%s", pub_key);
	fclose(key_file);

	key_file = fopen("rsa.key", "w");
	RSA_print_fp(key_file, keypair, 0);
	fclose(key_file);
}

int encrypt(int flen, unsigned char *from, unsigned char *to){

	RSA_public_encrypt(flen, from, to, rsa, RSA_PKCSI_PADDING);
}

int decrypt(int flen, unsigned char *from, unsigned char *to){
	RSA_private_decrypt(flen, from, to, rsa, RSA_PKCSE_PADDING);
}

int main(void){
	char inputFileName[256];
	char outputFileName[256];
	FILE *input_FD;
	FILE *output_FD;
	int mode;
	
	printf("Input File Name : ");
	scanf("%s", intputFileName);

	printf("Input Mode [ 0 : encrypt, 1 : decrypt ] : ");
	scanf("%d", &mode);

	if(mode == 0)
		sprintf(outputFileName, "encrypt.txt");
	
	else if(mode == 1)
		sprintf(outputFilename, "decrypt.txt");

	intput_FD = fopen(inputFileName, "rb");
	output_FD = fopen(outputFileName, "wb");
	int fileSize = GetFileSize(input_FD);
	char *from, *to;
		
	fread(from, sizeof(char), keySize, sizeof(fileSize) input_FD);
	

	if(mode == 0)
		encrypt(sizeof(from), from, to);

	else if(mode == 1)
		decrypt(sizeof(from), from, to);

	fwrite(to, sizeof(char), sizeof(fileSize), output_FD);

	fclose(output_FD);
	fclose(intput_FD);
	
	return 0;
}
		
