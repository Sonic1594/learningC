#include <stdio.h>
/*
This code takes an input from user and replaces all tabs with
the appropriate amount of spaces.
*/
int main() {

  /*
  c is the current getchar.
  places keeps count of where you are in the input.
  i declared so for each for loop it doesnt need to be redeclared.
  */
  int c;
  int places = 0;
  int i;
  while((c = getchar()) != EOF){
    // Checks to make sure the end of input isnt reached.
    if (c == '\n'){
      printf("\n");
      places = 0;
    } else {
      ++places;
      if (c == '\t'){
        // Checks for a tab at the beginning of input.
        if (places == 1){
          printf("        ");
          places = 8;
        } else {
          /* If tab is found at non beginnning it replaces it with spaces
          to the next 8th position*/
          for (i = 0; i <= (((places-1) % 8)); i++){
            printf(" ");
            ++places;
          }
          // Fixes some offset i create with my loop
          --places;
        }
        // If no tab is found it just puts whatever the current char is.
      } else {
        putchar(c);
      }
    }
  }
}
