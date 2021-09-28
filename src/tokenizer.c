#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if((c==' '||c =='\t')&& c!='\0'){
    return 1; //true
  }else{
    return 0; //false
  }
}//end of space_char()

int non_space_char(char c)
{
  if((c == ' ' || c == '\t') || c == '\0'){
    return 0;
  }else{
    return 1;
  }
}//end of non_space_char()

char *word_start(char *str)
{
  int i=0;

  while(*(str + i)){
    if (non_space_char(*(str+i))){
      return str+i;
    }
    i++;
  }
  return str+i;
}//Word star

char *word_terminator(char *word)
{
  int i=0;
  while(*(word + i)){
    if(space_char(*(word + i))){
      return word + i;
    }
    i++;
  }
  return word + i;
}//word terminator

int count_words(char *str)
{
  char *temp = str;

  int counter = 0;
  int i = 0;
  temp = word_start(temp);

  while(*temp){
    if(non_space_char(*temp)){
      counter++;
    }
    temp=word_terminator(temp);
    temp=word_start(temp);
  }
  // printf("%d",count);
  return counter;
}//counter words

char *copy_str(char *inStr,short len)
{
  char *copyStr = malloc(( len + 1) * sizeof(char));
  int i;
  
  for (i=0; i < len; i++){
    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';
  return copyStr;
}//copy string

char **tokenize(char* str)
{
  int size = count_words(str);
  char **tokens = malloc((size + 1) * sizeof(char *));
  
  int i;
  int length;
  char *p = str;
  
  for(i = 0;i < size;i++){
    p = word_start(p);
    length = word_terminator(p)-word_start(p); //works as length
    tokens[i] = copy_str(p, length);
    p = word_terminator(p);
  }
  tokens[i] = '\0';
  return tokens;
}//tokenize

void print_tokens(char **tokens)
{
  int i = 0;
  
  while(tokens[i]!=NULL){
    printf("tokens[%d]= %s \n",i,tokens[i]);
    i++;
  }
  return;
}//print tokens

void free_tokens(char **tokens)
{
  int i=0;
  while(tokens[i]!=NULL){
      free(tokens[i]);
      i++;
    }
  free(tokens);
  return;
}//free tokens
