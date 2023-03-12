#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Get input from user for X and Y values
    int n;
    cout << "Enter the number of observations: ";
    cin >> n;

    vector<double> X(n);
    vector<double> Y(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of X for observation " << i+1 << ": ";
        cin >> X[i];
        cout << "Enter the value of Y for observation " << i+1 << ": ";
        cin >> Y[i];
    }

    // Create the design matrix
    vector<vector<double>> X_design(n, vector<double>(2));
    for (int i = 0; i < n; i++) {
        X_design[i][0] = 1;
        X_design[i][1] = X[i];
    }

    // Compute the coefficients using the design matrix
    vector<vector<double>> X_transpose(2, vector<double>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            X_transpose[i][j] = X_design[j][i];
        }
    }
    vector<vector<double>> XTX(2, vector<double>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) {
                sum += X_transpose[i][k] * X_design[k][j];
            }
            XTX[i][j] = sum;
        }
    }
    vector<double> XY(2);
    for (int i = 0; i < 2; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += X_transpose[i][j] * Y[j];
        }
        XY[i] = sum;
    }
    double slope = (XY[1] * XTX[0][0] - XY[0] * XTX[1][0]) / (XTX[0][0] * XTX[1][1] - XTX[0][1] * XTX[1][0]);
    double intercept = (XY[0] - slope * XTX[0][1]) / XTX[0][0];

    // Calculate the regression line and error
    vector<double> Y_hat(n);
    double error = 0;
    for (int i = 0; i < n; i++) {
        Y_hat[i] = intercept + slope * X[i];
        error += pow((Y[i] - Y_hat[i]), 2);
    }

    // Output the results
    cout << "Slope: " << slope << endl;
    cout << "Intercept: " << intercept << endl;
    cout << "Error: " << error << endl;
    cout << "Regression line: Y = " << slope << "X + " << intercept << endl;

    return 0;
}
