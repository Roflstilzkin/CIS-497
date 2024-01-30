#include <iostream>
using namespace std;

double greedy(double a, double b, double c);

double arA[10]= {4.77317728, 5.99791051, 5.76776377, 4.47913849, 6.21411927, 6.84915318, 8.44082357, 6.15266159, 6.97135381, 7.43452167};

double arB[10]= {6.00449072, 3.34005839, 6.71096916, 4.11113061, 5.68416528, 3.88539945, 3.51181469, 3.67426432, 4.98069804, 4.41366311};

double arC[10]= {6.36086896, 5.65584783, 7.62912922, 13.29826146, 5.99876216, 8.14484021, 9.74488991, 6.616229, 14.26793535, 0.98932393};

int main() {
  double a = 0; 
  double b = 0; 
  double c = 0;  
  
  int k = 100;//times to loop
  //double e = 0.01;//1 percent chance to explore
  
  for (int i = 1; i < k; i++)
    {
      greedy(a, b, c);
    }
  return 0;
}

double greedy(double a, double b, double c){
      if (a && b && c == 0)
        {
          int r = rand() % 3;//generates a random number 0 to 2
          cout >> r;
          switch (r) 
          {
            case 0:
              return a;
            case 1:
              return b;
            case 2:
              return c;
          }
        }
  
    if (a > b && a > c)
      return a;
    else if (b > a && b > c)
      return b;
    else if (c > a && c > b)
      return c;
}