#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int start();
int evaluate(double a, double b, double c);
double calculate(double next, double counter, double average);
const clock_t begin_time = clock();


int main() {
    //makes the random generator create new numbers each time the program is ran.
    srand(time(0));

    double green[10] = { 4.77317728, 5.99791051, 5.76776377, 4.47913849, 6.21411927, 6.84915318, 8.44082357, 6.15266159, 6.97135381, 7.43452167 };
    double blue[10] = { 6.00449072, 3.34005839, 6.71096916, 4.11113061, 5.68416528, 3.88539945, 3.51181469, 3.67426432, 4.98069804, 4.41366311 };
    double red[10] = { 6.36086896, 5.65584783, 7.62912922, 13.29826146, 5.99876216, 8.14484021, 9.74488991, 6.616229, 14.26793535, 0.98932393 };

    double greenav = 15;
    double countergreen = 1;
    double blueav = 15;
    double counterblue = 1;
    double redav = 15;
    double counterred = 1;
    double hold, hold2, hold3;
    double aver1 = 0;

    vector<double> allv;
    vector<double> greenv;
    vector<double> bluev;
    vector<double> redv;

    for (int i = 0; i < 100; i++)
    {
        int largest = evaluate(greenav, blueav, redav);
        int r10 = rand() % 10; //picks a random number 0-9 length of the array

        switch (largest) {
        case 1:
            cout << i << " current green array pick: " << green[r10] << setw(15);
            hold = calculate(green[r10], countergreen, greenav);
            aver1 = calculate(green[r10], i, aver1);
            greenav = hold;
            countergreen = countergreen + 1;
            cout << greenav << " Green Average " << endl;
            break;

        case 2:
            cout << i << " current blue array pick: " << blue[r10] << setw(15);
            hold2 = calculate(blue[r10], counterblue, blueav);
            aver1 = calculate(blue[r10], i, aver1);
            blueav = hold2;
            counterblue = counterblue + 1;
            cout << blueav << " Blue Average " << endl;
            break;

        case 3:
            cout << i << " current red array pick: " << red[r10] << setw(15);
            hold3 = calculate(red[r10], counterred, redav);
            aver1 = calculate(red[r10], i, aver1);
            redav = hold3;
            counterred = counterred + 1;
            cout << redav << " Red Average " << endl;
            break;
        }
        greenv.push_back(greenav);
        bluev.push_back(blueav);
        redv.push_back(redav);
        allv.push_back(aver1);
    }

    /*
    ofstream greenf("../green.csv");
    for (int i1 = 0; i1 < gs; i1++) {
        greenf << "green" << "," << greenv.at(i1) << "," << endl;
    }
    greenf.close();

    ofstream bluef("../blue.csv");
    for (int i2 = 0; i2 < bs; i2++) {
        bluef << "blue" << "," << bluev.at(i2) << "," << endl;
    }
    bluef.close();


    ofstream redf("../red.csv");
    for (int i3 = 0; i3 < rs; i3++) {
        redf << "red" << "," << redv.at(i3) << "," << endl;
    }
    redf.close();
    */
    ofstream allf("../all.csv");
    allf << "green," << "blue," << "red," << "ALL" << endl;
    for (int i = 0; i < 100; i++) {
        allf << greenv.at(i) << "," << bluev.at(i) << "," << redv.at(i)<< "," << allv.at(i) << endl;
    }
    allf.close();

    cout << endl;
    cout << "GREEN AVERAGE: " << greenav << endl;
    cout << "BLUE AVERAGE: " << blueav << endl;
    cout << "RED AVERAGE: " << redav << endl;
    return 0;
}


//this function finds the new average
//x is new value to add, y is the average for array, i is the count
double calculate(double next, double counter, double average) {
    //double avg = average + ((1 / counter) * (next - average));
    double val = average + 2 * sqrt( (log(counter)/counter) )
    return val;
}

//this function randomly selects an array to pick from first
int start() {
    int r = rand() % 3;//generates a random number 0 to 2
    cout << r << endl;
    return r;
}


int evaluate(double aa, double bb, double cc) {
    int chance = rand() % 100 + 1;

    if (chance > 15) {
        if ((aa == bb) && (bb == cc)) {//case where all are equal
            int x = rand() % 3 + 1;
            return x;
        }
        else if ((aa == bb) && (aa && bb > cc)) {//case where green is same as blue but greater than red
            int y = rand() % 2 + 1;
            return y;
        }
        else if (aa > bb && aa > cc) {//aa is largest
            return 1;
        }
        else if (bb > aa && bb > cc) {//bb is largest
            return 2;
        }
        else if (cc > aa && cc > bb) {//cc is largest
            return 3;
        }
    }
    else
    {
        //cout << "\nWE OUT HERE EXPLORING FOLKS! \n" << endl;
        int y = rand() % 2;
        int largest = evaluate(aa, bb, cc);
        if (largest == 1) {
            int notgreen[2] = { 2,3 };
            return notgreen[y];
        }
        else if (largest == 2) {
            int notblue[2] = { 1,3 };
            return notblue[y];
        }
        else if (largest == 3) {
            int notred[2] = { 1,2 };
            return notred[y];
        }
    }
    return -1;
}