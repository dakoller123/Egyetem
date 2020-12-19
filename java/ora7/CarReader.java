import car.Car;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner; 
public class CarReader {
    

    public static void main(String[] args){
        List<Car> cars = loadCars(args[0]);
        for (Car car : cars) {
            System.out.println(car);
        }
    }

    private static List<Car> loadCars(String path) {
        List<Car> cars = new ArrayList<>();        

        Scanner scanner = new Scanner(path); 
        
        while (scanner.hasNext()){
            if (scanner.hasNext()){
                String regNumb = scanner.next();
                if (scanner.hasNext()){
                    String color = scanner.next();
                    if (scanner.hasNextInt()){
                        int speed = scanner.nextInt();
                        cars.add(new Car(regNumb, color, speed));
                    }
                }
            }
        }        
        return cars;
    }

}