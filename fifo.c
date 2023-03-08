#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fifo.h"

void myFIFOInsert(struct MYFIFO *fifo, uint32_t val){
    if (fifo->cnt == FIFO_SIZE){
        myFIFORemove(fifo);
    }
    fifo->array[fifo->in_p].value = val;
    fifo->in_p = (fifo->in_p + 1) % FIFO_SIZE;
    fifo->cnt++;
}

uint32_t myFIFOPeep(struct MYFIFO *fifo){
    return fifo->array[fifo->out_p].value;
}
