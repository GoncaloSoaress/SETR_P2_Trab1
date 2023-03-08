/** @file fifo.h
 * @brief Definition of the struct data and the function prototype
 *  
 * Contains two data structures: one containing the necessary variables
 * for creating a FIFO and another containing the content of each position
 * from FIFO. It also contains 5 functions: myFIFOInit(), myFIFOInsert(),
 * myFIFORemove(), myFIFOPeep() and myFIFOSize().
 * 
 * @author Gonçalo Soares & Gonçalo Rodrigues
 * @date 7 March 2023
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FIFO_SIZE 10

/**
 * @brief This struture contains the value to store in FIFO position 
 *
 */ 
struct CONTENT {
    uint32_t value; /**< Value of the FIFO position */
};

struct MYFIFO {
    uint32_t cnt;
    uint32_t in_p;
    uint32_t out_p;
    CONTENT array[FIFO_SIZE];
};

void myFIFOInit(struct MYFIFO *fifo);

/**
 * @brief This function adds a value in FIFO structure.
 * 
 * @param fifo Pointer to the FIFO struture.
 * @param val Value to insert in the FIFO position
 */
void myFIFOInsert(struct MYFIFO *fifo, uint32_t val);
void myFIFORemove(struct MYFIFO *fifo);

/**
 * @brief This function returns the oldest element from the FIFO structure, but does not
 * remove it
 * 
 * @param fifo Pointer to the FIFO struture.
 * @return The value of the oldest element in the FIFO structure. (uint32_t)
 */
uint32_t myFIFOPeep(struct MYFIFO *fifo);
uint32_t myFIFOSize(struct MYFIFO *fifo);