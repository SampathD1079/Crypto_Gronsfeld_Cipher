# Crypto_Gronsfeld_Cipher


## 📌 Overview
This project implements the **Gronsfeld Cipher**, a classical encryption technique that is a variation of the Vigenère Cipher. Instead of using a keyword, it uses a **numeric key (digits 0–9)** to perform shifts on each character of the plaintext.

The program supports:
- Uppercase and lowercase letters  
-  Preservation of original case  
-  Non-alphabet characters (left unchanged)  
-  Both encryption and decryption  

---

##  How It Works

The cipher operates by shifting each letter of the plaintext using a repeating numeric key.

###  Key Concept
- Each digit in the key represents the number of positions a letter is shifted.
- The key repeats cyclically if it is shorter than the text.

###  Example
**Plaintext:** `sampath`  
**Key:** `121`  

**Expanded Key:** `12112112`  

**Encryption Process:**
- s → t (+1)
- a → c (+2)
- m → n (+1)
- ...

**Decryption:** Reverse the shift using the same key.

---

##  Algorithm

###  Encryption
1. Read plaintext and numeric key.
2. For each character:
   - Check if it is alphabetic.
   - Convert key digit from character to integer.
   - Apply shift using modulo 26.
   - Preserve case (uppercase/lowercase).
3. Repeat key using modulo operation.
4. Store result as ciphertext.

### Decryption
1. Reset key index.
2. For each character:
   - Reverse the shift using subtraction.
   - Add 26 to avoid negative values.
3. Generate original plaintext.

---

## Code Features

- Uses `isalpha()` and `isupper()` from `<ctype.h>`
- Uses modular arithmetic (`% 26`) for wrapping
- Handles both uppercase and lowercase letters
- Leaves non-alphabet characters unchanged
- Proper string handling using `'\0'`

---

