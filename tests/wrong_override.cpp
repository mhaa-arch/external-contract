#include <external/line.hpp>

using namespace mhaa::external;

class WrongOverride final : public Line
{
public:
    bool configure(Trigger trigger) const override;
};
