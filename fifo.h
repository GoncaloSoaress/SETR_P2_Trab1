#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef FIFO_H
#define FIFO_H

#define FIFO_SIZE 10

struct CONTENT {
    uint32_t value;
};


/**
 * @brief This structure contains all the variables needed to implement a FIFO structure.
 */
struct MYFIFO {
    uint32_t cnt;                   /**<Number of elements in the FIFO structure.*/
    uint32_t in_p;                  /**<Pointer to the next position to insert an element in the FIFO structure.*/
    uint32_t out_p;                 /**<Pointer to the next position to remove an element from the FIFO structure.*/
    CONTENT array[FIFO_SIZE];       /**<Array of elements in the FIFO structure of size FIFO_SIZE. This array itself is a structure of the CONTENT type.*/
};

/**
 * @brief This function initializes the FIFO structure, setting all the variables to 0.
 * 
 * @param fifo Pointer to the FIFO structure to be initialized.
 */
void myFIFOInit(struct MYFIFO *fifo);


void myFIFOInsert(struct MYFIFO *fifo, uint32_t val);

/**
 * @brief This function removes the oldest element from the FIFO structure.
 * 
 * @param fifo Pointer to the FIFO structure.
 * @return The value of the oldest element in the FIFO structure. (uint32_t)
 */
uint32_t myFIFORemove(struct MYFIFO *fifo);


uint32_t myFIFOPeep(struct MYFIFO *fifo);

/**
 * @brief This function returns the number of elements in the FIFO structure.
 * 
 * @param fifo Pointer to the FIFO structure.
 * @return The number of elements in the FIFO structure. (uint32_t)
 */
uint32_t myFIFOSize(struct MYFIFO *fifo);

#endif