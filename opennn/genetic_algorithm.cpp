//   OpenNN: Open Neural Networks Library
//   www.opennn.net
//
//   G E N E T I C   A L G O R I T H M   C L A S S
//
//   Artificial Intelligence Techniques SL
//   artelnics@artelnics.com

#include "genetic_algorithm.h"

namespace OpenNN
{

/// Default constructor.

GeneticAlgorithm::GeneticAlgorithm()
    : InputsSelection()
{
    set_default();
}


/// Training strategy constructor.
/// @param new_training_strategy_pointer Pointer to a training strategy object.

GeneticAlgorithm::GeneticAlgorithm(TrainingStrategy* new_training_strategy_pointer)
    : InputsSelection(new_training_strategy_pointer)
{
    set_default();
}


/// Destructor.

GeneticAlgorithm::~GeneticAlgorithm()
{
}


/// Returns the population matrix.

const Tensor<bool, 2>& GeneticAlgorithm::get_population() const
{
    return population;
}


/// Returns the fitness of the population.

const Tensor<type, 1>& GeneticAlgorithm::get_fitness() const
{
    return fitness;
}


const Tensor<bool, 1>& GeneticAlgorithm::get_selection() const
{
    return selection;
}


/// Returns the size of the population.

Index GeneticAlgorithm::get_individuals_number() const
{
    return population.dimension(0);
}


Index GeneticAlgorithm::get_genes_number() const
{
    return population.dimension(1);
}


/// Returns the rate used in the mutation.

const type& GeneticAlgorithm::get_mutation_rate() const
{
    return mutation_rate;
}


/// Returns the size of the elite in the selection.

const Index& GeneticAlgorithm::get_elitism_size() const
{
    return elitism_size;
}


/// Sets the members of the genetic algorithm object to their default values.

void GeneticAlgorithm::set_default()
{
    const Index genes_number = get_genes_number();
    Index individuals_number;

    maximum_epochs_number = 100;

    mutation_rate = static_cast<type>(0.1);

    individuals_number = 10;

    // Population stuff

    population.resize(individuals_number, genes_number);

    parameters.resize(individuals_number);
    for(Index i = 0; i < individuals_number; i++) parameters(i).resize(genes_number);

    training_errors.resize(individuals_number);
    selection_errors.resize(individuals_number);

    fitness.resize(individuals_number);
    fitness.setConstant(-1.0);

    selection.resize(individuals_number);

    // Training operators

    elitism_size = 2;
}


/// Sets a new popualtion.
/// @param new_population New population matrix.

void GeneticAlgorithm::set_population(const Tensor<bool, 2>& new_population)
{
#ifdef OPENNN_DEBUG

    const Index individuals_number = get_individuals_number();
    const Index new_individuals_number = new_population.dimension(2);

    // Optimization algorithm

    ostringstream buffer;

    if(!training_strategy_pointer)
    {
        buffer << "OpenNN Exception: InputsSelection class.\n"
               << "void check() const method.\n"
               << "Pointer to training strategy is nullptr.\n";

        throw logic_error(buffer.str());
    }

    // Loss index

    const LossIndex* loss_index_pointer = training_strategy_pointer->get_loss_index_pointer();

    if(!loss_index_pointer)
    {
        buffer << "OpenNN Exception: InputsSelection class.\n"
               << "void check() const method.\n"
               << "Pointer to loss index is nullptr.\n";

        throw logic_error(buffer.str());
    }

    // Neural network

    const NeuralNetwork* neural_network_pointer = loss_index_pointer->get_neural_network_pointer();

    if(!neural_network_pointer)
    {
        buffer << "OpenNN Exception: InputsSelection class.\n"
               << "void check() const method.\n"
               << "Pointer to neural network is nullptr.\n";

        throw logic_error(buffer.str());
    }

    if(new_individuals_number  != individuals_number)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void set_population(const Tensor<type, 2>&) method.\n"
               << "Population rows("<<new_individuals_number
               << ") must be equal to population size("<<individuals_number<<").\n";

        throw logic_error(buffer.str());
    }

#endif

    population = new_population;
}


void GeneticAlgorithm::set_training_errors(const Tensor<type, 1>& new_training_errors)
{
    training_errors = new_training_errors;
}


void GeneticAlgorithm::set_selection_errors(const Tensor<type, 1>& new_selection_errors)
{
    selection_errors = new_selection_errors;
}


/// Sets a new fitness for the population.
/// @param new_fitness New fitness values.

void GeneticAlgorithm::set_fitness(const Tensor<type, 1>& new_fitness)
{
#ifdef OPENNN_DEBUG

    const Index individuals_number = get_individuals_number();

    if(new_fitness.size() != individuals_number)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void set_fitness(const Tensor<type, 1>&) method.\n"
               << "Fitness size ("<<new_fitness.size()
               << ") must be equal to population size ("<< individuals_number <<").\n";

        throw logic_error(buffer.str());
    }

    for(Index i = 0; i < individuals_number; i++)
    {
        if(new_fitness[i] < 0)
        {
            ostringstream buffer;

            buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
                   << "void set_fitness(const Tensor<type, 2>&) method.\n"
                   << "Fitness must be greater than 0.\n";

            throw logic_error(buffer.str());
        }
    }

#endif

    fitness = new_fitness;
}


/// Sets a new population size. It must be greater than 4.
/// @param new_population_size Size of the population.

void GeneticAlgorithm::set_individuals_number(const Index& new_individuals_number)
{
#ifdef OPENNN_DEBUG

    if(new_individuals_number < 4)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void set_individuals_number(const Index&) method.\n"
               << "Population size must be greater than 4.\n";

        throw logic_error(buffer.str());
    }

#endif

    const Index new_genes_number = training_strategy_pointer->get_data_set_pointer()->get_input_columns_number();

    population.resize(new_individuals_number, new_genes_number);

    parameters.resize(new_individuals_number);

    training_errors.resize(new_individuals_number);
    selection_errors.resize(new_individuals_number);

    fitness.resize(new_individuals_number);
    fitness.setConstant(-1.0);

    selection.resize(new_individuals_number);

    if(elitism_size > new_individuals_number) elitism_size = new_individuals_number;
}


/// Sets a new rate used in the mutation.
/// It is a number between 0 and 1.
/// @param new_mutation_rate Rate used for the mutation.

void GeneticAlgorithm::set_mutation_rate(const type& new_mutation_rate)
{
#ifdef OPENNN_DEBUG

    if(new_mutation_rate < 0 || new_mutation_rate > 1)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void set_mutation_rate(const type&) method.\n"
               << "Mutation rate must be between 0 and 1.\n";

        throw logic_error(buffer.str());
    }

#endif

    mutation_rate = new_mutation_rate;
}


/// Sets the number of individuals with the greatest fitness selected.
/// @param new_elitism_size Size of the elitism.

void GeneticAlgorithm::set_elitism_size(const Index& new_elitism_size)
{
#ifdef OPENNN_DEBUG

    const Index individuals_number = get_individuals_number();

    if(new_elitism_size > individuals_number)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void set_elitism_size(const Index&) method.\n"
               << "Elitism size("<< new_elitism_size
               <<") must be lower than the population size("<<individuals_number<<").\n";

        throw logic_error(buffer.str());
    }

#endif

    elitism_size = new_elitism_size;
}


/// Initialize the population depending on the intialization method.

void GeneticAlgorithm::initialize_population()
{
    const Index individuals_number = get_individuals_number();

#ifdef OPENNN_DEBUG

    if(individuals_number == 0)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void initialize_population() method.\n"
               << "Population size must be greater than 0.\n";

        throw logic_error(buffer.str());
    }

#endif

    const Index genes_number = get_genes_number();

    Tensor<bool, 1> individual(genes_number);

    for(Index i = 0; i < individuals_number; i++)
    {
        for(Index j = 0; j < genes_number; j++)
        {
            rand()%2 == 0 ? individual[j] = false : individual[j] = true;
        }

        // Prevent no inputs

        if(is_false(individual))
        {
            individual(static_cast<Index>(rand())%genes_number) = true;
        }

        for(Index j = 0; j < genes_number; j++)
        {
            population(i,j) = individual(j);
        }
    }
}


/// Evaluate the population loss.
/// Training all the neural networks in the population and calculate their fitness.

void GeneticAlgorithm::evaluate_population()
{
#ifdef OPENNN_DEBUG

    check();

    if(population.size() == 0)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void evaluate_population() method.\n"
               << "Population size must be greater than 0.\n";

        throw logic_error(buffer.str());
    }

#endif

    // Training strategy

    TrainingResults training_results;

    // Loss index

    const LossIndex* loss_index_pointer = training_strategy_pointer->get_loss_index_pointer();

    // Data set

    DataSet* data_set_pointer = loss_index_pointer->get_data_set_pointer();

    Tensor<string, 1> inputs_names;

    // Neural network

    NeuralNetwork* neural_network_pointer = loss_index_pointer->get_neural_network_pointer();

    // Optimization algorithm

    Tensor<bool, 1> individual;

    // Model selection

    const Index individuals_number = get_individuals_number();
    const Index genes_number = get_genes_number();

    for(Index i = 0; i < individuals_number; i++)
    {
        individual = population.chip(i, 0);

        if(display) cout << "Individual " << i+1 << endl;

        const Tensor<Index, 0> input_columns_number = individual.cast<Index>().sum();

        Tensor<Index, 1> input_columns_indices(input_columns_number(0));

        Index index = 0;

        for(Index j = 0; j < genes_number; j++)
        {
            if(individual(j))
            {
                input_columns_indices(index) = original_input_columns_indices(j);
                index++;
            }
        }

        data_set_pointer->set_input_target_columns(input_columns_indices, original_target_columns_indices);

        inputs_names = data_set_pointer->get_input_variables_names();

        neural_network_pointer->set_inputs_number(data_set_pointer->get_input_variables_number());

        neural_network_pointer->set_inputs_names(inputs_names);

        neural_network_pointer->set_parameters_random();

        training_results = training_strategy_pointer->perform_training();

        // Set stuff

        parameters(i) = neural_network_pointer->get_parameters();

        training_errors(i) = training_results.get_training_error();
        selection_errors(i) = training_results.get_selection_error();

        if(display)
        {
            cout << "Inputs: " << endl;

            const Tensor<string, 1> inputs_names = neural_network_pointer->get_inputs_names();

            for(Index i = 0; i < inputs_names.size(); i++) cout << "   " << inputs_names(i) << endl;

            cout << "Training error: " << training_results.get_training_error() << endl;
            cout << "Selection error: " << training_results.get_selection_error() << endl;
        }
    }
}


/// Calculate the fitness with the errors depending on the fitness assignment method.

void GeneticAlgorithm::perform_fitness_assignment()
{
    const Index individuals_number = get_individuals_number();

    const Tensor<Index, 1> rank = calculate_rank_greater(selection_errors);

    for(Index i = 0; i < individuals_number; i++)
    {
        fitness(rank(i)) = i+1;
    }
}


/// Selects for crossover some individuals from the population.

void GeneticAlgorithm::perform_selection()
{
#ifdef OPENNN_DEBUG

    if(population.size() == 0)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void perform_selection() method.\n"
               << "Population size must be greater than 0.\n";

        throw logic_error(buffer.str());
    }

    if(fitness.dimension(0) == 0)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void perform_selection() method.\n"
               << "No fitness found.\n";

        throw logic_error(buffer.str());
    }

#endif

    selection.setConstant(false);

    const Index individuals_number = get_individuals_number();

    const Index selected_individuals_number = static_cast<Index>((individuals_number-elitism_size)/2);

    const Tensor<type, 1> cumulative_fitness = fitness.cumsum(0);

    Tensor<Index, 1> fitness_rank = calculate_rank_greater(fitness);

    Index selection_count = 0;

    // Roulette wheel selection

    do
    {
        const type pointer = static_cast<type>(rand()/(RAND_MAX+1.0))*cumulative_fitness(individuals_number-1);

        if(pointer < cumulative_fitness(0) && !selection(0))
        {
            selection(0) = true;
            selection_count++;
            continue;
        }

        for(Index i = 1; i < individuals_number; i++)
        {
            if(cumulative_fitness(i-1) < pointer
                    && pointer < cumulative_fitness(i)
                    && !selection(i))
            {
                selection(i) = true;
                selection_count++;
                break;
            }
        }

    }while(selection_count < selected_individuals_number);

#ifdef OPENNN_DEBUG

    Index selection_assert = 0;
    for(Index i = 0; i < individuals_number; i++) if(selection(i)) selection_assert++;

    if(selection_assert != individuals_number/2)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void perform_selection() method.\n"
               << "Number of selected individuals (" << selection_assert << ") must be " << individuals_number/2 << " .\n";

        throw logic_error(buffer.str());
    }

#endif

}


/// Perform the crossover depending on the crossover method.

void GeneticAlgorithm::perform_crossover()
{
    const Index individuals_number = get_individuals_number();
    const Index genes_number = get_genes_number();

#ifdef OPENNN_DEBUG

    const Index selected_individuals_number = individuals_number/2;

    Index count_selected_individuals = 0;
    for(Index i = 0; i < individuals_number; i++) if(selection(i)) count_selected_individuals++;

    if(selected_individuals_number != count_selected_individuals)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void perform_crossover() method.\n"
               << "Selected individuals number is wrong.\n";

        throw logic_error(buffer.str());
    }

#endif

    Index parent_1_index = 0;
    Index parent_2_index = 0;

    Tensor<bool, 1> parent_1(genes_number);
    Tensor<bool, 1> parent_2(genes_number);

    Tensor<bool, 1> offspring_1(genes_number);
    Tensor<bool, 1> offspring_2(genes_number);

    Index offspring_count = 0;

    Tensor<bool, 2> new_population(individuals_number, genes_number);

    Index new_individual_index = 0;

    Tensor<Index, 1> fitness_rank = calculate_rank_greater(fitness);

    for(Index i = 0; i < elitism_size ; i++)
    {
        new_individual_index = fitness_rank(i);

        for(Index j = 0; j < genes_number; j++)
        {
            new_population(offspring_count, j) = population(new_individual_index, j);
        }

        offspring_count++;
    }

    for(Index i = 0; i < individuals_number; i++)
    {
        if(offspring_count > individuals_number-1) break;

        if(!selection(i)) continue;

        parent_1_index = i;

        do{
            parent_2_index = static_cast<Index>(rand())%individuals_number;
        }while(selection(parent_2_index) && parent_1_index != parent_2_index);

        parent_1 = population.chip(parent_1_index, 0);
        parent_2 = population.chip(parent_2_index, 0);

        for(Index j = 0; j < genes_number; j++)
        {
            if(rand()%2 == 0)
            {
                offspring_1(j) = parent_1[j];
                offspring_2(j) = parent_2[j];
            }
            else
            {
                offspring_1(j) = parent_2[j];
                offspring_2(j) = parent_1[j];
            }
        }

        // Prevent no inputs

        if(is_false(offspring_1))
            offspring_1(static_cast<Index>(rand())%genes_number) = true;

        if(is_false(offspring_2))
            offspring_2(static_cast<Index>(rand())%genes_number) = true;

        for(Index j = 0; j < genes_number; j++)
        {
            new_population(offspring_count, j) = offspring_1(j);

            // In case of even population size, this checks the size

            if(offspring_count + 1 <= individuals_number-1) new_population(offspring_count+1, j) = offspring_2(j);
        }

        offspring_count += 2;
    }

    // In case of odd population size, fill the last offspring of the new population

    if(offspring_count == individuals_number-1)
    {
        for(Index i = 0; i < individuals_number; i++)
        {
            if(!selection(i)) continue;

            parent_1_index = i;

            do{
                parent_2_index = static_cast<Index>(rand())%individuals_number;
            }while(selection(parent_2_index) && parent_1_index != parent_2_index);

            parent_1 = population.chip(parent_1_index, 0);
            parent_2 = population.chip(parent_2_index, 0);

            for(Index j = 0; j < genes_number; j++)
            {
                if(rand()%2 == 0)
                {
                    offspring_1(j) = parent_1[j];
                }
                else
                {
                    offspring_1(j) = parent_2[j];
                }
            }

            if(is_false(offspring_1))
                offspring_1(static_cast<Index>(rand())%genes_number) = true;

            for(Index j = 0; j < genes_number; j++)
            {
                new_population(offspring_count, j) = offspring_1(j);
            }
        }
    }

    population = new_population;
}


/// Perform the mutation of the individuals generated in the crossover.

void GeneticAlgorithm::perform_mutation()
{
    const Index individuals_number = get_individuals_number();

    const Index genes_number = get_genes_number();

    Tensor<bool, 1> individual(genes_number);

    for(Index i = 0; i < individuals_number; i++)
    {
        for(Index j = 0; j < genes_number; j++)
        {
            if(static_cast<type>(rand()/(RAND_MAX+1.0)) <= mutation_rate)
                population(i,j) = !population(i,j);
        }

        // Prevent no inputs

        individual = population.chip(i, 0);

        if(is_false(individual))
        {
            individual(static_cast<Index>(rand())%genes_number) = true;

            for(Index j = 0; j < genes_number; j++)
                population(i, j) = individual(j);
        }
    }
}


/// Select the inputs with best generalization properties using the genetic algorithm.

InputsSelectionResults GeneticAlgorithm::perform_inputs_selection()
{
#ifdef OPENNN_DEBUG

    check();

#endif

    if(population.size() == 0) set_individuals_number(10);

    if(display) cout << "Performing genetic inputs selection..." << endl << endl;

    InputsSelectionResults inputs_selection_results(maximum_epochs_number);

    // Training strategy

    training_strategy_pointer->set_display(false);

    // Loss index

    const LossIndex* loss_index_pointer = training_strategy_pointer->get_loss_index_pointer();

    // Data set

    DataSet* data_set_pointer = loss_index_pointer->get_data_set_pointer();

    original_input_columns_indices = data_set_pointer->get_input_columns_indices();
    original_target_columns_indices = data_set_pointer->get_target_columns_indices();

    // Neural network

    NeuralNetwork* neural_network_pointer = loss_index_pointer->get_neural_network_pointer();

    // Optimization algorithm

    Index optimal_individual_index;

    bool stop = false;

    time_t beginning_time, current_time;
    type elapsed_time = 0;

    time(&beginning_time);

    initialize_population();

    for(Index epoch = 0; epoch < maximum_epochs_number; epoch++)
    {
        if(display) cout << "Generation: " << epoch + 1 << endl;

        evaluate_population();

        optimal_individual_index = minimal_index(selection_errors);

        inputs_selection_results.training_error_history(epoch) = training_errors(optimal_individual_index);
        inputs_selection_results.selection_error_history(epoch) = selection_errors(optimal_individual_index);

        if(selection_errors(optimal_individual_index) < inputs_selection_results.optimum_selection_error)
        {
            // Neural network

            inputs_selection_results.optimal_inputs = population.chip(optimal_individual_index, 0);

            data_set_pointer->set_input_columns(original_input_columns_indices, inputs_selection_results.optimal_inputs);

            inputs_selection_results.optimal_input_columns_names = data_set_pointer->get_input_columns_names();

            inputs_selection_results.optimal_parameters = parameters(optimal_individual_index);

            // Loss index

            inputs_selection_results.optimum_training_error = training_errors(optimal_individual_index);

            inputs_selection_results.optimum_selection_error = selection_errors(optimal_individual_index);
        }

        time(&current_time);

        elapsed_time = static_cast<type>(difftime(current_time, beginning_time));

        if(display)
        {
            cout << endl;
            cout << "Generation mean training error: " << training_errors.mean() << endl;
            cout << "Generation mean selection error: " << selection_errors.mean() << endl;

            cout << "Generation minimum training error: " << training_errors(optimal_individual_index) << endl;
            cout << "Generation minimum selection error: " << selection_errors(optimal_individual_index) << endl;

            cout << "Best ever training error: " << inputs_selection_results.optimum_training_error << endl;
            cout << "Best ever selection error: " << inputs_selection_results.optimum_selection_error << endl;

            cout << "Elapsed time: " << write_time(elapsed_time) << endl;
        }

        // Stopping criteria

        if(elapsed_time >= maximum_time)
        {
            stop = true;

            if(display) cout << "Epoch " << epoch << endl << "Maximum time reached: " << write_time(elapsed_time) << endl;

            inputs_selection_results.stopping_condition = InputsSelection::MaximumTime;
        }

        if(selection_errors(optimal_individual_index) <= selection_error_goal) //???
        {
            stop = true;

            if(display) cout << "Epoch  " << epoch << endl << "Selection error reached: " << selection_errors(optimal_individual_index) << endl;

            inputs_selection_results.stopping_condition = InputsSelection::SelectionErrorGoal;
        }

        if(epoch >= maximum_epochs_number-1)
        {
            stop = true;

            if(display) cout << "Epoch " << epoch << endl << "Maximum number of epochs reached: " << epoch << endl;

            inputs_selection_results.stopping_condition = InputsSelection::MaximumEpochs;
        }

        if(stop)
        {
            inputs_selection_results.elapsed_time = write_time(elapsed_time);

            inputs_selection_results.resize_history(epoch+1);

            break;
        }

        perform_fitness_assignment();

        perform_selection();

        perform_crossover();

        perform_mutation();
    }

    // Set data set stuff

    data_set_pointer->set_input_columns(original_input_columns_indices, inputs_selection_results.optimal_inputs);

    const Tensor<Scaler, 1> input_variables_scalers = data_set_pointer->get_input_variables_scalers();

    const Tensor<Descriptives, 1> input_variables_descriptives = data_set_pointer->calculate_input_variables_descriptives();

    // Set neural network stuff

    neural_network_pointer->set_inputs_number(data_set_pointer->get_input_variables_number());

    neural_network_pointer->set_inputs_names(data_set_pointer->get_input_variables_names());

    if(neural_network_pointer->has_scaling_layer())
        neural_network_pointer->get_scaling_layer_pointer()->set(input_variables_descriptives, input_variables_scalers);

    neural_network_pointer->set_parameters(inputs_selection_results.optimal_parameters);

    if(display) inputs_selection_results.print();

    return inputs_selection_results;
}


/// Writes as matrix of strings the most representative atributes.
/// @todo to many rows in string matrix.

Tensor<string, 2> GeneticAlgorithm::to_string_matrix() const
{
    Tensor<string, 2> string_matrix(8, 2);

    const Index individuals_number = get_individuals_number();

    ostringstream buffer;

    Tensor<string, 1> labels(6);
    Tensor<string, 1> values(6);

    // Population size

    labels(0) = "Population size";
    values(0) = to_string(individuals_number);

    // Elitism size

    labels(1) = "Elitism size";
    values(1) = to_string(elitism_size);

    // Mutation rate

    labels(2) = "Mutation rate";
    values(2) = to_string(mutation_rate);

    // Selection loss goal

    labels(3) = "Selection loss goal";
    values(3) = to_string(selection_error_goal);

    // Maximum Generations number

    labels(4) = "Maximum Generations number";
    values(4) = to_string(maximum_epochs_number);

    // Maximum time

    labels(5) = "Maximum time";
    values(5) = to_string(maximum_time);

    string_matrix.chip(0, 1) = labels;
    string_matrix.chip(1, 1) = values;

    return string_matrix;
}


/// Serializes the genetic algorithm object into a XML document of the TinyXML library without keep the DOM
/// tree in memory.
/// See the OpenNN manual for more information about the format of this document.

void GeneticAlgorithm::write_XML(tinyxml2::XMLPrinter& file_stream) const
{
    const Index individuals_number = get_individuals_number();

    ostringstream buffer;

    file_stream.OpenElement("GeneticAlgorithm");

    // Population size

    file_stream.OpenElement("PopulationSize");

    buffer.str("");
    buffer << individuals_number;

    file_stream.PushText(buffer.str().c_str());

    file_stream.CloseElement();

    // Elitism size

    file_stream.OpenElement("ElitismSize");

    buffer.str("");
    buffer << elitism_size;

    file_stream.PushText(buffer.str().c_str());

    file_stream.CloseElement();

    // Mutation rate

    file_stream.OpenElement("MutationRate");

    buffer.str("");
    buffer << mutation_rate;

    file_stream.PushText(buffer.str().c_str());

    file_stream.CloseElement();

    // selection error goal

    file_stream.OpenElement("SelectionErrorGoal");

    buffer.str("");
    buffer << selection_error_goal;

    file_stream.PushText(buffer.str().c_str());

    file_stream.CloseElement();

    // Maximum iterations

    file_stream.OpenElement("MaximumGenerationsNumber");

    buffer.str("");
    buffer << maximum_epochs_number;

    file_stream.PushText(buffer.str().c_str());

    file_stream.CloseElement();

    // Maximum time

    file_stream.OpenElement("MaximumTime");

    buffer.str("");
    buffer << maximum_time;

    file_stream.PushText(buffer.str().c_str());

    file_stream.CloseElement();

    file_stream.CloseElement();
}


/// Deserializes a TinyXML document into this genetic algorithm object.
/// @param document TinyXML document containing the member data.

void GeneticAlgorithm::from_XML(const tinyxml2::XMLDocument& document)
{
    const tinyxml2::XMLElement* root_element = document.FirstChildElement("GeneticAlgorithm");

    if(!root_element)
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
               << "GeneticAlgorithm element is nullptr.\n";

        throw logic_error(buffer.str());
    }

    // Population size
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("PopulationSize");

        if(element)
        {
            const Index new_population_size = static_cast<Index>(atoi(element->GetText()));

            try
            {
                set_individuals_number(new_population_size);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Mutation rate
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("MutationRate");

        if(element)
        {
            const type new_mutation_rate = static_cast<type>(atof(element->GetText()));

            try
            {
                set_mutation_rate(new_mutation_rate);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Elitism size
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("ElitismSize");

        if(element)
        {
            const Index new_elitism_size = static_cast<Index>(atoi(element->GetText()));

            try
            {
                set_elitism_size(new_elitism_size);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Display
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("Display");

        if(element)
        {
            const string new_display = element->GetText();

            try
            {
                set_display(new_display != "0");
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // selection error goal
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("SelectionErrorGoal");

        if(element)
        {
            const type new_selection_error_goal = static_cast<type>(atof(element->GetText()));

            try
            {
                set_selection_error_goal(new_selection_error_goal);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Maximum iterations number
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumGenerationsNumber");

        if(element)
        {
            const Index new_maximum_epochs_number = static_cast<Index>(atoi(element->GetText()));

            try
            {
                set_maximum_epochs_number(new_maximum_epochs_number);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Maximum correlation
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumCorrelation");

        if(element)
        {
            const type new_maximum_correlation = static_cast<type>(atof(element->GetText()));

            try
            {
                set_maximum_correlation(new_maximum_correlation);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Minimum correlation
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("MinimumCorrelation");

        if(element)
        {
            const type new_minimum_correlation = static_cast<type>(atof(element->GetText()));

            try
            {
                set_minimum_correlation(new_minimum_correlation);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }

    // Maximum time
    {
        const tinyxml2::XMLElement* element = root_element->FirstChildElement("MaximumTime");

        if(element)
        {
            const type new_maximum_time = atoi(element->GetText());

            try
            {
                set_maximum_time(new_maximum_time);
            }
            catch(const logic_error& e)
            {
                cerr << e.what() << endl;
            }
        }
    }
}


void GeneticAlgorithm::print() const
{
    cout << "Genetic algorithm" << endl;
    cout << "Individuals number: " << get_individuals_number() << endl;
    cout << "Genes number: " << get_genes_number() << endl;
}


/// Saves to a XML-type file the members of the genetic algorithm object.
/// @param file_name Name of genetic algorithm XML-type file.

void GeneticAlgorithm::save(const string& file_name) const
{
    FILE * file = fopen(file_name.c_str(), "w");

    tinyxml2::XMLPrinter printer(file);

    write_XML(printer);

    fclose(file);
}


/// Loads a genetic algorithm object from a XML-type file.
/// @param file_name Name of genetic algorithm XML-type file.

void GeneticAlgorithm::load(const string& file_name)
{
    set_default();

    tinyxml2::XMLDocument document;

    if(document.LoadFile(file_name.c_str()))
    {
        ostringstream buffer;

        buffer << "OpenNN Exception: GeneticAlgorithm class.\n"
               << "void load(const string&) method.\n"
               << "Cannot load XML file " << file_name << ".\n";

        throw logic_error(buffer.str());
    }

    from_XML(document);
}

}

// OpenNN: Open Neural Networks Library.
// Copyright(C) 2005-2021 Artificial Intelligence Techniques, SL.
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
