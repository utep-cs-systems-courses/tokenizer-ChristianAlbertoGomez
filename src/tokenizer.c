#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c==' '||c =='\t'){
    return 1; //true
  }else{
    return 0; //false
  }
  return 0;
}//end of space_char()

int non_space_char(char c)
{
  if(c!=' '||c!='\t'){
    return 1; //true
  }else{
    return 0; //false
  }
  return 0;
}//end of non_space_char()

char *word_start(char *str)
{
  int i;
  i = 0;
  //Checks if str has words
  if(str==NULL){
    return NULL;
  }
  //Create a while loop
  while(space_char(str[i]==1)){
    if(str[i]=='\0'){
      return NULL;
    }
    i++;
  }
  return str;//Probably wrong
}//Word star

char *word_terminator(char *word)
{
  int i;
  i=0;
  word = word_start(word);
  //Check if word is null
  if(word==NULL){
    return NULL;
  }
  while(non_space_char(word[i]==1)){
    i++;
  }
  return word;
}//word terminator

int count_words(char *str)
{
  int counter;
  int i;
  //checks if str is null
  if(str==NULL){
    return 0;
  }
  //Use a for loop
  for(i=0;str[i]!='\0';i++){
    if(str[i]==' ' && str[i+1]!=' '){
      counter++;
    }//if bracket
  }//for bracket
  return counter;
}//counter words

char *copy_str(char *inStr,short len)
{
  int i;
  i=0;

  char *outputStr = (char*)malloc((len+1) *sizeof(char)); //remember cast->char*
  
  if(outputStr == NULL){
    return NULL;
  }
  //do a while loop
  while(i<len){
    outputStr[i] = inStr[i];
    i++;
  }
  outputStr[i] = '\0';
  
  return outputStr;
}//copy string

char **tokenize(char* str)
{
  
  //Now we have to know all the words from the string then:
  int totalWords = count_words(str);

  //Once we know the total then we use malloc to allocate.
  char **tokens =(char**)malloc((totalWords+1)*sizeof(char*));

  char *end;
  str = word_start(str);

  //While loop
  int i = 0;
  while(i<totalWords){
    //Allocate memory for copy str. (word_terminator(str)-str) works as the length.
    char *copyStr = (char*)malloc(((word_terminator(str)-str)+1)*sizeof(char));

    //Now we copy the word
    copyStr = copy_str(str,(word_terminator(str)-str));
    *tokens = copyStr;

    //Now we prepare for the next word is coming.
    end = word_terminator(str);
    str = word_start(end);
    tokens++;
  }
  *tokens = 0;
  return tokens - totalWords;
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
