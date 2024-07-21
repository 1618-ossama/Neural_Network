# Neural Network Implementation in C

This project demonstrates a basic implementation of a neural network in C. The code defines the structures and functions necessary to construct, initialize, and manipulate layers and weight matrices of a neural network. 

## Files

- `main.c`: The main file containing the implementation and example usage.

## Data Structures

### Layer

Represents a single layer in the neural network.

```c
typedef struct {
    int neuronCount;
    float *biasArray;
    float *neuronArray;
} Layer;
```
- neuronCount: The number of neurons in the layer.
- biasArray: An array of biases for each neuron.
- neuronArray: An array of neuron values.

### Matrix

Represents a weight matrix in the neural network.

```c
typedef struct {
    int rowCount;
    int colCount;
    float *values;
} Matrix;
```
- rowCount: The number of rows in the matrix.
- colCount: The number of columns in the matrix.
- values: A pointer to the array of values in the matrix.

### Network

Represents the entire neural network.

```c
typedef struct {
    int layerCount;
    Layer **layers;
    Matrix **weights;
} Network;
```
- layerCount: The number of layers in the network.
- layers: An array of pointers to the layers.
- weights: An array of pointers to the weight matrices.

## Functions

### Layer Functions

- **`Layer *construct_Layer(int count)`**: Constructs a layer with a given number of neurons.
- **`void destroy_Layer(Layer *layer)`**: Frees the memory allocated for a layer.
- **`void print_Layer(Layer *layer)`**: Prints the details of a layer.

### Matrix Functions

- **`void init_Weight(Matrix *weight, int rows, int columns)`**: Initializes a weight matrix with random values.
- **`void print_Weight(Matrix *weight)`**: Prints the details of a weight matrix.
- **`Matrix *dot_product(Matrix *a, Matrix *b)`**: Computes the dot product of two matrices.

### Network Functions

- **`Network *construct_Network(int layerCount, int *neuron_Layer)`**: Constructs a neural network with a given number of layers and neurons per layer.
- **`void destroy_Network(Network *network)`**: Frees the memory allocated for a network.

## Notes

- The implementation is unfinished and may not cover all aspects of a complete neural network system.
- The print_Weight function is currently commented out in the construct_Network function. Uncomment it to print the weight matrices during network construction.
- Ensure you have a suitable environment set up for compiling and running C programs.
- This implementation uses basic random initialization for weights and biases. For a production-level implementation, consider using more sophisticated initialization techniques.
