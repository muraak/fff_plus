/**
 * Copyright (c) 2022 muraak
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */
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
