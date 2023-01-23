/**
 * @file divideFiles.c
 * @author David Matuszak
 * @date 15 Sep 2019
 */
#include<stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILE_NAME 1000
#define MAX_LINE_LENGTH 1080
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
 * @fn int main(int argc, char **argv).
 * @brief This function devides the files acording to the imput.
 * This function creates the needed files to begine the division. 
 * The original file is copyied to the first file in chunks of 1080 bytes. When the appropriate size is reached the rest of the file is written to the remainder file.
 *
 * @param argc the first argument.
 * @param **argv the the name of files and the size of resoult program.
 */
int main(int argc, char **argv){
    int segments=0, i, len,accum;
    int setSize;
    FILE *fpOriginal, *fpResoult, *fpRemainder;
    
    char originalFileName[MAX_FILE_NAME];
    strcpy (originalFileName, argv[1]);
    long long int sizeFile = file_size(originalFileName);    
    setSize = atoi(argv[2]);
    setSize = setSize*1000;
    
    char remainderFileName[MAX_FILE_NAME];
    char resoultFileName[MAX_FILE_NAME];
    char line[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
	i = 1; 
	int j=0, sizeCounter=0;
	fpOriginal = fopen(originalFileName, "r");
	if(fpOriginal){
		
		accum = 0;
	    sprintf(resoultFileName, "%s_%d.tmp", originalFileName, i);
	    fpResoult = fopen(resoultFileName, "w");
	    if(fpResoult){
	    	while(accum<=sizeFile && accum <= setSize){
	    		for(j = 0; j < MAX_LINE_LENGTH; j++) {
       				fread(*&buffer+j, 1, 1, fpOriginal);
	       			for(j = 0; j < MAX_LINE_LENGTH;j++){  	
	    				fprintf(fpResoult,"%c",buffer[j]);
					}
    			}
    			accum+=MAX_LINE_LENGTH;
			}
	        fclose(fpResoult);
	        i++;
	        sprintf(remainderFileName, "%s_%d.tmp", originalFileName, i);
	        fpRemainder =   fopen(remainderFileName, "w");
			if(fpRemainder){
				
				while(accum<=sizeFile){
		    		for(j = 0; j < MAX_LINE_LENGTH; j++) {
	       				fread(*&buffer+j, 1, 1, fpOriginal);
		       			for(j = 0; j < MAX_LINE_LENGTH;j++){  	
		    				fprintf(fpRemainder,"%c",buffer[j]);
						}
    				}
				accum+=MAX_LINE_LENGTH;
				}
			}	
			else{
			perror("Error while opening the file.\n");
	    	exit(EXIT_FAILURE);
		}
	        
	        
		}
		else{
			perror("Error while opening the file.\n");
	    	exit(EXIT_FAILURE);
		}
	}
	else{
		perror("Error while opening the file.\n");
    	exit(EXIT_FAILURE);
	}
	
    remove(originalFileName);
    return 0;
}



