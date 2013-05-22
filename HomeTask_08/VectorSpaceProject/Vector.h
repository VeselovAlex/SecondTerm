#ifndef VECTOR_H
#define VECTOR_H


template <typename DataType>
class Vector
{
public:
    Vector(DataType* coordinates, unsigned int dimension) : dim(dimension), coordArray(coordinates)
    {
        checkNULL();
    }

    Vector(const Vector<DataType>& source) : dim(source.dim), nullVector(source.nullVector)
    {
        coordArray = new DataType[dim];
        try
        {
            for (unsigned int i = 0; i < dim; i++)
                coordArray[i] = source.coordArray[i];
        }
        catch(...){}
    }

    bool isNULLVector()
    {
        return nullVector;
    }

    DataType& operator[](int n)
    {
        try
        {
            return coordArray[n];
        }
        catch(...){}
    }

    Vector& operator+(const Vector<DataType>& rOperand)
    {
        try
        {
            Vector<DataType> result(rOperand);
            for (unsigned int i = 0; i < dim; i++)
            {
                DataType coord1 = result[i];
                DataType coord2 = coordArray[i];
                result[i] = coord1 + coord2;
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
                DataType coord1 = -result[i];
                DataType coord2 = coordArray[i];
                result[i] = coord1 + coord2;
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
                DataType coord1 = rOperand[i];
                DataType coord2 = coordArray[i];
                result =  result + (coord1 * coord2);
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
        nullVector = true;
        try
        {
            for (unsigned int i = 0; i < dim; i++)
            {
                if (coordArray[i] != 0)
                {
                    nullVector = false;
                    return;
                }
            }
        }
        catch(...)
        {
            nullVector = true;
        }
    }

private:
    bool nullVector;
    unsigned int dim;
    DataType* coordArray;

};

#endif // VECTOR_H
