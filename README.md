# sgx-random-device

A small example to show how to wrap Intel SGX `sgx_read_rand` so that it can be used
inside an enclave together with from C++ STL which expects random engines from `<random>`.

## Requirements

You need the Intel SGX SDK to compile the sources. I have not included any Makefiles since
the code will probably be used from within an already existing project anyway.

* I have tested this with SGX SDK version 2.4 on Ubuntu 16.04 LTS.

## Example

The file `random_examples.cpp` contains the following:

* The definition of the `sgx_random_device` class which wraps the `sgx_read_rand` function.
* An example which draws random integers from a uniform distribution.
* An example which uses `std::shuffle` from `<algorithm>` to randomly shuffle a vector.

## License

```
Copyright (c) 2019, Linus Karlsson

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
```

