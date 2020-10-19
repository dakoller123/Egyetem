import hu.elte.geometry.Circle;
import hu.elte.geometry.Point;
import hu.elte.geometry.GeometryTypes;
import java.util.Scanner; 
import java.io.File;
import java.io.FileNotFoundException;
public class GeometryMain {

    public static void main(String[] args) throws FileNotFoundException {
        if (args == null || args.length < 0){
            throw new IllegalArgumentException("args is null");
        }
        Scanner scanner;
        try{
            scanner = new Scanner(new File(args[0]));    
        }
        catch (FileNotFoundException ex){
            System.out.println("Bad path");
            return;
        }
        
        
        while (scanner.hasNext()){   
            String s = scanner.next();
            GeometryTypes type;
            
            try{
                type = GeometryTypes.valueOf(s);
            }
            catch (Exception ex){
                System.out.println("Unkown Geometry type in input file: " + s);
                scanner.nextLine();
                continue;
            }
            
            switch(type) {
                case CIRCLE:
                    Circle circle = new Circle(new Point(scanner.nextDouble(), scanner.nextDouble()), scanner.nextDouble());
                    System.out.println("Circle: "+ circle);
                    break;
                case POINT:
                    Point point   = new Point(scanner.nextDouble(), scanner.nextDouble());
                    System.out.println("Point: "+ point);
                    break;                        
                default:
                    System.out.println("Unknown geometry type");
            }        
           
        }
    }


}