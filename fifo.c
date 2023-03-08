#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fifo.h"

void myFIFOInit(struct MYFIFO *fifo) {
    fifo->cnt = 0;
    fifo->in_p = 0;
    fifo->out_p = 0;
}

uint32_t myFIFORemove(struct MYFIFO *fifo) {
    uint32_t rval = fifo->array[fifo->out_p].value;
    fifo->out_p = (fifo->out_p + 1) % FIFO_SIZE;
    fifo->cnt--;
    return rval;
}

uint32_t myFIFOSize(struct MYFIFO *fifo) {
    return fifo->cnt;
}