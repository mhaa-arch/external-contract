#include <external/line.hpp>

using namespace mhaa::external;

class Incomplete final : public Line
{
public:
    void enable() override;
    void disable() override;
    bool pending() const override;
    void clear_pending() override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
