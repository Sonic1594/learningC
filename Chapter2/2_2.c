#include <stdio.h>

int v alid = 1;
int lim = 10;

while(valid){
    if (i > (lim-1)){
        valid = 0;
    } else if (c=getchar() == '\n'){
        valid = 0;
    } else if (c == EOF){
        valid = 0;
    } else {
        //do something
    }
}
