#include <cassert>
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

// FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(int, noexcept, func0_0);
FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(int, throw(), func0_1);
FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(int,, func0_2);

// FAKE_VALUE_FUNC1_WITH_EXCEPTION_SPEC(int, noexcept, func1_0, int);
FAKE_VALUE_FUNC2_WITH_EXCEPTION_SPEC(int, noexcept, func2_0, int, int);
FAKE_VALUE_FUNC3_WITH_EXCEPTION_SPEC(int, noexcept, func3_0, int, int, int);
FAKE_VALUE_FUNC4_WITH_EXCEPTION_SPEC(int, noexcept, func4_0, int, int, int, int);
FAKE_VALUE_FUNC5_WITH_EXCEPTION_SPEC(int, noexcept, func5_0, int, int, int, int, int);
FAKE_VALUE_FUNC6_WITH_EXCEPTION_SPEC(int, noexcept, func6_0, int, int, int, int, int, int);
FAKE_VALUE_FUNC7_WITH_EXCEPTION_SPEC(int, noexcept, func7_0, int, int, int, int, int, int, int);
FAKE_VALUE_FUNC8_WITH_EXCEPTION_SPEC(int, noexcept, func8_0, int, int, int, int, int, int, int, int);

FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func0_0);
FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func1_0, int);

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
}

int main(void)
{
    test();
}
