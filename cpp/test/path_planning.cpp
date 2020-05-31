#include "path_planning.h"

#include <catch2/catch.hpp>

SCENARIO("クローズドリストの利用シナリオ")
{
    GIVEN("クローズドリストを用意する")
    {
        ClosedList<int, double> sut;

        WHEN("ノードを追加する")
        {
            const auto insert_result = sut.insert(1, 2.0);
            REQUIRE(insert_result == true);

            THEN("当該ノードを検索して取得できる")
            {
                const auto find_result = sut.find(1);
                REQUIRE(find_result);
                CHECK(*find_result == 2.0);
            }

            THEN("未知ノードは検索しても失敗する")
            {
                const auto find_result = sut.find(10);
                REQUIRE(!find_result);
            }
        }
    }
}

SCENARIO("オープンリストの利用シナリオ")
{
    GIVEN("オープンリストを用意する")
    {
        OpenList<int, int> sut;

        WHEN("この時点ではリストからノードを取り出せない")
        {
            CHECK(!sut.dequeue());
        }

        WHEN("リストにノードを1つ追加する")
        {
            sut.enqueue(1, 10);

            THEN("リストから1つ取り出すことができる")
            {
                const auto result = sut.dequeue();
                REQUIRE(result);
                CHECK(result->key == 1);
                CHECK(result->cost == 10);

                AND_THEN("取り出した後はもう取り出せない")
                {
                    CHECK(!sut.dequeue());
                }
            }
        }

        WHEN("リストにノードを2つ追加する")
        {
            sut.enqueue(2, 20);
            sut.enqueue(3, 30);

            THEN("リストから小さな値のノードを取り出せる")
            {
                const auto result = sut.dequeue();
                REQUIRE(result);
                CHECK(result->key == 2);
                CHECK(result->cost == 20);

                THEN("リストから大きな値のノードを取り出せる")
                {
                    const auto result2 = sut.dequeue();
                    REQUIRE(result2);
                    CHECK(result2->key == 3);
                    CHECK(result2->cost == 30);

                    AND_THEN("もう取り出せない")
                    {
                        CHECK(!sut.dequeue());
                    }
                }
            }
        }
    }
}
