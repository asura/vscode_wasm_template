#ifndef INTERFACE_H
#define INTERFACE_H

// JavaScript側に公開する関数群

#include <emscripten.h>

extern "C"
{
    /// 指定された2つの整数値を加算した結果を返す
    int EMSCRIPTEN_KEEPALIVE add(int a, int b);
};

#endif  // INTERFACE_H
