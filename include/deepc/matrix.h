#ifndef DEEPC_MATRIX_H
#define DEEPC_MATRIX_H

#include "deepc/error.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct deepc_matrix deepc_matrix;

struct deepc_matrix {
    float* data;
    int num_rows;
    int num_cols;
};

#define DEEPC_MATRIX_AT(matrix, i, j) ((matrix).num_cols * (i) + (j))

deepc_error deepc_initialize_matrix(deepc_matrix* matrix, int num_rows, 
    int num_cols);

void deepc_deinitialize_matrix(deepc_matrix* matrix);

deepc_error deepc_copy_matrix(deepc_matrix* dest, deepc_matrix src);

deepc_error deepc_zeros_matrix(deepc_matrix* dest, int num_rows, int num_cols);
deepc_error deepc_ones_matrix(deepc_matrix* dest, int num_rows, int num_cols);

deepc_error deepc_rand_matrix(deepc_matrix* dest, int num_rows, int num_cols);

bool deepc_matrix_has_nan(deepc_matrix matrix);

deepc_error deepc_matrix_row(deepc_matrix* dest, deepc_matrix src, int row_pos);
deepc_error deepc_matrix_col(deepc_matrix* dest, deepc_matrix src, int col_pos);

void deepc_set_matrix_row(deepc_matrix matrix, int row_pos, deepc_matrix row);
void deepc_set_matrix_col(deepc_matrix matrix, int col_pos, deepc_matrix col);

deepc_error deepc_sum_matrices(deepc_matrix* rslt, deepc_matrix lhs, 
    deepc_matrix rhs);

deepc_error deepc_subtract_matrices(deepc_matrix* rslt, deepc_matrix lhs, 
    deepc_matrix rhs);

deepc_error deepc_multiply_matrices(deepc_matrix* rslt, deepc_matrix lhs, 
    deepc_matrix rhs);

deepc_error deepc_hadamard_multiply_matrices(deepc_matrix* rslt, 
    deepc_matrix lhs, deepc_matrix rhs);

deepc_error deepc_scale_matrix(deepc_matrix* rslt, deepc_matrix matrix, 
    float scalar);

deepc_error deepc_transpose_matrix(deepc_matrix* rslt, deepc_matrix matrix);
deepc_error deepc_apply_function_to_matrix(deepc_matrix* rslt, 
    deepc_matrix matrix, float (*func)(float));

void deepc_sum_matrix_in_place(deepc_matrix* lhs, deepc_matrix rhs);
void deepc_subtract_matrix_in_place(deepc_matrix* lhs, deepc_matrix rhs);
void deepc_scale_matrix_in_place(deepc_matrix* matrix, float scalar);

float deepc_sigmoid(float x);
float deepc_relu(float x);
float deepc_tanh(float x);

deepc_error deepc_features(deepc_matrix* dest, deepc_matrix labeled_data, 
    int label_column);

deepc_error deepc_labels(deepc_matrix* dest, deepc_matrix labeled, 
    int label_column);

void deepc_print_matrix(deepc_matrix matrix);
deepc_error deepc_print_class_distribution(deepc_matrix labels);

#ifdef __cplusplus
}
#endif

#endif // DEEPC_MATRIX_H
