#include "algorithm.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int gcd(int a, int b) {
	if (a < b) {
		return gcd(b, a);
   }
	else if (a % b == 0) {
		return b;
  }
	else{
		return gcd(b, a % b);
  }
}


int gen_key(int q) {

	int key = ((int)(rand()) % (int)(q - pow(10, 2))) + pow(10,2);
	while (gcd(q, key) != 1){
		key = ((int)(rand()) % (int)(q - pow(10,2))) + pow(10,2);
  }
	return key;
}

int power(int a, int b, int c) {
	int x = 1;
	int y = a;

	while (b > 0) {
		if (b % 2 != 0) {
			x = ((x * y) % c);
    }
    
		y = ((y * y) % c);
		b = (int)(b / 2);
   
   }

	return x % c;
}


encrypted_message encrypt(char msg[], int q, int h, int g) {

	int en_msg[strlen(msg)];

	int k = gen_key(q);
 	int s = power(h, k, q);
	int p = power(g, k, q);

	for(int i = 0; i < strlen(msg); i++) {
     en_msg[i] = s * (int)(msg[i]);
 }
	encrypted_message a;
  memcpy(a.message, en_msg, sizeof(en_msg));
  a.p_key = p;
  return a;
}

void decrypt(encrypted_message en_msg, int key, int q) {

	char dr_msg[sizeof(en_msg.message)/sizeof(int) + 1];
	int h = power(en_msg.p_key, key, q);
  int temp = 0;
	for(int i = 0; i < sizeof(en_msg.message)/sizeof(int); i++){
     if(en_msg.message[i] == 0) {
       break;
     }
     dr_msg[i] = (char)((int)(en_msg.message[i]/h));
     if(en_msg.message[i]/h > 0 && en_msg.message[i]/h <= 128) {
       printf("%c", dr_msg[i]);
     }
     temp = temp + 1;
   }
   printf("\n");
}


