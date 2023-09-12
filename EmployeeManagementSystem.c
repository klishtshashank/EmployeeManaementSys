#include <stdio.h>
#include <stdbool.h>

struct Employee {
    // Structure declaration
    
    int employeeNo;
    char employeeName[30];
    float basicSal;
    
    struct Date {
        int dd, mm, yy;
    } hireDate;
    
    float netSalary;
};

void input(struct Employee*);
void show(struct Employee*);
float calcNet(float);

int main() {
    int n, i;
    
    // Get the number of elements for the array
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];
    
    // Get the details of the employees
    for (i = 0; i < n; i++) {
        input(&emp[i]);
    }
    
    // Print the details of the employees
    printf("\n======== EMPLOYEE RECORD =========");
    for (i = 0; i < n; i++) {
        show(&emp[i]);
        printf("\n");
    }
    
    return 0;
}

void input(struct Employee* emp) {
    // Function to accept the details of the employee
    printf("\n");
    printf("Employee Number: ");
    scanf("%d", &emp->employeeNo);
    
    printf("Employee Name: ");
    scanf("%s", emp->employeeName);
    
    printf("Hire Date (DD MM YY): ");
    scanf("%d %d %d", &emp->hireDate.dd, &emp->hireDate.mm, &emp->hireDate.yy);
    
    printf("Basic Salary: ");
    scanf("%f", &emp->basicSal);
  
    emp->netSalary = calcNet(emp->basicSal);
}

void show(struct Employee* emp) {
    // Function to display all the details
 
    printf("\nEmployee Number    :\t%d", emp->employeeNo);
    printf("\nEmployee Name      :\t%s", emp->employeeName);
    printf("\nHire Date(DD/MM/YY):\t%d/%d/%d", emp->hireDate.dd, emp->hireDate.mm, emp->hireDate.yy);
    printf("\nBasic Salary       :\t%0.2f", emp->basicSal);
    printf("\nNet Salary         :\t%0.2f", emp->netSalary);
}

float calcNet(float base) {
    // Function to calculate the net salary
    // gross salary = basic salary + DA + TA
    // net salary = gross salary - PF
    
    float DA = 0.4 * base;     // 40% of basic salary
    float TA = 0.1 * base;     // 10% of basic salary
    float PF = 0.05 * base;    // 5% of basic salary
    
    float gross = base + DA + TA;
    float net = gross - PF;
    
    return net;
}



