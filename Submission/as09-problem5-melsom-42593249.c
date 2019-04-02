// phys3071 as09 melsom 42593249

/*
This program calculates the integral of g(vBar) from 0 to infinity of program2 
of assignment 9 by computing the integral of g(t) where g(t) has the change of 
variables of vBar= (1/t) - 1. This changes the bounds for vBar= (0,inf) to 
t= (0,1)

Inputs: The user is only required to enter the step size, Deltat.

Calculations: The program calls a function that steps over each of the 
step_sizes which calculates the value of the function at 
(current step+ step_size/ 2). This is the before adding the latest calculated
rectangle of width step size and midpoint height.

Outputs: The program only outputs the calculated integral to terminal.

compiled as gcc as09-problem5-melsom-42593249.c -o as092 -Wall -lm
*/

// Libraries ******************************************************************
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

// Function prototypes ********************************************************
double function(double t); // Solves the function, used for midpoints.
double sum_over_k(double Deltat); // performs Riemann sum using midpoint.

// Begin Main function ********************************************************
int main () {
  double Deltat= 0.0;
  double gBar_approx= 0.0;
  
  // User input section *******************************************************
  printf("Please input the size of steps Delta t: ");
  do {
    scanf("%lf", &Deltat);
    if (Deltat<0.0) {
      printf("Invalid value, please try again: ");
    }
  } while (Deltat<0.0);  
  
  // function call ************************************************************
  gBar_approx= (4.0/sqrt(M_PI))* sum_over_k(Deltat);
  printf("The definite integral is approximately %.10lf\n\n", gBar_approx);
  
  return (EXIT_SUCCESS);
}

// Functions ******************************************************************

// Solves the function, used for midpoints.
double function(double t) {
  return  
      ((pow((1.0-t),2.0)* exp(-1.0* pow(((1.0/t)- 1.0), 2.0)))/ (pow(t, 4.0)));
}

// performs Reimann sum using midpoint.
double sum_over_k(double Deltat) {
  int k = 0; // Counts out how many steps are taken to keep track of t values
  double t= 0.0; // t is the LHS of the current rectangle being calculated for
  double integral_approx= 0.0; // Adds up area of already calculated rectangles
  
  do {
    integral_approx+= Deltat* function(t+(Deltat/2.0));
    t= k*Deltat;
    k++;
  } while (t<1.0); // Breaking condition once the end bound is reached
  return (integral_approx);
}
