#ifndef DEEPC_CSV_LOADER_H
#define DEEPC_CSV_LOADER_H

#include "deepc/matrix.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <math.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

deepc_matrix deepc_load_csv(const char* filename, bool has_header);

void deepc_fill_missing_with_mean(deepc_matrix* mat);
void deepc_fill_missing_with_zeros(deepc_matrix* mat);

size_t deepc_count_missing_values(deepc_matrix mat);
void deepc_print_matrix_stats(deepc_matrix mat);

void deepc_train_test_split(deepc_matrix x, deepc_matrix y, float test_size, 
    deepc_matrix* x_train, deepc_matrix* x_test, 
    deepc_matrix* y_train, deepc_matrix* y_test);

deepc_matrix deepc_split_features_labels(deepc_matrix mat, size_t label_column);

deepc_matrix deepc_one_hot_encode_labels(deepc_matrix labels, 
    size_t num_classes);

deepc_matrix deepc_normalize_matrix(deepc_matrix mat);
deepc_matrix deepc_standardize_matrix(deepc_matrix mat);

void deepc_shuffle_dataset(deepc_matrix* dst, deepc_matrix src);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_CSV_LOADER_H
