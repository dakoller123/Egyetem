package hu.elte.math;

import hu.elte.math.InvalidVectorAdditionException;

public class Vector {

    private final int[] elements;

    /**
    * Default ctor.
    *
    * @param  numberOfElements  the number of elements the vector will have.  
    * @throws IllegalArgumentException  if the numberOfElements is negative.
    */
    public Vector(int numberOfElements) {
        if (numberOfElements < 0){
            throw new IllegalArgumentException("vector length can't be negative. Given value: " + numberOfElements);
        }
        this.elements = new int[numberOfElements];
    }

    /**
    * Adds another vector to this one. 
    * Length of vectors should be the same.
    *
    * @param  other the second vector. It will not be modified.
    * @throws InvalidVectorAdditionException  if the length of the two vectors don't match
    */
    public void add(Vector other) {
        
        if (getLength() != other.getLength()){
            throw new InvalidVectorAdditionException("the two vectors have incompatible lengths. source vector's length:" + getLength() + ", second: " + other.getLength());
        }
        for (int i = 0; i < elements.length; i++) {
            elements[i] += other.elements[i];
        }
    }

    public int getElement(int index) {
        return elements[index];
    }

    public void setElement(int index, int element) {
        elements[index] = element;
    }

    public int getLength() {
        return elements.length;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < elements.length; i++) {
            sb.append(elements[i]);
            if (i != elements.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

}