import hu.elte.geometry.Circle;
import hu.elte.geometry.Point;
import hu.elte.image.Canvas;

import java.awt.Color;
import java.io.IOException;

public class Circles {

    public static void main(String[] args) throws IOException {
        Circle[] circles = createCircles(args);

        try (Canvas canvas = new Canvas(200, 200)) {	
			for (var circle : circles) 
			{ 
				canvas.draw(circle, Color.MAGENTA);
			}
            
            canvas.saveToPng("korok.png");
        }
    }

    private static Circle[] createCircles(String[] args) {
		
		if (args.length % 3 != 0) {
            System.out.println("Args length not good");
			return new Circle[0];
        }
		
		int circleCount = args.length / 3;
		var result =  new Circle[circleCount];
		
		
		for(int i=0; i<circleCount; i++){
			result[i]=new Circle(
				new Point(
					Integer.parseInt(args[i*3]), 
					Integer.parseInt(args[i*3+1])
					),
				Integer.parseInt(args[i*3+2])
				);
        }
		
        return result;
    }

}