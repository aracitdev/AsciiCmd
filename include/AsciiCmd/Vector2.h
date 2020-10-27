#ifndef VECTOR2_H_INCLUDED
#define VECTOR2_H_INCLUDED
#include <math.h>

/**************************************************************************************************
* \file Vector2.h
* \version 1.0
* Defines a 2 dimensional vector class.
***************************************************************************************************/

/**************************************************************************************************
* \class Vector2
* Defines a generic 2d vector class with two components and some math functions to help.
* There is a lot of stuff in here (documentation todo)
***************************************************************************************************/

template <class T>
class Vector2
{
public:
/**************************************************************************************************
* \fn Vector2(R x1=0, R y1=0)
* Constructs itself from x and y components.
* \param x1 The x component of the new vector.
* \param y1 The y component of the new vector.
***************************************************************************************************/
    template <class R>
    Vector2(R x1=0, R x2=0);

    Vector2();
/**************************************************************************************************
* \fn Vector2(const Vector2<R>& in)
* \param in The Vector to copy.
* Constructs itself from another Vector2.
***************************************************************************************************/
    template <class R>
    Vector2(const Vector2<R>& in);

/**************************************************************************************************
* \fn Vector2<T>& operator=(const Vector2<R>& in)
* \param in The vector to copy.
* \brief Copies the components from another Vector2.
* Constructs itself from another Vector2 of template type.
* \return A reference to the constructed vector (this)
***************************************************************************************************/
    template <class R>
    Vector2<T>& operator=(const Vector2<R>& in);

/**************************************************************************************************
* \fn Vector2<T> operator*(const Vector2<R>& in)
* \param in The Vector to multiply by.
* Multiplies this Vector2 by another Vector2 by multiplying its components.
* \return The result from the multiplication.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator*(const Vector2<R>& in);


/**************************************************************************************************
* \fn Vector2<T> operator+(const Vector2<R>& in)
* \param in The Vector to add by.
* Adds this Vector2 by another Vector2 by adding its components.
* \return The result from the addition.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator+(const Vector2<R>& in);


/**************************************************************************************************
* \fn Vector2<T> operator/(const Vector2<R>& in)
* \param in The Vector to divide by.
* Divides this Vector2 by another Vector2 by dividing its components.
* \return The result from the division.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator/(const Vector2<R>& in);


/**************************************************************************************************
* \fn Vector2<T> operator-(const Vector2<R>& in)
* \param in The vector to subtract by.
* Subtracts this Vector2 by another Vector2 by subtracting its components.
* \return The result from the subtraction.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator-(const Vector2<R>& in);


/**************************************************************************************************
* \fn Vector2<T> operator*(R in)
* \param in The scalar to multiply by.
* Multiplies this Vector2 by a scalar, multiplying its components.
* \return The result from the multiplication.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator*(R in);

/**************************************************************************************************
* \fn Vector2<T> operator+(R in)
* \param in The scalar to add by.
* Adds this Vector2 by a scalar, adding to its components.
* \return The result from the addition.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator+(R in);


/**************************************************************************************************
* \fn Vector2<T> operator/(R in)
* \param in The scalar to divide by.
* Divides this Vector2 by a scalar, dividing its components.
* \return The result from the division.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator/(R in);

/**************************************************************************************************
* \fn Vector2<T> operator-(R in)
* \param in The component to subtract by.
* Subtracts this Vector2 by a scalar, subtracting its components.
* \return The result from the subtraction.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator-(R in);

/**************************************************************************************************
* \fn bool operator==(const Vector2<R>& in)
* \param in The vector to compare against
* Compares this vector against another, checking if their equal.
* \return Returns true if the components are equal, false otherwise.
***************************************************************************************************/
    template <class R>
    bool operator ==(const Vector2<R>& in);

/**************************************************************************************************
* \fn bool operator!=(const Vector2<R>& in)
* \param in The component to compare against
* Compares this vector against another, checking if their not equal.
* \return Returns true if the components are not equal, false otherwise.
***************************************************************************************************/
    template <class R>
    bool operator !=(const Vector2<R>& in);

/**************************************************************************************************
* \fn Vector2<T> operator*(const Vector2<R>& in) const
* \param in The Vector to multiply by.
* Multiplies this Vector2 by another Vector2 by multiplying its components.
* \return The result from the multiplication.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator*(const Vector2<R>& in) const;

/**************************************************************************************************
* \fn Vector2<T> operator+(const Vector2<R>& in) const
* \param in The Vector to add by.
* Adds this Vector2 by another Vector2 by adding its components.
* \return The result from the addition.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator+(const Vector2<R>& in) const;

/**************************************************************************************************
* \fn Vector2<T> operator/(const Vector2<R>& in) const
* \param in The Vector to divide by.
* Divides this Vector2 by another Vector2 by dividing its components.
* \return The result from the division.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator/(const Vector2<R>& in) const;

/**************************************************************************************************
* \fn Vector2<T> operator-(const Vector2<R>& in) const
* \param in The vector to subtract by.
* Subtracts this Vector2 by another Vector2 by subtracting its components.
* \return The result from the subtraction.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator-(const Vector2<R>& in) const;


/**************************************************************************************************
* \fn Vector2<T> operator*(R in)
* \param in The scalar to multiply by.
* Multiplies this Vector2 by a scalar, multiplying its components.
* \return The result from the multiplication.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator*(R in) const;

/**************************************************************************************************
* \fn Vector2<T> operator+(R in)
* \param in The scalar to add by.
* Adds this Vector2 by a scalar, adding to its components.
* \return The result from the addition.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator+(R in) const;

/**************************************************************************************************
* \fn Vector2<T> operator/(R in)
* \param in The scalar to divide by.
* Divides this Vector2 by a scalar, dividing its components.
* \return The result from the division.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator/(R in) const;

/**************************************************************************************************
* \fn Vector2<T> operator-(R in)
* \param in The component to subtract by.
* Subtracts this Vector2 by a scalar, subtracting its components.
* \return The result from the subtraction.
***************************************************************************************************/
    template <class R>
    Vector2<T> operator-(R in) const;

/**************************************************************************************************
* \fn bool operator==(const Vector2<R>& in)
* \param in The vector to compare against
* Compares this vector against another, checking if their equal.
* \return Returns true if the components are equal, false otherwise.
***************************************************************************************************/
    template <class R>
    bool operator ==(const Vector2<R>& in) const;

/**************************************************************************************************
* \fn bool operator!=(const Vector2<R>& in)
* \param in The Vector to compare against
* Compares this vector against another, checking if their not equal.
* \return Returns true if the components are not equal, false otherwise.
***************************************************************************************************/
    template <class R>
    bool operator!=(const Vector2<R>& in) const;


/**************************************************************************************************
* \fn Vector2<T> Normalize()
* Normalizes the vector, making its length 1.
* \return The normalized vector.
***************************************************************************************************/
    Vector2<T> Normalize(void);

/**************************************************************************************************
* \fn Vector2<T> Magnitude()
* Returns the magnitude of the vector.
* \return The magnitude of the vector
***************************************************************************************************/
    float Magnitude(void) const;

/**************************************************************************************************
* \fn Vector2<T> Perp()
* Returns a vector perpendicular to this one.
* \return A vector perpendicular to this one.
***************************************************************************************************/
    Vector2<T> Perp(void) const;

/**************************************************************************************************
* \fn Vector2<T> Dot(const Vector2<R>& other) const
* \param other The vector to dot product against
* Gets the dot product of two vectors.
* \return The result of the dot product
***************************************************************************************************/
    template <class R>
    float Dot(const Vector2<R>& other) const;

/**************************************************************************************************
* \fn float CrossProduct(const Vector2<R>& in) const
* \param in The vector to cross product against
* Does the cross product between two 2d vectors. In 2D this has very little mathematical meaning.
* \return The result of the cross product
***************************************************************************************************/
    template <class R>
    float CrossProduct( const Vector2<R>& b) const;


/**************************************************************************************************
* \fn Vector2<T> CrossScalar(R in)
* \param in The scalar to cross by
* Finds the cross product by the scalar, used in some 2d calculations.
* \return The result from the cross.
***************************************************************************************************/
    template <class R>
    Vector2<T> CrossScalar(R in);


public:
    T x,y;
};

template <class T>
Vector2<T>::Vector2()
{
    x=0;
    y=0;
}



template <class T>
template <class R>
Vector2<T>::Vector2(R x1, R y1)
{
    x=x1;
    y=y1;
}

template <class T>
template <class R>
Vector2<T>::Vector2(const Vector2<R>& in)
{
    x=in.x;
    y=in.y;
}

template <class T>
template <class R>
Vector2<T>& Vector2<T>::operator=(const Vector2<R>& in)
{
    x=in.x;
    y=in.y;
    return *this;
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator*(const Vector2<R>& in)
{
    return Vector2<T>(x * in.x, y * in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator+(const Vector2<R>& in)
{
    return Vector2<T>(x + in.x, y + in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator/(const Vector2<R>& in)
{
    return Vector2<T>(x/in.x, y/in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator-(const Vector2<R>& in)
{
    return Vector2<T>(x-in.x, y-in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator*(R in)
{
    return Vector2<T>(x*in, y*in);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator+(R in)
{
    return Vector2<T>(x+in, y+in);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator/(R in)
{
    return Vector2<T>(x/in, y/in);
}

template <class T>
template <class R>
bool Vector2<T>::operator==(const Vector2<R>& in)
{
    return x==in.x && y == in.y;
}

template <class T>
template <class R>
bool Vector2<T>::operator!=(const Vector2<R>& in)
{
    return x!=in.x || y!=in.y;
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator*(const Vector2<R>& in) const
{
    return Vector2<T>(x * in.x, y * in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator+(const Vector2<R>& in) const
{
    return Vector2<T>(x + in.x, y + in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator/(const Vector2<R>& in) const
{
    return Vector2<T>(x/in.x, y/in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator-(const Vector2<R>& in) const
{
    return Vector2<T>(x-in.x, y-in.y);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator*(R in) const
{
    return Vector2<T>(x*in, y*in);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator+(R in) const
{
    return Vector2<T>(x+in, y+in);
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::operator/(R in) const
{
    return Vector2<T>(x/in, y/in);
}

template <class T>
template <class R>
bool Vector2<T>::operator==(const Vector2<R>& in) const
{
    return x==in.x && y == in.y;
}

template <class T>
template <class R>
bool Vector2<T>::operator!=(const Vector2<R>& in) const
{
    return x!=in.x || y!=in.y;
}


template <class T>
Vector2<T> Vector2<T>::Normalize(void)
{
    float Mag=Magnitude();
    if(Mag == 0)
        return Vector2<T>(0,0);
    return *this / Mag;
}

template <class T>
float Vector2<T>::Magnitude(void) const
{
    return sqrt(x * x + y * y);
}

template <class T>
Vector2<T> Vector2<T>::Perp(void) const
{
    return Vector2<T>(-y,x);
}

template <class T>
template <class R>
float Vector2<T>::Dot(const Vector2<R>& in) const
{
    return x * in.x + in.y * y;
}

template <class T>
template <class R>
float Vector2<T>::CrossProduct(const Vector2<R>& in) const
{
    return x * in.y - y * in.x;
}

template <class T>
template <class R>
Vector2<T> Vector2<T>::CrossScalar(R in)
{
    return Vector2<T>(in * y, -in * x);
}
#endif // VECTOR2_H_INCLUDED
