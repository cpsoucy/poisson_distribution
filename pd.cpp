#include <iostream>
#include <cmath>
using namespace std;

int main() {  
  double e = 2.718281828; //Euler's constant;  
  double q = 0.3; //prob. the attacker finds the next block;
  double p = (1 - q); //prob. the honest node finds the next block;
  int z = 10; //how many blocks ahead the honest node is;
  
  double lambda = z * (q / p);
  
  double pd_1; //initializing poisson distribution equation (1 / 2);
  double pd_2; //initializing poisson distribution equation (2 / 2);
  double summation = 0; //initializing summation value;
  int k_f = 1; //to calculate k!;
  
  for (int i = 0; i != (z + 1); i++) { //to calculate summation (from [0, z]);
    for (int j = 1; j <= i; j++) { //calculating k!;
      k_f *= j;
    }
    
    pd_1 = (pow(e, -lambda) * pow(lambda, i) / k_f); //solving equation (1 / 2);
    pd_2 = 1 - pow((q / p), z - i); //solving equation (2 / 2);
    
    k_f = 1; //resetting k! for the next iteration of the for loop;
    summation += (pd_1 * pd_2); //summing the calculated values;
  }
  
  double probability = 1 - summation; //finding the probability;
  cout << "q: " << q << endl;
  cout << "z: " << z << endl;
  cout << "probability: " << probability << endl; //outputting solution to terminal;
   
  return 0;
}
