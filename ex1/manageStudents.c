#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lineCounter = 0;
int studentCounter = 0;
#define FIELD_SIZE 42
#define MAX_SIZE_INPUT 61
#define MAX_STUDENTS 5501
/**
 * Struct that represents a student
 */
struct Student
{
    char idNumber[FIELD_SIZE], age[FIELD_SIZE], grade[FIELD_SIZE];
    char name[FIELD_SIZE], country[FIELD_SIZE], city[FIELD_SIZE];
};
/**
 * Swap Student objects between arrays
 * @param a Array of Student structs elements
 * @param b Array of Student structs elements
 */
void swapArray(struct Student a[], struct Student b[])
{
    struct Student tempStudentArray = *a;
    *a = *b;
    *b = tempStudentArray;
}
/**
 * Function to partition the array, using a pivot for the quicksort algorithm
 * @param A An array of Student objects
 * @param firstElementIndex Index at which the partitioning needs to start
 * @param lastElementIndex Index at which partitioning finishes
 * @return an Index
 */
int partitioning(struct Student A[], int firstElementIndex, int lastElementIndex)
{
    char pivotElement[FIELD_SIZE];
    strcpy(pivotElement, A[lastElementIndex].name);
    int storeIndex = (firstElementIndex - 1);
    int i;
    for (i = firstElementIndex; i <= lastElementIndex - 1; i++)
    {
        if (strcmp(A[i].name, pivotElement) < 0)
        {
            storeIndex++;
            swapArray(&A[storeIndex], &A[i]);
        }
    }
    swapArray(&A[storeIndex + 1], &A[lastElementIndex]);
    return (storeIndex + 1);
}
/**
 * Quicksort function that uses the partitioning function above
 * @param A An array of Student objects
 * @param firstElementIndex Index at which the quicksort algorithm needs to start
 * @param lastElementIndex Index at which the quicksort algorithm needs to end
 */
void quickSort(struct Student A[], int firstElementIndex, int lastElementIndex)
{
    if (firstElementIndex < lastElementIndex)
    {
        int partitionIndex = partitioning(A, firstElementIndex, lastElementIndex);
        quickSort(A, firstElementIndex, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, lastElementIndex);
    }

}
/**
 * Function to print the content of an array of Student objects
 * @param A An array of Student objects
 * @param size The size of the array (number of elements inside it)
 */
void printArray(struct Student A[], int size)
{

    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s,%s,%s,%s,%s,%s\n", A[i].idNumber, A[i].name, A[i].grade, A[i].age, A[i].country, A[i].city);
    }

}
/**
 * Function that performs a merge sort
 * @param arr The array that is divided into 2 sorted arrays to merge them
 * @param firstElement Index at which the array starts
 * @param midElement Index half between the indexes of the first and last element
 * @param lastElement Index at which the array ends
 */
void merge(struct Student arr[], int firstElement, int midElement, int lastElement)
{
    int firstHalfSize = midElement - firstElement + 1;
    int secondHalfSize = lastElement - midElement;
    struct Student firstHalfArray[MAX_STUDENTS];
    struct Student secondHalfArray[MAX_STUDENTS];

    char *p;
    char *s;

    for (int i = 0; i < firstHalfSize; i++)
    {
        firstHalfArray[i] = arr[firstElement + i];
    }

    for (int j = 0; j < secondHalfSize; j++)
    {
        secondHalfArray[j] = arr[midElement + 1 + j];
    }

    int index1 = 0;
    int index2 = 0;
    int mergedArrIndex = firstElement;

    while (index1 < firstHalfSize && index2 < secondHalfSize)
    {

        if (strtol(firstHalfArray[index1].grade, &p, 10) <= strtol(secondHalfArray[index2].grade, &s, 10))
        {
            arr[mergedArrIndex] = firstHalfArray[index1];
            index1++;
        }
        else
        {
            arr[mergedArrIndex] = secondHalfArray[index2];
            index2++;
        }
        mergedArrIndex++;
    }

    while (index1 < firstHalfSize)
    {
        arr[mergedArrIndex] = firstHalfArray[index1];
        mergedArrIndex++;
        index1++;
    }

    while(index2 < secondHalfSize)
    {
        arr[mergedArrIndex] = secondHalfArray[index2];
        mergedArrIndex++;
        index2++;
    }


}
/**
 * Merge sort function using the above merge function
 * @param arr The array to be sorted
 * @param firstElement Index at which the array starts
 * @param lastElement Index at which the array ends
 */
void mergeSort(struct Student arr[], int firstElement, int lastElement)
{
    if (firstElement < lastElement)
    {
        int midElement = (firstElement + lastElement) / 2;
        mergeSort(arr, firstElement, midElement);
        mergeSort(arr, midElement + 1, lastElement);
        merge(arr, firstElement, midElement, lastElement);

    }
}
/**
 * Function to check the validity of the city input
 * @param city City entered by the user
 * @return 0 if valid, 1 if not
 */
int checkCityValidity(char city[FIELD_SIZE])
{
    size_t len = strlen(city);

    for (int i = 0; i < (int)len; i++)
    {
        if (city[i] >= 'a' && city[i] <= 'z')
        {
            continue;
        }
        else if (city[i] >= 'A' && city[i] <= 'Z')
        {
            continue;
        }
        else if (city[i] == '-')
        {
            continue;
        }

        else
        {
            printf("ERROR: city can only contain alphabetic characters or '-'\n");
            printf("in line %d\n", lineCounter);
            return 1;
        }
    }
    return 0;
}
/**
 * Function to check the validity of the country input
 * @param country Country entered by the user
 * @return 0 if valid, 1 if not
 */
int checkCountryValidity(char country[FIELD_SIZE])
{
    size_t len = strlen(country);

    for (int i = 0; i < (int)len; i++)
    {
        if (country[i] >= 'a' && country[i] <= 'z')
        {
            continue;
        }
        else if (country[i] >= 'A' && country[i] <= 'Z')
        {
            continue;
        }
        else if (country[i] == '-')
        {
            continue;
        }

        else
        {
            printf("ERROR: Country contains invalid character: %c\n", country[i]);
            printf("in line %d\n", lineCounter);
            return 1;
        }
    }
    return 0;
}
/**
 * Function to check the validity of the age input
 * @param age Age entered by the user
 * @return 0 if valid, 1 if not
 */
int checkAgeValidity(char age[FIELD_SIZE])
{
    char *p;
    long numAge;
    size_t len = strlen(age);

    if ((int)len == 3 || (int)len == 2)
    {
        for (int i = 0; i < (int)len; i++)
        {
            if (age[i] >= '0' && age[i] <= '9')
            {
                continue;
            }
            else
            {
                printf("ERROR: Age contains invalid characters\n");
                printf("in line %d\n", lineCounter);
                return 1;
            }
        }
        numAge = strtol(age, &p, 10);
        if (numAge > 120)
        {
            printf("ERROR: Age can\'t be over 120\n");
            printf("in line %d\n", lineCounter);
            return 1;
        }
        else if (numAge < 18)
        {
            printf("ERROR: Age can\'t be under 18\n");
            printf("in line %d\n", lineCounter);
            return 1;
        }
    }
    else
    {
        printf("ERROR: Age contains more than 3 digits or none\n");
        printf("in line %d\n", lineCounter);
        return 1;
    }

    return 0;
}
/**
 * Function to check the validity of the grade input
 * @param grade Grade entered by the user
 * @return 0 if valid, 1 if not
 */
int checkGradeValidity(char grade[FIELD_SIZE])
{
    char *p;
    long numGrade;

    size_t len = strlen(grade);
    if ((int)len <= 3)
    {
        for (int i = 0; i < (int)len; i++)
        {
            if (grade[0] == '0' && (int)len > 1)
            {
                printf("ERROR: Grade can't start with 0\n");
                printf("in line %d\n", lineCounter);
                return 1;
            }
            else if (grade[i] >= '0' && grade[i] <= '9')
            {
                continue;
            }
            else
            {
                printf("ERROR: Grade contains invalid characters: %c\n", grade[i]);
                printf("in line %d\n", lineCounter);
                return 1;
            }
        }
        numGrade = strtol(grade, &p, 10);
        if (numGrade > 100)
        {
            printf("ERROR: Grade can\'t be over 100\n");
            printf("in line %d\n", lineCounter);
            return 1;
        }

    }
    else
    {
        printf("ERROR: Grade contains more than 3 digits or none\n");
        printf("in line %d\n", lineCounter);
        return 1;
    }

    return 0;
}
/**
 * Function to check the validity of the name input
 * @param name Name entered by the user
 * @return 0 if valid, 1 if not
 */
int checkNameValidity(char name[FIELD_SIZE])
{
    size_t len = strlen(name);

    for (int i = 0; i < (int)len; i++)
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            continue;
        }
        else if (name[i] >= 'A' && name[i] <= 'Z')
        {
            continue;
        }
        else if (name[i] == '-')
        {
            continue;
        }
        else if (name[i] == ' ')
        {
            continue;
        }
        else
        {
            printf("ERROR: Name contains invalid character: %c\n", name[i]);
            printf("in line %d\n", lineCounter);
            return 1;
        }
    }

    return 0;
}
/**
 * Function to check the validity of the ID Number input
 * @param idNumber ID Number entered by the user
 * @return 0 if valid, 1 if not
 */
int checkIdNumberValidity(char idNumber[FIELD_SIZE])
{
    size_t len = strlen(idNumber);
    if (len == 10)
    {
        for (int i = 0; i < (int)len ; i++)
        {
            if (idNumber[0] == '0')
            {
                printf("ERROR: ID Number can't start with 0\n");
                printf("in line %d\n", lineCounter);
                return 1;
            }
            else
            {
                if (idNumber[i] >= '0' && idNumber[i] <= '9')
                {
                    continue;
                }
                else
                {
                    printf("ERROR: Invalid characters in ID Number detected\n");
                    printf("in line %d\n", lineCounter);
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("ERROR: ID Number don't contains 10 numbers\n");
        printf("in line %d\n", lineCounter);
        return 1;
    }
    return 0;
}
/**
 * Function that checks if every input by the user is valid or not by calling the precedent declared functions
 * @param idNumber ID Number entered by the user
 * @param name Name entered by the user
 * @param grade Grade entered by the user
 * @param age Age entered by the user
 * @param country Country entered by the user
 * @param city City entered by the user
 * @return 0 if everything is valid, 1 if not
 */
int checkValidity(char *idNumber, char *name, char *grade, char *age, char *country, char *city)
{
    if (checkIdNumberValidity(idNumber) == 0 && checkNameValidity(name) == 0
        && checkGradeValidity(grade) == 0 && checkAgeValidity(age) == 0
        && checkCountryValidity(country) == 0 && checkCityValidity(city) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/**
 * Function to calculate the best ratio grade/age of the students entered
 * @param grade The grade entered by the user
 * @param age The age entered by the user
 * @return The ratio grade / age
 */
float calcBestRatio(char grade[FIELD_SIZE], char age[FIELD_SIZE])
{
    char *p;
    char *s;
    long gradeR;
    long ageR;

    gradeR = strtol(grade, &p, 10);
    ageR = strtol(age, &s, 10);

    return (float)gradeR / (float)ageR;
}
/**
Function to check if a student has a better ratio grade / age than the current one
 * @param bestRatio The current ratio
 * @param bestStudent The current best student
 * @param aStudent Student entered by the user
 * @param p A pointer
 * @return The best ratio
 */
float bestRatioCheck(float bestRatio, char bestStudent[60], struct Student aStudent, char *p)
{
    if (bestRatio == 0)
    {
        bestRatio = calcBestRatio(aStudent.grade, aStudent.age);
        strcpy(bestStudent, p);
    }
    else if (calcBestRatio(aStudent.grade, aStudent.age) > bestRatio)
    {
        bestRatio = calcBestRatio(aStudent.grade, aStudent.age);
        strcpy(bestStudent, p);
    }
    return bestRatio;
}
/**
 * Display message if the number of args is wrong
 */
void getErrorArg()
{
    printf("ERROR: Number of parameters entered is different than 6\n");
    printf("in line %d\n", lineCounter);
    lineCounter += 1;
}
/**
 * Checks what parameter was entered and executes functions accordingly
 * @param student Input of student
 * @param aStudent Student represented by a struct object
 * @param argv Argument entered
 * @param stopper Stopper to check whether was entered more than 6 args or not
 * @param students List of students
 * @param bestRatio Best ratio of students entered
 * @param p Pointer to student
 * @param bestStudent Best student with the best ratio
 * @return 0 if everything goes well, else 1
 */
int getInput(char student[MAX_SIZE_INPUT])
{
    printf("Enter student info. To exit press q, then enter\n");
    if (fgets(student, MAX_SIZE_INPUT, stdin) == NULL)
    {
        printf("ERROR: Input not valid\n");
        printf("in line %d\n", lineCounter);
        return 1;
    }
    return 0;
}

int actionExecution(char student[MAX_SIZE_INPUT], struct Student aStudent, char *argv[],char stopper[FIELD_SIZE],
    struct Student students[MAX_STUDENTS],float bestRatio, char *p,char bestStudent[MAX_SIZE_INPUT])
{
    if (strcmp (argv[1], "best") == 0) 
    {
        while (1) 
        {
            if (getInput(student) != 0) 
            {
                return 1;
            }
            if (sscanf(student, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n], %[^,\n]",
                aStudent.idNumber, aStudent.name, aStudent.grade, aStudent.age,
                aStudent.country, aStudent.city, stopper) == 6) {
                if (checkValidity(aStudent.idNumber, aStudent.name, aStudent.grade,
                    aStudent.age, aStudent.country, aStudent.city) == 0) 
                {
                    students[studentCounter] = aStudent;
                    studentCounter += 1;
                    bestRatio = bestRatioCheck(bestRatio, bestStudent, aStudent, p);
                }
                lineCounter += 1;
            } 
            else if (strcmp(student, "q\n") == 0) 
            {
                if (strcmp(bestStudent, "") == 0)
                {
                    break;
                } 
                else 
                {
                    printf("best student info is: %s", bestStudent);
                    return 0;
                }
            } else 
            {
                getErrorArg();
            }
        }
    }
    else if (strcmp(argv[1], "merge") == 0)
    {
        while (1)
        {
            if (getInput(student) != 0)
            {
                return 1;
            }
            if (sscanf(student, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n], %[^,\n]",
                aStudent.idNumber, aStudent.name, aStudent.grade, aStudent.age,
                aStudent.country, aStudent.city, stopper) == 6)
            {
                if (checkValidity(aStudent.idNumber, aStudent.name, aStudent.grade,
                    aStudent.age, aStudent.country, aStudent.city) == 0)
                {
                    students[studentCounter] = aStudent;
                    studentCounter += 1;

                }
                lineCounter += 1;
            }
            else if (strcmp(student, "q\n") == 0)
            {
                mergeSort(students, 0, studentCounter - 1);
                printArray(students, studentCounter);
                break;
            }
            else
            {
                getErrorArg();
            }
        }
    }
    else if (strcmp(argv[1], "quick") == 0)
    {
        while (1)
        {
            if (getInput(student) != 0)
            {
                return 1;
            }
            if (sscanf(student, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n], %[^,\n]",
                aStudent.idNumber, aStudent.name, aStudent.grade, aStudent.age,
                aStudent.country, aStudent.city, stopper) == 6) 
            {
                if (checkValidity(aStudent.idNumber, aStudent.name, aStudent.grade, aStudent.age, aStudent.country,
                    aStudent.city) == 0)
                {
                    students[studentCounter] = aStudent;
                    studentCounter += 1;
                }
                lineCounter += 1;
            }
            else if (strcmp(student, "q\n") == 0)
            {
                quickSort(students, 0, studentCounter - 1);
                printArray(students, studentCounter);
                break;
            }
            else
            {
                getErrorArg();
            }
        }
    }
    else
    {
        printf("USAGE: sortStudents <action>\n");
        return 1;
    }
    return 0;
}
/**
 *
 * @param argc Number of arguments entered
 * @param argv List of the arguments entered
 * @return 0 if the program worked well, 1 if not
 */
int main(int argc, char *argv[])
{
    struct Student aStudent;
    char stopper[FIELD_SIZE];
    char bestStudent[MAX_SIZE_INPUT];
    float bestRatio = 0;
    char student[MAX_SIZE_INPUT];
    char *p = student;
    struct Student students[MAX_STUDENTS];
    if (argc != 2)
    {
        printf("USAGE: sortStudents <action>\n");
        return 1;
    }
    else
    {
        if (actionExecution(student, aStudent, argv,stopper,students, bestRatio, p,bestStudent) == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }


    return 0;
}
