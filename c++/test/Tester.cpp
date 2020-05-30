#define CATCH_CONFIG_DEFAULT_REPORTER "junit"
#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

TEST_CASE("true")
{
    CHECK(1 == 1);
}

int main(int the_argc, char** the_argv) noexcept
{
    try
    {
        const int result = Catch::Session().run(the_argc, the_argv);

        return result;
    }
    catch (...)
    {
        return -1;
    }
}
