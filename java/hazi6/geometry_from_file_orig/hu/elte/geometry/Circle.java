package hu.elte.geometry;

public class Circle {
    private final Point center;
    private final double radius;

    public Circle(Point center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public Point getCenter() {
        return center;
    }

    public double getRadius() {
        return radius;
    }
 
    public boolean intersects(Circle other) {
        return Point.getDistance(center, other.center) <= radius + other.radius;
    }
    
    @Override
    public String toString(){
        return "C: " + center + ", R: " + radius;
    }
}