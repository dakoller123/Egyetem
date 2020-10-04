package hu.elte.geometry;

import hu.elte.geometry.Point;

public class CenterOfMassCalculator {

    public Point getCenterOfMass(Point[] points) {
		double x = 0.0;
		double y = 0.0;

		for (var point : points){
			x = x + point.getX();
			y = y + point.getY();
		}
		
		return new Point(x/points.length, y/points.length);		
    }

    
}