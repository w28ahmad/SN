// Print the matrix
template <typename type>
void print_matrix(type**& matrix, int size, int row_size = 0);

// Generate the matrix from txt file
bool** generate_matrix(bool**& matrix, int size);

// Reflexive closure
bool** reflexive_closure(bool**& matrix, int size);

// Transitive Closure
bool** trasitive_closure(bool**& matrix, int size);

// Finding Equivalent Closure by testing for symmetric closures
void test_symmetric_closure(bool**& matrix, int size);
