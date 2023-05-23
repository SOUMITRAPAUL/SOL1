#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a function to calculate the dot product of two vectors

double dot(vector<double> a, vector<double> b)

{
    double result = 0;
    for (int i = 0; i < a.size(); i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main()

{
    // Input data

    int n, p; // n = number of observations, p = number of predictors

    cout << "Enter the number of observations (n): ";
    cin >> n;
    cout << "Enter the number of predictors (p): ";
    cin >> p;

    vector<vector<double>> X(n, vector<double>(p));
    // Design matrix
    vector<double> Y(n);
     // Response variable

    cout << "Enter the data for the design matrix (X):" << endl;

    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < p; j++)
        {
            cin >> X[i][j];
        }
    }

    cout << "Enter the data for the response variable (Y):" << endl;

    for (int i = 0; i < n; i++)
        {
        cin >> Y[i];
    }

    // Calculate the OLS estimates

    vector<double> beta(p);
    // Coefficients
    double y_bar = 0; // Mean of Y
    for (int i = 0; i < n; i++)
        {
        y_bar += Y[i];
    }
    y_bar /= n;


    vector<double> x_bar(p);
    // Mean of each predictor
    for (int j = 0; j < p; j++)
        {
        for (int i = 0; i < n; i++)
         {
            x_bar[j] += X[i][j];
        }
        x_bar[j] /= n;
    }


    vector<double> s_xy(p);
    // Covariance between each predictor and Y
    vector<double> s_xx(p);
    // Variance of each predictory


    for (int j = 0; j < p; j++)
        {
        for (int i = 0; i < n; i++)
         {
            s_xy[j] += (X[i][j] - x_bar[j]) * (Y[i] - y_bar);
            s_xx[j] += pow(X[i][j] - x_bar[j], 2);
        }
        beta[j] = s_xy[j] / s_xx[j];
    }


    double intercept = y_bar;
    for (int j = 0; j < p; j++)
        {
        intercept -= beta[j] * x_bar[j];
    }

    // Calculate the predicted values and residuals
    vector<double> Y_hat(n);
    vector<double> residuals(n);

    double SSE = 0;
    for (int i = 0; i < n; i++)
        {
        Y_hat[i] = intercept;
        for (int j = 0; j < p; j++)
        {
            Y_hat[i] += beta[j] * X[i][j];
        }
        residuals[i] = Y[i] - Y_hat[i];
        SSE += pow(residuals[i], 2);
    }

    // Output the results
    cout << "The coefficients are: ";
    for (int j = 0; j < p; j++)
        {
        cout << beta[j] << " ";
    }

    cout << endl;
cout << "The intercept is: " << intercept << endl;

cout << "The best-fit line is: Y = " << intercept << " + ";

for (int j = 0; j < p; j++)
    {
    cout << beta[j] << "X" << j+1;
    if (j != p-1)
        {
        cout << " + ";
    }
}
cout << endl;

double MSE = SSE / (n - p - 1); // Mean squared error
int j;
double s_beta = sqrt(MSE / s_xx[j]); // Standard error of the coefficients
double t_crit = 2.306; // T-distribution critical value for 95% confidence interval with n-p-1 degrees of freedom

for (int j = 0; j < p; j++)
    {
    cout << "[" << beta[j] - t_crit * s_beta << ", " << beta[j] + t_crit * s_beta << "] ";
}
cout << endl;

cout << "The mean squared error is: " << MSE << endl;

cout << "The residual standard error is: " << sqrt(MSE) << endl;

cout << "The R-squared value is: " << 1 - SSE / ((n - 1) * pow(y_bar, 2)) << endl;

cout << "The residuals are: ";
for (int i = 0; i < n; i++) {
    cout << residuals[i] << " ";
}
cout << endl;

return 0;
}
