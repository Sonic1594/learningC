#include <stdio.h>
/*
This code takes an input as if its reading a c code
and removes all comments
*/


int endCheck(char next){
  if (next == '/'){
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int c;
  int hold;
  int isComment = 0;
  int printableLine;
  int needEnd = 0;


  while((c = getchar()) != EOF){
    if (c == '\n' && needEnd == 0){
      isComment = 0;
    }
    if(c == '/' || c == '*'){
      hold = c;
      c = getchar();
      if (isComment == 1 && needEnd == 1){
        isComment = endCheck(c);
        if(isComment == 0){
          needEnd = 0;
          c = getchar();
        }
      } else if (c  == '/'){
        isComment = 1;
        needEnd = 0;
      } else if(c == '*'){
        isComment = 1;
        needEnd = 1;
      } else if (isComment == 0){
        putchar(hold);
      }
    } else if (isComment == 0 && c != '\n'){
      printableLine = 1;
    }
    if (printableLine == 1 && isComment == 0){
      putchar(c);
    }
  }
}
