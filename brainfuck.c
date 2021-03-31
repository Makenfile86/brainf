#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int move_ptr_start(int byte, char *input, int i)
{
 //printf("testi2");
 if (byte == 0)
 {
 while (input[i] != ']' && input[i] != '\0')
 i++;
 }
 return (i);
}

int move_ptr_end(int byte, char *input, int i)
{
 if (byte != 0)
 {
 while (input[i] != '[' && i != 0)
 i--;
 }
 return (i);
}

void brainfuck(char *input)
{
//printf("input: %s\n", input);
char *bytes;
int i;
int i_ptr;

i = 0;
i_ptr = 0;
if (!(bytes = (char *)malloc(sizeof(char) * 2048)))
printf("malloc failed");

while (input[i] != '\0')
{
    //printf("%c", input[i]);
    //printf("testi");
    if (input[i] == '>')
    i_ptr += 1;
    else if (input[i] == '<')
    i_ptr -=1 ;
    else if (input[i] == '+')
    bytes[i_ptr] += 1;
    else if (input[i] == '-')
    bytes[i_ptr] -= 1;
    else if (input[i] == '.')
    {
        //printf("testerr");
        printf("%c", bytes[i_ptr]);
    }
    else if (input[i] == '[')
    i = move_ptr_start(bytes[i_ptr], input, i);
    else if (input[i] == ']')
    i = move_ptr_end(bytes[i_ptr], input, i);
    i++;
}

}

int main(int argc, char **argv)
{
//printf("%d", argc);
 if (argc != 2)
 printf("vaara argc nbr");
 else
 brainfuck(argv[1]);
 
 return (0);
}