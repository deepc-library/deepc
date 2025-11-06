#include "deepc/error.h"

const char* deepc_log(deepc_error_code err) {
    switch (err) {
    case DEEPC_SUCCESS:
        return "Success";
    case DEEPC_ALLOCATION_FAILED:
        return "Allocation failed";
    default:
        return "Invalid eror code";
    }
}
