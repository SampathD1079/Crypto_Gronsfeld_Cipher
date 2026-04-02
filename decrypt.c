#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char cipher[100], key[100];
    char decrypted[100];
    int i, j;

    printf("Enter encrypted text: ");
    scanf("%s", cipher);

    printf("Enter numeric key: ");
    scanf("%s", key);

    int text_len = strlen(cipher);
    int key_len = strlen(key);

    for(i = 0, j = 0; i < text_len; i++) {
        if(isalpha(cipher[i])) {
            int shift = key[j % key_len] - '0';
            decrypted[i] = ((cipher[i] - 'A' - shift + 26) % 26) + 'A';
            j++;
        } else {
            decrypted[i] = cipher[i];
        }
    }
    decrypted[text_len] = '\0';

    printf("\nDecrypted Text: %s\n", decrypted);

    return 0;
}
