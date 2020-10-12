import hu.elte.math.Matrix;

public class MatrixTest {

    public static void main(String[] args) {
        testAdd();
        System.out.println("testAdd passed");
        testIncompatibleMatrices();
        System.out.println("testIncompatibleMatrices passed");
        testConstructorFails();
        System.out.println("testConstructorFails passed");
        testToString();
        System.out.println("testToString passed");

        // :)
        System.out.println("All tests passed");
    }

    private static void testAdd() {
        Matrix matrix1 = new Matrix(2, 1);
        matrix1.setElement(1, 0, 0);
        matrix1.setElement(2, 1, 0);
        Matrix matrix2 = new Matrix(2, 1);
        matrix2.setElement(3, 0, 0);
        matrix2.setElement(4, 1, 0);

        matrix1.add(matrix2);
        assertEquals(matrix1.getElement(0, 0), 4, "wrong add or getElement implementation");
        assertEquals(matrix1.getElement(1, 0), 6, "wrong add or getElement implementation");
    }

    private static void testIncompatibleMatrices() {
        try {
            Matrix matrix1 = new Matrix(1, 2);
            Matrix matrix2 = new Matrix(1, 3);
            matrix1.add(matrix2);
            throw new AssertionError("add operation accepted incompatible matrix");
        } catch (IllegalArgumentException e) {
            // ok
        }
        try {
            Matrix matrix1 = new Matrix(1, 2);
            Matrix matrix2 = new Matrix(2, 2);
            matrix1.add(matrix2);
            throw new AssertionError("add operation accepted incompatible matrix");
        } catch (IllegalArgumentException e) {
            // ok
        }
    }

    private static void testToString() {
        Matrix matrix = new Matrix(2, 3);
        matrix.setElement(1, 0, 0);
        matrix.setElement(2, 0, 1);
        matrix.setElement(3, 0, 2);
        matrix.setElement(4, 1, 0);
        matrix.setElement(5, 1, 1);
        matrix.setElement(6, 1, 2);
        String matrixRepresentation = matrix.toString();

        assertEquals(matrixRepresentation, "1 2 3 | 4 5 6", "wrong toString representation");
    }

    private static void assertEquals(Object actual, Object expected, String message) {
        if (!actual.equals(expected)) {
            throw new AssertionError(
                    "Message: " + message + ". Expected was " + expected + " but actual was " + actual);
        }
    }

    private static void testConstructorFails() {
        try {
            new Matrix(0, 10);
            throw new AssertionError("constructor accepted invalid height");
        } catch (IllegalArgumentException e) {
            // ok
        }
        try {
            new Matrix(10, -1);
            throw new AssertionError("constructor accepted invalid width");
        } catch (IllegalArgumentException e) {
            // ok
        }
    }

}