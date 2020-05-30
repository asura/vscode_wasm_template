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
1. ブラウザから http://localhost:5500/c%2B%2B/ebuild/src/sample.html にアクセス

## 参考サイト

* [trzeci/emscripten - Docker Hub](https://hub.docker.com/r/trzeci/emscripten)
* [1年間本番環境で WebAssembly ( by Emscripten )を使ってきた中で生じた問題とその解決策 - Qiita](https://qiita.com/goccy/items/1b2ff919b4b5e5a06110)
* [EmscriptenとCMakeでのビルド方法](https://gist.github.com/faithandbrave/9b3d439d135e63abdbe7)
* [【Jasmine】Promiseのテスト方法 - 開発覚書はてな版](https://kakkoyakakko2.hatenablog.com/entry/2018/06/05/003000)
* [XMLHttpRequest する関数を Promise を返すように修正するチュートリアルをやってみた | deadwood](https://www.d-wood.com/blog/2017/02/13_8809.html)
