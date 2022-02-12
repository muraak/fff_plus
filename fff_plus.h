#ifndef FAKE_FUNCTIONS_PLUS
#define FAKE_FUNCTIONS_PLUS
#include "fff/fff.h"

// Macros for free functions with exception specifier

#define PP_NARG_MINUS3(...)   EXPAND(PP_NARG_MINUS3_(__VA_ARGS__, PP_RSEQ_N_MINUS3()))

#define PP_NARG_MINUS3_(...)   EXPAND(PP_ARG_MINUS3_N(__VA_ARGS__))

#define PP_ARG_MINUS3_N(returnVal,  exceptionSpec, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...)   N

#define PP_RSEQ_N_MINUS3()   20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define PP_NARG_MINUS4(...)   EXPAND(PP_NARG_MINUS4_(__VA_ARGS__, PP_RSEQ_N_MINUS4()))

#define PP_NARG_MINUS4_(...)   EXPAND(PP_ARG_MINUS4_N(__VA_ARGS__))

#define PP_ARG_MINUS4_N(a, b, c, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...)   N

#define PP_RSEQ_N_MINUS4()   20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define DECLARE_FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(void); \
        RETURN_TYPE(**custom_fake_seq)(void); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(void) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(void) EXCEPTION_SPEC{ \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME) \
    DECLARE_FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME) \
    DEFINE_FAKE_VALUE_FUNC0_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME) \

#define DECLARE_FAKE_VALUE_FUNC1_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC1_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC1_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE) \
    DECLARE_FAKE_VALUE_FUNC1_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE) \
    DEFINE_FAKE_VALUE_FUNC1_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC2_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC2_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC2_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE) \
    DECLARE_FAKE_VALUE_FUNC2_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE) \
    DEFINE_FAKE_VALUE_FUNC2_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC3_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ARG(ARG2_TYPE, 2, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC3_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        SAVE_ARG(FUNCNAME, 2); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
            SAVE_ARG_HISTORY(FUNCNAME, 2); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1, arg2); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1, arg2); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1, arg2); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC3_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE) \
    DECLARE_FAKE_VALUE_FUNC3_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE) \
    DEFINE_FAKE_VALUE_FUNC3_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC4_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ARG(ARG2_TYPE, 2, FUNCNAME) \
        DECLARE_ARG(ARG3_TYPE, 3, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC4_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        SAVE_ARG(FUNCNAME, 2); \
        SAVE_ARG(FUNCNAME, 3); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
            SAVE_ARG_HISTORY(FUNCNAME, 2); \
            SAVE_ARG_HISTORY(FUNCNAME, 3); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1, arg2, arg3); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC4_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE) \
    DECLARE_FAKE_VALUE_FUNC4_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE) \
    DEFINE_FAKE_VALUE_FUNC4_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC5_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ARG(ARG2_TYPE, 2, FUNCNAME) \
        DECLARE_ARG(ARG3_TYPE, 3, FUNCNAME) \
        DECLARE_ARG(ARG4_TYPE, 4, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC5_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        SAVE_ARG(FUNCNAME, 2); \
        SAVE_ARG(FUNCNAME, 3); \
        SAVE_ARG(FUNCNAME, 4); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
            SAVE_ARG_HISTORY(FUNCNAME, 2); \
            SAVE_ARG_HISTORY(FUNCNAME, 3); \
            SAVE_ARG_HISTORY(FUNCNAME, 4); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1, arg2, arg3, arg4); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC5_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE) \
    DECLARE_FAKE_VALUE_FUNC5_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE) \
    DEFINE_FAKE_VALUE_FUNC5_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC6_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ARG(ARG2_TYPE, 2, FUNCNAME) \
        DECLARE_ARG(ARG3_TYPE, 3, FUNCNAME) \
        DECLARE_ARG(ARG4_TYPE, 4, FUNCNAME) \
        DECLARE_ARG(ARG5_TYPE, 5, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC6_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        SAVE_ARG(FUNCNAME, 2); \
        SAVE_ARG(FUNCNAME, 3); \
        SAVE_ARG(FUNCNAME, 4); \
        SAVE_ARG(FUNCNAME, 5); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
            SAVE_ARG_HISTORY(FUNCNAME, 2); \
            SAVE_ARG_HISTORY(FUNCNAME, 3); \
            SAVE_ARG_HISTORY(FUNCNAME, 4); \
            SAVE_ARG_HISTORY(FUNCNAME, 5); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1, arg2, arg3, arg4, arg5); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4, arg5); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4, arg5); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4, arg5); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4, arg5); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC6_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE) \
    DECLARE_FAKE_VALUE_FUNC6_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE) \
    DEFINE_FAKE_VALUE_FUNC6_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC7_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ARG(ARG2_TYPE, 2, FUNCNAME) \
        DECLARE_ARG(ARG3_TYPE, 3, FUNCNAME) \
        DECLARE_ARG(ARG4_TYPE, 4, FUNCNAME) \
        DECLARE_ARG(ARG5_TYPE, 5, FUNCNAME) \
        DECLARE_ARG(ARG6_TYPE, 6, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC7_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        SAVE_ARG(FUNCNAME, 2); \
        SAVE_ARG(FUNCNAME, 3); \
        SAVE_ARG(FUNCNAME, 4); \
        SAVE_ARG(FUNCNAME, 5); \
        SAVE_ARG(FUNCNAME, 6); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
            SAVE_ARG_HISTORY(FUNCNAME, 2); \
            SAVE_ARG_HISTORY(FUNCNAME, 3); \
            SAVE_ARG_HISTORY(FUNCNAME, 4); \
            SAVE_ARG_HISTORY(FUNCNAME, 5); \
            SAVE_ARG_HISTORY(FUNCNAME, 6); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1, arg2, arg3, arg4, arg5, arg6); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4, arg5, arg6); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4, arg5, arg6); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4, arg5, arg6); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4, arg5, arg6); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC7_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE) \
    DECLARE_FAKE_VALUE_FUNC7_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE) \
    DEFINE_FAKE_VALUE_FUNC7_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE) \


#define DECLARE_FAKE_VALUE_FUNC8_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE, ARG7_TYPE) \
    typedef struct FUNCNAME##_Fake { \
        DECLARE_ARG(ARG0_TYPE, 0, FUNCNAME) \
        DECLARE_ARG(ARG1_TYPE, 1, FUNCNAME) \
        DECLARE_ARG(ARG2_TYPE, 2, FUNCNAME) \
        DECLARE_ARG(ARG3_TYPE, 3, FUNCNAME) \
        DECLARE_ARG(ARG4_TYPE, 4, FUNCNAME) \
        DECLARE_ARG(ARG5_TYPE, 5, FUNCNAME) \
        DECLARE_ARG(ARG6_TYPE, 6, FUNCNAME) \
        DECLARE_ARG(ARG7_TYPE, 7, FUNCNAME) \
        DECLARE_ALL_FUNC_COMMON \
        DECLARE_VALUE_FUNCTION_VARIABLES(RETURN_TYPE) \
        DECLARE_RETURN_VALUE_HISTORY(RETURN_TYPE) \
        DECLARE_CUSTOM_FAKE_SEQ_VARIABLES \
        RETURN_TYPE(*custom_fake)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6, ARG7_TYPE arg7); \
        RETURN_TYPE(**custom_fake_seq)(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6, ARG7_TYPE arg7); \
    } FUNCNAME##_Fake; \
    extern FUNCNAME##_Fake FUNCNAME##_fake; \
    void FUNCNAME##_reset(void); \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6, ARG7_TYPE arg7) EXCEPTION_SPEC; \

#define DEFINE_FAKE_VALUE_FUNC8_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE, ARG7_TYPE) \
    FUNCNAME##_Fake FUNCNAME##_fake; \
    RETURN_TYPE FFF_GCC_FUNCTION_ATTRIBUTES FUNCNAME(ARG0_TYPE arg0, ARG1_TYPE arg1, ARG2_TYPE arg2, ARG3_TYPE arg3, ARG4_TYPE arg4, ARG5_TYPE arg5, ARG6_TYPE arg6, ARG7_TYPE arg7) EXCEPTION_SPEC{ \
        SAVE_ARG(FUNCNAME, 0); \
        SAVE_ARG(FUNCNAME, 1); \
        SAVE_ARG(FUNCNAME, 2); \
        SAVE_ARG(FUNCNAME, 3); \
        SAVE_ARG(FUNCNAME, 4); \
        SAVE_ARG(FUNCNAME, 5); \
        SAVE_ARG(FUNCNAME, 6); \
        SAVE_ARG(FUNCNAME, 7); \
        if(ROOM_FOR_MORE_HISTORY(FUNCNAME)){ \
            SAVE_ARG_HISTORY(FUNCNAME, 0); \
            SAVE_ARG_HISTORY(FUNCNAME, 1); \
            SAVE_ARG_HISTORY(FUNCNAME, 2); \
            SAVE_ARG_HISTORY(FUNCNAME, 3); \
            SAVE_ARG_HISTORY(FUNCNAME, 4); \
            SAVE_ARG_HISTORY(FUNCNAME, 5); \
            SAVE_ARG_HISTORY(FUNCNAME, 6); \
            SAVE_ARG_HISTORY(FUNCNAME, 7); \
        } \
        else{ \
            HISTORY_DROPPED(FUNCNAME); \
        } \
        INCREMENT_CALL_COUNT(FUNCNAME); \
        REGISTER_CALL(FUNCNAME); \
        if (FUNCNAME##_fake.custom_fake_seq_len){ /* a sequence of custom fakes */ \
            if (FUNCNAME##_fake.custom_fake_seq_idx < FUNCNAME##_fake.custom_fake_seq_len){ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_idx++](arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
            } \
            else{ \
                RETURN_TYPE ret = FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
                SAVE_RET_HISTORY(FUNCNAME, ret); \
                return ret; \
                return FUNCNAME##_fake.custom_fake_seq[FUNCNAME##_fake.custom_fake_seq_len-1](arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
            } \
        } \
        if (FUNCNAME##_fake.custom_fake){  \
            RETURN_TYPE ret = FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
            SAVE_RET_HISTORY(FUNCNAME, ret); \
            return ret; \
            return FUNCNAME##_fake.custom_fake(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7); \
        } \
        RETURN_FAKE_RESULT(FUNCNAME) \
    } \
    DEFINE_RESET_FUNCTION(FUNCNAME) \

#define FAKE_VALUE_FUNC8_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE, ARG7_TYPE) \
    DECLARE_FAKE_VALUE_FUNC8_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE, ARG7_TYPE) \
    DEFINE_FAKE_VALUE_FUNC8_WITH_EXCEPTION_SPEC(RETURN_TYPE, EXCEPTION_SPEC, FUNCNAME, ARG0_TYPE, ARG1_TYPE, ARG2_TYPE, ARG3_TYPE, ARG4_TYPE, ARG5_TYPE, ARG6_TYPE, ARG7_TYPE) \

#define FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(...)     EXPAND(FUNC_VALUE_WITH_EXCEPTION_SPEC_(PP_NARG_MINUS3(__VA_ARGS__), __VA_ARGS__))

#define FUNC_VALUE_WITH_EXCEPTION_SPEC_(N,...)     EXPAND(FUNC_VALUE_WITH_EXCEPTION_SPEC_N(N,__VA_ARGS__))

#define FUNC_VALUE_WITH_EXCEPTION_SPEC_N(N,...)     EXPAND(FAKE_VALUE_FUNC ## N ##_WITH_EXCEPTION_SPEC(__VA_ARGS__))

#define AT_2_ARG_SET0() 
#define AT_2_ARG_SET1(at0) at0 a0
#define AT_2_ARG_SET2(at0,at1) at0 a0, at1 a1
#define AT_2_ARG_SET3(at0,at1,at2) at0 a0, at1 a1, at2 a2
#define AT_2_ARG_SET4(at0,at1,at2,at3) at0 a0, at1 a1, at2 a2, at3 a3
#define AT_2_ARG_SET5(at0,at1,at2,at3,at4) at0 a0, at1 a1, at2 a2, at3 a3, at4 a4
#define AT_2_ARG_SET6(at0,at1,at2,at3,at4,at5) at0 a0, at1 a1, at2 a2, at3 a3, at4 a4, at5 a5
#define AT_2_ARG_SET7(at0,at1,at2,at3,at4,at5,at6) at0 a0, at1 a1, at2 a2, at3 a3, at4 a4, at5 a5, at6 a6
#define AT_2_ARG_SET8(at0,at1,at2,at3,at4,at5,at6,at7) at0 a0, at1 a1, at2 a2, at3 a3, at4 a4, at5 a5, at6 a6, at7 a7

#define AT_2_ARG_IN_CALL0()
#define AT_2_ARG_IN_CALL1(at0) a0
#define AT_2_ARG_IN_CALL2(at0,at1) a0, a1
#define AT_2_ARG_IN_CALL3(at0,at1,at2) a0, a1, a2
#define AT_2_ARG_IN_CALL4(at0,at1,at2,at3) a0, a1, a2, a3
#define AT_2_ARG_IN_CALL5(at0,at1,at2,at3,at4) a0, a1, a2, a3, a4
#define AT_2_ARG_IN_CALL6(at0,at1,at2,at3,at4,at5) a0, a1, a2, a3, a4, a5
#define AT_2_ARG_IN_CALL7(at0,at1,at2,at3,at4,at5,at6) a0, a1, a2, a3, a4, a5, a6
#define AT_2_ARG_IN_CALL8(at0,at1,at2,at3,at4,at5,at6,at7) a0, a1, a2, a3, a4, a5, a6, a7


#define FAKE_VALUE_MEMBER_FUNC(...) EXPAND(FAKE_VALUE_MEMBER_FUNC_(PP_NARG_MINUS4(__VA_ARGS__), __VA_ARGS__))

#define FAKE_VALUE_MEMBER_FUNC_(N, ...) EXPAND(FAKE_VALUE_MEMBER_FUNC_N(N, __VA_ARGS__))

#define FAKE_VALUE_MEMBER_FUNC_N(N, ty, es, cn, fn, ...) FAKE_VALUE_FUNC_WITH_EXCEPTION_SPEC(ty, es, Fake##fn, ##__VA_ARGS__); \
ty cn::fn(AT_2_ARG_SET##N(__VA_ARGS__)) es { return Fake##fn(AT_2_ARG_IN_CALL##N(__VA_ARGS__)); }

#endif // FAKE_FUNCTIONS_PLUS