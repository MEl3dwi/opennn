//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   P E R C E P T R O N   L A Y E R   T E S T   C L A S S
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

#include "perceptron_layer_test.h"
#include "loss_index.h"

PerceptronLayerTest::PerceptronLayerTest() : UnitTesting()
{
}


PerceptronLayerTest::~PerceptronLayerTest()
{
}


void PerceptronLayerTest::test_constructor()
{
    cout << "test_constructor\n";

    // Default constructor

    PerceptronLayer perceptron_layer_1;

    assert_true(perceptron_layer_1.get_inputs_number() == 0, LOG);
    assert_true(perceptron_layer_1.get_neurons_number() == 0, LOG);
    assert_true(perceptron_layer_1.get_type() == Layer::Perceptron, LOG);

    // Architecture constructor

    PerceptronLayer perceptron_layer_3(10, 3, PerceptronLayer::Linear);
    assert_true(perceptron_layer_3.write_activation_function() == "Linear", LOG);
    assert_true(perceptron_layer_3.get_inputs_number() == 10, LOG);
    assert_true(perceptron_layer_3.get_neurons_number() == 3, LOG);
    assert_true(perceptron_layer_3.get_biases_number() == 3, LOG);
    assert_true(perceptron_layer_3.get_synaptic_weights_number() == 30, LOG);
    assert_true(perceptron_layer_3.get_parameters_number() == 33, LOG);

    PerceptronLayer perceptron_layer_4(0, 0, PerceptronLayer::Logistic);
    assert_true(perceptron_layer_4.write_activation_function() == "Logistic", LOG);
    assert_true(perceptron_layer_4.get_inputs_number() == 0, LOG);
    assert_true(perceptron_layer_4.get_neurons_number() == 0, LOG);
    assert_true(perceptron_layer_4.get_biases_number() == 0, LOG);
    assert_true(perceptron_layer_4.get_synaptic_weights_number() == 0, LOG);
    assert_true(perceptron_layer_4.get_parameters_number() == 0, LOG);

    PerceptronLayer perceptron_layer_5(1, 1, PerceptronLayer::Linear);
    assert_true(perceptron_layer_5.write_activation_function() == "Linear", LOG);
    assert_true(perceptron_layer_5.get_inputs_number() == 1, LOG);
    assert_true(perceptron_layer_5.get_neurons_number() == 1, LOG);
    assert_true(perceptron_layer_5.get_biases_number() == 1, LOG);
    assert_true(perceptron_layer_5.get_synaptic_weights_number() == 1, LOG);
    assert_true(perceptron_layer_5.get_parameters_number() == 2, LOG);
}


void PerceptronLayerTest::test_get_inputs_number()
{
   cout << "test_get_inputs_number\n";

   // Test
   perceptron_layer.set();
   assert_true(perceptron_layer.get_inputs_number() == 0, LOG);

   // Test
   perceptron_layer.set(1, 1);
   assert_true(perceptron_layer.get_inputs_number() == 1, LOG);

   // Test
   perceptron_layer.set(4,5);
   assert_true(perceptron_layer.get_inputs_number() == 4, LOG);
}


void PerceptronLayerTest::test_get_neurons_number()
{
   cout << "test_get_size\n";



   // Test
   perceptron_layer.set();
   assert_true(perceptron_layer.get_neurons_number() == 0, LOG);

   // Test
   perceptron_layer.set(1, 1);
   assert_true(perceptron_layer.get_neurons_number() == 1, LOG);

   // Test
   perceptron_layer.set(4,5);
   assert_true(perceptron_layer.get_neurons_number() == 5, LOG);
}


void PerceptronLayerTest::test_get_activation_function()
{
   cout << "test_get_activation_function\n";

   perceptron_layer.set();

   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::Threshold, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::SymmetricThreshold, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Logistic);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::Logistic, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::HyperbolicTangent, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::Linear, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::RectifiedLinear);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::RectifiedLinear, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::ExponentialLinear);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::ExponentialLinear, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::ScaledExponentialLinear);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::ScaledExponentialLinear, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SoftPlus);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::SoftPlus, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SoftSign);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::SoftSign, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HardSigmoid);
   assert_true(perceptron_layer.get_activation_function() == PerceptronLayer::HardSigmoid, LOG);
}


void PerceptronLayerTest::test_write_activation_function()
{
   cout << "test_write_activation_function\n";

   perceptron_layer.set();

   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   assert_true(perceptron_layer.write_activation_function() == "Threshold", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   assert_true(perceptron_layer.write_activation_function() == "SymmetricThreshold", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Logistic);
   assert_true(perceptron_layer.write_activation_function() == "Logistic", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   assert_true(perceptron_layer.write_activation_function() == "HyperbolicTangent", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   assert_true(perceptron_layer.write_activation_function() == "Linear", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::RectifiedLinear);
   assert_true(perceptron_layer.write_activation_function() == "RectifiedLinear", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::ExponentialLinear);
   assert_true(perceptron_layer.write_activation_function() == "ExponentialLinear", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SoftPlus);
   assert_true(perceptron_layer.write_activation_function() == "SoftPlus", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SoftSign);
   assert_true(perceptron_layer.write_activation_function() == "SoftSign", LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HardSigmoid);
   assert_true(perceptron_layer.write_activation_function() == "HardSigmoid", LOG);
}


void PerceptronLayerTest::test_get_parameters_number()
{
   cout << "test_get_parameters_number\n";

   Index inputs_number;
   Index neurons_number;

   // Test
   perceptron_layer.set();
   assert_true(perceptron_layer.get_parameters_number() == 0, LOG);

   // Test
   perceptron_layer.set(3, 1);
   assert_true(perceptron_layer.get_parameters_number() == 4, LOG);

   // Test
   perceptron_layer.set(2, 4);
   assert_true(perceptron_layer.get_parameters_number() == 12, LOG);

   //Test3

   inputs_number = 0;
   neurons_number = 0;

   perceptron_layer.set(inputs_number, neurons_number);
   assert_true(perceptron_layer.get_parameters_number() ==0, LOG);
}


void PerceptronLayerTest::test_set()
{
   cout << "test_set\n";

   // Test

   perceptron_layer.set();

   assert_true(perceptron_layer.get_inputs_number() == 0, LOG);
   assert_true(perceptron_layer.get_neurons_number() == 0, LOG);

   // Test

   perceptron_layer.set(1,1);

   perceptron_layer.set();

   assert_true(perceptron_layer.get_inputs_number() == 0, LOG);
   assert_true(perceptron_layer.get_neurons_number() == 0, LOG);

   // Test

   perceptron_layer.set();

   perceptron_layer.set(1,1);

   assert_true(perceptron_layer.get_inputs_number() == 1, LOG);
   assert_true(perceptron_layer.get_neurons_number() == 1, LOG);

}


void PerceptronLayerTest::test_set_default()
{
   cout << "test_set_default\n";

   perceptron_layer.set_default();

   assert_true(perceptron_layer.get_display(), LOG);
   assert_true(perceptron_layer.get_type() == OpenNN::Layer::Perceptron, LOG);
}


void PerceptronLayerTest::test_get_biases()
{
   cout << "test_get_biases\n";

   Tensor<type, 2> biases;

   // Test  
   perceptron_layer.set();
   perceptron_layer.set_parameters_constant(0);
   biases = perceptron_layer.get_biases();

   assert_true(biases.size() == 0, LOG);

   // Test
   perceptron_layer.set(0, 0);
   perceptron_layer.set_parameters_constant(0);
   biases = perceptron_layer.get_biases();

   assert_true(biases.size() == 0, LOG);

   // Test
   perceptron_layer.set(1, 1);
   perceptron_layer.set_parameters_constant(0);
   biases = perceptron_layer.get_biases();

   assert_true(biases.size() == 1, LOG);
   assert_true(biases(0,0) < numeric_limits<type>::min(), LOG);

   // Test
   perceptron_layer.set(4, 5);
   perceptron_layer.set_parameters_constant(0);
   biases = perceptron_layer.get_biases();

   assert_true(biases.size() == 5, LOG);

   cout << "test_get_biases_with_parameters\n";

   // Test  1

   biases.resize(1, 4);
   biases.setValues({{9},{8},{7},{6}});

   Tensor<type, 2> synaptic_weights(2, 4);
   synaptic_weights.setValues({{11, 12, 13, 14},{21, 22, 23, 24}});

   Tensor<type, 1> parameters(12);
   perceptron_layer.set(2, 4);

   perceptron_layer.set_synaptic_weights(synaptic_weights);
   perceptron_layer.set_biases(biases);

   parameters = perceptron_layer.get_parameters();
   biases = perceptron_layer.get_biases(parameters);

   assert_true(biases.size() == 4, LOG);
   assert_true(abs(biases(0,0) - 9) < static_cast<type>(1e-5), LOG);
   assert_true(abs(biases(0,1) - 8) < static_cast<type>(1e-5), LOG);
   assert_true(abs(biases(0,2) - 7) < static_cast<type>(1e-5), LOG);
   assert_true(abs(biases(0,3) - 6) < static_cast<type>(1e-5), LOG);

   assert_true(parameters.size() == 12, LOG);
}


void PerceptronLayerTest::test_get_synaptic_weights()
{
   cout << "test_get_synaptic_weights\n";

   Tensor<type, 2> synaptic_weights;

   // Test
   perceptron_layer.set(1, 1);

   perceptron_layer.set_parameters_constant(0.0);

   synaptic_weights = perceptron_layer.get_synaptic_weights();

   assert_true(synaptic_weights.dimension(0) == 1, LOG);
   assert_true(synaptic_weights.dimension(1) == 1, LOG);
   assert_true(synaptic_weights(0,0) < numeric_limits<type>::min(), LOG);

   // Test
   perceptron_layer.set(1, 2);

   perceptron_layer.set_parameters_constant(0.0);

   synaptic_weights = perceptron_layer.get_synaptic_weights();

   assert_true(synaptic_weights.dimension(0) == 1, LOG);
   assert_true(synaptic_weights.dimension(1) == 2, LOG);
   assert_true(synaptic_weights(0,0) < numeric_limits<type>::min(), LOG);
   assert_true(synaptic_weights(0,1) < numeric_limits<type>::min(), LOG);

   cout << "test_get_synaptic_weight_with_parameters\n";

   // Test
   Tensor<type, 2> biases(1, 4);
   biases.setValues({{9},{-8},{7},{-6}});

   synaptic_weights.resize(2, 4);
   synaptic_weights.setValues({{-11, 12, -13, 14},{21, -22, 23, -24}});

   Tensor<type, 1> parameters(12);
   perceptron_layer.set(2, 4);

   perceptron_layer.set_synaptic_weights(synaptic_weights);
   perceptron_layer.set_biases(biases);

   parameters = perceptron_layer.get_parameters();
   synaptic_weights = perceptron_layer.get_synaptic_weights(parameters);

   assert_true(synaptic_weights.size() == 8, LOG);

   assert_true(abs(synaptic_weights(0,0) + 11) < static_cast<type>(1e-5), LOG);
   assert_true(abs(synaptic_weights(0,1) - 12) < static_cast<type>(1e-5), LOG);
   assert_true(abs(synaptic_weights(1,0) - 21) < static_cast<type>(1e-5), LOG);
   assert_true(abs(synaptic_weights(1,3) + 24) < static_cast<type>(1e-5), LOG);

   // Test

   Index inputs_number = 3;
   Index neurons_number = 1;

   Tensor<type, 2> synaptic_weights_3(1, 3);
   synaptic_weights_3.setValues({{1.0, -0.75, 0.25}});

   Tensor<type, 2> biases_3(1, 1);
   biases_3.setValues({{-0.5}});

   Tensor<type, 2> inputs(1, 3);
   inputs.setValues({{-0.8, 0.2, -0.4}});

   perceptron_layer.set(inputs_number, neurons_number, PerceptronLayer::HyperbolicTangent);

   perceptron_layer.set_biases(biases_3);
   perceptron_layer.set_synaptic_weights(synaptic_weights_3);

   Tensor<type, 2> new_biases = perceptron_layer.get_biases();
   Tensor<type, 2> new_synaptic_weights = perceptron_layer.get_synaptic_weights();

   assert_true(new_biases(0,0) == -0.5, LOG);
   assert_true(new_synaptic_weights(0,0) == 1.0, LOG);
   assert_true(new_synaptic_weights(0,1) == -0.75, LOG);
   assert_true(new_synaptic_weights(0,2) == 0.25, LOG);

}


void PerceptronLayerTest::test_get_parameters()
{
   cout << "test_get_parameters\n";

   Index inputs_number;
   Index neurons_number;
   Index layers_number;

   Index parameters_number;

   Tensor<type, 2> inputs;
   Tensor<type, 2> biases;
   Tensor<type, 2> synaptic_weights;
   Tensor<type, 1> parameters;

   // Test
   perceptron_layer.set(1, 1);
   perceptron_layer.set_parameters_constant(2.0);

   parameters = perceptron_layer.get_parameters();

   assert_true(parameters.size() == 2, LOG);
   assert_true(abs(parameters(0) - 2) < numeric_limits<type>::min(), LOG);

   // Test

   biases.resize(1, 4);
   biases.setValues({{9},{-8},{7},{-6}});

   synaptic_weights.resize(2, 4);
   synaptic_weights.setValues({{-11, 12, -13, 14},{21, -22, 23, -24}});

   perceptron_layer.set_synaptic_weights(synaptic_weights);
   perceptron_layer.set_biases(biases);

   parameters = perceptron_layer.get_parameters();

   assert_true(parameters.size() == 12, LOG);
   assert_true(abs(parameters(0) - 9) < static_cast<type>(1e-5), LOG);
   assert_true(abs(parameters(3) + 6) < static_cast<type>(1e-5), LOG);
   assert_true(abs(parameters(4) + 11) < static_cast<type>(1e-5), LOG);
   assert_true(abs(parameters(7) + 22) < static_cast<type>(1e-5), LOG);
   assert_true(abs(parameters(8) + 13) < static_cast<type>(1e-5), LOG);
   assert_true(abs(parameters(11) + 24) < static_cast<type>(1e-5), LOG);

   // Test

   inputs_number = 3;
   neurons_number = 1;
   layers_number = 1;

   synaptic_weights.resize(1, 3);
   synaptic_weights.setValues({{1.0, -0.75, 0.25}});

   biases.resize(1, 1);
   biases.setValues({{-0.5}});

   inputs.resize(1, 3);
   inputs.setValues({{-0.8, 0.2, -0.4}});

   perceptron_layer.set(inputs_number, neurons_number, PerceptronLayer::HyperbolicTangent);

   perceptron_layer.set_biases(biases);
   perceptron_layer.set_synaptic_weights(synaptic_weights);

   biases = perceptron_layer.get_biases();
   synaptic_weights = perceptron_layer.get_synaptic_weights();

   assert_true(biases(0,0) == -0.5, LOG);
   assert_true(synaptic_weights(0,0) == 1.0, LOG);
   assert_true(synaptic_weights(0,1) == -0.75, LOG);
   assert_true(synaptic_weights(0,2) == 0.25, LOG);

   parameters_number = perceptron_layer.get_parameters_number();

   assert_true(parameters_number == 4, LOG);

   parameters = perceptron_layer.get_parameters();

   assert_true(parameters(0) == -0.5, LOG);
   assert_true(parameters(1) == 1.0, LOG);
   assert_true(parameters(2) == -0.75, LOG);
   assert_true(parameters(3) == 0.25, LOG);
}


void PerceptronLayerTest::test_set_biases()
{

   cout << "test_set_biases\n";

    Tensor<type, 2> biases;

    // Test

    perceptron_layer.set(1, 4);

    biases.resize(1, 4);
    biases.setZero();

    perceptron_layer.set_biases(biases);

    assert_true(perceptron_layer.get_biases_number() == 4, LOG);

    assert_true(abs(perceptron_layer.get_biases()(0)) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(3)) < static_cast<type>(1e-5), LOG);

    // Test
    perceptron_layer.set(1, 4);

    biases.setValues({{9},{-8},{7},{-6}});

    perceptron_layer.set_biases(biases);

    assert_true(perceptron_layer.get_biases_number() == 4, LOG);

    assert_true(abs(perceptron_layer.get_biases()(0) - 9) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(3) + 6) < static_cast<type>(1e-5), LOG);

    // Test

    perceptron_layer.set(2, 3);

    biases.resize(2, 3);
    biases.setValues({{9,1,-8},{7,3,-6}});

    perceptron_layer.set_biases(biases);

    assert_true(perceptron_layer.get_biases_number() == 6, LOG);

    assert_true(abs(perceptron_layer.get_biases()(0,0) - 9) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(0,1) - 1) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(0,2) + 8) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(1,0) - 7) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(1,1) - 3) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_biases()(1,2) + 6) < static_cast<type>(1e-5), LOG);

}


void PerceptronLayerTest::test_set_synaptic_weights()
{
   cout << "test_set_synaptic_weights\n";

   Tensor<type, 2> synaptic_weights;

    // Test

    perceptron_layer.set(1, 2);

    synaptic_weights.resize(2, 1);

    // Test
    synaptic_weights.setZero();

    perceptron_layer.set_synaptic_weights(synaptic_weights);

    assert_true(perceptron_layer.get_synaptic_weights().size() == 2, LOG);

    assert_true(abs(perceptron_layer.get_synaptic_weights()(0)) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(1)) < static_cast<type>(1e-5), LOG);

    // Test
    synaptic_weights.setValues({{-11},{21}});

    perceptron_layer.set_synaptic_weights(synaptic_weights);

    assert_true(perceptron_layer.get_synaptic_weights().size() == 2, LOG);

    assert_true(abs(perceptron_layer.get_synaptic_weights()(0) + 11) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(1) - 21) < static_cast<type>(1e-5), LOG);

    // Test
    Tensor<type, 2> synaptic_weights_1(3,2);

    synaptic_weights_1.setValues({{1,-2},{3,-4},{5,-6}});
    perceptron_layer.set_synaptic_weights(synaptic_weights_1);

    assert_true(perceptron_layer.get_synaptic_weights().size() == 6, LOG);

    assert_true(abs(perceptron_layer.get_synaptic_weights()(0,0) - 1) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(0,1) + 2) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(1,0) - 3) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(1,1) + 4) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(2,0) - 5) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(2,1) + 6) < static_cast<type>(1e-5), LOG);
}


void PerceptronLayerTest::test_set_inputs_number()
{
   cout << "test_set_inputs_number\n";

   Tensor<type, 2> biases;
   Tensor<type, 2> synaptic_weights;

    Tensor<type, 2> new_biases;
    Tensor<type, 2> new_synaptic_weights;

    // Test

    perceptron_layer.set_biases(biases);
    perceptron_layer.set_synaptic_weights(synaptic_weights);

    Index new_inputs_number = 0;

    perceptron_layer.set_inputs_number(new_inputs_number);

    new_biases = perceptron_layer.get_biases();
    new_synaptic_weights = perceptron_layer.get_synaptic_weights();

    assert_true(biases.size() == new_biases.size(), LOG);
    assert_true(synaptic_weights.size() == new_synaptic_weights.size(), LOG);

    // Test

    perceptron_layer.set(1,1);

    biases.resize(2, 2);
    biases.setValues({{7,3},{-1,1}});

    synaptic_weights.resize(1, 2);
    synaptic_weights.setValues({{-11},{21}});

    perceptron_layer.set_biases(biases);
    perceptron_layer.set_synaptic_weights(synaptic_weights);

    Index new_inputs_number_1 = 1;

    perceptron_layer.set_inputs_number(new_inputs_number_1);

    biases = perceptron_layer.get_biases();
    new_synaptic_weights = perceptron_layer.get_synaptic_weights();

//    assert_true(biases.size() == new_biases_1.size(), LOG);
//    assert_true(synaptic_weights_1.size() != new_synaptic_weights_1.size(), LOG);

    // Test
    perceptron_layer.set(2, 2);

    biases.resize(1, 4);
    biases.setValues({{9},{-8},{7},{-6}});

    synaptic_weights.resize(2, 4);
    synaptic_weights.setValues({{-11, 12, -13, 14},{21, -22, 23, -24}});

    perceptron_layer.set_biases(biases);
    perceptron_layer.set_synaptic_weights(synaptic_weights);

    Index new_inputs_number_2 = 6;

    perceptron_layer.set_inputs_number(new_inputs_number_2);

    biases = perceptron_layer.get_biases();
    new_synaptic_weights = perceptron_layer.get_synaptic_weights();

//    assert_true(biases.size() == new_biases_2.size(), LOG);
//    assert_true(synaptic_weights.size() != new_synaptic_weights_2.size(), LOG);
}


void PerceptronLayerTest::test_set_perceptrons_number()
{
   cout << "test_set_perceptrons_number\n";


    Tensor<type, 2> new_biases;
    Tensor<type, 2> new_synaptic_weights;

    // Test

    Tensor<type, 2> biases;
    Tensor<type, 2> synaptic_weights;

    perceptron_layer.set_biases(biases);
    perceptron_layer.set_synaptic_weights(synaptic_weights);

    Index new_perceptrons_number = 0;

    perceptron_layer.set_inputs_number(new_perceptrons_number);

    new_biases = perceptron_layer.get_biases();
    new_synaptic_weights = perceptron_layer.get_synaptic_weights();

    assert_true(biases.size() == new_biases.size(), LOG);
    assert_true(synaptic_weights.size() == new_synaptic_weights.size(), LOG);


    // Test
    perceptron_layer.set(3, 2);

    Tensor<type, 2> biases_1(1, 4);
    biases_1.setValues({{9},{-8},{7},{-6}});

    Tensor<type, 2> synaptic_weights_1(2, 4);
    synaptic_weights_1.setValues({{-11, 12, -13, 14},{21, -22, 23, -24}});

    perceptron_layer.set_synaptic_weights(synaptic_weights_1);

    Index new_perceptrons_number_1= 1;

    perceptron_layer.set_neurons_number(new_perceptrons_number_1);

    new_biases = perceptron_layer.get_biases();
    new_synaptic_weights = perceptron_layer.get_synaptic_weights();

    assert_true(biases_1.size() != new_biases.size(), LOG);
    assert_true(synaptic_weights_1.size() != new_synaptic_weights.size(), LOG);
}


void PerceptronLayerTest::test_set_parameters()
{
  cout << "test_set_parameters\n";



    // Test
    perceptron_layer.set(1, 4);

    Tensor<type, 1> parameters_0(2);

    parameters_0.setZero();

    perceptron_layer.set_parameters(parameters_0);

    assert_true(abs(perceptron_layer.get_biases()(0)) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(0) - parameters_0(0)) < static_cast<type>(1e-5), LOG);


    // Test

    perceptron_layer.set(1, 2);

    Tensor<type, 1> parameters(4);

    parameters.setValues({11,12,21,22});

    perceptron_layer.set_parameters(parameters);

    assert_true(abs(perceptron_layer.get_biases()(0) - parameters(0)) < static_cast<type>(1e-5), LOG);
    assert_true(abs(perceptron_layer.get_synaptic_weights()(0) - parameters(2))  < static_cast<type>(1e-5), LOG);
}


void PerceptronLayerTest::test_set_activation_function()
{
   cout << "test_set_activation_function\n";



   string new_activation_function_name = "Threshold";
   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   assert_true(perceptron_layer.get_activation_function() == 0, LOG);

   new_activation_function_name = "SymmetricThreshold";
   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   assert_true(perceptron_layer.get_activation_function() == 1, LOG);

   new_activation_function_name = "Logistic";
   perceptron_layer.set_activation_function(PerceptronLayer::Logistic);
   assert_true(perceptron_layer.get_activation_function() == 2, LOG);

   new_activation_function_name = "HyperbolicTangent";
   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   assert_true(perceptron_layer.get_activation_function() == 3, LOG);

   new_activation_function_name = "Linear";
   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   assert_true(perceptron_layer.get_activation_function() == 4, LOG);

   new_activation_function_name = "RectifiedLinear";
   perceptron_layer.set_activation_function(PerceptronLayer::RectifiedLinear);
   assert_true(perceptron_layer.get_activation_function() == 5, LOG);

   new_activation_function_name = "ExponentialLinear";
   perceptron_layer.set_activation_function(PerceptronLayer::ExponentialLinear);
   assert_true(perceptron_layer.get_activation_function() == 6, LOG);

   new_activation_function_name = "ScaledExponentialLinear";
   perceptron_layer.set_activation_function(PerceptronLayer::ScaledExponentialLinear);
   assert_true(perceptron_layer.get_activation_function() == 7, LOG);

   new_activation_function_name = "SoftPlus";
   perceptron_layer.set_activation_function(PerceptronLayer::SoftPlus);
   assert_true(perceptron_layer.get_activation_function() == 8, LOG);

   new_activation_function_name = "SoftSign";
   perceptron_layer.set_activation_function(PerceptronLayer::SoftSign);
   assert_true(perceptron_layer.get_activation_function() == 9, LOG);

   new_activation_function_name = "HardSigmoid";
   perceptron_layer.set_activation_function(PerceptronLayer::HardSigmoid);
   assert_true(perceptron_layer.get_activation_function() == 10, LOG);
}


void PerceptronLayerTest::test_set_parameters_constant()
{
   cout << "test_set_parameters_constant\n";


   Tensor<type, 1> parameters;

   // Test

   perceptron_layer.set(2, 1);
   perceptron_layer.set_parameters_constant(0);

   parameters = perceptron_layer.get_parameters();

   assert_true(static_cast<Index>(parameters(0)) == 0, LOG);
   assert_true(static_cast<Index>(parameters(2)) == 0, LOG);

   // Test

   perceptron_layer.set(1, 1);
   perceptron_layer.set_parameters_constant(5);

   parameters = perceptron_layer.get_parameters();

   assert_true(static_cast<Index>(parameters(0)) == 5, LOG);
   assert_true(static_cast<Index>(parameters(1)) == 5, LOG);
}


void PerceptronLayerTest::test_set_synaptic_weights_constant()
{
   cout << "test_set_synaptic_weights_constant\n";



   Tensor<type, 2> synaptic_weights;

   perceptron_layer.set(1, 1);
   perceptron_layer.set_synaptic_weights_constant(5);

   synaptic_weights = perceptron_layer.get_synaptic_weights();

   assert_true(static_cast<Index>(synaptic_weights(0,0)) == 5, LOG);

}


void PerceptronLayerTest::test_set_parameters_random()
{
   cout << "test_set_parameters_random\n";


   Tensor<type, 1> parameters;;

   // Test
   perceptron_layer.set(1,1);
   perceptron_layer.set_parameters_random();

   parameters = perceptron_layer.get_parameters();

   assert_true((parameters(0) >= static_cast<type>(1e-5)) || (parameters(0) <= static_cast<type>(1e-5)), LOG);
   assert_true((parameters(1) >= static_cast<type>(1e-5)) || (parameters(1) <= static_cast<type>(1e-5)), LOG);
}


void PerceptronLayerTest::test_calculate_combinations()
{
   cout << "test_calculate_combinations\n";

   Index parameters_number;

   Tensor<type, 2> biases;
   Tensor<type, 2> synaptic_weights;
   Tensor<type, 1> parameters;

   Tensor<type, 2> inputs;
   Tensor<type, 2> combinations;

   // Test

   inputs_number = 1;
   neurons_number = 1;
   samples_number = 1;

   perceptron_layer.set(inputs_number, neurons_number);
   perceptron_layer.set_parameters_constant(0.0);

   inputs.resize(samples_number, inputs_number);
   inputs.setZero();

   combinations.resize(samples_number, neurons_number);
   combinations.setConstant(3.1416);

   biases = perceptron_layer.get_biases();
   synaptic_weights = perceptron_layer.get_synaptic_weights();

   perceptron_layer.calculate_combinations(inputs, biases, synaptic_weights, combinations);

   // Test

   biases.setConstant(1.0);
   synaptic_weights.setConstant(2.0);

   inputs.setConstant(3.0);

   perceptron_layer.calculate_combinations(inputs, biases, synaptic_weights, combinations);

   assert_true(combinations.rank() == 2, LOG);
   assert_true(combinations.dimension(0) == 1, LOG);
   assert_true(abs(combinations(0,0) - 7) < static_cast<type>(1e-5) , LOG);

    // Test

   inputs_number = 2;
   neurons_number = 2;
   samples_number = 1;

   perceptron_layer.set(inputs_number, neurons_number);
   perceptron_layer.set_parameters_constant(1);

   inputs.resize(samples_number, inputs_number);
   inputs.setConstant(1.0);

   combinations.resize(samples_number, neurons_number);
   combinations.setZero();

   perceptron_layer.calculate_combinations(inputs, perceptron_layer.get_biases(), perceptron_layer.get_synaptic_weights(), combinations);

   assert_true(combinations.rank() == 2, LOG);
   assert_true(combinations.dimension(0) == samples_number, LOG);
   assert_true(combinations.dimension(1) == neurons_number, LOG);
   assert_true(abs(combinations(0,0) - 3) < static_cast<type>(1e-5), LOG);

   // Test

   combinations.resize(2, 4);
   combinations.setZero();

   perceptron_layer.set(3, 4);

   synaptic_weights.resize(3, 4);
   synaptic_weights.setConstant(1.0);
   biases.resize(1,4);
   biases.setConstant(2.0);

   inputs.resize(2,3);
   inputs.setConstant(0.5);

   perceptron_layer.set_synaptic_weights(synaptic_weights);
   perceptron_layer.set_biases(biases);

   perceptron_layer.calculate_combinations(inputs, perceptron_layer.get_biases(), perceptron_layer.get_synaptic_weights(), combinations);

   assert_true(combinations.rank() == 2, LOG);
   assert_true(combinations.dimension(0) == 2, LOG);
   assert_true(combinations.dimension(1) == 4, LOG);
   assert_true(abs(combinations(0,0) - static_cast<type>(3.5)) < static_cast<type>(1e-5), LOG);

   // Test

   inputs_number = 2;
   neurons_number = 4;
   samples_number = 1;

   perceptron_layer.set(inputs_number, neurons_number);

   synaptic_weights.resize(inputs_number, neurons_number);
   synaptic_weights.setConstant(1.0);
   perceptron_layer.set_synaptic_weights(synaptic_weights);

   biases.resize(1, neurons_number);
   biases.setConstant(1.0);
   perceptron_layer.set_biases(biases);

   inputs.resize(samples_number, inputs_number);
   inputs.setValues({{0.5, 0.5}});

   combinations.resize(samples_number, neurons_number);
   combinations.setZero();

   perceptron_layer.calculate_combinations(inputs, perceptron_layer.get_biases(), perceptron_layer.get_synaptic_weights(), combinations);

   assert_true(combinations.rank() == 2, LOG);
   assert_true(combinations.dimension(0) == samples_number, LOG);
   assert_true(combinations.dimension(1) == neurons_number, LOG);
   assert_true(static_cast<Index>(combinations(0,0)) == 2, LOG);

   // Test 

   inputs_number = 1;
   neurons_number = 1;
   samples_number = 1;

   perceptron_layer.set(inputs_number, neurons_number, PerceptronLayer::HyperbolicTangent);

   synaptic_weights.resize(inputs_number, neurons_number);
   synaptic_weights.setValues({{1.0}});
   perceptron_layer.set_synaptic_weights(synaptic_weights);

   synaptic_weights.resize(inputs_number, neurons_number);
   biases.setValues({{-0.5}});
   perceptron_layer.set_biases(biases);

   inputs.resize(samples_number, inputs_number);
   inputs.setValues({{-0.8}});

   biases = perceptron_layer.get_biases();
   synaptic_weights = perceptron_layer.get_synaptic_weights();

   assert_true(biases(0, 0) == -0.5, LOG);
   assert_true(synaptic_weights(0, 0) == 1.0, LOG);

   // Test

   parameters_number = perceptron_layer.get_parameters_number();

   assert_true(parameters_number == 2, LOG);

   parameters = perceptron_layer.get_parameters();

   assert_true(parameters(0) == -0.5, LOG);
   assert_true(parameters(1) == 1.0, LOG);

   // Test

   inputs_number = 1;
   neurons_number = 1;
   samples_number = 1;

   perceptron_layer.set(inputs_number, neurons_number);

   inputs.resize(samples_number, inputs_number);
   inputs.setZero();

   biases.resize(1, neurons_number);
   biases.setZero();

   synaptic_weights.resize(inputs_number, neurons_number);
   synaptic_weights.setZero();

   combinations.resize(samples_number, neurons_number);

   perceptron_layer.calculate_combinations(inputs, biases, synaptic_weights, combinations);

    assert_true(combinations.rank() == 2, LOG);
    assert_true(combinations.dimension(0) == 1, LOG);
    assert_true(combinations.dimension(1) == 1, LOG);

    assert_true(static_cast<type>(combinations(0,0)) - static_cast<type>(-1.55) < static_cast<type>(1e-5), LOG);

}


void PerceptronLayerTest::test_calculate_activations()
{
   cout << "test_calculate_activations\n";

   Tensor<type, 2> biases;
   Tensor<type, 2> synaptic_weights;
   Tensor<type, 1> parameters;

   Tensor<type, 2> inputs;
   Tensor<type, 2> combinations;
   Tensor<type, 2> activations;

   // Test

   inputs_number = 1;
   neurons_number = 1;
   samples_number = 1;

   perceptron_layer.set(inputs_number, neurons_number);
   perceptron_layer.set_parameters_constant(1.0);

   biases = perceptron_layer.get_biases();
   synaptic_weights = perceptron_layer.get_synaptic_weights();

   inputs.resize(samples_number, inputs_number);
   inputs.setConstant(1);

   combinations.resize(samples_number, neurons_number);
   perceptron_layer.calculate_combinations(inputs, biases, synaptic_weights, combinations);

   activations.resize(samples_number, neurons_number);

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   perceptron_layer.calculate_activations(combinations, activations);

   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 1, LOG);
   assert_true(activations.dimension(1) == 1, LOG);
   assert_true(static_cast<Index>(activations(0,0)) == 2 , LOG);

   // Test

   inputs_number = 2;
   neurons_number = 3;
   samples_number = 4;

   perceptron_layer.set(inputs_number, neurons_number);
   perceptron_layer.set_parameters_constant(2);

   inputs.resize(samples_number, inputs_number);
   inputs.setConstant(2);

   combinations.resize(samples_number, neurons_number);
   perceptron_layer.calculate_combinations(inputs, perceptron_layer.get_biases(), perceptron_layer.get_synaptic_weights(), combinations);

   activations.resize(samples_number, neurons_number);

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   perceptron_layer.calculate_activations(combinations, activations);

   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 1, LOG);
   assert_true(activations.dimension(1) == 2, LOG);
   assert_true(static_cast<Index>(activations(0,0)) == 10, LOG);

   // Test
/*
   perceptron_layer.set(2, 2);
   parameters.resize(6);

   parameters.setConstant(0.0);

   combinations.resize(1,2);
   combinations.setConstant(0.0);

   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   perceptron_layer.calculate_activations(combinations, activations);

   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 1, LOG);
   assert_true(activations.dimension(1) == 2, LOG);
   assert_true(static_cast<Index>(activations(0,0)) == 0, LOG);

   // Test 

   perceptron_layer.set(1, 2);
   parameters.resize(4);

   parameters.setConstant(0.0);

   combinations.resize(1,2);
   combinations.setConstant(0.0);

   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   perceptron_layer.calculate_activations(combinations, activations);

   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 1, LOG);
   assert_true(activations.dimension(1) == 2, LOG);
   assert_true(static_cast<Index>(activations(0,0)) == 1 , LOG);

   // Test

   perceptron_layer.set(2, 2);
   parameters.resize(6);

   parameters.setConstant(0.0);

   combinations.resize(1,2);
   combinations.setConstant(-2.0);

   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   perceptron_layer.calculate_activations(combinations, activations);

   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 1, LOG);
   assert_true(activations.dimension(1) == 2, LOG);
   assert_true(static_cast<Index>(activations(0,0))  == -1, LOG);

   // Test

   perceptron_layer.set(1, 2);
   perceptron_layer.set_parameters_constant(0.0);

   combinations.resize(2,2);
   combinations.setConstant(4.0);

   activations.resize(2,2);
   activations.setZero();

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   perceptron_layer.calculate_activations(combinations, activations);

   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 2, LOG);
   assert_true(activations.dimension(1) == 2, LOG);
   assert_true(static_cast<Index>(activations(0,0)) == 4.0, LOG);

   // Test

   perceptron_layer.set(3, 2);
   perceptron_layer.set_parameters_constant(1);

   inputs.resize(1,3);
   inputs.setConstant(0.5);

   combinations.resize(1,2);
   activations.resize(1,2);

   perceptron_layer.calculate_combinations(inputs, perceptron_layer.get_biases(), perceptron_layer.get_synaptic_weights(), combinations);
   assert_true(combinations.rank() == 2, LOG);
   assert_true(combinations.dimension(0) == 1, LOG);
   assert_true(combinations.dimension(1) == 2, LOG);
   assert_true(abs(combinations(0,0) - static_cast<type>(2.5)) < static_cast<type>(1e-5), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   perceptron_layer.calculate_activations(combinations, activations);
   assert_true(activations.rank() == 2, LOG);
   assert_true(activations.dimension(0) == 1, LOG);
   assert_true(activations.dimension(1) == 2, LOG);
   assert_true(static_cast<Index>(activations(0,0)) == 1, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   perceptron_layer.calculate_activations(combinations, activations);
   assert_true(static_cast<Index>(activations(0,0)) == 1, LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Logistic);
   perceptron_layer.calculate_activations(combinations, activations);
   assert_true(abs(activations(0,0) - static_cast<type>(1.0/(1.0+exp(-2.5)))) < static_cast<type>(1e-5), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   perceptron_layer.calculate_activations(combinations, activations);
   assert_true(abs(activations(0,0) - static_cast<type>(tanh(2.5))) < static_cast<type>(1e-5), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   perceptron_layer.calculate_activations(combinations, activations);
   assert_true(abs(activations(0,0) - static_cast<type>(2.5)) < static_cast<type>(1e-5), LOG);
*/
}


void PerceptronLayerTest::test_calculate_activations_derivatives()
{
   cout << "test_calculate_activations_derivatives\n";

   Tensor<type, 1> parameters(1);
   Tensor<type, 2> inputs(1,1);
   Tensor<type, 2> combinations(1,1);
   Tensor<type, 2> activations(1,1);
   Tensor<type, 2> activations_derivatives(1,1);

   // Test

   perceptron_layer.set(1,1);
   perceptron_layer.set_parameters_constant(1);

   inputs.setConstant(1);

   combinations.setConstant(1);

   activations_derivatives.setZero();

   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   assert_true(activations_derivatives.rank() == 2, LOG);
   assert_true(activations_derivatives.dimension(0) == 1, LOG);
   assert_true(activations_derivatives.dimension(1) == 1, LOG);
   assert_true(abs(activations(0,0) - 1) < static_cast<type>(1e-5), LOG);
   assert_true(abs(activations_derivatives(0,0) - 0) < static_cast<type>(1e-5), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - 1) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - 0) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Logistic);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(0.731)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(0.196)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(0.761)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(0.41997)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - 1) < static_cast<type>(1e-5), LOG);
   assert_true(abs(activations_derivatives(0,0) - 1) < static_cast<type>(1e-5), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::RectifiedLinear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(1)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(1)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::ExponentialLinear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(1)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(1)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::ScaledExponentialLinear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(1.05)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(1.05)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SoftPlus);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(1.313)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(0.731)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::SoftSign);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(0.5)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(0.25)) < static_cast<type>(1e-3), LOG);

   perceptron_layer.set_activation_function(PerceptronLayer::HardSigmoid);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);
   assert_true(abs(activations(0,0) - static_cast<type>(0.7)) < static_cast<type>(1e-3), LOG);
   assert_true(abs(activations_derivatives(0,0) - static_cast<type>(0.2)) < static_cast<type>(1e-3), LOG);

   // Test

   perceptron_layer.set(2, 4);
   perceptron_layer.set_parameters_constant(1);

   combinations.resize(1,4);
   combinations.setValues({{1.56f, -0.68f, 0.91f, -1.99f}});

   activations.resize(1,4);

   activations_derivatives.resize(1,4);
   activations_derivatives.setZero();

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::Threshold);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_differentiation.set_numerical_differentiation_method(NumericalDifferentiation::CentralDifferences);
   Tensor<type, 2> numerical_activation_derivative(1,4);
   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::SymmetricThreshold);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::Logistic);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::HyperbolicTangent);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::Linear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::RectifiedLinear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::ExponentialLinear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::ScaledExponentialLinear);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test
   perceptron_layer.set_activation_function(PerceptronLayer::SoftPlus);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test

   perceptron_layer.set_activation_function(PerceptronLayer::SoftSign);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);

   // Test

   perceptron_layer.set_activation_function(PerceptronLayer::HardSigmoid);
   perceptron_layer.calculate_activations_derivatives(combinations, activations, activations_derivatives);

   numerical_activation_derivative
           = numerical_differentiation.calculate_derivatives(perceptron_layer, &PerceptronLayer::calculate_activations, 0, combinations);

   assert_true(activations_derivatives(0,0) - numerical_activation_derivative(0,0) < static_cast<type>(1e-3), LOG);
}


void PerceptronLayerTest::test_calculate_outputs()
{
    cout << "test_calculate_outputs\n";  

    Tensor<type, 2> biases;
    Tensor<type, 2> synaptic_weights;

    Tensor<type, 2> inputs;
    Tensor<type, 2> outputs;
    Tensor<type, 1> parameters;

    // Test    

    inputs_number = 3;
    neurons_number = 4;

    perceptron_layer.set(inputs_number, neurons_number);

    synaptic_weights.resize(inputs_number, neurons_number);
    biases.resize(1, neurons_number);
    inputs.resize(1, inputs_number);

    inputs.setConstant(1);
    biases.setConstant(1);
    synaptic_weights.setValues({{1,-1,0,1},{2,-2,0,2},{3,-3,0,3}});

    perceptron_layer.set_synaptic_weights(synaptic_weights);
    perceptron_layer.set_biases(biases);

    perceptron_layer.set_activation_function(PerceptronLayer::Linear);

    outputs = perceptron_layer.calculate_outputs(inputs);

    assert_true(outputs.rank() == 2, LOG);
    assert_true(outputs.dimension(0) == 1, LOG);
    assert_true(outputs.dimension(1) == 4, LOG);
    assert_true(static_cast<Index>(outputs(0,0)) == 7, LOG);
    assert_true(static_cast<Index>(outputs(1,0)) == -5, LOG);
    assert_true(static_cast<Index>(outputs(2,0)) == 1, LOG);

    // Test

    inputs_number = 2;
    neurons_number = 4;

    biases.resize(1, neurons_number);
    biases.setValues({{9},{-8},{7},{-6}});

    synaptic_weights.resize(2, 4);

    synaptic_weights.resize(2, 4);
    synaptic_weights.setValues({{-11, 12, -13, 14},{21, -22, 23, -24}});

    perceptron_layer.set_synaptic_weights(synaptic_weights);
    perceptron_layer.set_biases(biases);

    inputs.resize(1, 2);
    inputs.setConstant(1);

    perceptron_layer.set_activation_function(PerceptronLayer::Threshold);

    outputs = perceptron_layer.calculate_outputs(inputs);

    assert_true(outputs.rank() == 2, LOG);
    assert_true(outputs.dimension(0) == 1, LOG);
    assert_true(outputs.dimension(1) == 4, LOG);
    assert_true(static_cast<Index>(outputs(0,0)) == 1, LOG);
    assert_true(static_cast<Index>(outputs(1,0)) == 0, LOG);
    assert_true(static_cast<Index>(outputs(2,0)) == 1, LOG);

   // Test

   perceptron_layer.set(3, 2);
   perceptron_layer.set_parameters_constant(0.0);

   inputs.resize(1,3);
   inputs.setConstant(0.0);

   outputs = perceptron_layer.calculate_outputs(inputs);

   assert_true(outputs.rank() == 2, LOG);
   assert_true(outputs.dimension(0) == 1, LOG);
   assert_true(outputs.dimension(1) == 2, LOG);
   assert_true(abs(outputs(0,0) - 0) < static_cast<type>(1e-5), LOG);

   // Test 

   perceptron_layer.set(4, 2);
   parameters.resize(10);
   parameters.setValues({-1,2,-3,4,-5,6,-7,8,-9,10});
   perceptron_layer.set_parameters(parameters);

   inputs.resize(1,4);
   inputs.setValues({{4,-3,2,-1}});

   outputs = perceptron_layer.calculate_outputs(inputs);

   assert_true(outputs.rank() == 2, LOG);
   assert_true(outputs.dimension(0) == 1, LOG);
   assert_true(outputs.dimension(1) == 2, LOG);
   assert_true(abs(outputs(0,0) + 1) < static_cast<type>(1e-5), LOG);

   // Test 5

   inputs.resize(1,1);
   inputs.setConstant((3.0));

   perceptron_layer.set(1, 1);
   perceptron_layer.set_parameters_constant(-2.0);

   outputs = perceptron_layer.calculate_outputs(inputs);

   parameters.resize(2);
   parameters.setConstant(1.0);

   // Test

   perceptron_layer.set(1, 1);

   inputs.resize(1,1);
   inputs.setRandom();

   parameters = perceptron_layer.get_parameters();

}


void PerceptronLayerTest::test_forward_propagate()
{
    cout << "test_forward_propagate\n";

    Tensor<type, 1> parameters;
    Tensor<type, 2> inputs;

    Tensor<type, 1> potential_parameters;

    // Test

    samples_number = 2;
    inputs_number = 2;
    neurons_number = 2;

    perceptron_layer.set(inputs_number, neurons_number, PerceptronLayer::Linear);
    perceptron_layer.set_parameters_constant(1);

    inputs.resize(samples_number, inputs_number);
    inputs.setConstant(1);

    forward_propagation.set(samples_number, &perceptron_layer);
    perceptron_layer.forward_propagate(inputs, &forward_propagation);

    assert_true(forward_propagation.combinations.rank() == 2, LOG);
    assert_true(forward_propagation.combinations.dimension(0) == samples_number, LOG);
    assert_true(forward_propagation.combinations.dimension(1) == neurons_number, LOG);

    assert_true(abs(forward_propagation.combinations(0,0) - static_cast<type>(3)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.combinations(0,1) - static_cast<type>(3)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations(0,0) - static_cast<type>(3)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations(0,1) - static_cast<type>(3)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations_derivatives(0,0) - static_cast<type>(1)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations_derivatives(0,1) - static_cast<type>(1)) < static_cast<type>(1e-3), LOG);

    // Test

    samples_number = 2;
    inputs_number = 2;
    neurons_number = 2;

    perceptron_layer.set(inputs_number, neurons_number, PerceptronLayer::HyperbolicTangent);
    perceptron_layer.set_parameters_constant(1);

    inputs.resize(samples_number, inputs_number);
    inputs.setConstant(1);

    potential_parameters = perceptron_layer.get_parameters();

    forward_propagation.set(samples_number, &perceptron_layer);

/*  @todo
    perceptron_layer.forward_propagate(inputs, potential_parameters, &forward_propagation);

    assert_true(forward_propagation.combinations.rank() == 2, LOG);
    assert_true(forward_propagation.combinations.dimension(0) == samples_number, LOG);
    assert_true(forward_propagation.combinations.dimension(1) == neurons_number, LOG);
    assert_true(abs(forward_propagation.combinations(0,0) - static_cast<type>(3)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.combinations(0,1) - static_cast<type>(3)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations(0,0) - static_cast<type>(0.99505)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations(0,1) - static_cast<type>(0.99505)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations_derivatives(0,0) - static_cast<type>(0.00986)) < static_cast<type>(1e-3), LOG);
    assert_true(abs(forward_propagation.activations_derivatives(0,1) - static_cast<type>(0.00986)) < static_cast<type>(1e-3), LOG);
*/
}


void PerceptronLayerTest::test_write_expression()
{
   cout << "test_write_expression\n";

   Tensor<string, 1> inputs_names(2);
   inputs_names.setValues({"1_in","2_in"});

   Tensor<string, 1> outputs_names(2);
   outputs_names.setValues({"1_out","2_out"});

   string expression;

   perceptron_layer.set(2,2, PerceptronLayer::Logistic);

   expression = perceptron_layer.write_expression(inputs_names,outputs_names);

   assert_true(!expression.empty(), LOG);
}


void PerceptronLayerTest::run_test_case()
{
   cout << "Running perceptron layer test case...\n";

   // Constructor and destructor

   test_constructor();

   // Inputs and perceptrons

   test_get_inputs_number();
   test_get_neurons_number();

   // Parameters

   test_get_parameters_number();
   test_get_biases();
   test_get_synaptic_weights();
   test_get_parameters();

   // Activation functions

   test_get_activation_function();
   test_write_activation_function();

   // Set methods

   test_set();
   test_set_default();

   // Perceptron layer parameters

   test_set_biases();
   test_set_synaptic_weights();
   test_set_perceptrons_number();

   // Inputs

   test_set_inputs_number();

   // Activation functions

   test_set_activation_function();

   // Parameters methods

   test_set_parameters();

   // Parameters initialization methods

   test_set_parameters_constant();
   test_set_synaptic_weights_constant();
   test_set_parameters_random();

   // Combinations

   test_calculate_combinations();

   // Activation

   test_calculate_activations();
   test_calculate_activations_derivatives();

   // Outputs

   test_calculate_outputs();

   // Forward propagate

   test_forward_propagate();

   // Expression methods

   test_write_expression();

   cout << "End of perceptron layer test case.\n\n";
}


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
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
