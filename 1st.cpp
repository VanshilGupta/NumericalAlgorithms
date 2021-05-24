/**
    Calculates the root of the polynomial using bisection algorithm in a given range.Memory allocation is dynamic.
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


double *func(double *x, int *order, double *coeffs)
{
    /**
     Defines the polynomial for given order and coefficients.
     @param x Variable x of polynomial.
     @param order Order of the polynomial.
     @param coeffs Coefficients of the polynomial.
     @return The value of the polynomial at x.
      */

    double *sum = new double(0); //value of the function at x
    for (int i = *order; i >= 0; --i)
    {
        *sum += pow(*x, i) * coeffs[i];
    }
    return sum;
}

double *bisect(double *a, double *b, int *order, double *coeffs)
{   
    /**
     Implements the biection algorithm to calculate the root of the function.
     @param a lower limit of the function. 
     @param b upper limit of the function.
     @param order order of the function .
     @param coeffs coefficients of the function.  
     @return Root of the function if found else NULL.
     */
    if (*func(a, order, coeffs) * *func(b, order, coeffs) > 0) //  no root in between
    {
        return NULL;
    }
    else if (*func(a, order, coeffs) * *func(b, order, coeffs) == 0)  // one of the limit is the root
    {
        if (*func(a, order, coeffs) == 0)
            return a;
        else
            return b;
    }
    double *c = new double;
    while (*b - *a >= 0.001) //precision value
    {
        *c = (*a + *b) / 2; //middle of the range
        if (abs(*func(c, order, coeffs)) <= 0.000001) //middle point is the root
            return c;
        else if (*func(a, order, coeffs) * *func(c, order, coeffs) < 0) //root lie between middle point a lower limit
            *b = *c;
        else
            *a = *c; //root lie between middle point a lower limit
    }
    *c = (*a + *b) / 2;
    return c;
}

void driver(ifstream &indata, int *count)
{
    /**
     Driver code to take data from a file, find the root and write it in another file.
     @param indata object of class ifstream to take data from the file.
     @param count keeps the count of the number of polynomials solved.
     */
    int *order = new int; //order of the polynomial
    if (!indata)
    {
        cerr << "Error: file could not be opened" << endl; //error opening file
        exit(1);
    }
    indata >> *order;
    double *coeff = new double[*order + 1]; // coeffiecients of the polynomial
    for (int i = *order; i >= 0; --i)
    {
        indata >> coeff[i]; //takes coefficient from the file
    } 

    double *a = new double; //lower limit
    double *b = new double; //upper limit
    cout << "Give the brackets seperated by a space for polynomial " << *count << endl;
    cin >> *a >> *b;
    double *root = bisect(a, b, order, coeff);
    if (root != NULL)
    {
        ofstream outfile;
        outfile.open("output.txt", ios_base ::app);
        outfile << "Polynomial " << *count << " : " << *root << endl; //write the root to file
        outfile.close();
    }
    else
    {
        ofstream outfile;
        outfile.open("output.txt", ios_base ::app);
        outfile << "Polynomial " << *count << " : "   //No roots found
                << "No Root in given range" << endl; 
        outfile.close();
    }
}

int main()
{
    /**
     Initialize object indata of class ifstream and call the driver functions until indata has read all the polynomial from the file.
     */
    int *count = new int(1);
    ifstream indata;
    indata.open("data.txt");
    driver(indata, count);
    *count += 1;
    while (!indata.eof())
    {
        driver(indata, count); //call driver for each polynomial
        *count += 1;
    }
    indata.close();
    delete count;
    return 0;
}
