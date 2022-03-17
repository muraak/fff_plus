
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

> NOTE：
 本章で紹介するコードはすべて`example`フォルダにあり，以下の手順で実際にビルド・実行できます。
    - コマンド`sh build.sh`でビルド
    - `./build/example`で実行
    - 無事に実行されると`ALL PASSED!!`が標準出力されます
#### 例外指定子つきの自由関数のFakeを作成する

以下のマクロを利用します。

- `FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(戻り値型, <例外指定子|なければ空白>, 関数名<, 引数型1, ...>)`
- `FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(<例外指定子|なければ空白>, 関数名<, 引数型1, ...>)`

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

以下、テスト関数`test()`で検証する関数`testee_func()`は、関数の中でFakeを作成した`lib.h`のライブラリ関数をコールしています。Fakeを作成することで、当該ライブラリ関数のコール回数、呼び出し時の引数の値などを検証することができます。

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

以下のマクロを利用します。

- `FAKE_VALUE_MEMBER_FUNC(戻り値型, <例外指定子|なければ空白>, クラス名, 関数名<, 引数型1, ...>)`
- `FAKE_VOID_MEMBER_FUNC(<例外指定子|なければ空白>, クラス名, 関数名<, 引数型1, ...>)`

例）

以下`lib.h`に宣言されたメンバ関数のFakeを、テストコードを含む`example_test.cpp`に生成します。

```cpp
// lib.h
...
/** 
 * @brief Fake作成対象の具象クラス
 * @details 
 * テスト対象のtestee.cppで使用されますが
 * 宣言のみで実装がまだ存在しません。
 * fff_plusを利用して各メンバ関数のFakeを作成する対象です。
 */
class ExClass
{
public:
    int valueMethodA(int a) noexcept; // 例外指定子つき
    int valueMethodA0() noexcept; // 引数なし
    void voidMethodA(int a) noexcept; // void型
    int valueMethodB(int a, int b); // 例外指定子なし
};
```

```cpp
// example_test.cpp
...
#include "fff_plus.h"
#include "lib.h"
...
// メンバ関数のFake作成例
// 引数は8個まで指定可能です。
FAKE_VALUE_MEMBER_FUNC(int/*戻り値型*/, noexcept/*例外指定子*/, ExClass/*クラス名*/, valueMethodA/*関数名*/, int/*引数型（1つ目）*/);
// メンバ関数のFake作成例
// 引数なしも指定可能です。
FAKE_VALUE_MEMBER_FUNC(int/*戻り値型*/, noexcept/*例外指定子*/, ExClass/*クラス名*/, valueMethodA0/*関数名*//*引数なし*/);
// メンバ関数のFake作成例
// 例外指定子がない場合は空白とします。
FAKE_VALUE_MEMBER_FUNC(int, /*例外指定子なし*/, ExClass, valueMethodB, int, int);
// void型メンバ関数のFake作成例
// void型関数はFAKE_VOID_MEMBER_FUNCマクロを使用します。
FAKE_VOID_MEMBER_FUNC(noexcept/*例外指定子*/, ExClass/*クラス名*/, voidMethodA/*関数名*/, int/*引数型（1つ目）*/);
```

以下、テスト関数`test()`で検証する関数`testee_func()`は、関数の中でFakeを作成した`lib.h`のライブラリ関数をコールしています。Fakeを作成することで、当該ライブラリ関数のコール回数、呼び出し時の引数の値などを検証することができます。

```cpp
// example_test.cpp
...
// テスト関数
void test(void)
{
    // 以下のマクロでFakeの呼出し履歴等をリセットすることができます
    ...
    // メンバ関数のFakeは引数にFake+クラス名+関数名を指定します
    RESET_FAKE(FakeExClassvalueMethodA);
    RESET_FAKE(FakeExClassvalueMethodA0);
    RESET_FAKE(FakeExClassvalueMethodB);
    RESET_FAKE(FakeExClassvoidMethodA);

    ...

    testee_func(); // 中でlib.hの関数をコールするテスト対象です
    
    // RESET_FAKEの引数に指定した名前_fake構造体のメンバにアクセスすることで
    // コール回数やコール時の引数の値を検証できます（FFFの仕様と同じです）
    // Fakeの呼出し回数の検証
    ...
    ASSERT_EQ(1, FakeExClassvalueMethodA_fake.call_count);
    ASSERT_EQ(1, FakeExClassvalueMethodA0_fake.call_count);
    ASSERT_EQ(1, FakeExClassvalueMethodB_fake.call_count);
    ASSERT_EQ(1, FakeExClassvoidMethodA_fake.call_count);
    ...
}
```


#### Fakeを複数のソースで共有する

FAKEの「宣言」マクロと「定義」マクロを使用します。
FAKEの「宣言」を記述したヘッダファイルをインクルードすることで，複数のソースでFAKEを共有したり，再利用を考慮してFAKEのリソースをテストコードから分離することができます。

- FAKEの「宣言」マクロ
    - `DECLARE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(戻り値型, <例外指定子|なければ空白>, 関数名<, 引数型1, ...>)`
    - `DECLARE_FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(<例外指定子|なければ空白>, 関数名<, 引数型1, ...>)`
    - `DECLARE_FAKE_VALUE_MEMBER_FUNC(戻り値型, <例外指定子|なければ空白>, クラス名, 関数名<, 引数型1, ...>)`
    - `DECLARE_FAKE_VOID_MEMBER_FUNC(<例外指定子|なければ空白>, クラス名, 関数名<, 引数型1, ...>)`

例）

以下，`lib_fake.h`では，FAKEの「宣言」，`lib_fake.cpp`では，FAKEの「定義」を行っています。

```cpp
// lib_fake.h
#ifndef LIB_FAKE_H
#define LIB_FAKE_H
#include "fff_plus.h"
#include "lib.h"

// メンバ関数のFake作成例
// 引数は8個まで指定可能です。
DECLARE_FAKE_VALUE_MEMBER_FUNC(int/*戻り値型*/, noexcept/*例外指定子*/, ExClass2/*クラス名*/, valueMethodA/*関数名*/, int/*引数型（1つ目）*/);
// メンバ関数のFake作成例
// 引数なしも指定可能です。
DECLARE_FAKE_VALUE_MEMBER_FUNC(int/*戻り値型*/, noexcept/*例外指定子*/, ExClass2/*クラス名*/, valueMethodA0/*関数名*//*引数なし*/);
// メンバ関数のFake作成例
// 例外指定子がない場合は空白とします。
DECLARE_FAKE_VALUE_MEMBER_FUNC(int, /*例外指定子なし*/, ExClass2, valueMethodB, int, int);
// void型メンバ関数のFake作成例
// void型関数はFAKE_VOID_MEMBER_FUNCマクロを使用します。
DECLARE_FAKE_VOID_MEMBER_FUNC(noexcept/*例外指定子*/, ExClass2/*クラス名*/, voidMethodA/*関数名*/, int/*引数型（1つ目）*/);

// 例外指定子付き関数のFake作成例
// 引数は8個まで指定可能です。
DECLARE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int/*戻り値型*/, noexcept/*例外指定子*/, Ex2_valueFuncA/*関数名*/, int/*引数型（1つ目）*/);
// 例外指定子付き関数のFake作成例
// 引数なしも指定可能です。
DECLARE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int/*戻り値型*/, noexcept/*例外指定子*/, Ex2_valueFuncA0/*関数名*//*引数なし*/);
// 例外指定子付き関数のFake作成例
// 例外指定子がない場合は空白とします。
DECLARE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, /*例外指定子なし*/, Ex2_valueFuncB, int, int);
// void型例外指定子付き関数のFake作成例
// void型関数はFAKE_VOID_MEMBER_FUNCマクロを使用します。
DECLARE_FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept/*例外指定子*/, Ex2_voidFuncA/*関数名*/, int/*引数型（1つ目）*/);

#endif // LIB_FAKE_H
```

```cpp
// lib_fake.cpp
#include "lib_fake.h"

// メンバ関数のFake作成例
// 引数は8個まで指定可能です。
DEFINE_FAKE_VALUE_MEMBER_FUNC(int/*戻り値型*/, noexcept/*例外指定子*/, ExClass2/*クラス名*/, valueMethodA/*関数名*/, int/*引数型（1つ目）*/);
// メンバ関数のFake作成例
// 引数なしも指定可能です。
DEFINE_FAKE_VALUE_MEMBER_FUNC(int/*戻り値型*/, noexcept/*例外指定子*/, ExClass2/*クラス名*/, valueMethodA0/*関数名*//*引数なし*/);
// メンバ関数のFake作成例
// 例外指定子がない場合は空白とします。
DEFINE_FAKE_VALUE_MEMBER_FUNC(int, /*例外指定子なし*/, ExClass2, valueMethodB, int, int);
// void型関数はFAKE_VOID_MEMBER_FUNCマクロを使用します。
DEFINE_FAKE_VOID_MEMBER_FUNC(noexcept/*例外指定子*/, ExClass2/*クラス名*/, voidMethodA/*関数名*/, int/*引数型（1つ目）*/);

// 例外指定子付き関数のFake作成例
// 引数は8個まで指定可能です。
DEFINE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int/*戻り値型*/, noexcept/*例外指定子*/, Ex2_valueFuncA/*関数名*/, int/*引数型（1つ目）*/);
// 例外指定子付き関数のFake作成例
// 引数なしも指定可能です。
DEFINE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int/*戻り値型*/, noexcept/*例外指定子*/, Ex2_valueFuncA0/*関数名*//*引数なし*/);
// 例外指定子付き関数のFake作成例
// 例外指定子がない場合は空白とします。
DEFINE_FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, /*例外指定子なし*/, Ex2_valueFuncB, int, int);
// void型例外指定子付き関数のFake作成例
// void型関数はFAKE_VOID_MEMBER_FUNCマクロを使用します。
DEFINE_FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept/*例外指定子*/, Ex2_voidFuncA/*関数名*/, int/*引数型（1つ目）*/);
```

`testee.cpp`では`lib_fake.h`をインクルードし，上記FAKEを利用しています。

```cpp
// example_test.cpp
...
#include "lib_fake.h"
#include "testee.h"

...
// テスト関数
void test(void)
{
    // 以下のマクロでFakeの呼出し履歴等をリセットすることができます
    // マクロの引数にはリセット対象の関数名を指定します
    ...

    // 外部で「定義」したFakeも「宣言」をインクルードすることで同様に利用できます
    RESET_FAKE(Ex2_valueFuncA);
    RESET_FAKE(Ex2_valueFuncA0);
    RESET_FAKE(Ex2_valueFuncB);
    RESET_FAKE(Ex2_voidFuncA);
    RESET_FAKE(FakeExClass2valueMethodA);
    RESET_FAKE(FakeExClass2valueMethodA0);
    RESET_FAKE(FakeExClass2valueMethodB);
    RESET_FAKE(FakeExClass2voidMethodA);

    testee_func(); // 中でlib.hの関数をコールするテスト対象です
    
    // RESET_FAKEの引数に指定した名前_fake構造体のメンバにアクセスすることで
    // コール回数やコール時の引数の値を検証できます（FFFの仕様と同じです）
    // Fakeの呼出し回数の検証
    ...

    // 外部で「定義」したFake
    ASSERT_EQ(1, Ex2_valueFuncA_fake.call_count);
    ASSERT_EQ(1, Ex2_valueFuncA0_fake.call_count);
    ASSERT_EQ(1, Ex2_valueFuncB_fake.call_count);
    ASSERT_EQ(1, Ex2_voidFuncA_fake.call_count);

    ASSERT_EQ(1, FakeExClass2valueMethodA_fake.call_count);
    ASSERT_EQ(1, FakeExClass2valueMethodA0_fake.call_count);
    ASSERT_EQ(1, FakeExClass2valueMethodB_fake.call_count);
    ASSERT_EQ(1, FakeExClass2voidMethodA_fake.call_count);


    printf("ALL PASSED!!\n");
}

int main(void)
{
    test(); // テスト実行
    return 0;
}

```

このように，Fake「宣言」と「定義」を利用することで具体的に以下のメリットがあります。

- テストコードのソースが増え，`testee.cpp`とは別のファイル`testee_part2.cpp`を追加した場合も，両方のファイルでFAKEを利用可能
- これらのリソース`lib_fake.h`，`lib_fake.cpp`は，同じスタブを利用する，他のテストに再利用可能

以上
