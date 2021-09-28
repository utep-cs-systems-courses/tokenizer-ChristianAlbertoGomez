#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300


int main()
{
  List *history = init_history();
  char userInput[MAX];
  while(1){
  printf("Hello! Please enter 's' to enter a string and display history.'!' to node.'q' to exit.\n");
  fgets(userInput,300,stdin);

  if(*userInput=='s'){
    printf("Enter a String:\n");
    fgets(userInput,MAX,stdin);
    char* start = word_start(userInput);
    char* end = word_terminator(userInput);
    char **userTokens = (char**)malloc(end-start);
    userTokens = tokenize(userInput);
    print_tokens(userTokens);
    add_history(history,userInput);

    print_history(history);
  }else if(*userInput=='!'){
    printf("Please enter the number node you want:\n");
    fgets(userInput,MAX,stdin);

    int i = atoi(userInput);
    char *getNode = get_history(history,i);
    printf("Get node-> %s\n",getNode);
    
  }else{
    printf("Goodbye!\n");
    return 0;
  }
  }
  return 0;
}
