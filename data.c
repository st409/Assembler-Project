#include "data.h"

dataTable* createdata(char code[WORD_LEN])
{
    dataTable* data = malloc(sizeof(dataTable));/*Allocate memory space for a new label*/
    if (!data) /*No space found in memory*/
    {
        return NULL;
    }
    strcpy(data->dataCode, code);
    data->nextData = NULL;
    return data;
}

void addData(dataTable** datatbl, char code[WORD_LEN])
{
    dataTable* data = createdata(code);


    if (*datatbl != NULL)
    {
        dataTable* current = *datatbl;
        while (current->nextData != NULL)
        {
            current = current->nextData;
        }
        current->nextData = data;
    }
    else
    {
        *datatbl = data;
    }
}

void freeDataTable(dataTable* datatbl)
{

    free(datatbl);
}

void printlist_data(dataTable* head)
{

    dataTable* temp = head;
    printf("*********************this is printlist_data********************\n\n");
    while (temp != NULL)
    {
        printf("CODE IS : %s\n", temp->dataCode);
        temp = temp->nextData;
    }
    printf("\n\n\n");
}
