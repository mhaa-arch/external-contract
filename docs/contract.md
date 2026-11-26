# External Interrupt contract

## Line and group identity

[Line](../include/external/line.hpp) represents one logical interrupt source. `configure` accepts an available level or edge trigger. Rejection keeps the previous trigger. [PinChangeGroup](../include/external/pin_change_group.hpp) represents up to 32 group-local slots, with bit zero selecting slot zero. A zero mask selects no sources. Reject unsupported mask bits as a whole and preserve the previous selection.

## Delivery and pending flags

Configure before enabling, or use a resource that was configured by composition. Enable and disable control delivery. Read `pending()` to observe the flag and call `clear_pending()` to acknowledge it. An active source can assert it again. Pending reports the represented line or group condition, with callback registration and per-member event decoding left to integration.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`external/types.hpp`](../include/external/types.hpp).
