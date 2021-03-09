#include <stdio.h>
/*
This code finds all spaces in a code and replaces them
with a tab where applicable
*/

int main() {

  /*
  c is the current getchar.
  cantab tells you if the code thinks it can replace spaces with a tab.
  places is how far in the line c is if everything was spaces.
  count tracks how many spaces since last letter or number.
  i is declared so for loops dont have to constantly declare it.
  */
  int c;
  int canTab = 0;
  int places = 0;
  int count = 0;
  int i;
  //makes sure current input line isnt finished
  while ((c = getchar()) != EOF){

//test case, "a dd     a a"

    //checks if the code can tab and is at a position
    //where it can tab as in when %8 = 0
    if(canTab == 1 && ((places)%8) == 0){
      printf("\t");
      canTab = 0;
      count = 0;
    }
    //if end is reached creates new line for more input
    if(c == '\n'){
      if(canTab == 1){
        printf("\t");
      }
      printf("\n");
      places = 0;
    } else if (c != ' ' && c != '\t'){
      //looks to see if a letter or number is there
      //which would prohibit a tab replacement
      if (canTab == 1){
        for (i = 0; i < count; i++){
          printf(" ");
        }
      }
      count = 0;
      canTab = 0;
      putchar(c);
      ++places;
    } else if (c == ' '){
      canTab = 1;
      ++count;
      ++places;
    } else if (c == '\t'){
      printf("\t");
      places = places + (8-(places%8));
      canTab = 0;
      count = 0;
    }
  }
}
