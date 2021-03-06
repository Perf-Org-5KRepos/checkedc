// Feature tests of typechecking bounds-safe
// interfaces for the C standard library.
//
// The following lines are for the LLVM test harness:
//
// Test include files in an unchecked scope
//
// RUN: %clang -fsyntax-only %s
// RUN: %clang -fsyntax-only -D_FORTIFY_SOURCE=0 %s
// RUN: %clang -fsyntax-only -D_FORTIFY_SOURCE=1 %s
// RUN: %clang -fsyntax-only -D_FORTIFY_SOURCE=2 %s
//
// Test include files in a checked scope.
//
// RUN: %clang -fsyntax-only  -DCHECKED_SCOPE=1 %s
// RUN: %clang -fsyntax-only -D_FORTIFY_SOURCE=0 -DCHECKED_SCOPE=1 %s
// RUN: %clang -fsyntax-only -D_FORTIFY_SOURCE=1 -DCHECKED_SCOPE=1 %s
// RUN: %clang -fsyntax-only -D_FORTIFY_SOURCE=2 -DCHECKED_SCOPE=1 %s

#if CHECKED_SCOPE
#pragma CHECKED_SCOPE on
#endif

// C Standard
#include "../../include/assert_checked.h"
#include "../../include/errno_checked.h"
#include "../../include/fenv_checked.h"
#include "../../include/inttypes_checked.h"
#include "../../include/math_checked.h"
#include "../../include/signal_checked.h"
#include "../../include/stdio_checked.h"
#include "../../include/stdlib_checked.h"
#include "../../include/string_checked.h"
#define _CHECKEDC_MOCKUP_THREADS 1
#include "../../include/threads_checked.h"
#include "../../include/time_checked.h"
#include "../../include/checkedc_extensions.h"

// Posix Headers
//
// Uses clang-specific __has_include macro to detect unistd.h
// which is required by Posix Standard.
#if defined(__has_include)
#if __has_include(<unistd.h>)
#include "../../include/unistd_checked.h"
#endif

#if __has_include(<sys/socket.h>)
#include "../../include/sys/socket_checked.h"
#endif

#if __has_include(<arpa/inet.h>)
#include "../../include/arpa/inet_checked.h"
#endif

#endif
