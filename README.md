
# FFF Plus

## 日本語

FFF Plusは[Fake Function Framewark(FFF)](https://github.com/meekrosoft/fff)をC++向けに機能拡張したものです。FFFは、宣言済みで未実装の関数のFake（スタブ）の生成を簡略化するテスト補助マクロです。
FFF Plusでは、以下の機能を追加しています。

- 例外指定子付きの自由関数のFakeを生成可能
- 具象クラスのメンバ関数のFakeを生成可能

## 使い方

### インストール

以下のコマンドでfffと一緒にダウンロードできます。

```
git clone --recursive https://github.com/muraak/fff_plus.git
```

クローン時に生成された、fff_plusディレクトリをインクルードパスに設定すれば準備完了です。

### 主な使用例

- [例外指定子つきの自由関数のFakeを作成する](#例外指定子つきの自由関数のFakeを作成する)
- [具象クラスのメンバ関数のFakeを作成する](#具象クラスのメンバ関数のFakeを作成する)
- [Fakeを複数のソースで共有する](#Fakeを複数のソースで共有する)

#### 例外指定子つきの自由関数のFakeを作成する

`FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC`および`FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC`マクロを利用します。

例）

以下`lib.h`に宣言された関数のFakeを、テストコードを含む`example_test.cpp`に生成します。

```cpp
// lib.h
...
int     Ex1_valueFuncA(int a) noexcept; // 例外指定子つき
int     Ex1_valueFuncA0() noexcept; // 引数なし
void    Ex1_voidFuncA(int a) noexcept; // void型
int     Ex1_valueFuncB(int a, int b); // 例外指定子なし
```

```cpp
// example_test.cpp
...
#include "fff_plus.h"
#include "lib.h"
...
// 例外指定子付き関数のFake作成例
// 引数は8個まで指定可能です。
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int/*戻り値型*/, noexcept/*例外指定子*/, Ex1_valueFuncA/*関数名*/, int/*引数型（1つ目）*/);
// 例外指定子付き関数のFake作成例
// 引数なしも指定可能です。
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int/*戻り値型*/, noexcept/*例外指定子*/, Ex1_valueFuncA0/*関数名*//*引数なし*/);
// 例外指定子付き関数のFake作成例
// 例外指定子がない場合は空白とします。
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, /*例外指定子なし*/, Ex1_valueFuncB, int, int);
// void型例外指定子付き関数のFake作成例
// void型関数はFAKE_VOID_FUNC_WITH_EXCEPTION_SPECマクロを使用します。
FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept/*例外指定子*/, Ex1_voidFuncA/*関数名*/, int/*引数型（1つ目）*/);
```

以下、テスト関数`test()`で検証する関数`testee_func()`は、中でFakeを作成した`lib.h`のライブラリ関数をコールしています。Fakeを作成することで、当該ライブラリ関数のコール回数、呼び出し時の引数の値などを検証することができます。

```cpp
// example_test.cpp
...
// テスト関数
void test(void)
{
    // 以下のマクロでFakeの呼出し履歴等をリセットすることができます
    // マクロの引数にはリセット対象の関数名を指定します
    RESET_FAKE(Ex1_valueFuncA);
    RESET_FAKE(Ex1_valueFuncA0);
    RESET_FAKE(Ex1_valueFuncB);
    RESET_FAKE(Ex1_voidFuncA);

    ...

    testee_func(); // 中でlib.hの関数をコールするテスト対象です
    
    // RESET_FAKEの引数に指定した名前_fake構造体のメンバにアクセスすることで
    // コール回数やコール時の引数の値を検証できます（FFFの仕様と同じです）
    // Fakeの呼出し回数の検証
    ASSERT_EQ(1, Ex1_valueFuncA_fake.call_count);
    ASSERT_EQ(1, Ex1_valueFuncA0_fake.call_count);
    ASSERT_EQ(1, Ex1_valueFuncB_fake.call_count);
    ASSERT_EQ(1, Ex1_voidFuncA_fake.call_count);

    ...
}
```

#### 具象クラスのメンバ関数のFakeを作成する

#### Fakeを複数のソースで共有する


以上
