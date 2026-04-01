#  Crypto_Gronsfeld_Cipher

---

##  Overview

This project implements the **Gronsfeld Cipher**, a classical encryption technique derived from the Vigenère Cipher. Unlike Vigenère, it uses a **numeric key (digits 0–9)** to determine the shift applied to each character in the plaintext.

Additionally, this project includes:

*  Encryption and Decryption
*  Custom Hash Function (Polynomial Rolling Hash)
*  Full round-trip verification (Encrypt → Hash → Decrypt)

---

## ⚙️ Features

*  Supports uppercase and lowercase letters
*  Preserves original character case
*  Non-alphabet characters remain unchanged
*  Repeating numeric key mechanism
* Custom hashing implementation (no libraries used)
*  Efficient and lightweight C implementation

---

##  How It Works

The cipher shifts each letter of the plaintext using digits from a numeric key.

###  Key Concept

* Each digit in the key defines the shift value
* The key repeats cyclically if shorter than the text

---

### Example

**Plaintext:** `sampath`
**Key:** `121`

**Expanded Key:** `12112112`

###  Encryption Process

* s → t (+1)
* a → c (+2)
* m → n (+1)
* p → q (+1)
* a → c (+2)
* t → u (+1)
* h → i (+1)

**Ciphertext:** `tcnqcu i` *(example format)*

---

###  Decryption

* Reverse the shift using the same key
* Original plaintext is restored

---

##  Algorithm

###  Encryption

1. Read plaintext and numeric key
2. Traverse each character of plaintext
3. If character is alphabetic:

   * Convert key digit to integer
   * Apply shift using modulo 26
   * Preserve case
4. If non-alphabetic:

   * Leave unchanged
5. Repeat key using modulo operation
6. Store result as ciphertext

---

###  Decryption

1. Reset key index
2. Traverse ciphertext
3. Reverse shift using subtraction
4. Add 26 to avoid negative values
5. Preserve case
6. Reconstruct original plaintext

---

##  Hash Function

A **Polynomial Rolling Hash** is implemented to ensure data integrity.

###  Formula

Hash = Σ (char_value × p^i) mod m

Where:

* p = 31 (prime base)
* m = 1,000,000,007 (large prime modulus)

###  Why this hash?

* Fast computation
* Good distribution
* Reduces collisions
* Common in string matching algorithms

---

##  Program Flow

1. User inputs plaintext
2. User inputs numeric key
3. Program encrypts the plaintext
4. Computes hash of ciphertext
5. Decrypts ciphertext back to original

---

##  Sample Run

**Input:**
Plaintext: HELLO
Key: 123

**Output:**
Encrypted: IGOMQ
Hash: 123456789 *(example)*
Decrypted: HELLO

---

## Code Highlights

* Uses `<ctype.h>` for character handling
* Uses `% 26` for alphabet wrapping
* Uses modular arithmetic for hashing
* Efficient loop-based implementation
* No external cryptography libraries used

---

## Constraints Followed

*  No built-in crypto libraries
*  Implemented from scratch
*  Custom hash function used
* Written in C

---

## Project Structure

Crypto_Gronsfeld_Cipher/
│── gronsfeld.c
│── README.md

This project demonstrates:
* Classical encryption (Gronsfeld Cipher)
* Secure hashing technique
* Complete encryption-decryption pipeline
* Practical implementation of modular arithmetic
