
# FFF Plus

## 日本語

FFF Plusは[Fake Function Framewark(FFF)](https://github.com/meekrosoft/fff)をC++向けに機能拡張したものです。FFFは、宣言済みで未実装の関数のFake（スタブ）の生成を簡略化するテスト補助マクロです。
FFF Plusでは、以下の機能を追加しています。

- 例外指定子付きの自由関数のFakeを生成可能
- 具象クラスのメンバ関数のFakeを生成可能

## 使い方

### FFF Plusを利用する

利用するソースまたはヘッダファイルで、`fff_plus.h`をインクルードするだけです。

例)

```{*.cpp}
// test_sample.cpp
#include "fff_plus.h"
```


### void型の自由関数のFakeを例外指定子付きで定義する

`FAKE_VOID_FUNC0_WITH_EXCEPTION_SPEC`マクロを利用します。

例）

```{*.cpp}
// lib.h
void void_func0_0(void) noexcept; // Fakeの作成対象の関数宣言
...
// test_sample.cpp
#include <cassert>
#include "fff_plus.h"
...
DEFINE_FFF_GLOBALS;
...
FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept, void_func0_0); // void_func0_0のFakeを定義

void do_test(void)
{
    // Fakeの操作はFFFと同様
    RESET_FAKE(void_func0_0); // Fakeをリセット
    test_target(); // Fakeをコールするテスト対象を実行
    assert(1 == func0_0_fake.call_count); // 呼出し回数の検査
    ...
}
```

### 任意の型の自由関数のFakeを例外指定子付きで定義する

### void型のメンバ関数のFakeを定義する

### 任意の型のメンバ関数のFakeを定義する


以上
