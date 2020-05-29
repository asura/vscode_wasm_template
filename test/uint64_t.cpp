#include <catch2/catch.hpp>
#include <cstdint>

namespace
{
uint64_t f(uint64_t the_number)
{
    return the_number / 1000;
}
}  // namespace

TEST_CASE("uint64_tを使用可")
{
    CHECK(f(0xFF) == 0);
    CHECK(f(0xFFFF) == 65);
    CHECK(f(0xFFFFFFFF) == 4294967);
    CHECK(f(0xFFFFFFFFFFFFFFFFL) == 18446744073709551);
}
