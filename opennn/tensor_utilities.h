
#ifndef TENSORUTILITIES_H
#define TENSORUTILITIES_H

// System includes

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <math.h>
#include <vector>
#include <numeric>

// OpenNN includes

#include "config.h"

#include "../eigen/Eigen/Dense"

using namespace std;
using namespace Eigen;

namespace OpenNN
{

void initialize_sequential(Tensor<type, 1>&);

void multiply_rows(Tensor<type, 2>&, const Tensor<type, 1>&);
void divide_columns(Tensor<type, 2>&, const Tensor<type, 1>&);

bool is_zero(const Tensor<type, 1>&);
bool is_constant(const Tensor<type, 1>&);

bool is_equal(const Tensor<type, 2>&, const type&, const type& = 0.0);

bool are_equal(const Tensor<type, 1>&, const Tensor<type, 1>&, const type& = 0.0);
bool are_equal(const Tensor<type, 2>&, const Tensor<type, 2>&, const type& = 0.0);

bool is_false(const Tensor<bool, 1>&);

bool is_binary(const Tensor<type, 2>&);

void save_csv(const Tensor<type,2>&, const string&);

Tensor<Index, 1> calculate_rank_greater(const Tensor<type, 1>&);
Tensor<Index, 1> calculate_rank_less(const Tensor<type, 1>&);

void scrub_missing_values(Tensor<type, 2>&, const type&);

type l1_norm(const ThreadPoolDevice*, const Tensor<type, 1>&);
void l1_norm_gradient(const ThreadPoolDevice*, const Tensor<type, 1>&, Tensor<type, 1>&);
void l1_norm_hessian(const ThreadPoolDevice*, const Tensor<type, 1>&, Tensor<type, 2>&);

type l2_norm(const ThreadPoolDevice*, const Tensor<type, 1>&);
void l2_norm_gradient(const ThreadPoolDevice*, const Tensor<type, 1>&, Tensor<type, 1>&);
void l2_norm_hessian(const ThreadPoolDevice*, const Tensor<type, 1>&, Tensor<type, 2>&);

Tensor<type, 2> kronecker_product(const Tensor<type, 1>&, const Tensor<type, 1>&);

void sum_diagonal(Tensor<type, 2>&, const type&);

Tensor<type, 1> perform_Householder_QR_decomposition(const Tensor<type, 2>&, const Tensor<type, 1>&);

void fill_submatrix(const Tensor<type, 2>& matrix,
          const Tensor<Index, 1>& rows_indices,
          const Tensor<Index, 1>& columns_indices, type* submatrix);

Index count_NAN(const Tensor<type, 1>&);

void check_size(const Tensor<type, 1>&, const Index&, const string&);

void check_dimensions(const Tensor<type, 2>&, const Index&, const Index&, const string&);

void check_columns_number(const Tensor<type, 2>&, const Index&, const string&);

bool is_less_than(const Tensor<type, 1>&, const type&);


Tensor<type, 2> assemble_vector_vector(const Tensor<type, 1>&, const Tensor<type, 1>&);
Tensor<type, 2> assemble_vector_matrix(const Tensor<type, 1>&, const Tensor<type, 2>&);
Tensor<type, 2> assemble_matrix_vector(const Tensor<type, 2>&, const Tensor<type, 1>&);
Tensor<type, 2> assemble_matrix_matrix(const Tensor<type, 2>&, const Tensor<type, 2>&);

}

#endif
