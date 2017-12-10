/*----------------------------------------------------------------------
This is the header file twod.h. This is the interface for the clas TwoD.
Values of this type represent a two-dimensional dynamic array.

Author: Chibuikem Amaechi
Email:  cramaechi@me.com
----------------------------------------------------------------------*/

typedef double* DoublePtr;

class TwoD
{
   public:
       TwoD(); //Default constructor

       TwoD(unsigned int theRows, unsigned int  theColumns);

       TwoD(const TwoD& otherTwoD); //Copy constructor       

       unsigned int getRows() const { return rows; }

       unsigned int getCols() const { return cols; }           

       double getElement(unsigned int theRow, unsigned int theColumn) const;
       //Returns the two-dimensional array element at position (row, column).

       void setRows(unsigned int theRows) { rows = theRows; }

       void setCols(unsigned int theCols) { cols = theCols; }

       void setElement(unsigned int theRow, unsigned int theColumn, double number);
       //Set the value of the element in position (theRow, theColumn) to
       //number.

       friend const TwoD operator +(const TwoD& left, const TwoD& right);
       //Returns a TwoD object whose ith row and jth column element is the sum
       //of the ith row, jth column element of the left-hand operand TwoD
       //object and the ith row, jth column element of the right-hand operand
       //TwoD object.

       TwoD& operator =(const TwoD& rightSide);  
       //Assigns the value of every ith row, jth column element from the TwoD
       //object rightSide to the ith row, jth column element in the calling
       //TwoD object. 

       ~TwoD(); //Destructor
   private:
       unsigned int rows, cols;
       DoublePtr *TwoDArray;
};
