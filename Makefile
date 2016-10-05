main: main.o Student.o Input.o
	gcc main.o Student.o Input.o -o main
main.o: main.c Input.h Student.h
	gcc  -c main.c
Student.o: Student.c Input.h Student.h
	gcc  -c Student.c
Input.o: Input.c Input.h
	gcc  -c Input.c

clean:
	@echo "cleaning project"
	-rm main *.o
	@echo "clean completed"

