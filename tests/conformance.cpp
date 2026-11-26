#include <external/line.hpp>
#include <external/pin_change_group.hpp>

#include <cassert>

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

class FakeGroup final : public PinChangeGroup
{
public:
    bool set_mask(PinMask mask) override
    {
        if (mask & UINT32_C(0x7FFFFFFF))
        {
            return false;
        }
        selected = mask;
        return true;
    }
    void enable() override { enabled = true; }
    void disable() override { enabled = false; }
    bool pending() const override { return flagged; }
    void clear_pending() override { flagged = false; }

    PinMask selected = 0;
    bool flagged = false;
    bool enabled = false;
};

int main()
{
    FakeLine fake;
    Line &line = fake;
    assert(!line.configure(Trigger::LowLevel));
    assert(line.configure(Trigger::RisingEdge));
    line.enable();
    assert(fake.enabled && line.pending());
    line.clear_pending();
    assert(!line.pending());
    line.disable();
    assert(!fake.enabled);
    FakeGroup fake_group;
    PinChangeGroup &group = fake_group;
    assert(group.set_mask(UINT32_C(0x80000000)));
    assert(!group.set_mask(1) && fake_group.selected == UINT32_C(0x80000000));
    assert(group.set_mask(0) && fake_group.selected == 0);
}
