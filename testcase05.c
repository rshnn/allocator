#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

int main (){

    /*
        TESTCASE 05
        Attemping to deallocate memory not allocated by mymalloc().
    */
    printf("TESTCASE 05:\tInvalid pointer input into free().\n");
    char *p1 = (char*)malloc(100);
    strcpy(p1, "These are not the droids you're looking for.");
    free(p1+50);
    free(p1);
    printf("\n");                
 
	return 0;
}
