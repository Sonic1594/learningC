#include <stdio.h>
#include <string.h>

/*
this code checks code for syntax errors
this means the code looks for matching
[, ', ", (, {, and end ;
no errors are fixed, but when the first error is found
the code will stop reading and print that error.
*/

/*
8 is the max open pieces the code can hold,
this can be changed by changing max.
*/

int matchCheck(char check, int index, char openSyntax[]){
  if (check == ']'){
    if(openSyntax[index] == '['){
      return 1;
    }
  } else if (check == '}'){
    if(openSyntax[index] == '{'){
      return 1;
    }
  } else if (check == ')'){
    if(openSyntax[index] == '('){
      return 1;
    }
  } else if (check == '\''){
    if(openSyntax[index] == '\''){
      return 1;
    }
  } else if (check == '\"'){
    if(openSyntax[index] == '\"'){
      return 1;
    }
  } else {
    return 0;
  }
}


int main(){
  int max = 8;

  char syntaxOpen[] = "[({\'\"";
  char syntaxClose[] = "])}\'\"";
  char openSyntax[max + 2];
  int index = 0;  int c;
  int semicolon = 0;
  memset(&openSyntax, '\0', sizeof(openSyntax));
  while((c = getchar()) != EOF){
    printf("\%c \n", c);
    if (c == ';'){
      semicolon = 1;
    }
    if (c == '\n'){
      if (semicolon == 0){
        printf("You didnt end your line with a ;\n");
        return(0);
      } else {
        semicolon = 0;
      }
    }
    if(strchr(syntaxClose, c)){
      if (index > 0 && matchCheck(c, index - 1, openSyntax) == 1){
        --index;
        openSyntax[index] = '\0';
      } else if (c != '\'' && c != '\"'){
        printf("You have a missmatched syntax, you have \%c and \%c.\n", openSyntax[index-1], c);
        return(0);
      }
    } else if(strchr(syntaxOpen, c)){
      if(index < max){
        openSyntax[index] = c;
        ++index;
      } else {
        printf("You have too many open syntax at once.\n");
        return(0);
      }
    }
    printf("\%s \n", openSyntax);
  }
}
