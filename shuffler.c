#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HEX_LENGTH 2

void renameFile(char* file_name);
char* getRandomHex(int);

char HEX_VALUES[] = "0123456789ABCDEF";

char* programName;

int main(int argc, char* argv[])
{ 
    int programName_length = strlen(argv[0]);
    programName = malloc(programName_length + 1);
    strncpy(programName, argv[0], programName_length);

    for (char* i = programName; *(i+2); i++)
    {    
        *i = *(i+2);
        *(i+1) = '\0';
    }
    //by default, argv[0] starts with a "./"

    char workingDirectory[150];
    
    system("pwd > out");

    FILE *outputFile;
    outputFile = fopen("out", "r");
    fgets(workingDirectory, 150, outputFile);
    fclose(outputFile);

    system("ls > out");

    outputFile = fopen("out", "r");

    char files[1000][150];
    char buffer[150];

    int fileCount = 1;

    for (int i = 0;; i++)
    {       //null means EOF !!
        if (fgets(buffer, 150, outputFile) == NULL || buffer[0] == '\n')
            break;
        strcpy(files[i], buffer);
        fileCount++;
    }

    fclose(outputFile);

    system("rm -f out");


    if (strncmp(workingDirectory, "F:\\", 3) == 0)
    {
    start:
        for (int i = 0; i < fileCount; i++)
        {
            renameFile(files[i]);
        }
        
    } else {
        printf(
            "Using this outside of your USB drive is not recommended, are you sure?\n"
            "Type 'y' to continue or 'n' to terminate\n"
            "[y/n]\n"
        );
        char choice[4];
        fgets(choice, 3, stdin);
        if (choice[0] == 'y' || choice[0] == 'Y')
            goto start;
    }

    free(programName);

    return 0;
}

void renameFile(char* file_name)
{
    for (char* nl = file_name; *nl; nl++)
    {
        if (*nl == '\n')
        {
            *nl = '\0';
        }
    }
    
    if (
        strcmp(file_name, programName) == 0 || 
        strcmp(file_name, "shuffler.c") == 0 || 
        strcmp(file_name, "out") == 0 ||
        strcmp(file_name, "") == 0
    )
        return;


    char* hex_value = getRandomHex(HEX_LENGTH);

    const size_t MAX_COMMAND_LENGTH = 250;
    char renameCommand[MAX_COMMAND_LENGTH + 1];

    snprintf(renameCommand, MAX_COMMAND_LENGTH, "mv \"%s\" \"%s %s\"", file_name, hex_value, file_name);
    printf("%s\n", renameCommand);
    system(renameCommand);

    free(hex_value);
}

char* getRandomHex(int length)
{
    char* hexArray = malloc(length+1);
    for (int i = 0; i < length; i++)
    {
        int hexDenary = (rand() % 16);
        char hexChar = HEX_VALUES[hexDenary];
        hexArray[i] = hexChar;
    }
    hexArray[length] = '\0';
    return hexArray;
}