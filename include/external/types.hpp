#ifndef MHAA_EXTERNAL_TYPES_HPP
#define MHAA_EXTERNAL_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace external
    {
        enum class Trigger
        {
            LowLevel,
            AnyChange,
            FallingEdge,
            RisingEdge
        };

        using PinMask = uint32_t;
    }
}

#endif
