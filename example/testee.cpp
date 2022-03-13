/**
 * Copyright (c) 2022 muraak
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */
#include "lib.h"

void testee_func(void)
{
    ExClass obj;

    obj.valueMethodA(1);
    obj.valueMethodA0();
    obj.valueMethodB(1,2);
    obj.voidMethodA(1);

    ExClass2 obj2;

    obj2.valueMethodA(1);
    obj2.valueMethodA0();
    obj2.valueMethodB(1,2);
    obj2.voidMethodA(1);

    Ex1_valueFuncA(1);
    Ex1_valueFuncA0();
    Ex1_valueFuncB(1,2);
    Ex1_voidFuncA(1);

    Ex2_valueFuncA(1);
    Ex2_valueFuncA0();
    Ex2_valueFuncB(1,2);
    Ex2_voidFuncA(1);
}

