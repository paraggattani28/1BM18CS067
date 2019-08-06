#include<stdio.h>
#include<conio.h>

struct stud
	{
		char name[20];
		char usn[10];
		int sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8,sub9;
	}s;

void main()
{
	clrscr();
	printf("Enter the Name of the student\n");
	gets(s.name);
	printf("Enter the USN of the student\n");
	gets(s.usn);
	printf("Enter the amrks of the student of all subjects\n");
	scanf("%d %d %d %d %d %d %d %d %d", &s.sub1, &s.sub2, &s.sub3, &s.sub4, &s.sub5, &s.sub6, &s.sub7, &s.sub8, &s.sub9);
	printf("NAME = %s", s.name);
	printf("\nUSN = %s", s.usn);
	printf("\nmarks obtained by the student in all subjects \nsub1=%d\n sub2=%d\n sub3=%d\n sub4=%d\n sub5=%d\n sub6=%d\n sub7=%d\n sub8=%d\n sub9=%d\n", s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, s.sub6, s.sub7, s.sub8, s.sub9);

	getch();

}