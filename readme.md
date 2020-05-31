# WASM C++ビルド環境

## ビルド方法

```
$ cd c++
$ mkdir -p ebuild
$ cd ebuild
$ emcmake cmake .. -DCMAKE_BUILD_TYPE=Debug
$ make
```

## 動かしてみる

1. Live Serverを起動
1. ブラウザから http://localhost:5500/c%2B%2B/ebuild/src/sample.html にアクセス (Hello World)
1. ブラウザから http://localhost:5500/c%2B%2B/ebuild/test/Tester_sample.html にアクセス (Catch2のテスト結果)
1. ブラウザから http://localhost:5500/js/test/ にアクセス (Jasmineのテスト結果)

## 参考にしたサイト

* [trzeci/emscripten - Docker Hub](https://hub.docker.com/r/trzeci/emscripten)
* [1年間本番環境で WebAssembly ( by Emscripten )を使ってきた中で生じた問題とその解決策 - Qiita](https://qiita.com/goccy/items/1b2ff919b4b5e5a06110)
* [EmscriptenとCMakeでのビルド方法](https://gist.github.com/faithandbrave/9b3d439d135e63abdbe7)
* [【Jasmine】Promiseのテスト方法 - 開発覚書はてな版](https://kakkoyakakko2.hatenablog.com/entry/2018/06/05/003000)
* [XMLHttpRequest する関数を Promise を返すように修正するチュートリアルをやってみた | deadwood](https://www.d-wood.com/blog/2017/02/13_8809.html)
* [バイナリデータの送信と受信 - XMLHttpRequest | MDN](https://developer.mozilla.org/ja/docs/XMLHttpRequest/Sending_and_Receiving_Binary_Data)
* [サーバからのデータ取得 - ウェブ開発を学ぶ | MDN](https://developer.mozilla.org/ja/docs/Learn/JavaScript/Client-side_web_APIs/Fetching_data)
* [File System API — Emscripten 1.39.14 documentation](https://emscripten.org/docs/api_reference/Filesystem-API.html)
* [ホイール欲しい ハンドル欲しい » Emscripten C++/OpenGL ES 2.0 (9) C関数呼び出しと FileSystem](https://wlog.flatlib.jp/item/1709)
* [Emscripten(C/C++) と JavaScript 間の関数呼び出し方法 まとめ | Sumire Lab Docs](https://www.sumiretool.net/docs/tech/emscriptencc-%E3%81%A8-javascript-%E9%96%93%E3%81%AE%E9%96%A2%E6%95%B0%E5%91%BC%E3%81%B3%E5%87%BA%E3%81%97%E6%96%B9%E6%B3%95-%E3%81%BE%E3%81%A8%E3%82%81/)
