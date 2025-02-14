//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   S C A L I N G   L A Y E R   T E S T   C L A S S   H E A D E R         
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

#ifndef SCALINGLAYERTEST_H
#define SCALINGLAYERTEST_H

// Unit testing includes

#include "unit_testing.h"

class ScalingLayerTest : public UnitTesting
{

public:  

   explicit ScalingLayerTest();

   virtual ~ScalingLayerTest();

   // Constructor and destructor methods

   void test_constructor();

   // Get methods

   void test_get_dimensions();

   // Multilayer perceptron architecture 

   void test_get_inputs_number();
   void test_get_neurons_number();

   // Statistics

   void test_get_descriptives();
   
   void test_get_minimums();
   void test_get_maximums();
   void test_get_means();
   void test_get_standard_deviations();

   // Variables scaling and unscaling

   void test_get_scaling_method();
   void test_write_scalers();

   // Display messages

   

   // Set methods

   void test_set();

   void test_set_inputs_number();
   void test_set_neurons_number();

   void test_set_default();

   // Descriptives

   void test_set_descriptives();
   void test_set_item_descriptives();

   // Multilayer perceptron architecture

   void test_set_layers_neurons_number();
   void test_set_layer_size();

   // Multilayer perceptron parameters

   void test_set_network_parameters();
   void test_set_layers_biases();
   void test_set_layer_biases();
   void test_set_layers_synaptic_weights();
   void test_set_layer_synaptic_weights();
   void test_set_layers_parameters();
   void test_set_layer_parameters();

   // Activation functions

   void test_set_layers_activation_function();
   void test_set_layer_activation_function();
   void test_set_output_layer_activation_function();

   // Input variables descriptives

   void test_set_mean();
   void test_set_standard_deviation();
   void test_set_minimum();
   void test_set_maximum();

   // Scaling method

   void test_set_scaling_method();

   // Display messages

   

   // Input range

   void test_is_empty();

   void test_check_range();

   // Scaling 

   void test_calculate_outputs();
   void test_calculate_minimum_maximum_output();
   void test_calculate_mean_standard_deviation_output();

   // XML expression methods

   void test_write_expression();

   // Serialization methods

   void test_to_XML();
   void test_from_XML();

   // Unit testing methods

   void run_test_case();

private:

   ScalingLayer scaling_layer;

   Tensor<Descriptives, 1> descriptives;
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
