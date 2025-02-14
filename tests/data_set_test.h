//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   D A T A   S E T   T E S T   C L A S S   H E A D E R                   
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

#ifndef DATASETTEST_H
#define DATASETTEST_H

// Unit testing includes

#include "unit_testing.h"

class DataSetTest : public UnitTesting 
{

public:  

   explicit DataSetTest();

   virtual ~DataSetTest();

   // Constructor and destructor methods

   void test_constructor();
   void test_destructor();  

   // Get methods

   void test_get_samples_number();
   void test_get_variables_number();
   void test_get_variables();
   
   void test_write_first_cell();
   void test_has_time_columns();

   // Data methods

   void test_get_data();
   void test_get_training_data();
   void test_get_selection_data();
   void test_get_testing_data();
   void test_get_input_data();
   void test_get_target_data();
   void test_get_time_series_columns();
   void test_get_time_series_columns_number();
   void test_get_time_series_column_data();
   void test_get_time_series_columns_names();
   void test_get_time_series_data();
  
   // Sample methods

   void test_get_sample();

   // Set methods
   void test_set();
   void test_set_samples_number();
   void test_set_columns_number();
   
   void test_set_lags_number();
   void test_set_steps_ahead_number();
   void test_set_time_series_data();
   void test_save_time_series_data_binary();
   void test_set_time_index();

   // Data methods

   void test_set_data();
   void test_is_empty();

   // Data resizing methods

   void test_add_sample();
   void test_append_variable();
   void test_remove_variable();
   void test_unuse_constant_columns();
   void test_unuse_repeated_samples();
   void test_unuse_uncorrelated_columns();

   // Initialization methods

   void test_set_data_constant();

   // Statistics methods

   void test_calculate_variables_descriptives();
   void test_calculate_input_variables_descriptives();
   void test_calculate_variables_means();

   void test_calculate_used_targets_mean();
   void test_calculate_selection_targets_mean();

   // Correlation methods

   void test_calculate_linear_correlations();
   void test_calculate_autocorrelations();
   void test_calculate_cross_correlations();
   void test_calculate_input_target_correlations();
   void test_calculate_total_input_correlations();

   // Trending methods

   void test_calculate_trends();

   // Histrogram methods

   void test_calculate_data_distributions();

   // Filtering methods

   void test_filter_data();

   // Data scaling

   void test_scale_data();

   void test_unscale_data();

   // Classification methods

   void test_calculate_target_distribution();

   void test_calculate_Tukey_outliers();

   void test_calculate_euclidean_distance();
   void test_calculate_distance_matrix();
   void test_calculate_k_nearest_neighbors();
   void test_calculate_average_reachability();

   void test_calculate_LOF_outliers();
   void test_unuse_local_outlier_factor_outliers();

   // Data generation

   void test_generate_constant_data();

   // Serialization methods

   void test_print_data_preview();

   void test_read_csv();

   void test_read_adult_csv();
   void test_read_airline_passengers_csv();
   void test_read_car_csv();
   void test_read_empty_csv();
   void test_read_heart_csv();
   void test_read_iris_csv();
   void test_read_mnsit_csv();
   void test_read_one_variable_csv();
   void test_read_pollution_csv();
   void test_read_urinary_inflammations_csv();
   void test_read_wine_csv();
   void test_read_binary_csv();

   // Trasform methods

   void test_transform_time_series();

   // Principal components mehtod

   void test_calculate_training_negatives();
   void test_calculate_selection_negatives();
   void test_scrub_missing_values();
   void test_impute_missing_values_mean();

   // Unit testing methods

   void run_test_case();

  private:

   Index inputs_number;
   Index targets_number;
   Index samples_number;

   Tensor<type, 2> data;

   DataSet data_set;

   Tensor<Index, 1> training_indices;
   Tensor<Index, 1> selection_indices;
   Tensor<Index, 1> testing_indices;

   Tensor<Index, 1> input_variables_indices;
   Tensor<Index, 1> target_variables_indices;

};

#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2021 Artificial Intelligence Techniques, SL.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
