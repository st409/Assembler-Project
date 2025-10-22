#include "label_manager.h"

labelTable* createLabel(char* name, unsigned int address, int lblType)
{
    labelTable* label = malloc(sizeof(labelTable));/*Allocate memory space for a new label*/
    if (!label) /*No space found in memory*/
    {
        return NULL;
    }

    label->labelName = (char*)malloc(strlen(name) + 1);
    if (label->labelName == NULL)
    {
        printf("no allocation");
        exit(0);
    }
    strcpy(label->labelName, name);
    label->labelAddress = address;
    label->labelType = lblType;
    label->externLabel = start;
    label->nextLabel = NULL;
    return label;
}

void addLabel(labelTable** labeltbl, char* name, unsigned int address, int lblType)
{
    labelTable* label = createLabel(name, address, lblType);


    if (*labeltbl != NULL)
    {
        labelTable* current = *labeltbl;
        while (current->nextLabel != NULL)
        {
            current = current->nextLabel;
        }
        current->nextLabel = label;
    }
    else
    {
        *labeltbl = label;
    }
}

void freeLabelTable(labelTable* labeltbl)
{

    free(labeltbl->labelName);
    free(labeltbl);
}

void  setAddress(labelTable* labeltbl, int ic)
{
    labelTable* temp = labeltbl;
    while (temp != NULL)
    {
        if (temp->labelType == prompt)
        {
            temp->labelAddress = temp->labelAddress + ic;
        }
        temp = temp->nextLabel;
    }
}

void  setExtern(labelTable* labeltbl, char* name, int a)
{
    labelTable* temp = labeltbl;
    while (temp != NULL)
    {
        if (!strcmp(temp->labelName, name))
        {
            if (a == 1)
                temp->externLabel = external;
            else if (a == 2)
                temp->externLabel = internal;
            break;
        }
        else
            temp = temp->nextLabel;

    }

}

int is_extern(labelTable* head, char* label)
{
    labelTable* temp = head;
    while (temp != NULL)
    {
        if (!strcmp(temp->labelName, label))
        {
            if (temp->externLabel == external)
                return 1;

        }
        temp = temp->nextLabel;
    }
    return 0;

}
    

int find_label(labelTable* head, char* label)
{
    labelTable* temp = head;
    while (temp != NULL)
    {
        if (!strcmp(temp->labelName, label))
            return 1;
        temp = temp->nextLabel;
    }
    return 0;

}

int find_adress_label(labelTable* head, char* label)
{
    int adress;
    labelTable* temp = head;
    while (temp != NULL)
    {
        if (!strcmp(temp->labelName, label))
            adress = temp->labelAddress;
        temp = temp->nextLabel;
    }
    return adress;

}
void printlist(labelTable* head)
{
    labelTable* temp = head;
    while (temp != NULL)
    {
        printf("NAME IS : %s\n", temp->labelName);
        printf("ADDRESS IS : %d\n", temp->labelAddress);
        printf("TYPE IS : %d\n", temp->labelType);
        printf("EXTERN IS : %d\n\n", temp->externLabel);
        temp = temp->nextLabel;
    }
}
