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
    for(uint32_t i = 0; i < FIFO_SIZE; i++){
        fifo->array[i].value = 0;
        fifo->array[i].priority = 0;
    }

    // Values:   0 0 0 0 0 0 0 0 0 0
    // Priority: 0 0 0 0 0 0 0 0 0 0
}

void myFIFOInsert(struct MYFIFO *fifo, uint32_t val, uint32_t priority){

    if (fifo->cnt == FIFO_SIZE){
        printf("FIFO Full! Removed oldest value: %d \n",myFIFORemove(fifo));
    }

    /*Insertion when the FIFO is empty*/
    if(fifo->cnt == 0){
        fifo->array[0].value = val;
        fifo->array[0].priority = priority;
        fifo->cnt++;
        return;
    }


    for(uint32_t i = 0; i < fifo->cnt; i++){
        if(priority > fifo->array[i].priority){
            
            /*Shift values to right*/
            for(uint32_t j = fifo->cnt; j > i; j--){
                fifo->array[j].value = fifo->array[j-1].value;
                fifo->array[j].priority = fifo->array[j-1].priority;
            }         
            fifo->array[i].value = val;
            fifo->array[i].priority = priority;
            fifo->cnt++;
            return;
        }
    }

    /*Insertion at the end of FIFO*/
    if(priority == fifo->array[fifo->cnt-1].priority){
        fifo->array[fifo->cnt].value = val;
        fifo->array[fifo->cnt].priority = priority;
        fifo->cnt++;
        return;
    }
}

uint32_t myFIFORemove(struct MYFIFO *fifo) {
    if (fifo->cnt == 0){
        printf("Empty FIFO! \n");
        return 9999;
    }

    uint32_t rval = fifo->array[0].value;

    /*Remove value and shift values to left*/
    for(uint32_t i = 0; i < fifo->cnt; i++){
        fifo->array[i].value = fifo->array[i+1].value;
        fifo->array[i].priority = fifo->array[i+1].priority;
    }
    fifo->cnt--;
    
    return rval;
}

uint32_t myFIFOPeep(struct MYFIFO *fifo){
    return fifo->array[0].value;
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
    printf("FIFO Priority: ");
    for(uint32_t i = 0; i < fifo->cnt; i++){
        printf("%4d ",fifo->array[i].priority);
    }
    printf("\n");
    printf("\n");
}
