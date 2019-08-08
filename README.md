This is a basic union find structure.

## Usage

```cpp
#include <string>
#include "union_find.hpp"

UnionFind<std::string> unionFind;

std::string three("3");
unionFind.add(three); // Add a single element

std::string three_b("three");
unionFind.add(three_b, three); // Add three_b, and mark that
                               // it's similar to three;

```

## Issues and troubleshooting

Feel free to raise an issue, include a minimum working example that
demonstrates a problem, and I will try to have a look.

## Licence

Insofar as it can, this software is released into the public domain, without
warranty or guarantee as to its correctness or efficiency.
