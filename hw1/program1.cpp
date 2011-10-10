////////////////////////////////////////////////////
// Program 1
//
// For given h this program computes the difference 
// quotient
//         
//           df = ( f(x+h) - f(x) )/h,
//
// where f(x) = x^2 and x=1.
//
//
// Here's how to get started:
//
//        1) Copy program1.cpp (this file) into 
//           your working directory.
//
//        2) Compile the program by typing
//           "c++ -o program1 program1.cpp"
//           at the Linux prompt.
//
//        3) Type "program1" to run the program.
//
//  Note: The version of C++ on the math dept machines
//  is slightly different than what is described in the
//  Ortega and Grimshaw text.  Some differences are
// 
//       Current version              O&G version
//       ---------------              -----------
//     #include <iostream>       #include <iostream.h>
//        int main{...}              void main{...}
//     using namespace std;            (not used)
// 
//  The statement "using namespace std;" is used 
//  to ensure that functions in the standard C++ 
//  libraries are accessible by their usual names.
////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main(){
  double x, h, fx, fxh, df, minus ;  

  x = 1.0 ; // set value of x 
  h = 1.0 ; // initialize h 

  while(h != 0){
	cout << "yo" << endl;
    cout << "Enter h (or zero to terminate): " ; 
    cin  >> h ;
    if(h != 0){
      fxh = (x+h)*(x+h) ;
      fx  = x*x ;
	  minus = fxh-fx;
	  cout << "minus " << minus << endl;
      df  = (fxh-fx)/h ;
      cout << "h  = " << h << endl ;
      cout << "df = " << df << endl ;
      cout << endl ;
    }
  } 

  return 0 ; // terminate main program
}

