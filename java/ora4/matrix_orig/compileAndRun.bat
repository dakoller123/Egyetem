dir /s /b *.java > sources.txt
javac @sources.txt
java MatrixTest

pause