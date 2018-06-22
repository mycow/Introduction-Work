#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "set.h"

struct set
{
        int count;
        int length;
        char **data;
};

SET *createSet(int maxElts)
{
        SET *sp;
        sp=(SET*)malloc(sizeof(SET));
        assert(sp!=NULL);
        sp->count=0;
        sp->length=maxElts;
        sp->data=(char**)malloc(maxElts*sizeof(char*));
        assert(sp->data!=NULL);

        return sp;
}

void destroySet(SET *sp)
{
        assert(sp!=NULL);
        int i;
        for(i=0; i<sp->count; i++)
                free(sp->data[i]);
        free(sp->data);
        free(sp);
}

int numElements(SET *sp)
{
        return sp->count;
}

bool hasElements(SET *sp, char *elt)
{
        int i;
        for(i=0; i<sp->count; i++)
        {
                if((strcmp(sp->data[i], elt))==0)
                        return true;
        }

        return false;
}

int findElement(SET *sp, char *elt)
{
        int i;
        for(i=0; i<sp->count; i++)
        {
                if((strcmp(sp->data[i], elt))==0)
                        return i;
        }

        return -1;
}

bool addElement(SET *sp, char *elt)
{
        assert(sp->count<sp->length);
        if(findElement(sp, elt)!=-1)
                return false;
        sp->data[sp->count]=strdup(elt);
        sp->count++;
        return true;
}

bool removeElement(SET *sp, char *elt)
{
        if((findElement(sp, elt))!=-1)
                return false;
        int z=findElement(sp, elt);
        strcpy(sp->data[z], sp->data[sp->count]);
        sp->count--;
        return true;
}
