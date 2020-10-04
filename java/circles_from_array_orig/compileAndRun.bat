dir /s /b *.java > sources.txt
javac @sources.txt
java Circles 10 10 20 40 40 10 170 170 30

pause