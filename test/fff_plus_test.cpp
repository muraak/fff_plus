#include <cassert>
#include <stdio.h>
#include "../fff_plus.h"

DEFINE_FFF_GLOBALS;

int func0_0(void) noexcept;
int func0_1(void) throw();
int func0_2(void);

int func1_0(int arg1) noexcept;
int func2_0(int arg1, int arg2) noexcept;
int func3_0(int arg1, int arg2, int arg3) noexcept;
int func4_0(int arg1, int arg2, int arg3, int arg4) noexcept;
int func5_0(int arg1, int arg2, int arg3, int arg4, int arg5) noexcept;
int func6_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) noexcept;
int func7_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) noexcept;
int func8_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) noexcept;

// overload functions
float func1_0(float arg1) noexcept;
float func2_0(float arg1, float arg2) noexcept;
float func3_0(float arg1, float arg2, float arg3) noexcept;
float func4_0(float arg1, float arg2, float arg3, float arg4) noexcept;
float func5_0(float arg1, float arg2, float arg3, float arg4, float arg5) noexcept;
float func6_0(float arg1, float arg2, float arg3, float arg4, float arg5, float arg6) noexcept;
float func7_0(float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7) noexcept;
float func8_0(float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8) noexcept;

class test_class
{
public:
int member_func0_0() noexcept;
int member_func0_1() throw();
int member_func0_2();

int member_func1_0(int arg1) noexcept;
int member_func2_0(int arg1, int arg2) noexcept;
int member_func3_0(int arg1, int arg2, int arg3) noexcept;
int member_func4_0(int arg1, int arg2, int arg3, int arg4) noexcept;
int member_func5_0(int arg1, int arg2, int arg3, int arg4, int arg5) noexcept;
int member_func6_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) noexcept;
int member_func7_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) noexcept;
int member_func8_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) noexcept;
};


FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func0_0);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, throw(), func0_1);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int,, func0_2);

FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func1_0, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func2_0, int, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func3_0, int, int, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func4_0, int, int, int, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func5_0, int, int, int, int, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func6_0, int, int, int, int, int, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func7_0, int, int, int, int, int, int, int);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func8_0, int, int, int, int, int, int, int, int);

#define func1_0_Fake    func1_0_Fake_ovl1
#define func1_0_fake    func1_0_fake_ovl1
#define func1_0_reset   func0_0_reset_ovl1
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func1_0, float);
#undef func1_0_Fake
#undef func1_0_fake
#undef func1_0_reset
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func2_0, float, float);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func3_0, float, float, float);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func4_0, float, float, float, float);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func5_0, float, float, float, float, float);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func6_0, float, float, float, float, float, float);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func7_0, float, float, float, float, float, float, float);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(float, noexcept, func8_0, float, float, float, float, float, float, float, float);


void void_func0_0(void) noexcept;
void void_func0_1(void) throw();
void void_func0_2(void);

void void_func1_0(int arg1) noexcept;
void void_func2_0(int arg1, int arg2) noexcept;
void void_func3_0(int arg1, int arg2, int arg3) noexcept;
void void_func4_0(int arg1, int arg2, int arg3, int arg4) noexcept;
void void_func5_0(int arg1, int arg2, int arg3, int arg4, int arg5) noexcept;
void void_func6_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) noexcept;
void void_func7_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) noexcept;
void void_func8_0(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) noexcept;

// FAKE_VOID_FUNC0_WITH_EXCEPTION_SPEC(noexcept, void_func0_0);
FAKE_VOID_FUNC0_WITH_EXCEPTION_SPEC(throw(), void_func0_1);
FAKE_VOID_FUNC0_WITH_EXCEPTION_SPEC(, void_func0_2);

// FAKE_VOID_FUNC1_WITH_EXCEPTION_SPEC(noexcept, void_func1_0, int);
FAKE_VOID_FUNC2_WITH_EXCEPTION_SPEC(noexcept, void_func2_0, int, int);
FAKE_VOID_FUNC3_WITH_EXCEPTION_SPEC(noexcept, void_func3_0, int, int, int);
FAKE_VOID_FUNC4_WITH_EXCEPTION_SPEC(noexcept, void_func4_0, int, int, int, int);
FAKE_VOID_FUNC5_WITH_EXCEPTION_SPEC(noexcept, void_func5_0, int, int, int, int, int);
FAKE_VOID_FUNC6_WITH_EXCEPTION_SPEC(noexcept, void_func6_0, int, int, int, int, int, int);
FAKE_VOID_FUNC7_WITH_EXCEPTION_SPEC(noexcept, void_func7_0, int, int, int, int, int, int, int);
FAKE_VOID_FUNC8_WITH_EXCEPTION_SPEC(noexcept, void_func8_0, int, int, int, int, int, int, int, int);

FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept, void_func0_0);
FAKE_VOID_FUNC_WITH_EXCEPTION_SPEC(noexcept, void_func1_0, int);


FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func0_0);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func1_0, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func2_0, int, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func3_0, int, int, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func4_0, int, int, int, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func5_0, int, int, int, int, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func6_0, int, int, int, int, int, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func7_0, int, int, int, int, int, int, int);
FAKE_VALUE_MEMBER_FUNC(int, noexcept, test_class, member_func8_0, int, int, int, int, int, int, int, int);

void test_target()
{
    func0_0();
    func0_2();
    func1_0(1);
    func2_0(1, 2);
    func3_0(1, 2, 3);
    func4_0(1, 2, 3, 4);
    func5_0(1, 2, 3, 4, 5);
    func6_0(1, 2, 3, 4, 5, 6);
    func7_0(1, 2, 3, 4, 5, 6, 7);
    func8_0(1, 2, 3, 4, 5, 6, 7, 8);

    void_func0_0();
    void_func0_2();
    void_func1_0(1);
    void_func2_0(1, 2);
    void_func3_0(1, 2, 3);
    void_func4_0(1, 2, 3, 4);
    void_func5_0(1, 2, 3, 4, 5);
    void_func6_0(1, 2, 3, 4, 5, 6);
    void_func7_0(1, 2, 3, 4, 5, 6, 7);
    void_func8_0(1, 2, 3, 4, 5, 6, 7, 8);

    test_class obj;

    obj.member_func0_0();
    obj.member_func1_0(1);
    obj.member_func2_0(1,2);
    obj.member_func3_0(1,2,3);
    obj.member_func4_0(1,2,3,4);
    obj.member_func5_0(1,2,3,4,5);
    obj.member_func6_0(1,2,3,4,5,6);
    obj.member_func7_0(1,2,3,4,5,6,7);
    obj.member_func8_0(1,2,3,4,5,6,7,8);
}

void test()
{
    RESET_FAKE(func0_2);
    RESET_FAKE(func0_0);
    RESET_FAKE(func1_0);
    RESET_FAKE(func2_0);
    RESET_FAKE(func3_0);
    RESET_FAKE(func4_0);
    RESET_FAKE(func5_0);
    RESET_FAKE(func6_0);
    RESET_FAKE(func7_0);
    RESET_FAKE(func8_0);

    RESET_FAKE(void_func0_2);
    RESET_FAKE(void_func0_0);
    RESET_FAKE(void_func1_0);
    RESET_FAKE(void_func2_0);
    RESET_FAKE(void_func3_0);
    RESET_FAKE(void_func4_0);
    RESET_FAKE(void_func5_0);
    RESET_FAKE(void_func6_0);
    RESET_FAKE(void_func7_0);
    RESET_FAKE(void_func8_0);

    RESET_FAKE(Faketest_classmember_func0_0);
    RESET_FAKE(Faketest_classmember_func1_0);

    test_target();

    assert(1 == func0_2_fake.call_count);
    assert(1 == func0_0_fake.call_count);
    assert(1 == func1_0_fake.call_count);
    assert(1 == func2_0_fake.call_count);
    assert(1 == func3_0_fake.call_count);
    assert(1 == func4_0_fake.call_count);
    assert(1 == func5_0_fake.call_count);
    assert(1 == func6_0_fake.call_count);
    assert(1 == func7_0_fake.call_count);
    assert(1 == func8_0_fake.call_count);

    assert(1 == void_func0_2_fake.call_count);
    assert(1 == void_func0_0_fake.call_count);
    assert(1 == void_func1_0_fake.call_count);
    assert(1 == void_func2_0_fake.call_count);
    assert(1 == void_func3_0_fake.call_count);
    assert(1 == void_func4_0_fake.call_count);
    assert(1 == void_func5_0_fake.call_count);
    assert(1 == void_func6_0_fake.call_count);
    assert(1 == void_func7_0_fake.call_count);
    assert(1 == void_func8_0_fake.call_count);

    assert(1 == Faketest_classmember_func0_0_fake.call_count);
    assert(1 == Faketest_classmember_func1_0_fake.call_count);
    assert(1 == Faketest_classmember_func2_0_fake.call_count);
    assert(1 == Faketest_classmember_func3_0_fake.call_count);
    assert(1 == Faketest_classmember_func4_0_fake.call_count);
    assert(1 == Faketest_classmember_func5_0_fake.call_count);
    assert(1 == Faketest_classmember_func6_0_fake.call_count);
    assert(1 == Faketest_classmember_func7_0_fake.call_count);
    assert(1 == Faketest_classmember_func8_0_fake.call_count);

    printf("PASSED!\n");
}

int main(void)
{
    test();
}
