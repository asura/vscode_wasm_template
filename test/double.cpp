#include <catch2/catch.hpp>
#include <cmath>

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