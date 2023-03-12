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
#include "libs/fifo.h"


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
	
    printf("---FIFO TEST---\nInitializing FIFO.\n");
    myFIFOInit(&fifo);
	
    printf("Adding 10 values to FIFO.\n");
    for (int i=0;i<10;i++){
		myFIFOInsert(&fifo,i,i);
	}
    myFIFOPrint(&fifo);

    printf("Peep inside the FIFO.\n");
    uint32_t oldest_val = myFIFOPeep (&fifo);
	printf("Oldest Value = %d\n",oldest_val);
    myFIFOPrint(&fifo);

    printf("Adding the value 99, with priority 99 to the FIFO while Full.\n");
    uint32_t add_value = 99;
    myFIFOInsert(&fifo,add_value,99);
    printf("Added Value = %d\n",add_value);
    myFIFOPrint(&fifo);

    printf("Remove a value.\n");
	uint32_t removed_val = myFIFORemove(&fifo);
	printf("Removed Value = %d\n",removed_val);
    myFIFOPrint(&fifo);

    printf("Adding the value 100, with priority 2 to the FIFO.\n");
    add_value = 100;
    myFIFOInsert(&fifo,add_value,2);
    printf("Added Value = %d\n", add_value);
    myFIFOPrint(&fifo);

    printf("Print Size.\n");
	uint32_t size = myFIFOSize(&fifo);
	printf("Size = %d\n",size);

    printf("Adding the value 0, with priority 0 to the FIFO.\n");
    add_value = 0;
    myFIFOInsert(&fifo,add_value,0);
    printf("Added Value = %d\n",add_value);
    myFIFOPrint(&fifo);

    printf("Remove all values, even when the FIFO goes empty.\n");
    for (int i=0; i<11;i++){
        uint32_t rmVal = myFIFORemove(&fifo);
        printf("Removed Value = %d\n",rmVal);
    }

    myFIFOPrint(&fifo);

	return 0;
}