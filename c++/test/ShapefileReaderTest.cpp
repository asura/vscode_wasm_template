#include "ShapefileReader.h"
#include "config.h"

#include <catch2/catch.hpp>

TEST_CASE(
    "ShapefileReader::read",
    "[ShapefileReader]")
{
    SECTION("存在するファイル")
    {
        ShapefileReader sut(std::string(PROJECT_SOURCE_DIR) + "/test/P32-14_40.shp");
        auto result = sut.read();

        REQUIRE(!result.has_value());

        CHECK(sut.size() == 19448);

        const auto file_header = sut.fileHeader();
        CHECK(file_header.file_code == 9994);
        CHECK(file_header.not_in_use_1 == 0);
        CHECK(file_header.not_in_use_2 == 0);
        CHECK(file_header.not_in_use_3 == 0);
        CHECK(file_header.not_in_use_4 == 0);
        CHECK(file_header.not_in_use_5 == 0);
        CHECK(file_header.file_length == 19448 / 2);
        CHECK(file_header.version == 1000);
        CHECK(file_header.shape_type == 1);
        CHECK(file_header.x_min == 130.179824);
        CHECK(file_header.y_min == 33.007735);
        CHECK(file_header.x_max == 135.773125);
        CHECK(file_header.y_max == 34.989965);
        CHECK(file_header.z_min == 0.0);
        CHECK(file_header.z_max == 0.0);
        CHECK(file_header.m_min == 0.0);
        CHECK(file_header.m_max == 0.0);

        const auto p = sut.recordAs<shapefile::Point>(1);
        CHECK(p.shape_type == 1);
        CHECK(p.x == 130.873257);
        CHECK(p.y == 33.885578);
    }

    SECTION("存在しないファイル")
    {
        ShapefileReader sut("not exists");
        auto result = sut.read();

        REQUIRE(result.has_value());
        CHECK(result.value() == std::io_errc::stream);
    }
}