#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FIFO_SIZE 10

struct CONTENT {
    uint32_t value;
};

struct MYFIFO {
    uint32_t cnt;
    uint32_t in_p;
    uint32_t out_p;
    CONTENT array[FIFO_SIZE];
};

void myFIFOInit(struct MYFIFO *fifo);
void myFIFOInsert(struct MYFIFO *fifo, uint32_t val);
void myFIFORemove(struct MYFIFO *fifo);
uint32_t myFIFOPeep(struct MYFIFO *fifo);
uint32_t myFIFOSize(struct MYFIFO *fifo);