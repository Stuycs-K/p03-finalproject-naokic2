// generates the random sample of data with a specified y = mx_1 + mx_2 ...mx_n + b equation, then writes it into a file.


//WRITE ERROR FUNCTIOn---
#include <fcntl.h>
#include <unistd.h>
#include "Data_Generate.h"
#include <math.h>
double randomDouble(double min, double max){
    return (double) rand() * (min - max) + min;
}

double function(double* Weights, double* Bias,int dims){

}

double NormalDSampler(int std, int mean){ //generates a random number based on a mean and std from the normal distribution

        double u = (double)rand() / RAND_MAX;
        double v = (double)rand() / RAND_MAX;
        while(u ==0.0){ // no errs
            u = double rand() / RAND_MAX;
        }
        double num = sqrt(-2.0 * log(u)) * cos(2.0 * pi * v);
        return mean + (z * std);

}


int main(intargc, char *argv[]){
    if(argc == 3){
        double points = argv[1];
        double dims = argv[2];
        char* filename = argv[0]
    }else{
        printf("wrong input! Input filename, # data points, dimensions\n");
    }

    srand(time(NULL));
    

    /////////////// DATA GENERATION //////////////////////
    //randomly get true weights and bias
    double* trueWeights = calloc(dims, sizeof(double));
    double* trueBias = randomDouble(-100,100);
    for(int i=0,i<dims;i++){
        trueWeights[i] = randomDouble(-10,10);
    }
    printf("True equation:\n");
    for(int i=0;i<dims;i++){
        printf("%f * x(%d) + ",trueWeights[i],i+1);
    }
    printf(" %f\n\n",trueBias);

    
    double** dataPoints = calloc(points, sizeof(double*)); //initialize memory for all data
    for(int i=0;i<dims;i++){ //initialize memory for each datapoint n dimensins
        dataPoints[i] = calloc(dims, sizeof(double));
    }
    


    for(int i=0;i<points;i++){
        int Y = 0;
        for(int x=1;x<=dims;x++){  /// FORMAT IS y =mx +b-----  data[i][0] = y, data[i][1] = x1 ... data[i][dims + 1] = Bias
            dataPoints[i][x] = randomDouble(-10,10);   // random init dataPoints
            Y += dataPoints[i][x] * (trueWeights[x] + NormalDSampler(0.1,0)); // solve for y while adding random noise to weights
        }
        dataPoints[i][0] = Y;
        dataPoints[i][dims + 1] = trueBias + NormalDSampler(1,0);


    }

    printf("Data Generation has completed. Data is approx %lf KiloBytes large!\n", (long)points * sizeof(double) / 1000)
    printf("Now saving data to file!\n")
    saveData(filename, points,dims,dataPoints);
    printf("data has been saved to %s",filename);

}


void saveData(char* filename, int points, int dims, double** data){//write data into a file!
    int fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd < 0){
        err();
    }
    char buffer[50000];
    
    for(int i=0;i<rows;i++){
        int count =0;
        count += sprintf(buffer + offset,"%f",data[i][0]);
        for(int x=1;x<=dims+1;x++){
            count += sprintf(buffer+count,"%f",data[i][x]);
        }
        count += sprintf(buffer +count,"\n");
        write(fd, buffer, offset);
    }
    close(fd);
}