package hu.elte.geometry;
import hu.elte.geometry.Color;

public class ColoredCircle extends Circle implements Comparable  {
    private Color color;

    public ColoredCircle(Point center, double radius, Color color) {
        super(center, radius);
        this.color = color;
    }

    public Color getColor() {
        return this.color;
    }
 
    @Override
    public String toString() {
        return "ColoredCircle { color:" + this.color + super.toString() +"}";
    }
    
    @Override
    public int compareTo(Object other)
    {
        if (other instanceof ColoredCircle) {
            ColoredCircle otherCircle = (ColoredCircle) other;
            return (int) (this.getRadius() - otherCircle.getRadius());
        }
        return -1;
    }
}