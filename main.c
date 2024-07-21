#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

typedef struct {
    int neuronCount ; 
    float *biasArray ;
    float *neuronArray ;
} Layer ;

typedef struct {
    int rowCount;
    int colCount;
    float *values; 
} Matrix;

typedef struct {
    int layerCount ;
    Layer **layers ;
    Matrix **weights;
} Network ;

Layer *construct_Layer(int count){
    Layer *layer = (Layer*)malloc(sizeof(Layer));
    layer->neuronCount = count ;
    layer->biasArray = (float*)malloc(sizeof(float)*count);
    layer->neuronArray = (float*)malloc(sizeof(float)*count);
    if (!layer->biasArray || !layer->neuronArray) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        layer->biasArray[i] = ((float) rand() / RAND_MAX) * 1; 
    }
    return layer;
}

void destroy_Layer(Layer *layer){
    free(layer->biasArray);
    free(layer->neuronArray);
    free(layer);
}

void print_Layer(Layer *layer){
    printf("Neuron Count = %d\n",layer->neuronCount);    
    printf("------------------\n");
    printf("%-10s %-10s\n", "Bias","Neuron");    
    printf("------------------\n");
    for(int i=0 ; i< (layer->neuronCount);i++){
        printf("%-10.3f %.3f |\n",layer->biasArray[i],layer->neuronArray[i]);    
    }
    printf("------------------\n\n");
}

void init_Weight(Matrix *weight , int rows , int colums){
    weight->rowCount = rows ;
    weight->colCount = colums ;
    weight->values = (float*)malloc(rows*colums*sizeof(float));
    for (int i = 0; i < rows * colums; i++) {
        weight->values[i] = ((float) rand() / RAND_MAX) * 1;
    }
}

void print_Weight(Matrix *weight){
    for(int i=0;i<(weight->rowCount);i++){    
        printf("|");
        for(int j=0;j<(weight->colCount);j++){
            printf("%7.3f",weight->values[i * weight->colCount + j]);
        }
        printf(" |\n");
    }
    printf("\n");
}

Matrix *dot_product(Matrix *a , Matrix *b){
    if (a->colCount != b->rowCount) {
        fprintf(stderr, "Matrix dimensions do not match for multiplication\n");
        exit(EXIT_FAILURE);
    }

    Matrix *c = (Matrix*)malloc(sizeof(Matrix));
    c->rowCount = a->rowCount ; 
    c->colCount = b->colCount ;
    c->values = (float*)calloc((c->colCount)*(c->rowCount),sizeof(float));

    for(int i=0;i<(c->rowCount);i++){
        for(int j=0;j<(c->colCount);j++){
            for(int k=0;k<(a->colCount);k++){
                c->values[i*(c->colCount)+j] += (a->values[i*(a->colCount)+k])*(b->values[k*(b->colCount)+j]) ; 
            }
        }
    }
    return c;
}





Network *construct_Network(int layerCount , int *neuron_Layer){
    Network *network = (Network*)malloc(sizeof(Network));
    network->layerCount = layerCount ;
    network->layers = (Layer**)malloc(sizeof(Layer*)*layerCount);
    for(int i=0;i<layerCount;i++){
        network->layers[i] = construct_Layer(neuron_Layer[i]);
        printf("--> Layer [%d] : ",i+1);
        print_Layer(network->layers[i]);
    }
    network->weights = (Matrix**)malloc(sizeof(Matrix*)*(layerCount-1));
    for(int i=0;i<(layerCount-1);i++){
        network->weights[i] = (Matrix*)malloc(sizeof(Matrix));
        init_Weight(network->weights[i] , neuron_Layer[i+1] , neuron_Layer[i]); 
//        printf("--> Weight Matrix [%d]\n\n",i+1);
//        print_Weight(network->weights[i]);
    }
    return network;
}

void destroy_Network(Network *network){
    for (int i = 0; i < network->layerCount; i++) {
        destroy_Layer(network->layers[i]);
    }
    free(network->layers);
    
    for (int i = 0; i < network->layerCount - 1; i++) {
        free(network->weights[i]->values);
        free(network->weights[i]);
    }
    free(network->weights);
    free(network);
}



int main(){

    int Layers_neuron_count[]={3,7,2};
    Network *network = construct_Network(3,Layers_neuron_count);

    destroy_Network(network);
    return 0;
}

