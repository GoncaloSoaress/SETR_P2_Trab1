/** @file main.c
 * @brief Test aplication for FIFO
 *
 * Test aplication that use all functions and data structures created in fifo.h.
 * 
 * @author Gonçalo Soares & Gonçalo Rodrigues
 * @date 12 March 2022
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
 * The main code uses and tests all the functions developed for the fifo.h module 
 * in order to be able to guarantee a good functioning of the module. 
 * These include initializing the FIFO (myFIFOInit), inserting values (myFIFOInsert), 
 * removing values (myFIFORemove), printing the next value to be removed (myFIFOPeep) 
 * and printing its contents (myFIFOPrint).   
 * 
 * @return main() always returns 0
 */
int main(void){
	struct MYFIFO fifo;
	
    /* Initializing the FIFO*/
    printf("---FIFO TEST---\nInitializing FIFO.\n");
    myFIFOInit(&fifo);
	
    /*Adding 10 Values*/
    printf("Adding 10 values to FIFO.\n");
    for (int i=0;i<10;i++){
		myFIFOInsert(&fifo,i,i);
	}
    myFIFOPrint(&fifo);

    /*Printing the next value to remove*/
    printf("Peep inside the FIFO.\n");
    uint32_t oldest_val = myFIFOPeep (&fifo);
	printf("Oldest Value = %d\n",oldest_val);
    myFIFOPrint(&fifo);

    /*Adding Value*/
    printf("Adding the value 99, with priority 99 to the FIFO while Full.\n");
    uint32_t add_value = 99;
    myFIFOInsert(&fifo,add_value,99);
    printf("Added Value = %d\n",add_value);
    myFIFOPrint(&fifo);

    /*Removing Value*/
    printf("Remove a value.\n");
	uint32_t removed_val = myFIFORemove(&fifo);
	printf("Removed Value = %d\n",removed_val);
    myFIFOPrint(&fifo);

    /*Adding Value*/
    printf("Adding the value 100, with priority 2 to the FIFO.\n");
    add_value = 100;
    myFIFOInsert(&fifo,add_value,2);
    printf("Added Value = %d\n", add_value);
    myFIFOPrint(&fifo);

    /*Printing the Size*/
    printf("Print Size.\n");
	uint32_t size = myFIFOSize(&fifo);
	printf("Size = %d\n",size);

    /*Adding Value*/
    printf("Adding the value 0, with priority 0 to the FIFO.\n");
    add_value = 0;
    myFIFOInsert(&fifo,add_value,0);
    printf("Added Value = %d\n",add_value);
    myFIFOPrint(&fifo);

    /*Remove all Values*/
    printf("Remove all values, even when the FIFO goes empty.\n");
    for (int i=0; i<11;i++){
        uint32_t rmVal = myFIFORemove(&fifo);
        printf("Removed Value = %d\n",rmVal);
    }

    /*Print the content*/
    myFIFOPrint(&fifo);

	return 0;
}