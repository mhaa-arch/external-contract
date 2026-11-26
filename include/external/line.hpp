#ifndef MHAA_EXTERNAL_LINE_HPP
#define MHAA_EXTERNAL_LINE_HPP

#include <external/types.hpp>

namespace mhaa
{
    namespace external
    {
        /** @brief One external interrupt line bound to a logical source. */
        class Line
        {
        public:
            virtual ~Line() = default;
            virtual bool configure(Trigger trigger) = 0;
            virtual void enable() = 0;
            virtual void disable() = 0;
            virtual bool pending() const = 0;
            virtual void clear_pending() = 0;
        };
    }
}

#endif
