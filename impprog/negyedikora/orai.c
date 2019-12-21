#include <stdio.h>
#include <string.h>

int main() {
	char *p = "Koller David Daniel";
	char s[] = "12345678";
	char *q = s;
	
	// s = "sasadsad" <- ezt nem lehet, mert tömbnek nem lehet új értéked adni
	p = "Kiss Erik"; //pointernek simán lehet
	
	s[4] = 'A'; //tömb elemeinek lehet új értéket adni
	//p[1] = 'B'; // pointernek már nem, SegFault-ot fogsz kapni
	printf ("%s %s \n", p, s);
	return 0;
}