#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LENGTH 100

bool delim_character(char c,char delim);
bool non_delim_character(char c, char delim);
int strlength(char *words);
char* word_start(char *str,char delimeter);
char* end_word(char *str,char delimeter);
int count_tokens(char* str,char delim);
char *copy_str(char *inStr, short len, char delim);

/*
  First we are going to create the main menu.
*/

int main(){
   //First we declared the String we will split and the delimeter.
   char words[MAX_LENGTH];
   char delimeter;

   //Ask the user to enter a word with delimeter.
   printf("Please enter the sentence:\n");
   fgets(words,MAX_LENGTH,stdin);
   printf("Your input is:%s \n",words);

  //Ask the user to enter the delimeter.
   printf("Please enter the delimeter:\n");
   delimeter = getchar();
   printf("Your deliminator is:%c \n",delimeter);

   //test new strlength.
   int len = strlength(words);
   printf("Length of your word is:%d \n",len);

   //Test word_start method
   char *test = word_start(words,delimeter);
   printf("word_start test:%c \n",*test);
   //Test word_end method
   char *test2 = end_word(words,delimeter);
   printf("word_end test:%c \n",*test2);

   //Test count_tokens method
   int counter = count_tokens(words,delimeter);
   printf("Total of tokens:%d \n",counter);

   //Test copy_str method
   char* temp_test = copy_str(words,len,delimeter);
   printf("Copy Test:%s \n",temp_test);

  //end of the program
  return 0;
}
/*
  This method will help us to know the length of string words.
*/
int strlength(char *words){
  int i;
  int len;
  for(i=0;words[i]!='\0';i++){
  len = i;
 }
  return len;
}
/* Return true (non-zero) if c is the delimiter character
   previously chosen by the user.
   Zero terminators are not printable (therefore false) */
bool delim_character(char c, char delim)
{
  char zeroTerminator = '\0';
  if(c==delim){
     return true;
   }
  if(c==zeroTerminator){
     return false;
   }
   else{
    return false;
   }
}

/* Return true (non-zero) if c is a non-delimiter
   character.
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c, char delim)
{
  char zeroTerminator = '\0';
  if(c!=delim){
     return true;
   }
  if(c==zeroTerminator){
     return false;
   }else{
     return false;
   }
}

/* Returns a pointer to the first character of the next
   word starting with a non-delimiter character. Return a zero pointer if
   str does not contain any words.*/
char *word_start(char* str,char delim)
{
  char *temp_str = str; //copy of str.
  int len = strlength(temp_str); //length of str.
  int i = 0; //i will be used for the while loop.
  bool target;//variable to store return value of delim_character()

  //if str length is 0 then we return null.
  if(len == 0){
    return NULL;
  }

  while(*(temp_str+i)){
   target = non_delim_character(*(temp_str+i),delim);
    if(target == true){
      return temp_str+i;
    }
    i++;
  }
   return temp_str+i;

}

/* Returns a pointer to the first delimiter character of the zero
   terminated string*/
char *end_word(char* str,char delim)
{
  char *temp_str = str; //copy of str.
  int len = strlength(temp_str); //length of str.
  int i = 0; //i will be used for the while loop.
  bool target;//variable to store return value of delim_character()

  //if str length is 0 then we return null.
  if(len == 0){
    return NULL;
  }

  while(*(temp_str+i)){
   target = delim_character(*(temp_str+i),delim);
    if(target == true){
      return temp_str+i;
    }
    i++;
  }
   return temp_str+i;
}

/* Counts the number of words or tokens*/
int count_tokens(char* str,char delim)
{
  int counter = 0; //works as counter for each word.
  int i = 0; //works for our loop.
  char* temp_str = str; //copy of char* str
  bool target; //this will help us to know the return value of non-delim

  //Now we use the temp variable to get the start_word result;
  temp_str = word_start(str,delim);
  //Now we apply a while loop to start counting the tokens.
  while(*temp_str){
     target = non_delim_character(*(temp_str+i),delim);
     if(target == true){
       counter++;
     }
     temp_str=end_word(temp_str,delim);
     temp_str=word_start(temp_str,delim);
   }
  return counter;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len, char delim)
{
   //Declare the length of inStr.
   short temp_len = len;

  //Declare a temp copy string for inStr.
  //We use len+1 to take in count the '\0' at the end of a string.
  //To copy correctly we need malloc. Sizeof will tell us the size
  // capacity of a char*.
   char* temp_inStr = malloc((len+1)*sizeof(char*));

   //Next thing is copy each index of inStr into the temp_inStr.
   int i; //for loop
   for(i=0;i<temp_len;i++){
    temp_inStr[i] = inStr[i];
  }
   temp_inStr[i] = '\0'; //We have to add the \0 at the end of the copy.

   return temp_inStr; //Now we return the copy!
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   delimiter-separated tokens from zero-terminated str.
   For example, tokenize("hello world string"), with a character delimiter
   of a space " " would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char** tokenize(char* str, char delim)
{

}

void print_all_tokens(char** tokens)
{

}
