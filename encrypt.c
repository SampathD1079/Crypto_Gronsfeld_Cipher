#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    char cipher[100];
    int i, j;

    printf("Enter plaintext : ");
    scanf("%s", text);

    printf("Enter numeric key: ");
    scanf("%s", key);

    int text_len = strlen(text);
    int key_len = strlen(key);

    for(i = 0; i < text_len; i++) {
        text[i] = toupper(text[i]);
    }

    for(i = 0, j = 0; i < text_len; i++) {
        if(isalpha(text[i])) {
            int shift = key[j % key_len] - '0';
            cipher[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            j++;
        } else {
            cipher[i] = text[i];
        }
    }
    cipher[text_len] = '\0';

    printf("\nEncrypted Text: %s\n", cipher);

    unsigned long long hash = 0;
    unsigned long long p = 31;
    unsigned long long power = 1;
    unsigned long long mod = 1000000007;

    for(i = 0; i < text_len; i++) {
        if(isalpha(cipher[i])) {
            int val = cipher[i] - 'A' + 1;
            hash = (hash + val * power) % mod;
            power = (power * p) % mod;
        }
    }

    printf("Hash Value: %llu\n", hash);

    return 0;
}
