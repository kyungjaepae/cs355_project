typedef struct Encrypted_message {
  int message[300];
  int p_key;
} encrypted_message;

int gcd(int a, int b);
int gen_key(int q);
int power(int a, int b, int c);
encrypted_message encrypt(char msg[], int q, int h, int g);
void decrypt(encrypted_message en_msg, int key, int q);
