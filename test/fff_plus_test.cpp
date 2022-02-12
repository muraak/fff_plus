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

// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func0_0);
// FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(int, noexcept, func1_0, int);

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

    RESET_FAKE(Fakemember_func0_0);
    RESET_FAKE(Fakemember_func1_0);

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

    assert(1 == Fakemember_func0_0_fake.call_count);
    assert(1 == Fakemember_func1_0_fake.call_count);
    assert(1 == Fakemember_func2_0_fake.call_count);
    assert(1 == Fakemember_func3_0_fake.call_count);
    assert(1 == Fakemember_func4_0_fake.call_count);
    assert(1 == Fakemember_func5_0_fake.call_count);
    assert(1 == Fakemember_func6_0_fake.call_count);
    assert(1 == Fakemember_func7_0_fake.call_count);
    assert(1 == Fakemember_func8_0_fake.call_count);

    printf("PASSED!\n");
}

int main(void)
{
    test();
}
