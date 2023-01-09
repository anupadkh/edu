#include<stdio.h>
#include<stdlib.h>

int main(){
  char *x;
  gets(x);
  FILE *fp;
  if((fp=fopen(x,"r")) == NULL){
    printf("File not found : %s\n",x);
  }
  return 0;
}
