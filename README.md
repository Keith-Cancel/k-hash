# K-HASH
A simple single header 64 bit hash function using only add, sub, ror, and xor. This a just general-purpose hash function for like making hash maps and similar data-structures. It's is not a cryptographic hash function!

It is quite easy to choose a new function at runtime by just passing a random 64 bit value to the func parameter such as:
```C
#include "khash.h"

void foo() {
    /*
    code ....
    */
    uint64_t hash = khash64_fn(value, your_random_number);
    /*
    code ....
    */
}

```
