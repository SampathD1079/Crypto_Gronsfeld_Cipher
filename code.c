#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter numeric key: ");
    scanf("%s", key);

    int textLen = strlen(text);
    int keyLen = strlen(key);

    char cipher[100];

    // Encryption
    for(i = 0; i < textLen; i++) {

        if(isalpha(text[i])) {
            int shift = key[j] - '0';

            if(isupper(text[i])) {
                cipher[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            } else {
                cipher[i] = ((text[i] - 'a' + shift) % 26) + 'a';
            }

            j = (j + 1) % keyLen; // move key only for letters
        } else {
            cipher[i] = text[i]; // keep symbols unchanged
        }
    }
    cipher[i] = '\0';

    printf("Encrypted Text: %s\n", cipher);

    // Decryption
    j = 0;
    char decrypted[100];

    for(i = 0; i < textLen; i++) {

        if(isalpha(cipher[i])) {
            int shift = key[j] - '0';

            if(isupper(cipher[i])) {
                decrypted[i] = ((cipher[i] - 'A' - shift + 26) % 26) + 'A';
            } else {
                decrypted[i] = ((cipher[i] - 'a' - shift + 26) % 26) + 'a';
            }

            j = (j + 1) % keyLen;
        } else {
            decrypted[i] = cipher[i];
        }
    }
    decrypted[i] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
