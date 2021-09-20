#include <stdlib.h>

int space_char(char c)
{
  if(c==' '||c =='\t'){
    return 1; //true
  }else{
    return 0; //false
  }
}//end of space_char()

int non_space_char(char c)
{
  if(c!=' '||c!='\t'){
    return 1; //true
  }else{
    return 0; //false
  }
}//end of non_space_char()

char *word_star(char *str)
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
  return *(str+i);//Probably wrong
}
char *word_terminator(char *word)
{
  int i;
  i=0;
  word = word_star(word);
  //Check if word is null
  if(word==NULL){
    return NULL;
  }
  while(non_space_char(word[i]==1)){
    i++;
  }
  return *(word+i);
}
int count_words(char *str)
{
  int counter;
  int i;
  //checks if str is null
  if(str==NULL){
    return 0;
  }
  //Use a for loop
  for(i=0;s[i]!='\0';i++){
    if(s[i]==' ' && s[i+1]!=''){
      counter++;
    }//if bracket
  }//for bracket
  return counter;
}
char *copy_str(char *inStr,short len)
{
  int i;
  i=0;

  char *outputStr = malloc((len+1) *sizeof(char));

  if(outputStr == NULL){
    fprintf(stderr,"ERROR!!!");
    return NULL;
  }
  //do a while loop
  while(i<len){
    outputStr[i] = inStr[i];
    i++;
  }
  outputStr[i] = '\0';
  return outputStr;
}
