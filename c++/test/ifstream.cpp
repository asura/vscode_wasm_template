#include "config.h"

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#include <catch2/catch.hpp>
#include <fstream>

TEST_CASE("ファイルの読み込み")
{
#ifdef EMSCRIPTEN
    // Emscripten環境だとパス名に "+" があると失敗する
    const auto base_path = std::string("/data");
#else
    const auto base_path = std::string(PROJECT_SOURCE_DIR) + "/../data";
#endif
    const auto path = base_path + "/sum_input";
    INFO("path=" << path);

#ifdef EMSCRIPTEN
    // ファイルシステム作成
    EM_ASM_({
        const path = UTF8ToString($0, $1 + 1);
        console.log(path);
        FS.mkdir(path);
        FS.mount(MEMFS, [], path);
    },
            base_path.c_str(), base_path.length());

    // ファイル内容を出力
    {
        std::ofstream ofs(path);
        ofs << "1\n2 3\ntest\n";
    }

    // ファイルを書き出し
    EM_ASM(
        // 書き込み (false は省略できる)
        FS.syncfs(false, function(err){}););
#endif

    std::ifstream ifs(path);
    REQUIRE(!!ifs);

    const std::string file_contents((std::istreambuf_iterator<char>(ifs)),
                                    std::istreambuf_iterator<char>());

    CHECK(file_contents == std::string("1\n2 3\ntest\n"));
}
