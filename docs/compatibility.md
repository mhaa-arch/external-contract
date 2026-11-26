# Porting the External Interrupt Contract

The composition selects the object for the intended line or group. Hardware Definitions describe pin routing, trigger support and the number of interrupt sources. The Adapter maps a compatible subset into the common trigger types or group slots. Edge detection and delivery behavior depend on the hardware. A group-wide flag may report only that at least one selected pin changed.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
