#include <stdio.h>

/*
Declaring a variable before main and any function
allows it to be called anywhere as long as 'extern'
preceeds the variable declaration.

The difference between these types of variables and
#define variables is that #define creates static variables
whereas extern variables can be modified
*/
#define Y 2
int x = 2;

int main() {
  extern int x;
  ++x;
  printf("%d", x);
}
