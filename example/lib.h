// lib.h
#ifndef LIB_H
#define LIB_H

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

/** 
 * @brief Fake作成対象の具象クラス
 * @details 
 * テスト対象のtestee.cppで使用されますが
 * 宣言のみで実装がまだ存在しません。
 * fff_plusを利用して各メンバ関数のFakeを作成する対象です。
 */
class ExClass2
{
public:
    int valueMethodA(int a) noexcept; // 例外指定子つき
    int valueMethodA0() noexcept; // 引数なし
    void voidMethodA(int a) noexcept; // void型
    int valueMethodB(int a, int b); // 例外指定子なし
};


int     Ex1_valueFuncA(int a) noexcept; // 例外指定子つき
int     Ex1_valueFuncA0() noexcept; // 引数なし
void    Ex1_voidFuncA(int a) noexcept; // void型
int     Ex1_valueFuncB(int a, int b); // 例外指定子なし

int     Ex2_valueFuncA(int a) noexcept; // 例外指定子つき
int     Ex2_valueFuncA0() noexcept; // 引数なし
void    Ex2_voidFuncA(int a) noexcept; // void型
int     Ex2_valueFuncB(int a, int b); // 例外指定子なし

#endif // LIB_H
