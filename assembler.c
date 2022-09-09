/**
 * Project 1 
 * Assembler code fragment for LC-2K 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define MAXLINELENGTH 1000

int readAndParse(FILE *, char *, char *, char *, char *, char *);
int isNumber(char *);

int
main(int argc, char *argv[])
{
    char *inFileString, *outFileString;
    FILE *inFilePtr, *outFilePtr;
    char label[MAXLINELENGTH], opcode[MAXLINELENGTH], arg0[MAXLINELENGTH],
            arg1[MAXLINELENGTH], arg2[MAXLINELENGTH];

    if (argc != 3) {
        printf("error: usage: %s <assembly-code-file> <machine-code-file>\n",
            argv[0]);
        exit(1);
    }

    inFileString = argv[1];
    outFileString = argv[2];

    inFilePtr = fopen(inFileString, "r");
    if (inFilePtr == NULL) {
        printf("error in opening %s\n", inFileString);
        exit(1);
    }
    outFilePtr = fopen(outFileString, "w");
    if (outFilePtr == NULL) {
        printf("error in opening %s\n", outFileString);
        exit(1);
    }

    /* here is an example for how to use readAndParse to read a line from
        inFilePtr */
    if (! readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2) ) {
        printf("hello");
        /* reached end of file */
    }


    /* this is how to rewind the file ptr so that you start reading from the
        beginning of the file */
    rewind(inFilePtr);
    
    /* after doing a readAndParse, you may want to do the following to test the
        opcode */
    if (!strcmp(opcode, "add")) {
        /* do whatever you need to do for opcode "add" */
    }
    
    int numlines = 0;
    
    while (readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2)){
        numlines++;
    }
    rewind(inFilePtr);
    //***********************************************************
    char strs[numlines][7];
    int count = 0;
    //************************************************************
    
    while (readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2)){
        
        //undefined label
        if (strlen(label) > 8){
            printf("undefined label");
            exit(1);
        }
        
        //duplicate labels
       
        
        if (strcmp(label,"")){
            for (int i = 0; i < count; i++){
                if (!strcmp(label,strs[i])){
                    printf("duplicated label");
                    exit(1);
                }
                
            }
            strcpy(strs[count],label);
            
        }
        
        
        
        
        count++;
    }
    
    
    rewind(inFilePtr);
    
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    int sixth;
    int seventh;
    int eighth;
    int sum;
    
    int tick = 0;
    while (readAndParse(inFilePtr, label, opcode, arg0, arg1, arg2)){
        first = 0;
        second = 0;
        third = 0;
        fourth = 0;
        fifth = 0;
        sixth = 0;
        seventh = 0;
        eighth = 0;
        sum = 0;
        
        int temp0 = atoi(arg0);
        int temp1 = atoi(arg1);
        int temp2 = atoi(arg2);
        
        
        if (!strcmp(opcode, "add")) {
            /* do whatever you need to do for opcode "add" */
            
            
            //ARG 0
            if (temp0 % 2 != 0){
                fourth += 8;
            }//if
            if (temp0 == 7 || temp0 == 6){
                third += 3;
            }
            if (temp0 ==5 || temp0 == 4){
                third += 2;
            }
            
            if (temp0 ==3 || temp0 == 2){
                third += 1;
            }
            if (temp0 == 1){
                
            }
            //ARG 0
            //*******************
            //ARG 1
            fourth += temp1;
            //ARG 1
            //*******
            //Arg 2
            eighth += temp2;
            //Arg 2
            
        }
        
        else if (!strcmp(opcode, "nor")) {
            third += 4;
            
            //ARG 0
            if (temp0 % 2 != 0){
                fourth += 8;
            }//if
            if (temp0 == 7 || temp0 == 6){
                third += 3;
            }
            if (temp0 ==5 || temp0 == 4){
                third += 2;
            }
            
            if (temp0 ==3 || temp0 == 2){
                third += 1;
            }
            if (temp0 == 1){
                
            }
            //ARG 0
            //*******************
            //ARG 1
            fourth += temp1;
            //ARG 1
            //*******
            //Arg 2
            eighth += temp2;
            //Arg 2
            
        }
        
        else if (!strcmp(opcode, "lw")) {
            third += 8;
            
            //ARG 0
            if (temp0 % 2 != 0){
                fourth += 8;
            }//if
            if (temp0 == 7 || temp0 == 6){
                third += 3;
            }
            if (temp0 ==5 || temp0 == 4){
                third += 2;
            }
            
            if (temp0 ==3 || temp0 == 2){
                third += 1;
            }
            if (temp0 == 1){
                
            }
            //ARG 0
            //*******************
            //ARG 1
            fourth += temp1;
            //ARG 1
            
            //ARG2
            if(isalpha(arg2[0])&& !isupper(arg2[0])){
                bool found = false;
                for (int i = 0; i < count; i++){
                    if (!strcmp(strs[i],arg2)){
                        found = true;
                    }
                }
                if (found == false){
                    exit(1);
                }
            }
            
            
            if (strcmp(arg2,"")){
                for (int i = 0; i < count; i++){
                    if (!strcmp(arg2,strs[i])){
                        sum += i;
                    }
                    
                }
            }//if
            if (sum == 0){
                
                if (temp2 > 32767 || temp2 < -32768){
                    printf("invalid offset");
                    exit(1);
                }
                
                
                if (temp2 > 0){
                    sum += temp2;
                }
                else if (temp2 < 0){
                    temp2 = 65536 + temp2;
                    sum += temp2;
                }
            }
            
            //ARG 2
            
        }
        else if (!strcmp(opcode, "sw")) {
            third += 12;
            
            //ARG 0
            if (temp0 % 2 != 0){
                fourth += 8;
            }//if
            if (temp0 == 7 || temp0 == 6){
                third += 3;
            }
            if (temp0 ==5 || temp0 == 4){
                third += 2;
            }
            
            if (temp0 ==3 || temp0 == 2){
                third += 1;
            }
            if (temp0 == 1){
                
            }
            //ARG 0
            //*******************
            //ARG 1
            fourth += temp1;
            //ARG 2
            
            if(isalpha(arg2[0]) && !isupper(arg2[0])){
                bool found = false;
                for (int i = 0; i < count; i++){
                    if (!strcmp(strs[i],arg2)){
                        found = true;
                    }
                }
                if (found == false){
                    exit(1);
                }
            }
            
            if (strcmp(arg2,"")){
                for (int i = 0; i < count; i++){
                    if (!strcmp(arg2,strs[i])){
                        sum += i;
                    }
                    
                }
            }//if
            if (sum == 0){
                if (temp2 > 32767 || temp2 < -32768){
                    printf("invalid offset");
                    exit (1);
                }
                
                if (temp2 > 0){
                    sum += temp2;
                }
                else if (temp2 < 0){
                    temp2 = 65536 + temp2;
                    sum += temp2;
                }
            }
            
            
        }
        
        else if (!strcmp(opcode, "beq")) {
            second += 1;
            
            //ARG 0
            if (temp0 % 2 != 0){
                fourth += 8;
            }//if
            if (temp0 == 7 || temp0 == 6){
                third += 3;
            }
            if (temp0 ==5 || temp0 == 4){
                third += 2;
            }
            
            if (temp0 ==3 || temp0 == 2){
                third += 1;
            }
            if (temp0 == 1){
                
            }
            //ARG 0
            //*******************
            //ARG 1
            fourth += temp1;
            //ARG 2
            
            
            if(isalpha(arg2[0])){
                bool found = false;
                for (int i = 0; i < count; i++){
                    if (!strcmp(strs[i],arg2)){
                        found = true;
                    }
                }
                if (found == false){
                    exit(1);
                }
            }
            
            
            
            
            if (strcmp(arg2,"")){
                for (int i = 0; i < count; i++){
                    if (!strcmp(arg2,strs[i])){
                        int x = i - (tick + 1);
                        
                        if (x < 0){
                            x = 65536 + x;
                        }
                        sum += x;
                        
                    }
                    
                }
            }
            //if
            if (sum == 0){
                if (temp2 > 32767 || temp2 < -32768){
                    printf("invalid offset");
                    exit(1);
                }
                
                if (temp2 > 0){
                    sum += temp2;
                }
                else if (temp2 < 0){
                    temp2 = 65536 + temp2;
                    sum += temp2;
                }
            }
            
            
            
        }
        else if (!strcmp(opcode, "jalr")) {
            second += 1;
            third += 4;
            
            //ARG 0
            if (temp0 % 2 != 0){
                fourth += 8;
            }//if
            if (temp0 == 7 || temp0 == 6){
                third += 3;
            }
            if (temp0 ==5 || temp0 == 4){
                third += 2;
            }
            
            if (temp0 ==3 || temp0 == 2){
                third += 1;
            }
            if (temp0 == 1){
                
            }
            //ARG 0
            //*******************
            //ARG 1
            fourth += temp1;
            //ARG 1
            //*******
            
            
        }
        else if (!strcmp(opcode, "halt")) {
            second += 1;
            third += 8;
        }
        else if (!strcmp(opcode, "noop")) {
            second += 1;
            third += 12;
        }
        else if (!strcmp(opcode, ".fill")) {
            for (int i = 0; i < count; i++){
                if (!strcmp(arg0,strs[i])){
                    sum += i;
                }
            }
            
            if (sum == 0){
                
                if (temp0 > 2147483647 || temp0 < -2147483648){
                    printf("invalid offset");
                    exit(1);
                }
                
                
                if (temp0 > 0){
                    sum += temp0;
                }
                else if (temp0 < 0){
                    sum += temp0;
                }
            }
            
        }
        //unrecognized opcode
        else {
            if (strcmp(opcode,"")){
                printf("unrecognized opcode");
                exit(1);
            }
        }
        
        
        
        
        tick++;
        
        sum += (eighth);
        sum += (seventh * (16));
        sum += (sixth * (16 * 16));
        sum += (fifth * (16 * 16 * 16));
        sum += (fourth * (16 * 16 * 16 * 16));
        sum += (third * (16 * 16 * 16 * 16 * 16));
        sum += (second * (16 * 16 * 16 * 16 * 16 * 16));
        sum += first;
        
         if (strcmp(opcode,"")){
        fprintf(outFilePtr, "%d", sum);
        fprintf(outFilePtr, "\n");
         }
    }
    
    
    
    
    
    //printf("end");
    return(0);
}

/*
 * Read and parse a line of the assembly-language file.  Fields are returned
 * in label, opcode, arg0, arg1, arg2 (these strings must have memory already
 * allocated to them).
 *
 * Return values:
 *     0 if reached end of file
 *     1 if successfully read
 *
 * exit(1) if line is too long.
 */
int
readAndParse(FILE *inFilePtr, char *label, char *opcode, char *arg0,
        char *arg1, char *arg2)
{
    
    char line[MAXLINELENGTH];

    /* delete prior values */
    label[0] = opcode[0] = arg0[0] = arg1[0] = arg2[0] = '\0';

    /* read the line from the assembly-language file */
    if (fgets(line, MAXLINELENGTH, inFilePtr) == NULL) {
        /* reached end of file */
        return(0);
    }

    /* check for line too long (by looking for a \n) */
    if (strchr(line, '\n') == NULL) {
        /* line too long */
        printf("error: line too long\n");
        exit(1);
    }

    /* is there a label? */
    char *ptr = line;
    if (sscanf(ptr, "%[^\t\n\r ]", label)) {
        /* successfully read label; advance pointer over the label */
        ptr += strlen(label);
    }

    /*
     * Parse the rest of the line.  Would be nice to have real regular
     * expressions, but scanf will suffice.
     */
    sscanf(ptr, "%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]%*[\t\n\r ]%[^\t\n\r ]",
        opcode, arg0, arg1, arg2);
    return(1);
}

int
isNumber(char *string)
{
    /* return 1 if string is a number */
    int i;
    return( (sscanf(string, "%d", &i)) == 1);
}


