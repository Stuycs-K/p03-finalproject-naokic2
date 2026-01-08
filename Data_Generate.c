// generates the random sample of data with a specified y = mx_1 + mx_2 ...mx_n + b equation, then writes it into a file.
#include <fcntl.h>
#include <unistd.h>
double randomDouble(double min, double max){
    srand(time(NULL));
    return (double) rand() * (min - max) + min;
}

int main(argc,char *argv[]){
    if(argc == 3){
        points = [1];
        dims = argv[2];
    }else{
        printf("wrong input! Input filename, # data points, dimensions");
    }
    double* X;
    double* y;
    int rows = load_csv(filename, dims, &X, &y);

}