#include <stdio.h>

int main() {
  double temp = 0;
  double max = 300;
  double celc;

  while (temp <= max){
    celc = (temp - 32)*(5.0/9.0);
    printf("%.0fF\t=\t%.1fC\n", temp, celc);
    temp = temp + 20;
  }
}
