#ifndef DEEPC_DEBUG_H
#define DEEPC_DEBUG_H

#ifdef NDEBUG
    #define DEEPC_ASSERT(cond, msg) ((void)0)
#else
    #include <stdio.h>
    #include <stdlib.h>

    #define DEEPC_ASSERT(cond, msg) \
        do { \
            if (!cond) { \
                fprintf(stderr, "Assertion failed: %s\n", msg); \
                abort(); \
            } \
        } while (0)
#endif

#endif // DEEPC_DEBUG_H
