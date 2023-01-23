/**
 * @file sha_test.c
 * @author David Matuszak
 * @date 15 Sep 2019
 */
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include "sha256.h"
#define MAX 100
/**
 * @fn file_size(char *name).
 * @brief A function that returns the size of a file.
 *
 * @param *name the name of file.
 */
long file_size(char *name){
    FILE *fp = fopen(name, "rb");

    long size=-1;
    if(fp){
        fseek (fp, 0, SEEK_END);
        size = ftell(fp)+1;
        fclose(fp);
    }
    return size;
}
/**
 * @fn sha256(BYTE name[], char filename[]).
 * @brief A function that creates the hash from a given name array.
 *
 * @param name the array to be hashed.
 * @param filename file to save the hash.
 */
 
void sha256(BYTE name[], char filename[]){
	BYTE hash[SHA256_BLOCK_SIZE] = {0xba,0x78,0x16,0xbf,0x8f,0x01,0xcf,0xea,0x41,0x41,0x40,0xde,0x5d,0xae,0x22,0x23,
	                                 0xb0,0x03,0x61,0xa3,0x96,0x17,0x7a,0x9c,0xb4,0x10,0xff,0x61,0xf2,0x00,0x15,0xad};
	BYTE buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;
	
	sha256_init(&ctx);
	sha256_update(&ctx, name, strlen(name));
	sha256_final(&ctx, buf);
	
	FILE *fp = fopen(filename, "ab");
    if (fp != NULL){
        fputs(buf, fp);
        fclose(fp);
    }	
		
	
}
/**
 * @fn string2ByteArray(char* input, BYTE* output).
 * @brief A function that changes a string to a byte array.
 *
 * @param input the string being inputed.
 * @param output the byte array.
 */
void string2ByteArray(char* input, BYTE* output,long len ){
    long  loop;
    long  i;
    
    loop = 0;
    i = 0;
    printf("%d",len);
    while(loop < len){
        output[i] = input[loop];
        i++;
        loop++;
    }
}
/**
 * @fn int main(int argc, char **argv).
 * @brief A function creates a hash from a given file.
 *
 * @param argc the first param.
 * @param **argv the the input and output files.
 */
int main(int argc, char **argv){
	int j=0;
	char *buffer;
   	FILE *fl = fopen(argv[1], "r");    
    long len = file_size(argv[1]);    
    buffer = (BYTE *)malloc((len+1)*sizeof(BYTE)); 
	for(j = 0; j < len; j++) {
       	fread(*&buffer+j, 1, 1, fl);   	
	}
    fclose(fl);
	sha256(buffer, argv[2]);
	
	
	return(0);
	
}
