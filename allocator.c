#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    "allocator.h"

#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define CYAN        "\x1b[36m"
#define NORMALIZE   "\x1b[0m"

/* 8KB Heap Space */
#define BLOCKSIZE   8192

static char block[BLOCKSIZE];


/*
    Checks the global block structure for a recognition pattern.
    If the pattern matches, the stucture is valid.  Else, it is corrupt.
*/
int validityCheck()
{
    struct memEntry *root;
    struct memEntry *temp;

    root = (struct memEntry *) block;
    for(temp = root; temp != NULL; temp = temp->next){
        if(temp->recognPattern != 13371337){
            return 1;
        }
    }
    return 0;
}

/*
    Returns a pointer to a successfully allocated block of memory.
*/
void* mymalloc(int size, char *file, int line)
{
    static struct memEntry *root;
    static int initialzied      = 0;
    struct memEntry *temp       = 0;
    struct memEntry *newUnit    = 0;
    struct memEntry *target     = 0;

    int extraSpace = BLOCKSIZE;

    if(!initialzied){
        root                    = (struct memEntry*) block;
        root->prev              = root->next = 0;
        root->size              = BLOCKSIZE - sizeof(struct memEntry);
        root->isfree            = 1;
        root->recognPattern     = 13371337;       
        root->linenum           = line;
        root->file              = file;
        initialzied = 1;
    }

    if(validityCheck()){
        printf(RED "(line %d, %s) Error:  Internal structure failure.\n" NORMALIZE, line, file);
        return NULL;
    }
    if(size <= 0){
        printf(RED "(line %d, %s) Error:  Allocation request is not of a valid size.  Must be a positive integer.\n" NORMALIZE, line, file);
        return NULL;
    }
    if(size > BLOCKSIZE){
        printf(RED "(line %d, %s) Error:  Allocation request is larger than virtual heap structure.\n" NORMALIZE, line, file);
        return NULL;
    }


    temp = root;

    do{
        /* Request size is too big for this unit. */
        if(temp->size < size){
            temp = temp->next;
        }
        /* Skip unit if it is unavailable. */
        else if(!temp->isfree){
            temp = temp->next;
        }
        /*  */
        else if(temp->size - size < extraSpace){
            extraSpace  = temp->size - size;
            target      = temp;
            temp        = temp->next;
        }
        /*  */
        else{
            temp = temp->next;
        }

    }while(temp != NULL);


    if(target == NULL){
        printf(RED "(line %d, %s) Error:  Not enough available memory in the virtual heap structure for the request.\n" NORMALIZE, line, file);
        return NULL;
    }

    temp = target;

    /* Can the request fit into the memory unit? */
    if(temp->size < (size + sizeof(struct memEntry))){
        temp->isfree    = 0;
        temp->linenum   = line;
        temp->file      = file;
        return (char *)temp + sizeof(struct memEntry);
    }
    /*  */
    else{
        newUnit = (struct memEntry*)((char *)temp + sizeof(struct memEntry) + size);
        newUnit->recognPattern = 13371337;
        newUnit->prev          = temp;
        newUnit->next          = temp->next;
        if(temp->next != NULL)
            temp->next->prev = newUnit;
        temp->next             = newUnit;
        newUnit->size          = temp->size - sizeof(struct memEntry) - size;
        newUnit->isfree        = 1;
        temp->size             = size;
        temp->isfree           = 0;
        temp->file             = file;
        temp->linenum          = line;
        printf(GREEN "(line %d, %s) Successful malloc call. \n" NORMALIZE, line, file);
        return (char*)temp + sizeof(struct memEntry);
    }

    //printf(RED "Error (line %d, %s):  Not enough available memory in the virtual heap structure for the request.\n" NORMALIZE, line, file);
    //return NULL;
}

void myfree(void *ptr, char *file, unsigned int line)
{

    if(ptr == NULL){
        printf(RED "(line %d, %s) Error:  Null pointer attempting to be freed.\n" NORMALIZE, line, file);
        return;
    }
    struct memEntry *curr, *prev, *next;

    if(((char*)ptr-sizeof(struct memEntry)) < (char*)block || 
    ((char*)ptr-sizeof(struct memEntry)) > (char*)block + BLOCKSIZE ){

        printf(RED "(line %d, %s) Error:  Invalid free() call.\n" NORMALIZE, line, file);
        return;
    }


    curr = (memEntry *)((char*)ptr - sizeof(memEntry));
    if(curr->recognPattern != 13371337){
        printf(RED "(line %d, %s) Error:  Invalid free() call.  This pointer was not allocated by mymalloc().\n" NORMALIZE, line, file);
        return;
    }
    else if(curr->isfree){
        printf(RED "(line %d, %s) Error:  Attempting to free unassigned memory units.\n" NORMALIZE, line, file);
        return;
    }

    prev = curr->prev;
    next = curr->next;

    if(prev != NULL && prev->isfree){
        prev->size += sizeof(memEntry) + curr->size;
        prev->next = curr->next;
        if(curr->next != NULL)
            curr->next->prev = prev;
    }
    else{
        curr->isfree    = 1;
        prev            = curr;
    }

    if(next != NULL && next->isfree){
        prev->size += sizeof(memEntry) + next->size;
        prev->next = next->next;
        if(next->next != NULL)
            next->next->prev = prev;
    }

    printf(CYAN "(line %d, %s) Successful free. \n" NORMALIZE, line, file);
}




























