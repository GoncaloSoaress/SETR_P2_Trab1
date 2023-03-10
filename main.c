/** @file main.c
 * @brief Test aplication for FIFO
 *
 * Test aplication that use all functions and data structures created in fifo.h.
 * 
 * @author Gonçalo Soares & Gonçalo Rodrigues
 * @date 10 March 2022
 * @bug No known bugs.
 */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fifo.h"


/**
 * @brief Test aplication for FIFO
 *
 * It create and initialize a fifo (myFIFOInit), insert four values in FIFO (myFIFOInsert) 
 * and remove the oldest value (myFIFORemove).
 * It then prints the oldest value and the atual size from FIFO.
 * 
 * @return main() always returns 0
 */
int main(void){
	struct MYFIFO fifo;
	
    myFIFOInit(&fifo);
	
    for (int i=0;i<10;i++){
		myFIFOInsert(&fifo,i);
	}
    // FIFO values: 0 1 2 3 4 5 6 7 8 9  


    uint32_t oldest_val = myFIFOPeep (&fifo);
	printf("Oldest Value = %d\n",oldest_val);
    // FIFO Values: 0 1 2 3 4 5 6 7 8 9 
    // Oldest Value: 0

    uint32_t add_value = 99;
    myFIFOInsert(&fifo,add_value);
    printf("Added Value = %d\n",add_value);
    // FIFO values: 99 1 2 3 4 5 6 7 8 9 

	uint32_t removed_val = myFIFORemove(&fifo);
	printf("Removed Value = %d\n",removed_val);
    // FIFO values: 99 _ 2 3 4 5 6 7 8 9 

	uint32_t size = myFIFOSize(&fifo);
	printf("Size = %d\n",size);
    // FIFO values: 99 _ 2 3 4 5 6 7 8 9 
    // Size: 9

    for (int i=0; i<11;i++){
        uint32_t flag = myFIFORemove(&fifo);
    }

	return 0;
}