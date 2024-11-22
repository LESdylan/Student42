#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char **argv)
{
    //unsigned int key;
    //int i;
    //char *endptr;
    char input[50];
    //to validate the key
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./substitution key\n");
        return 1;
    }
    // check if the key has a length of 26
    if(strlen(argv[1]) != 26)
    {
        fprintf(stderr, "Error 1: the sequence of character has to be of 26\n");
        return 1;
    }
    //check if the key has only characters
    if(!isalpha(argv[1]))
    {
        fprintf(stderr, "the argument only has to include alphabetic characters\n");
    }
    //check for repeated characters (case-insensitive)
    //key = strtoul(argv[1], &endptr, 10);
    
    printf("plaintext: ");
    
    if(fgets(input, sizeof(input), stdin)== NULL)
    {
        fprintf(stderr, "Err 3: failed to read plaintext\n");
        return 1;
    }
    
    
    
    
    //get_string
    //for each alha char, determine what letter it maps to
    //preserve case
    //leave non-alphabetic character as-is.
}


//int ft_check_doublons(char *str)
//{
//    
//}