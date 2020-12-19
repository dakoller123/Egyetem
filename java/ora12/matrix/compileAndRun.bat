dir /s /b *.java > sources.txt
javac -cp .;junit-4.12.jar;hamcrest-core-1.3.jar @sources.txt
java -cp .;junit-4.12.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore MatrixTest

pause