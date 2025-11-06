#ifndef DEEPC_ERROR_H
#define DEEPC_ERROR_H

typedef enum deepc_error_code deepc_error_code;

enum deepc_error_code {
    DEEPC_SUCCESS = 0,
    DEEPC_ALLOCATION_FAILED = 1
};

const char* deepc_log(deepc_error_code err);

#endif // DEEPC_ERROR_H
