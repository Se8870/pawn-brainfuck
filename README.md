# pawn brainfuck

[![sampctl](https://img.shields.io/badge/sampctl-pawn--brainfuck-2f2f2f.svg?style=for-the-badge)](https://github.com/Kirima2nd/testing)

Brainfuck interpreter for pawn.

*NOTE:*
Since pawn have shared stk and hea, i believe it's have own limitation so please dont run some huge code or it will have colisions.

## Installation

Simply install to your project:

```bash
sampctl package install Kirima2nd/pawn-brainfuck
```

Include in your code and begin using the library:

```pawn
#include <brainfuck>
```

## Function List

```pawn
forward BF_Interpret(output[], const input[], len = sizeof(output));
```


## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```

