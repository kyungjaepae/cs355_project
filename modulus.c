#include<stdio.h>
#include<math.h>

int main() {

  int x = cal(7428, 52777, 100000);
  printf("%d\n", x);
  printf("%d\n", sizeof(int));

}


int cal(int base, int exp, int mod) {
  int x = 1;
  int power = base%mod;

  for(int i = 0; i < sizeof(int) *8; i++) {
    int least_sig_bit = 0x00000001 & (exp >> i);
    if(least_sig_bit) {
      x = (x*power)%mod;
    }
    power = (power*power)%mod;
  }
  return x;

}
