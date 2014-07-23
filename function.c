#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "token.h"

int addition(int pop1, int pop2) {
  int sum=0;
  sum=pop1+pop2;
  
  return sum;
}

int  multi(int pop1, int pop2) {
  int pro=1;
  pro=pop1*pop2;
  
  return pro;
}

int  subtract(int pop1, int pop2) {
  int val=0;
  val=pop1-pop2;
  
  return val;
}

int  division(int pop1, int pop2) {
  int num=1;
  num=pop1/pop2;
  
  return num;
}

int  iffun(int pop1,int pop2,int* get,long key1) {
  int sum=0;
  //printf("%ld",key1);
  if(key1 == 109111114101){
    if(pop1>pop2)
      *get = 1;
    else
      *get = 0;
  }
  
  if(key1 == 3108101115115){
    if(pop1<pop2)
      *get = 1;
    else
      *get = 0;
  }
  
  if(key1 == 101113117097108){
    if(pop1==pop2)
      *get = 1;
    else
      *get = 0;
  }
}
