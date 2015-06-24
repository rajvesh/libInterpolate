#ifndef INTERPLIB_H
#define INTERPLIB_H value

#include <string>
#include "boost/filesystem.hpp"
#include "boost/numeric/ublas/matrix.hpp"
#include "boost/numeric/ublas/vector.hpp"
#include "boost/numeric/ublas/lu.hpp"


namespace fs=boost::filesystem;
namespace ublas=boost::numeric::ublas;

//right now this just takes the path to a filename in the constructor and sets up an instance
//of the interpolator class where all of the necessary matrices/vectors are built.
//
//After the object is built, its interpAt member function can be run any number of times without having to redo all the time-intensive math.
//
//
//ToDo:
//-overload the constructor so that it can take *x, *y, and n (double pointer arrays as straight form the output of Dr.Clark's file reader
//-overload the constructor so that it can take std::arrays or vectors

class SplineInterp
{

    private:

        fs::path filename;

        //this is the length of the input file
        int n;

        //These are the vectors that the data will be stored int
        ublas::vector<double> X;
        ublas::vector<double> Y;

        //these will hold intermediate data for the interpolation method
        ublas::matrix<double> A;
        ublas::vector<double> B;

        //these are the "end goal" from the interpolation method. When these coefficients are determined,
        //they can be used to generate the splines that the interpolations are calculated at
        ublas::vector<double> a;
        ublas::vector<double> b;

    protected:

    public:
        SplineInterp(std::string dataFile);
        ~SplineInterp();

        //int getN();
        double interpAt(double targetValue);

};

#endif
