#include "catch2/catch.hpp"
#include "config.h"

#include <fstream>
#include <iostream>
#include <sstream>

TEST_CASE("ファイル読み込み & 合計値表示")  // ローカルファイル読み込みはブラウザ側で例外発生
{
    // std::ifstream ifs(std::string(PROJECT_SOURCE_DIR) + "/test/sum_input");
    // REQUIRE(!!ifs);

    int a, b, c;
    std::string s;

    // ifs >> a >> b >> c;
    // ifs >> s;
    a = 1;
    b = 2;
    c = 3;
    s = "test";

    std::ostringstream oss;
    oss << a + b + c << " " << s;

    CHECK(oss.str() == "6 test");
}
