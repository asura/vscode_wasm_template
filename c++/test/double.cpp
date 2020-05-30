#include <catch2/catch.hpp>
#include <cmath>

namespace
{
double div(double the_number)
{
    return the_number / 1000;
}

double dec(double the_number)
{
    return the_number - 1;
}
}  // namespace

TEST_CASE("処理系は IEC 559 に準拠")
{
    SECTION("float")
    {
        CHECK(std::numeric_limits<float>::is_iec559);
    }
    SECTION("double")
    {
        CHECK(std::numeric_limits<double>::is_iec559);
    }
}

TEST_CASE("三角関数")
{
    CHECK(sin(0.0) == 0.0);
    CHECK(cos(0.0) == 1.0);
}

TEST_CASE("double除算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(div(0xFF) == 0.255);
        CHECK(div(0xFFFF) == 65.535);
        CHECK(div(0xFFFFFFFF) == Approx(4294967.295));
        CHECK(div(0xFFFFFFFFFFFFFFFFL) == Approx(18446744073709551.0));
    }
}

TEST_CASE("double減算")
{
    for (int i = 0; i < 1000; ++i)
    {
        CHECK(dec(0xFF) == 0xFE);
        CHECK(dec(0xFFFF) == 0xFFFE);
        CHECK(dec(0xFFFFFFFF) == 0xFFFFFFFE);
        CHECK(dec(0xFFFFFFFFFFFFFFFFL) == 0xFFFFFFFFFFFFFFFEL);
    }
}
