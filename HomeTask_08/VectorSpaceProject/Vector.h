#ifndef VECTOR_H
#define VECTOR_H
#include <assert.h>


template <typename DataType>
class Vector
{
public:
    Vector(DataType* coordinates, unsigned int dimension) : dim(dimension), coordArray(coordinates)
    {
        checkNULL();
    }

    Vector(const Vector<DataType>& source) : dim(source.dim), isNullVector(source.isNullVector)
    {
        coordArray = new DataType[dim];
        try
        {
            for (unsigned int i = 0; i < dim; i++)
                coordArray[i] = source.coordArray[i];
        }
        catch(...)
        {
            throw;
        }
    }

    bool isNULLVector()
    {
        return isNullVector;
    }

    DataType& operator[](unsigned int n)
    {
        assert(n < dim);
        return coordArray[n];
    }

    Vector& operator+(const Vector<DataType>& rOperand)
    {
        try
        {
            Vector<DataType> result(rOperand);
            for (unsigned int i = 0; i < dim; i++)
            {
                result[i] = result[i] + coordArray[i];
                result.checkNULL();
            }
            return (result);
        }
        catch(...){}

    }

    Vector& operator-()
    {
        try
        {
            Vector<DataType> result(*this);
            for (unsigned int i = 0; i < dim; i++)
            {
                DataType coord1 = coordArray[i];
                result[i] = -coord1;
            }
            return (result);
        }
        catch(...){}
    }

    Vector& operator-(const Vector<DataType>& rOperand)
    {
        try
        {
            Vector<DataType> result(rOperand);
            for (unsigned int i = 0; i < dim; i++)
            {
                result[i] = -result[i] + coordArray[i];
                result.checkNULL();
            }
            return (result);
        }
        catch(...){}
    }

    DataType operator* (Vector<DataType>& rOperand)
    {
        DataType result = 0;
        try
        {
            for (unsigned int i = 0; i < dim; i++)
            {
                result =  result + (rOperand[i] * coordArray[i]);
            }
            return result;
        }
        catch(...)
        {
            return 0;
        }

    }

private:
    void checkNULL()
    {
        isNullVector = true;
        try
        {
            for (unsigned int i = 0; i < dim; i++)
            {
                if (coordArray[i] != 0)
                {
                    isNullVector = false;
                    return;
                }
            }
        }
        catch(...)
        {
            isNullVector = true;
        }
    }

private:
    bool isNullVector;
    unsigned int dim;
    DataType* coordArray;

};

#endif // VECTOR_H
