//   OpenNN: An Open Source Neural Networks C++ Library                    
//   www.opennn.net
//
//   M O D E L   S E L E C T I O N   T E S T   C L A S S   H E A D E R     
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com                                           

#ifndef MODELSELECTIONTEST_H
#define MODELSELECTIONTEST_H

#include "unit_testing.h"

class ModelSelectionTest : public UnitTesting 
{

public:

   explicit ModelSelectionTest();

   virtual ~ModelSelectionTest();

   // Constructor and destructor methods

   void test_constructor();
   void test_destructor();

   // Get methods

   void test_get_training_strategy_pointer();

   // Set methods

   void test_set();

   // Model selection methods

   void test_perform_neurons_selection();

   // Serialization methods

   void test_to_XML();   
   void test_from_XML();
   void test_save();
   void test_load();

   // Unit testing methods

   void run_test_case();

private:

   DataSet data_set;

   NeuralNetwork neural_network;

   TrainingStrategy training_strategy;

   ModelSelection model_selection;

};

#endif
