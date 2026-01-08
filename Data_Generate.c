// generates the random sample of data with a specified y = mx_1 + mx_2 ...mx_n + b equation, then writes it into a file.


//WRITE ERROR FUNCTIOn---
#include <fcntl.h>
#include <unistd.h>
#include "Data_Generate.h"
double randomDouble(double min, double max){
    return (double) rand() * (min - max) + min;
}

double function(double* Weights, double* Bias,int dims){
    for(int i=0;i<dims;i++){
        
    }
}

double NormalDSampler(int std, int mean){ //generates a random number based on a mean and std from the normal distribution

    double
}


int main(intargc, char *argv[]){
    if(argc == 3){
        double points = argv[1];
        double dims = argv[2];
        char* filename = argv[0]
    }else{
        printf("wrong input! Input filename, # data points, dimensions");
    }

    srand(time(NULL));
    

    //randomly get true weights and bias
    double* trueWeights = calloc(dims, sizeof(double));
    double* trueBias = randomDouble(-10,10);
    for(int i=0,i<dims;i++){
        trueWeights[i] = randomDouble(-10,10);
    }
    printf("True equation:\n");
    for(int i=0;i<dims;i++){
        printf("%f * x(%d) + ",trueWeights[i],i+1);
    }
    printf(" %f",trueBias);

    
    double** dataPoints = calloc(points * sizeof(double*)); //initialize memory for all data
    for(int i=0;i<dims;i++){ //initialize memory for each datapoint n dimensins
        dataPoints[i] = calloc(dims * sizeof(double));
    }
    double* Y = calloc(points * sizeof(double));

    for(int i=0;i<points;i++){

        for(int x=0;x<dims;x++){
            dataPoints[i][x] = randomDouble(-100,100);
            Y += dataPoints[i][x] * (trueWeights[x] );
        }
        Y += trueBias

    }


    //write data into a file!
    int fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd < 0){
        err();
    }

}