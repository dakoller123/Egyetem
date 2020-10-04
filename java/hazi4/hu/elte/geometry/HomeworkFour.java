package hu.elte.geometry;

import hu.elte.geometry.Point;
import hu.elte.geometry.CenterOfMassCalculator;

public class HomeworkFour {
	
	private static final int POINTCOUNT = 3;
	

    public static void main(String[] args){
		if (args.length != POINTCOUNT*2) {
            throw new IllegalArgumentException("argument count is wrong. exptected: " + POINTCOUNT*2 + " actual: " + args.length);
        }
		var points = new Point[POINTCOUNT];
				
		for(int i=0; i<POINTCOUNT; i++){
			points[i]= new Point(
				Double.parseDouble(args[i*2]), 
				Double.parseDouble(args[i*2+1])
			);
				
        }	
		
		var calc = new CenterOfMassCalculator();
		var result = calc.getCenterOfMass(points);
		
		System.out.println(result);
	}
    
}