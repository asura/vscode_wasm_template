# WASM C++ビルド環境

## ビルド方法

```
$ mkdir -p ebuild
$ cd ebuild
$ emcmake cmake .. -DCMAKE_BUILD_TYPE=Debug
$ make
```

## 動かしてみる

1. Live Serverを起動
1. ブラウザから http://localhost:5500/sample.html にアクセス
