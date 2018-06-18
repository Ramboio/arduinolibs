/*
 * Copyright (C) 2018 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef NOISE_SYMMETRIC_STATE_h
#define NOISE_SYMMETRIC_STATE_h

#include <stddef.h>
#include <inttypes.h>

class NoiseCipherState;

class NoiseSymmetricState
{
public:
    NoiseSymmetricState() {}
    virtual ~NoiseSymmetricState();

    virtual void initialize(const char *protocolName) = 0;

    virtual bool hasKey() const = 0;
    virtual size_t macLen() const;

    virtual void mixKey(const void *data, size_t size) = 0;
    virtual void mixHash(const void *data, size_t size) = 0;
    virtual void mixKeyAndHash(const void *data, size_t size) = 0;

    virtual void getHandshakeHash(void *data, size_t size) = 0;

    virtual int encryptAndHash
        (uint8_t *output, size_t outputSize,
         const uint8_t *input, size_t inputSize) = 0;
    virtual int decryptAndHash
        (uint8_t *output, size_t outputSize,
         const uint8_t *input, size_t inputSize) = 0;

    virtual void split(NoiseCipherState **c1, NoiseCipherState **c2) = 0;

    virtual void clear() = 0;
};

#endif