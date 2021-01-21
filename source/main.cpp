#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int t_cant=3;
int t_dim=4;
int cant[3] = {10000,20000,25000};
int dim[4] = {5,10,15,20};
vector<double> dis;
double dist_euclideana(int i,int j,vector<vector<int> > &v) {
    int x=0,z=0;
	for(;x<cant[i];x++)
    {
        for(int y=x+1;y < cant[i];y++)
        {
          double dist_=0;
          for(;z<dim[j];z++)
          {
            int tmp =v[x][z]-v[y][z];
            dist_+= tmp*tmp;
          }
          dist_=sqrt(dist_);
        }
    }
}

int main(){
  srand (time(NULL));
  std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

  // llenar vector
  cout<<"\n-----( cantidad - dimensiones )---------"<<endl;
  for(int i = 0; i < t_cant; i++)
  {
      for(int j = 0; j < t_dim; j++){
            vector<vector<int> > vec(cant[i], vector<int>(dim[j]));
            for(int x = 0; x < cant[i]; x++){
                for(int y = 0; y < dim[j]; y++)
                {
                    vec[x][y] = rand()%15220;
                }
            }
            // distancia euclidiana
            start = std::chrono::high_resolution_clock::now();

            dist_euclideana(i,j,vec);

            end = std::chrono::high_resolution_clock::now();
            int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            cout<<"Tiempo (" << cant[i] << " - " << dim[j] << ") : " << duration << " ns\n";
      }
  }
  return 0;
}
