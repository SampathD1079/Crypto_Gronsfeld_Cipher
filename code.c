#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100], encrypted[100], decrypted[100];
    int i, j;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter numeric key: ");
    scanf("%s", key);

    int textLen = strlen(text);
    int keyLen = strlen(key);

  
    j = 0;
    for(i = 0; i < textLen; i++) {
        if(isalpha(text[i])) {
            int shift = key[j % keyLen] - '0';

            if(isupper(text[i]))
                encrypted[i] = ((text[i] - 'A' + shift) % 26) + 'A';
            else
                encrypted[i] = ((text[i] - 'a' + shift) % 26) + 'a';

            j++;
        } else {
            encrypted[i] = text[i];
        }
    }
    encrypted[i] = '\0';

    printf("\nEncrypted Text: %s\n", encrypted);
    j = 0;
    for(i = 0; i < textLen; i++) {
        if(isalpha(encrypted[i])) {
            int shift = key[j % keyLen] - '0';

            if(isupper(encrypted[i]))
                decrypted[i] = ((encrypted[i] - 'A' - shift + 26) % 26) + 'A';
            else
                decrypted[i] = ((encrypted[i] - 'a' - shift + 26) % 26) + 'a';

            j++;
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}
