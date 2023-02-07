
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate mean

double mean(vector<double> x)

{
    int n = x.size();
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    return sum / n;
}

// Function to calculate coefficient b1 and b0

void OLS(vector<double> x, vector<double> y, double &b1, double &b0)

 {
    int n = x.size();
    double x_mean = mean(x);
    double y_mean = mean(y);

    double numerator = 0.0, denominator = 0.0;

    for (int i = 0; i < n; i++) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += pow(x[i] - x_mean, 2);
    }

    b1 = numerator / denominator;
    b0 = y_mean - b1 * x_mean;
}

int main()

{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the x and y values:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double b1, b0;
    OLS(x, y, b1, b0);

    cout << "Coefficients b1 and b0: " << b1 << ", " << b0 << endl;
    cout << "Equation of the line of best fit: y = " << b0 << " + " << b1 << " * x" << endl;
   return 0;
}
