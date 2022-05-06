#include <iostream>
#include <omp.h>
#include <math.h>
#include <time.h>
using namespace std;
// #pragma omp construct [params]
int main(){
    // #pragma omp parallel
// {
//     #pragma omp task
//     {
//         std::cout << "Estou rodando na tarefa " << omp_get_thread_num() << "\n";
//     }
//     }
    int n;
    cin>>n;
    double soma = 0;
    // omp_set_num_threads(1);
    // time_t now;
    // struct tm *mytime = localtime(&now); 
    time_t start, finish;

    time(&start);

    #pragma omp parallel for reduction(+:soma)
        for (int i = 0; i < n; i+=1){
            soma += pow(-1,i)/(2*i+1);
        }
    cout<<"Soma= "<<soma<<endl;
    cout<<"Pi= "<<soma*4<<endl;
    time(&finish);
    cout << "Time required = " << difftime(finish, start) << " seconds";


    
    return 0;

}