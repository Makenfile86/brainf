#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int move_ptr(char *input, int i)
{
 //printf("testi2");
 int count;
 int direction;

 direction = 0;
 count = 0;
 if (input[i] == '[')
 direction = 1;
 if (input[i] == ']')
 direction = -1;

 while (input[i] != '\0')
 {
 if (input[i] == '[')
 count += 1;
 else if (input[i] == ']')
 count -= 1;
 if ((input[i] == '[' || input[i] == ']') && count == 0)
return (i);
 i += direction;
 }
 
 return (0);
 
}

int move_ptr_end(int byte, char *input, int i)
{
 if (byte != 0)
 {
 while (i != 0)
 {
if (input[i] == '[')
 return (i);
 i--;
 }
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
    else if (input[i] == '[' && bytes[i_ptr] == 0)
    i = move_ptr(input, i);
    else if (input[i] == ']' && bytes[i_ptr] != 0)
    i = move_ptr(input, i);
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