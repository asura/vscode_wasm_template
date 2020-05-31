#ifndef INTERFACE_H
#define INTERFACE_H

// JavaScript側に公開する関数群

#include <emscripten.h>

#include <cstddef>  // size_t
#include <cstdint>  // uint8_t

extern "C"
{
    /// 指定された2つの整数値を加算した結果を返す
    int EMSCRIPTEN_KEEPALIVE add(int a, int b);

    /// 指定された3つの整数値を加算し、結果値の後ろに指定テキストを追加した文字列を返す
    const char* EMSCRIPTEN_KEEPALIVE sum(int a, int b, int c, const char* text);
    const char* EMSCRIPTEN_KEEPALIVE sumFromText(const char* text);

    /// Shapefile内容を読んで件数を返す
    size_t EMSCRIPTEN_KEEPALIVE getShapefileNRecord(const uint8_t* buffer, size_t buffer_size);
};

#endif  // INTERFACE_H
