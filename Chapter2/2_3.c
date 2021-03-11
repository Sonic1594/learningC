#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


/*
 * This code takes in a hexadecimal and 
 * converts it to an int
 */ 

int convertchar(char c){
    if (isdigit(c)){
        return c - '0';
    } else {
        // here would go a check to see if c is a-f/A-F
        int converted = tolower(c) - 'a';
        
        return converted + 10; //add 10 because 'a' is 10
    }
}

// 0xffffffff
// ffffffff
// 00000000
// f
// 0x
int hex2int(char* hex_string){
    int length = strnlen(hex_string, 11);
    int prefix = 0;
    if (length >= 2 && tolower(hex_string[1]) == 'x' && hex_string[0] == '0'){
        prefix = 2;
    }
    int final = 0;
    int pow = 1;
    while (length --> prefix){
        final += convertchar(hex_string[length]) * (pow);
        pow *= 16;

    }
    return final;
}


int main(){
    char input[11];
    char* c = input;
    int valid = 1;
    while (valid){
        printf("Please give a hexadecimal to convert or q to quit: ");
        scanf("%10s", input);
        if (tolower(input[0]) == 'q'){
            valid = 0;
        } else {
           printf("%d\n", hex2int(c));
        }
    }
}
