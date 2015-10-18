#ifndef MYMALLOC_H
#define MYMALLOC_H

#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )

typedef struct memEntry{
    struct memEntry *prev, *next;
    int 	size;
    int 	isfree;
    int 	recognPattern;
    int 	linenum;
    char 	*file;



    int lineno;
}memEntry;

void* mymalloc(unsigned int, char* file, int line);
void myfree(void*, char* file, unsigned int line);

#endif
