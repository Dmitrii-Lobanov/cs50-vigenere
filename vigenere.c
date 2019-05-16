#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage ./viginere keyword\n");
        return 1;
    }
    else
    {
        for(int i=0; i<strlen(argv[1]); i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Only characters are allowed.\n");
                return 1;
            }
        }
    }
    
    string key = argv[1];
    int key_len = strlen(key);
    
    string plaintext = get_string("Plaintext: ");
    printf("Ciphertext: ");
    
    for(int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        int letter_key = tolower(key[j % key_len]) - 'a';
        
        if(isupper(plaintext[i]))
        {
            char cypher = 'A' + (plaintext[i] - 'A' + letter_key) % 26;
            printf("%c", cypher);
            j++;
        }
        else if(islower(plaintext[i]))
        {
            char cypher = 'a' + (plaintext[i] - 'a' + letter_key) % 26;
            printf("%c", cypher);
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}


