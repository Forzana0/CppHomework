#include <iostream>

using namespace std;

const int SIZE = 100;

void fillArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101 - 50;;
    }
}

void Show(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

/////// task 1
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;
    while (day1 != day2 || month1 != month2 || year1 != year2) {
        days++;
        day1++;
        if (day1 > daysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }
    return days;
}

////// task 2
double average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

///// task 3
void countElements(int arr[], int size, int& positive, int& negative, int& zero) {
    positive = 0;
    negative = 0;
    zero = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive++;
        }
        else if (arr[i] < 0) {
            negative++;
        }
        else {
            zero++;
        }
    }
}

////// task 1
void initializeMatrix(int matrix[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 101;
        }
    }
}

void printMatrix(int matrix[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findDiagonal(int matrix[][SIZE], int size, int& minDiagonal, int& maxDiagonal) {
    minDiagonal = matrix[0][0];
    maxDiagonal = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minDiagonal) {
            minDiagonal = matrix[i][i];
        }
        if (matrix[i][i] > maxDiagonal) {
            maxDiagonal = matrix[i][i];
        }
    }
}

void sortRows(int matrix[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
}

// TASK 2
int searchDiv(int a, int b) {
    if (b == 0) {
        return a;
    }
    return searchDiv(b, a % b);
}

// TASK 3
int cows = 0, bulls = 0;
string secretNumber;

string generateSecretNumber() {
    srand(time(NULL));
    string number = "";
    while (number.length() < 4) {
        char digit = '0' + rand() % 10;
        if (number.find(digit) == string::npos) {
            number += digit;
        }
    }
    return number;
}

void checkGuess(string guess) {
    cows = 0;
    bulls = 0;
    for (int i = 0; i < 4; i++) {
        if (guess[i] == secretNumber[i]) {
            bulls++;
        }
        else if (secretNumber.find(guess[i]) != string::npos) {
            cows++;
        }
    }
}

void playGame(int attempts) {
    string guess;
    cout << "Enter your guess (4-digit number): ";
    cin >> guess;
    checkGuess(guess);
    if (bulls == 4) {
        cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
    }
    else {
        cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
        playGame(attempts + 1);
    }
}

int main()
{
    srand(time(NULL));
    const int SIZE = 25;
    int arr1[SIZE];

    // task 1
    int day1, month1, year1, day2, month2, year2;
    cout << "Enter the first date (day): "; cin >> day1;
    cout << "Enter the first date (month): "; cin >> month1;
    cout << "Enter the first date (year): "; cin >> year1; cout << endl;

    cout << "Enter the second date (day): "; cin >> day2;
    cout << "Enter the second date (month): "; cin >> month2;
    cout << "Enter the second date (year): "; cin >> year2; cout << endl;

    int days = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    cout << "The difference in days between the two dates is: " << days << endl << endl;

    // task 2
    int arr2[SIZE];
    fillArr(arr2, SIZE);
    double avg = average(arr2, SIZE);
    cout << "Array: "; Show(arr2, SIZE); cout << endl;
    cout << "Average: " << avg << endl << endl;


    // task 3
    int arr3[SIZE] = { 3, -2, 0, 5, -1, 0, -4 };
    int positive, negative, zero;
    fillArr(arr3, SIZE);
    countElements(arr3, SIZE, positive, negative, zero);

    cout << "Array: "; Show(arr3, SIZE); cout << endl;
    cout << "Positive elements: " << positive << endl;
    cout << "Negative elements: " << negative << endl;
    cout << "Zero elements: " << zero << endl;

    srand(time(NULL));

    // task 1
    int matrix[SIZE][SIZE];
    int size;

    cout << "Enter size: ";
    cin >> size;

    initializeMatrix(matrix, size);

    cout << "Matrix:" << endl; printMatrix(matrix, size);

    int minDiagonal, maxDiagonal;
    findDiagonal(matrix, size, minDiagonal, maxDiagonal);
    cout << "Minimum element on diagonal: " << minDiagonal << endl;
    cout << "Maximum element on diagonal: " << maxDiagonal << endl;

    sortRows(matrix, size);

    cout << "Sorted matrix:" << endl; printMatrix(matrix, size);

    // task 2
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = searchDiv(a, b);

    cout << "Divisor of " << a << " and " << b << " is: " << result << endl;

    // task 3
    secretNumber = generateSecretNumber();
    playGame(1);
}
