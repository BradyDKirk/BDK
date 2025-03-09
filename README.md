# BDK
A C standard library replacement with built-in math and cross-platform window creation functionality. This doesn't replace every feature of the C standard library but provides an alternative solution for the functionality you likely wanted anyway.

**IMPORTANT:** Please be aware that parts of this codebase are intentionally left unprefixed; thus, it is assumed incompatibility with some or potentially all of the C standard library. As this codebase grows, I will provide a more formal overview of what is and isn't prefixed and how it is intended to be used.

### *CAUTION: This project is extremely young and may contain security bugs. Use at your own discretion.*

## Usage
In a single source file:
```c
#define BDK_NO_PREFIX // Optional: Turn of type/function name prefixing
#define BDK_IMPLEMENTATION
#include <bdk/bdk.h>
```

Be sure to set the base repo folder as an include directory for your compiler or just copy the `bdk/` folder into your source and reference everything locally.

*Visit [nothings/stb](https://github.com/nothings/stb) for more information on this approach.*

## Running Tests
Tests are currently not formally being written but if you desire to build and run what is there perform the following:

(This only will work on Windows)
1. Open a Developer Command Prompt or just verify your environment can invoke MSVC.
2. `cd ..\path\to\BDK\tests\`
3. Run `build`
4. The resulting executable is in `BDK\tests\build\`

## License
*BDK* is licensed under the MIT License. See [LICENSE.txt](LICENSE.txt) for details.
