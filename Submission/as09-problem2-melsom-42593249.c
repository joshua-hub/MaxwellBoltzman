// phys3071 as09 melsom 42593249

/*
This program will find the fraction of molecules that are less than vBar (which
is a function of velocity, Temperature and mass). It solves it with trapezoidal
method.

Inputs: The user is requested to input the upper bound of the integral and the 
Error that the user wishes to fall within.

The program calculates the individual elements separately. f_0 and f_N are
found outside of the loop (as they are easy to solve for), and the sum of all 
middle points calculated. 

Outputs: The program will output a table of values {N, gBar, Error} for each 
iteration of N. as well as a final statement.

Compiled as gcc as09-problem2-melsom-42593249.c -o as09 -Wall -lm
*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

// Global Variable ************************************************************
double Err_max; // used to store the maximum of f''(x_k) per N

// Funtion Prototypes *********************************************************
double function(double vBar, double beta);
double functionDashDash(double vBar, double beta);
double sum_over_k(double vBar_max, int N, double beta);

// Main Function **************************************************************
int main () {
  // I couldn't perform calculations while declaring global varisblaes
  // so I placed them inside and have to pass beta to functions. 
  // This is in case beta is ever not 1.0 (generalising my program).
  const double alpha= 4.0/ sqrt(M_PI); 
  const double beta = 1.0;

  double f0, fN, SumfK;
  double vBar_max, E; // User defined values
  double gBar_approx; // The approximated value of the integral
  double Error; // The final error (plus/minus) *equation* from equation (3)
  
  int N; // Number of steps
  
  printf("Please give me v_bar max: ");
  do {
    scanf("%lf",&vBar_max);
    if (vBar_max<0.0) {
      printf("Invalid value, Please enter again: ");
    }
  } while (vBar_max < 0.0);
  
  printf("Thank you, the program will integrate from zero to %lf\n", vBar_max);
  printf("Please give me your desired accuracy: ");
  scanf("%lf", &E);
  
  gBar_approx= 0.0; // initialising to zero area
  f0= function(0.0, beta); // an element of equation (3) from assignment 9
  fN= function(vBar_max,beta); // an element of equation (3) from assignment 9
  
  // prints column headers
  printf("\n%1s %11s %16s\n","N", "gBar", "Error" );
  printf("____________________________________\n");
  N= 1; // starting at n=2
  
  do {
    N= N* 2; // This starts calculations for N=2
    // an element of equation (3) from assignment 9
    SumfK= sum_over_k(vBar_max, N, beta);
    
    // Final form of equation (3) from assignment 9
    gBar_approx= alpha* (vBar_max/(2.0* N))* (f0+ 2*SumfK+ fN);   
    Error=alpha* (Err_max* pow((vBar_max- 0.0), 2.0))/(12.0* pow(1.0* N, 2.0));
    
    // Printing to screen specified values.
    printf("%d \t %.9lf \t %.9lf \n",N, gBar_approx, Error);
    
  } while (Error>E); // Condition breaks when the calculated 
                     // error is less than the user specified error
  
  printf("\nThe integral converged to %.9lf with %d steps.\n\n", gBar_approx, N);
  return (EXIT_SUCCESS);
}

// Functions ******************************************************************

// function for the integrand of equation (2) from Assignment 9
double function(double vBar, double beta) {
  return (exp(-beta* pow(vBar, 2.0))* pow(vBar, 2.0));
}

// function to solve f''(VBar_k) as found in equation (3) from Assignment 9
double functionDashDash(double vBar, double beta) { 
  return ((exp(-beta* pow(vBar, 2.0)))* (
      4.0* pow(beta, 2.0)* pow(vBar, 4.0)+ 
      10.0* beta* pow(vBar, 2.0) + 2.0));
}

// function solving the sum inside of equation (3) from Assignment 9
double sum_over_k(double vBar_max, int N, double beta) {
  // calculates the step siz used given N
  double step_size= vBar_max/(1.0* N);
  // calculates vBar at each step to send to function and functioDashDash
  double vBar;
  int k;
  double sum= 0.0;
  
  Err_max = functionDashDash(0.0, beta);
  for (k= 1; k< N; k++) {
    vBar= step_size* k;
    sum += function(vBar, beta);  
    if (Err_max< functionDashDash(vBar, beta)) {// finds f''(M) from assignment
      Err_max= functionDashDash(vBar, beta);
    }
  }
      
  return (sum);  
}
