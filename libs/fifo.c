/** @file fifo.c
 * @brief Implementation of all FIFO functions
 *  
 * Contains the implementation of all functions declared in fifo.h
 * 
 * @author Gonçalo Soares & Gonçalo Rodrigues
 * @date 14 March 2023
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fifo.h"

void myFIFOInit(struct MYFIFO *fifo) {
    fifo->cnt = 0;
    fifo->in_p = 0;
    fifo->out_p = 0;
}

void myFIFOInsert(struct MYFIFO *fifo, uint32_t val){
    if (fifo->cnt == FIFO_SIZE){
        printf("FIFO Full! Removed oldest value: %d \n",myFIFORemove(fifo));
    }
    fifo->array[fifo->in_p].value = val;
    fifo->in_p = (fifo->in_p + 1) % FIFO_SIZE;
    fifo->cnt++;
}

uint32_t myFIFORemove(struct MYFIFO *fifo) {
    if (fifo->cnt == 0){
        printf("Empty FIFO! \n");
        return 9999;
    }
    
    uint32_t rval = fifo->array[fifo->out_p].value;
    fifo->out_p = (fifo->out_p + 1) % FIFO_SIZE;
    fifo->cnt--;
    return rval;
}

uint32_t myFIFOPeep(struct MYFIFO *fifo){
    return fifo->array[fifo->out_p].value;
}

uint32_t myFIFOSize(struct MYFIFO *fifo) {
    return fifo->cnt;
}

void myFIFOPrint(struct MYFIFO *fifo){
    printf("\n");
    printf("FIFO Values:   ");
    for(uint32_t i = 0; i < fifo->cnt; i++){
        printf("%4d ",fifo->array[i].value);
    }
    printf("\n");
    printf("\n");
}