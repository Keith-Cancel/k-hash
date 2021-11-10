/*
MIT License

Copyright (c) 2021 Keith-Cancel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef KEITHS_HASH_H
#define KEITHS_HASH_H

#include <stdint.h>

#define ROTR(x,n) (((x) >> (n)) | ((x) << (64 - (n))))

// Just initialize with the fractional part of sqrt(2)
#define khash(input) khash_fn(input, 0x6a09e667f3bcc908)

static inline uint64_t khash_fn(uint64_t input, uint64_t func) {
    uint64_t h = func;
    h ^= input - 7;
    h ^= ROTR(h, 31);
    h -= ROTR(h, 11);
    h -= ROTR(h, 17);

    h ^= input - 13;
    h ^= ROTR(h, 23);
    h += ROTR(h, 31);
    h -= ROTR(h, 13);

    h ^= input - 2;
    h -= ROTR(h, 19);
    h -= ROTR(h, 31);
    h += ROTR(h, 5);
    return h;
}

#endif