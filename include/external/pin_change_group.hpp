#ifndef MHAA_EXTERNAL_PIN_CHANGE_GROUP_HPP
#define MHAA_EXTERNAL_PIN_CHANGE_GROUP_HPP

#include <external/types.hpp>

namespace mhaa
{
    namespace external
    {
        /** @brief A group of sources selectable by logical mask bits. */
        class PinChangeGroup
        {
        public:
            virtual ~PinChangeGroup() = default;

            /** @brief Selects active sources. Rejected masks leave the selection unchanged. */
            virtual bool set_mask(PinMask mask) = 0;
            virtual void enable() = 0;
            virtual void disable() = 0;
            virtual bool pending() const = 0;
            virtual void clear_pending() = 0;
        };
    }
}

#endif
