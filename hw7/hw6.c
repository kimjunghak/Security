#include "rsa.h"

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
		
