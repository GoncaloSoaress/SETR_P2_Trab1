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
        myFIFORemove(fifo);
    }
    fifo->array[fifo->in_p].value = val;
    fifo->in_p = (fifo->in_p + 1) % FIFO_SIZE;
    fifo->cnt++;
}

uint32_t myFIFORemove(struct MYFIFO *fifo) {
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
