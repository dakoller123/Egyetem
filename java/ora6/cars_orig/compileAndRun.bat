dir /s /b *.java > sources.txt
javac @sources.txt
java CarsMain cars.txt

pause