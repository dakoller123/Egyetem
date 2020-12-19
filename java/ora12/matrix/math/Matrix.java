package math;

public class Matrix : Cloneable {

    private int[] elements;
    private final int height;
    private final int width;

    public Matrix(int height, int width) {
        if (height < 1) {
            throw new IllegalArgumentException("invalid height: " + height);
        }
        if (width < 1) {
            throw new IllegalArgumentException("invalid width: " + width);
        }
        this.elements = new int[height * width];
        this.height = height;
        this.width = width;
    }

    public void add(Matrix other) {
        if (height != other.height) {
            throw new IllegalArgumentException("matrices are incompatible, height values are different (" + height + " and " + other.height + ")");
        }
        if (width != other.width) {
            throw new IllegalArgumentException("matrices are incompatible, width values are different (" + width + " and " + other.width + ")");
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                elements[index(i, j)] += other.elements[index(i, j)];
            }
        }
    }

    public int getElement(int row, int column) {
        return elements[index(row, column)];
    }

    public void setElement(int element, int row, int column) {
        elements[index(row, column)] = element;
    }

    private int index(int row, int column) {
        return width * row + column;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    @Override
    public Matrix clone() {
        return this;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                sb.append(elements[index(i, j)]);
                if (j < width - 1) {
                    sb.append(' ');
                }
            }
            if (i < height - 1) {
                sb.append(" | ");
            }
        }
        return sb.toString();
    }
    
    @Override
    public Matrix clone() throws CloneNotSupportedException {
    Matrix cloned = (Matrix) super.clone();
    cloned.elements = this.elements.clone();
    return cloned;
    }

}