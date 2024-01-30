#include <stdio.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	//TODO
	int MAX_EMPLOYEES = 5;
	Employee employees[MAX_EMPLOYEES];
	int validUser = 0;
	int ch;
	int index;
	int i;
	for(i = 0; i < MAX_EMPLOYEES && validUser < 2; i++){
		validUser = 0;
		while(!validUser){
			struct Employee tempEmployee;
			printf("Please enter in the name of employee #%d: ", i+1);
			index = 0;
			while( (ch = getchar()) != '\n' ) {
				if (index < sizeof(tempEmployee.name) - 1){
					tempEmployee.name[index] = ch;
					index++;
				}
				
			}
			tempEmployee.name[index] = '\0';

			printf("Please enter in the salary for employee %s: ", tempEmployee.name);
			scanf("%d", &tempEmployee.salary);
			getchar(); //scanf doen't remove the '\n' character from the input stream, so we do it here
			employees[i] = tempEmployee;
			printf("You created an employee with name: %s, and salary %d.\n", tempEmployee.name, tempEmployee.salary);
			printf("Is this correct? type '0' to recreate employee, '1' to continue, '2' to exit employee creation: ");
			scanf("%d", &validUser);
			getchar();
		}
		
	}
	if(i == MAX_EMPLOYEES){
		printf("Maximum employees reached. Exiting employee creation\n");
	}
	int numEmployees = i;
	printf("Before: ");
	printList(employees, numEmployees);
	heapSort(employees, numEmployees);
	printf("After: ");
	printList(employees, numEmployees);

	return 0;
}
