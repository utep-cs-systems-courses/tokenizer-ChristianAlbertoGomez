#include <stdio.h>
#include <stdlib.h>

int main()
{
  char inputUser[300];

  while(1){
    putchar('$');
    fgets(userInput,300,stdin);
    printf("%s\n",userInput);
  }
  return 0;
}
