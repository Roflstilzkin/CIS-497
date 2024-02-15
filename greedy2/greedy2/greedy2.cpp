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

    double greenav = 13;
    double countergreen = 0;
    double blueav = 13;
    double counterblue = 0;
    double redav = 13;
    double counterred = 0;
    double allav = 0;
    double counterall = 0;
    double ucbg, ucbb, ucbr = 0;

    vector<double> greenv;
    vector<double> bluev;
    vector<double> redv;
    vector<double> allv;


    for (int i = 0; i < 100; i++)
    {
        //int largest = evaluate(greenav, blueav, redav);
        int r10 = rand() % 10; //picks a random number 0-9 length of the array
        if (countergreen == 0) {
            countergreen = greenav;
            ucbg = greenav + (3 * sqrt((log(i)) / countergreen));
        }
        else {
            ucbg = greenav + (3 * sqrt((log(i)) / countergreen));
        }

        if (counterblue == 0) {
            counterblue = blueav;
            ucbb = blueav + (3 * sqrt((log(i)) / counterblue));
        }
        else {
            ucbb = blueav + (3 * sqrt((log(i)) / counterblue));
        }

        if (counterred == 0) {
            counterred = redav;
            ucbr = redav + (3 * sqrt((log(i)) / counterred));
        }
        else {
            ucbr = redav + (3 * sqrt((log(i)) / counterred));
        }
        
        int largest = evaluate(ucbg, ucbb, ucbr);

        switch (largest) {
        case 1:
            countergreen = countergreen + 1;
            greenav = calculate(green[r10], countergreen, greenav);
            counterall = counterall + 1;
            allav = calculate(green[r10], counterall, allav);
            break;

        case 2:
            counterblue = counterblue + 1;
            blueav = calculate(blue[r10], counterblue, blueav);
            counterall = counterall + 1;
            allav = calculate(blue[r10], counterall, allav);
            break;

        case 3:
            counterred = counterred + 1;
            redav = calculate(red[r10], counterred, redav);
            counterall = counterall + 1;
            allav = calculate(red[r10], counterall, allav);
            break;
        }
        greenv.push_back(greenav);
        bluev.push_back(blueav);
        redv.push_back(redav);
        allv.push_back(allav);
    }

    ofstream allf("../all.csv");
    allf << "green," << "blue," << "red," << "all average" << endl;
    for (int i = 0; i < 100; i++) {
        allf << greenv.at(i) << "," << bluev.at(i) << "," << redv.at(i) << "," << allv.at(i) << endl;
    }
    allf.close();

    cout << endl;
    cout << "GREEN AVERAGE: " << greenav << endl;
    cout << "BLUE AVERAGE: " << blueav << endl;
    cout << "RED AVERAGE: " << redav << endl;
    cout << "ALL AVERAGE: " << allav << endl;
    return 0;
}


//this function finds the new average
//next is new value to add, average is the average for array, counter is the count
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

//this function tells us if we should explore or exploit
int evaluate(double aa, double bb, double cc) {
    int chance = rand() % 100 + 1;
    if (chance > 0) {
        if ((aa == bb) && (bb == cc)) {//case where all are equal
            int x = rand() % 3 + 1;
            return x;
        }
        else if ((aa == bb) && (aa && bb > cc)) {//case where green is same as blue but greater than red
            int y = rand() % 2 + 1;
            return y;
        }
        else if ((aa == cc) && (aa && cc > bb)) {
            int notbb[2] = { 1,3 };
            int z = rand() % 2;
            return notbb[z];
        }
        else if ((bb == cc) && (bb && cc > aa)) {
            int notaa[2] = { 2,3 };
            int u = rand() % 2;
            return notaa[u];
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
        int y = rand() % 3 + 1;
        if (y == 1) {
            return 1;
        }
        else if (y == 2) {
            return 2;
        }
        else if (y == 3) {
            return 3;
        }
    }
    return -1;
}