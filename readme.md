![LOGO](c++.png)
# Numerical Methods in C++

<br>

## 👤 AUTHOR :

 **VANSHIL GUPTA**

- [GITHUB](https://github.com/VanshilGupta)
- [LINKEDIN](https://www.linkedin.com/in/vanshil-gupta-234b72179/)

<br>

## ℹ️ DESCRIPTION

Implementation of different algorithms in C++ to get the root of polynomial in the given range and solve the system of linear equations. The memory allocation is dynamic, and the data is read and write from the different files. 

**BUILT WITH :** 

![https://img.shields.io/badge/C%2B%2B-14-blue](https://img.shields.io/badge/C%2B%2B-14-blue)

![https://img.shields.io/badge/g%2B%2B-8.1.0-brightgreen](https://img.shields.io/badge/g%2B%2B-8.1.0-brightgreen)

<br>

## ✏️ ALGORITHMS

- BISECTION
- GAUSS - SIEDEL

<br>

**1 .** **BISECTION ALGORITHM :**

The bisection algorithm is a simple method for finding the roots of 1-D functions. Goal is to find a root x0∈[a,b] such that f(x0) = 0.The algorithm starts with a large interval, known to contain x0, and then successively reduces the size of the interval until it brackets the root.

**Pseudo Code** 

```python
INPUT: Functionf,
       endpoint values a,b,
       tolerance TOL,
       maximum iterations NMAX
CONDITIONS:a <b,
            eitherf(a) < 0 and f(b) > 0 or f(a) > 0 and f(b) < 0
OUTPUT: value which differs from a root of f(x) = 0 by less than TOL

N ← 1
while N ≤NMAX do// limit iterations to prevent infinite loop 
c ← (a +b)/2// new midpoint
if f(c) = 0 or (b –a)/2 <TOL then // solution found
        Output(c)
Stop
end if
N ←N + 1// increment step counter
if sign(f(c)) = sign(f(a)) then a ←c else b ←c // new interval
end while
Output("Method failed.") // max number of steps exceeded
```

IMPLEMENTATION

It is implemented in the *1st.cpp* file. Run the file and give the limits for the polynomial. The data is taken from the *data.txt* file which first gives the order of the polynomials followed with coefficients according to order for each polynomial. The root of the polynomial (if any) is written in the *output.txt* file.

**[Documentation](https://drive.google.com/file/d/1VIraSHw7FCVuYHDx9iIV9rKBizqGN34V/view?usp=sharing)**

<br>

**2 .** **GAUSS - SIEDEL ALGORITHM :**

It is an iterative method used to solve the system of linear equations. Its convergence is only guaranteed for diagonally dominant, or symmetric and positive definite matrices.

System of equations : *Ax =B*

The elements of *x* can be calculated as :

$$x_{i}^{(k+1)}=\frac{1}{a_{i i}}\left(b_{i}-\sum_{j=1}^{i-1} a_{i j} x_{j}^{(k+1)}-\sum_{j=i+1}^{n} a_{i j} x_{j}^{(k)}\right), \quad i=1,2, \ldots, n .^{[4]}$$

**Pseudo Code**

```python
Inputs: A, b
Output: X

Choose an initial guess X to the solution
repeat until convergence
    for i from 1 until n do
        k <- 0
        for j from 1 until n do
            if j ≠ i then
                k <- k + a(ij)*x(j)
            end if
        end (j-loop)
        x(i) <- (b(i) - k) * 1/a(ii)
    end (i-loop)
    check if convergence is reached
end (repeat)
```

IMPLEMENTATION

It is implemented in the file *2nd.cpp .* The initial value of x is given which is converges approximately to the actual solution when the program ends. The data is taken from *data2.txt* which first gives the order of polynomial followed by the coefficient matrix (A) and constant matrix (b).Solution matrix (x) is written in *output2.txt.*

**[Documentation](https://drive.google.com/file/d/1_JAFrGbC9XeUGuwVe9lrPlY0ryxeX-ss/view?usp=sharing)**

