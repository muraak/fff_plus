// example_test.cpp
#include <stdio.h>
#include <cassert>

#include "fff_plus.h"
#include "lib.h"
#include "lib_fake.h"
#include "testee.h"


DEFINE_FFF_GLOBALS

#define ASSERT_EQ(lhs, rhs) assert((lhs) == (rhs));

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

// テスト関数
void test(void)
{
    // 以下のマクロでFakeの呼出し履歴等をリセットすることができます
    // マクロの引数にはリセット対象の関数名を指定します
    RESET_FAKE(Ex1_valueFuncA);
    RESET_FAKE(Ex1_valueFuncA0);
    RESET_FAKE(Ex1_valueFuncB);
    RESET_FAKE(Ex1_voidFuncA);

    // メンバ関数のFakeは引数にFake+クラス名+関数名を指定します
    RESET_FAKE(FakeExClassvalueMethodA);
    RESET_FAKE(FakeExClassvalueMethodA0);
    RESET_FAKE(FakeExClassvalueMethodB);
    RESET_FAKE(FakeExClassvoidMethodA);

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
    ASSERT_EQ(1, Ex1_valueFuncA_fake.call_count);
    ASSERT_EQ(1, Ex1_valueFuncA0_fake.call_count);
    ASSERT_EQ(1, Ex1_valueFuncB_fake.call_count);
    ASSERT_EQ(1, Ex1_voidFuncA_fake.call_count);

    ASSERT_EQ(1, FakeExClassvalueMethodA_fake.call_count);
    ASSERT_EQ(1, FakeExClassvalueMethodA0_fake.call_count);
    ASSERT_EQ(1, FakeExClassvalueMethodB_fake.call_count);
    ASSERT_EQ(1, FakeExClassvoidMethodA_fake.call_count);

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
