#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "token.h"
#include "function.h"

void edt_txt(char *s) {
  int m = strlen(s),n,count=0,i;
  
  //For arnging proper number of gaps
  for(i=0 ; i<= m ; i++) {
    if(s[i] == ' ') {
      n=i;
      while(1) {
	if(s[n] == s[n+1]) {
	  count++;
	  n++;
	}
	else
	  break;
      }
    }
    
    if(count) {
      for(int  j=i; j<=m ; j++) {
	s[j]=s[j+count];
      }
      
      count=0;
    }
  }
  
  if(s[0] == ' ') {
    for(int  j=0; j<=m ; j++)
      s[j]=s[j+1];
  }
  
}

int putWords(struct word_t* Words[], char *s) {
  int i;
  
  edt_txt(s);
  int count=0;
  int len=strlen(s);
  s[len]='\0';
  s[len-1]=' ';
  
  //fputs(s, stdout);
  for(int i=0; i<len; i++) {
    if(s[i]==' ' && s[i-1]!=' ')
      count++;
  }
  
  int temp=0;
  
  for(i=0 ; i<count ; i++) {
    Words[i] = malloc(sizeof(struct word_t)*MAX);
    int num =0;
    Words[i]->word = malloc(sizeof(char) * MAX);
    
    for(int j=temp ; s[j] != ' ' ; j++,temp++) {
      Words[i]->word[num++] = s[j];
    }
    
    if(s[temp] == ' ')
      temp++;
    
    Words[i]->length = strlen(Words[i]->word);
  }
  
  return count;
}

long getkey(char* word,int length){
  int temp;
  long token=0;
  
  for(int i=0;i<length;i++) {
    temp=word[i];
    token=1000*token+temp;
  }
  
  //printf("%ld ... %s\n",token,word);
  return token;
}

int checkIfNumber(struct word_t* Word) {
  int i;
  
  for(i=0 ; i<Word->length ; i++) {
    if(!(Word->word[i] > 47 && Word->word[i] < 58)) {
      return 0;
    }
  }
}

int main(int argc, char * argv[]) {
  if(argc < 2) {
    while (1) {
      struct word_t* myWords[MAX];
	  int count;
	  char *s = malloc(sizeof(char)*MAX);
	  fgets(s,MAX,stdin);
	  count=putWords(myWords,s);
	  
	  int i,pop1=0,pop2=0,reln=0;
	  int* stack = malloc(sizeof(int)*MAX);
	  int top=0;
	  for(i=0 ; i<count ; i++) {
	    if(checkIfNumber(myWords[i])) {
	      stack[top]=atof(myWords[i]->word);
	      top++;
	    }
	    else {
	      long key=0;
	      key=getkey(myWords[i]->word,myWords[i]->length);
	      if(key == print){
		printf("%d \n",stack[top-1]);
	      }
	      else if (key == add) {
		pop1=stack[top-1];
		pop2=stack[top-2];
		top = top-1;					
		stack[top-1]=addition(pop1,pop2);
	      }
	      else if (key == mul) {
		pop1=stack[top-1];
		pop2=stack[top-2];
		top = top-1;
		stack[top-1]=multi(pop1,pop2);
	      }
	      else if (key == sub) {
		pop1=stack[top-1];
		pop2=stack[top-2];
		top = top-1;
		stack[top-1]=subtract(pop1,pop2);
	      }
	      else if (key == div) {
		pop1=stack[top-1];
		pop2=stack[top-2];
		top = top-1;
		stack[top-1]=division(pop1,pop2);
	      }
	      else if (key == iff) {
		int get=5;
		pop1=stack[top-2];
		pop2=stack[top-1];
		iffun(pop1,pop2,&get,getkey(myWords[reln]->word,myWords[reln]->length));
		if(get == 0) {
		  i=count;
		  printf("Condition not Matched ...\n");
		}
		reln=0;
	      }
	      else if ((key == more) || (key == less)||(key == equal)) {
		reln=i;
	      }
	      else if (key == quit) {
		return 0;
	      }
	      else {
		printf("Keyword not found.. ..\n");
	      }
	    }
	  }
    }
    return 0;
  }
  else {
    FILE *file = fopen( argv[1], "r" );
    if(file==0) {
      printf("Could not open file...\n");
    }
    else {
      FILE *file = fopen( argv[1], "r" );
      char *s = malloc(sizeof(char)*MAX);
      
      while (fgets(s, MAX, file) != NULL) {
	struct word_t* myWords[MAX];
	int count;
	count=putWords(myWords,s);
	
	int i,pop1=0,pop2=0,reln=0;
	int* stack = malloc(sizeof(int)*MAX);
	int top=0;
	for(i=0 ; i<count ; i++) {
	  if(checkIfNumber(myWords[i])) {
	    stack[top]=atof(myWords[i]->word);
	    top++;
	  }
	  else {
	    long key=0;
	    key=getkey(myWords[i]->word,myWords[i]->length);
	    if(key == print){
	      printf("%d \n",stack[top-1]);
	    }
	    else if (key == add) {
	      pop1=stack[top-1];
	      pop2=stack[top-2];
	      top = top-1;					
	      stack[top-1]=addition(pop1,pop2);
	    }
	    else if (key == mul) {
	      pop1=stack[top-1];
	      pop2=stack[top-2];
	      top = top-1;
	      stack[top-1]=multi(pop1,pop2);
	    }
	    else if (key == sub) {
	      pop1=stack[top-1];
	      pop2=stack[top-2];
	      top = top-1;
	      stack[top-1]=subtract(pop1,pop2);
	    }
	    else if (key == div) {
	      pop1=stack[top-1];
	      pop2=stack[top-2];
	      top = top-1;
	      stack[top-1]=division(pop1,pop2);
	    }
	    else if (key == iff) {
	      int get=5;
	      pop1=stack[top-2];
	      pop2=stack[top-1];
	      iffun(pop1,pop2,&get,getkey(myWords[reln]->word,myWords[reln]->length));
	      if(get == 0) {
		i=count;
		printf("Condition not Matched ...\n");
	      }
	      reln=0;
	    }
	    else if ((key == more) || (key == less)||(key == equal)) {
	      reln=i;
	    }
	    else if (key == quit || key == 0) {
	      return 0;
	    }
	    else {
	      printf("Keyword not found.. ..\n");
	    }
	  }
	}
      }
    }
    return 0;
  }
}
		
