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

// オーバーロード関数のFake作成例
// 2つ目以降のオーバーロード関数のFakeを作成するときは、define/undefをつかって
// 一部のリソースのシンボル名を置換する必要があります。少々手間でごめんなさい。
// 1つ目のオーバーロード関数のFake定義
DEFINE_FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept, Ex3_valueFuncA, int);
// ２つ目のオーバーロード関数のFake定義
#define Ex3_valueFuncA_Fake             Ex3_valueFuncA_ovl1_Fake
#define Ex3_valueFuncA_fake             Ex3_valueFuncA_ovl1_fake
#define Ex3_valueFuncA_reset            Ex3_valueFuncA_ovl1_reset
DEFINE_FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept, Ex3_valueFuncA, float);
#undef Ex3_valueFuncA_Fake 
#undef Ex3_valueFuncA_fake 
#undef Ex3_valueFuncA_reset
// ３つ目のオーバーロード関数のFake定義
#define Ex3_valueFuncA_Fake             Ex3_valueFuncA_ovl2_Fake
#define Ex3_valueFuncA_fake             Ex3_valueFuncA_ovl2_fake
#define Ex3_valueFuncA_reset            Ex3_valueFuncA_ovl2_reset
DEFINE_FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept, Ex3_valueFuncA, int, float);
#undef Ex3_valueFuncA_Fake 
#undef Ex3_valueFuncA_fake 
#undef Ex3_valueFuncA_reset
