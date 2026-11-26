# External Interrupt Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The fake line accepts a rising edge and declines a low-level trigger. The program binds it through `Line&`, enables it, observes and clears the flag, then disables delivery. A separate fake group accepts only its high mask bit. It tests that rejection preserves the selected mask and that zero deselects the group.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <external/line.hpp>
#include <external/pin_change_group.hpp>


using namespace mhaa::external;

class FakeLine final : public Line
{
public:
    bool configure(Trigger trigger) override { return trigger == Trigger::RisingEdge; }
    void enable() override { enabled = true; }
    void disable() override { enabled = false; }
    bool pending() const override { return flagged; }
    void clear_pending() override { flagged = false; }

    bool enabled = false;
    bool flagged = true;
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
