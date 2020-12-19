import org.junit.Assert;
import org.junit.Test;
import math.Matrix;

public class MatrixTest {

    @Test
    public void testClone() {
        // GIVEN
        Matrix originalMatrix = new Matrix(2, 1);
        originalMatrix.setElement(1, 0, 0);
        originalMatrix.setElement(2, 1, 0);

        // WHEN
        Matrix clonedMatrix = originalMatrix.clone();
        originalMatrix.setElement(-1, 1, 0);

        // THEN
        Assert.assertEquals(1, clonedMatrix.getElement(0, 0));
        Assert.assertEquals(2, clonedMatrix.getElement(1, 0));
    }
}