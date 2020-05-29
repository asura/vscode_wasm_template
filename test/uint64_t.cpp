#include <catch2/catch.hpp>
#include <cstdint>

namespace
{
uint16_t div16(uint16_t the_number)
{
    return the_number / 1000;
}

uint32_t div32(uint32_t the_number)
{
    return the_number / 1000;
}

uint64_t div(uint64_t the_number)
{
    return the_number / 1000;
}

uint16_t dec16(uint16_t the_number)
{
    return the_number - 1;
}

uint32_t dec32(uint32_t the_number)
{
    return the_number - 1;
}

uint64_t dec(uint64_t the_number)
{
    return the_number - 1;
}
}  // namespace

TEST_CASE("uint64_t除算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(div(0xFF) == 0);
        CHECK(div(0xFFFF) == 65);
        CHECK(div(0xFFFFFFFF) == 4294967);
        CHECK(div(0xFFFFFFFFFFFFFFFFL) == 18446744073709551);
    }
}

TEST_CASE("uint32_t除算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(div32(0xFF) == 0);
        CHECK(div32(0xFFFF) == 65);
        CHECK(div32(0xFFFFFFFF) == 4294967);
    }
}

TEST_CASE("uint16_t除算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(div16(0xFF) == 0);
        CHECK(div16(0xFFFF) == 65);
    }
}

TEST_CASE("uint64_t減算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(dec(0xFF) == 0xFE);
        CHECK(dec(0xFFFF) == 0xFFFE);
        CHECK(dec(0xFFFFFFFF) == 0xFFFFFFFE);
        CHECK(dec(0xFFFFFFFFFFFFFFFFL) == 0xFFFFFFFFFFFFFFFEL);
    }
}

TEST_CASE("uint32_t減算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(dec32(0xFF) == 0xFE);
        CHECK(dec32(0xFFFF) == 0xFFFE);
        CHECK(dec32(0xFFFFFFFF) == 0xFFFFFFFE);
    }
}

TEST_CASE("uint16_t減算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(dec16(0xFF) == 0xFE);
        CHECK(dec16(0xFFFF) == 0xFFFE);
    }
}
