//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   B O U N D I N G   L A Y E R   T E S T   C L A S S   H E A D E R       
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

#ifndef BOUNDINGLAYERTEST_H
#define BOUNDINGLAYERTEST_H

// Unit testing includes

#include "unit_testing.h"

class BoundingLayerTest : public UnitTesting
{

public: 

   explicit BoundingLayerTest();

   virtual ~BoundingLayerTest();

   // Constructor and destructor methods

   void test_constructor();

   // Get methods

   // Architecture

   void test_get_neurons_number();
   
   // Variables bounds

   void test_get_type();

   // Output methods

   void test_calculate_outputs();

   // Unit testing methods

   void run_test_case();

private:

   BoundingLayer bounding_layer;
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
