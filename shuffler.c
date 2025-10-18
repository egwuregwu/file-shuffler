#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define HEX_LENGTH 2

void renameFile(char* file_name, char* main_name);
char* getRandomHex(int);

char HEX_VALUES[] = "0123456789ABCDEF";

int main(int argc, char* argv[])
{ 
    argv[0] = argv[0] + 2;
    //by default, argv[0] starts with a "./"

    struct dirent* entry;
    DIR* directory;

    directory = opendir(".");

    srand(time(NULL));

    while ((entry = readdir(directory)))
        renameFile(entry->d_name, argv[0]);

    return 0;
}

void renameFile(char* file_name, char* main_name)
{
    for (char* nl = file_name; *nl; nl++)
    {
        if (*nl == '\n')
        {
            *nl = '\0';
        }
    }
    
    if (
        strcmp(file_name, main_name) == 0 || 
        strcmp(file_name, "shuffler.c") == 0 ||
        strcmp(file_name, "..") == 0 ||
        strcmp(file_name, ".") == 0 ||
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