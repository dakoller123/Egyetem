package car;

public class Car {

    private static int counter = 0;

    private int maxSpeed;

    public Car(String RegNumb, String color, int maxSpeed) {
        this.maxSpeed = maxSpeed;
        counter++;
    }

    public boolean isFasterThan(Car other){
        return maxSpeed > other.maxSpeed;
    }

}