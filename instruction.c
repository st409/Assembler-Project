#include "instruction.h"

instructionsTable* createinstructions(char code[WORD_LEN])
{
    instructionsTable* instructions = malloc(sizeof(instructionsTable));
    if (!instructions) /*No space found in memory*/
    {
        return NULL;
    }
    strcpy(instructions->instructionsCode, code);
    instructions->nextInstructions = NULL;  
    return instructions;
}

void addInstructions(instructionsTable** instructionstbl, char code[WORD_LEN])
{
    instructionsTable* instructions = createinstructions(code);


    if (*instructionstbl != NULL)
    {
        instructionsTable* current = *instructionstbl;
        while (current->nextInstructions != NULL)
        {
            current = current->nextInstructions;
        }
        current->nextInstructions = instructions;
    }
    else
    {
        *instructionstbl = instructions;
    }
}

void freeInstructionsTable(instructionsTable* instructionstbl)
{
    free(instructionstbl);
}


int num_of_cells(instructionsTable* head)
{
    int i = 0;
    instructionsTable* temp = head;
    while (temp != NULL)
    {
        i++;
        temp = temp->nextInstructions;
    }
    return i;

}

void setInstructions(instructionsTable* head, char code[WORD_LEN], int back)
{

    int i = 0;
    instructionsTable* temp = head;
    while (i < back)
    {
        i++;
        temp = temp->nextInstructions;
    }
    strcpy(temp->instructionsCode, code);
}


void printlist_instructions(instructionsTable* head)
{

    instructionsTable* temp = head;
    printf("*********************this is printlist_instructions********************\n\n");
    while (temp != NULL)
    {
        printf("CODE IS : %s\n", temp->instructionsCode);
        temp = temp->nextInstructions;
    }
    printf("\n\n\n");
}



