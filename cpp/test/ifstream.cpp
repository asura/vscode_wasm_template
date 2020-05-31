#include "config.h"

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

#include <catch2/catch.hpp>
#include <filesystem>
#include <fstream>

TEST_CASE("ファイルの読み込み")
{
#ifdef EMSCRIPTEN
    SECTION("MEMFS")
    {
        // Emscripten環境だとパス名に "+" があると失敗する
        const auto base_path = std::string("/data_memfs");
        const auto path = base_path + "/sum_input";

        // ファイルシステム作成
        EM_ASM_({
            const path = UTF8ToString($0, $1);
            FS.mkdir(path);
            FS.mount(MEMFS, [], path);
        },
                base_path.c_str(), base_path.length());

        // ファイル内容を出力
        {
            std::ofstream ofs(path);
            ofs << "1\n2 3\ntest\n";
        }

        std::ifstream ifs(path);
        REQUIRE(!!ifs);

        const std::string file_contents((std::istreambuf_iterator<char>(ifs)),
                                        std::istreambuf_iterator<char>());

        CHECK(file_contents == std::string("1\n2 3\ntest\n"));
    }

    SECTION("IDBFS")
    {
        const auto base_path = std::string("/data_idbfs");
        const auto path = base_path + "/sum_input";

        if (!std::filesystem::exists(path))
        {
            {
                std::ofstream ofs(path);
                ofs << "1\n2 3\ntest\n";
            }

            // ファイルを書き出し
            EM_ASM(
                FS.syncfs(
                    false, function(err) {
                        if (err)  // error
                        {
                            console.error(err);
                        }
                    });

            );
        }
        REQUIRE(std::filesystem::exists(path));

        std::ifstream ifs(path);
        REQUIRE(!!ifs);

        const std::string file_contents((std::istreambuf_iterator<char>(ifs)),
                                        std::istreambuf_iterator<char>());

        CHECK(file_contents == std::string("1\n2 3\ntest\n"));
    }
#else
    const auto base_path = std::string(PROJECT_SOURCE_DIR) + "/../data";
    const auto path = base_path + "/sum_input";

    std::ifstream ifs(path);
    REQUIRE(!!ifs);

    const std::string file_contents((std::istreambuf_iterator<char>(ifs)),
                                    std::istreambuf_iterator<char>());

    CHECK(file_contents == std::string("1\n2 3\ntest\n"));
#endif
}
