#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char userInput[300];
  List *list = init_history();
  
  int i=0;
  while(i<3){
    putchar('$');
    fgets(userInput,300,stdin);
    printf("%s\n",userInput);

    char* start = word_start(userInput);
    char* end = word_terminator(userInput);

    printf("Number of words: %d\n",count_words(userInput));
    printf("Start of word: %s\n",start);
    printf("End of word: %s\n",end);

    int len = count_words(userInput);

    char **user_tokenize = (char**)malloc((len)*sizeof(char));
    user_tokenize = tokenize(userInput);
    print_tokens(user_tokenize);

    //TEST LINKEDLIST
    char *str = "UTEP";
    add_history(list,str);

    print_history(list);

    printf("Get node value of 1:\n");
    char *get_node = get_history(list,0);
    printf("%s\n",get_node);
    
    i++;
  }
  return 0;
}
