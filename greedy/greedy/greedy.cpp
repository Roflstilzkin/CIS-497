#include <iostream>
#include <ctime>

using namespace std;

int start();
double evaluate(double a, double b, double c);
double calculate(double x, int i, double y);



int main() {
    //makes the random generator create new numbers each time the program is ran.
    srand(time(0));

    double green[10] = {4.77317728, 5.99791051, 5.76776377, 4.47913849, 6.21411927, 6.84915318, 8.44082357, 6.15266159, 6.97135381, 7.43452167};
    double blue[10] = { 6.00449072, 3.34005839, 6.71096916, 4.11113061, 5.68416528, 3.88539945, 3.51181469, 3.67426432, 4.98069804, 4.41366311 };
    double red[10] = { 6.36086896, 5.65584783, 7.62912922, 13.29826146, 5.99876216, 8.14484021, 9.74488991, 6.616229, 14.26793535, 0.98932393 };

    double a = 0;
    double b = 0;
    double c = 0;

    //double e = 0.01;//1 percent chance to explore

    int pick = start();//selects an array to start at randomly.

    int r10 = rand() % 10; //picks a random number 0-9 length of the array
    
    cout << "pick: " << pick << endl << r10 << " <- R10" << endl; //testing purposes
    switch (pick) {
        case 0:
            a = green[r10];
            break;
        case 1:
            b = blue[r10];
            break;
        case 2:
            c = red[r10];
            break;
    }

    cout << a << " " << b << " " << c << endl;

    for (int i = 1; i < 10; i++)
        {
            double count = i;
            double chosen = evaluate(a, b, c);
            double set = calculate(chosen, count, a);
            a = set;
            cout << a << endl;
        }

    return 0;
}


//this function finds the new average
//x is new value to add, y is the average for array, i is the count
double calculate(double x, int i, double y) {
    double avg = y + ((1 / i) * (x - y));
    return avg;
}

//this function randomly selects an array to pick from first
int start() {
    int r = rand() % 3;//generates a random number 0 to 2
    cout << r << endl;
    return r;
}


double evaluate(double aa, double bb, double cc) {
    if (aa > bb && aa > cc) {
        double green = green + 1; //counter
        return aa;
    }
    else if (bb > aa && bb > cc) {
        double blue = blue + 1;
        return bb;
    }
    else if (cc > aa && cc > bb) {
        double red = red + 1;
        return cc;
    }
}