/**
    Solves the system of linear equation using Gauss-Seidel algorithm.
    @file 1st.cpp
    @author Vanshil Gupta
    @version 24/15/21 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

void copyArray(double *a, double *b, int *n)
{
    /**
     Copies the elements of one array into another.
     @param a Array contains the elements to be copied.
     @param b Array that recieves the elements.
     @param n Order of the arrays.
     */
    for (int i = 0; i < *n; ++i)
    {
        b[i] = a[i];
    }
}

double *difference(double *a, double *b, int *n)
{
    /**
     Calculates the scalar difference between two arrays.
     @param a Array 1
     @param b Array 2
     @param n Order of the arrays
     @return Root of sum of squared difference of given arrays.
     */
    double *sum = new double(0);
    for (int i = 0; i < *n; i++)
    {
        *sum += pow(a[i] - b[i], 2); //adding the squared differnce of each element
    }
    *sum = sqrt(*sum); //square root of the final sum
    return sum;
}

void solver(double *A, double *x, double *B, int *order)
{                                           /**
    Implements the Gauss-Seidel algorithm. Converge the given intial solution of linear system to the actual solution.
    @param A 1D array of coefficients of linear equations.
    @param x Initial solution of the linear system.
    @param B Array of constants of the linear system.
    @param order Order of linear system.
    Prints the no. of iterations took place to converge to a sufficient optimum solution.
    */
    int iterations = 0;                     //no. of iterations
    double *previousX = new double[*order]; //store the value of x at previous iteration
    for (int i = 0; i < *order; i++)
    {
        previousX[i] = x[i] + 1; //Initializing the previousX with random values.
    }

    //Algorithm Implementation

    double *store = new double[*order];
    while (*difference(x, previousX, order) >= 0.00001) //precision
    {
        iterations += 1;
        copyArray(x, previousX, order);
        for (int j = 0; j < *order; ++j)
        {
            store[j] = B[j] / A[j * (*order + 1)];
            for (int k = 0; k < *order; ++k)
            {
                if (k == j)
                    continue;
                store[j] -= A[j * *order + k] * x[k] / A[j * *order + j];
            }
            x[j] = store[j];
        }
    }
    cout << "No. of iterations took place is " << iterations << "\n";
}

void driver(ifstream &indata, int *count)
{
    /**
     Driver code to take the data from the file, solve the system of linear equation and write the solution in other file.
    */

    int *order = new int;
    if (!indata)
    {
        cerr << "Error: file could not be opened" << endl; //error opening file
        exit(1);
    }
    indata >> *order; //extracting order
    if (*order == 0)
        exit(1);
    double *A = new double[*order * *order]; // A of Ax = B
    for (int row = 0; row < *order; ++row)
    {
        for (int column = 0; column < *order; ++column)
        {
            indata >> A[row * *order + column]; //extracting the coefficients and storing them in array A.
        }
    }
    double *B = new double[*order]; // B of Ax = B
    for (int i = 0; i < *order; ++i)
    {
        indata >> B[i]; //extracting the constant of the linear system and store them in array B
    }
    double *x = new double[*order];
    for (int i = 0; i < *order; ++i)
    {
        x[i] = 1; //initializing the solution with random values.
    }
    solver(A, x, B, order); //converge the x to the solution
    delete[] A;
    delete[] B;

    //Writing data to other file
    ofstream outfile;
    outfile.open("output2.txt", ios_base::app);
    outfile << "Solution for set " << *count << " : "
            << "[";
    for (int i = 0; i < *order - 1; ++i)
    {
        outfile << x[i] << " , ";
    }
    outfile << x[*order - 1] << "]"
            << "\n\n";
    outfile.close();
    delete order;
}

int main()
{
    int *count = new int(1);
    ifstream indata;
    indata.open("data2.txt");
    driver(indata, count);
    *count += 1;
    while (!indata.eof())
    {
        driver(indata, count); //call driver for each system of linear equation in the data file.
        *count += 1;
    }
    indata.close();
    delete count;

    return 0;
}