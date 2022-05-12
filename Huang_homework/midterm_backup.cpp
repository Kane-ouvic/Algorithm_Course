#include <iostream>
#include <algorithm>
#include <math.h>
#include <random>
#include <vector>
#include <array>
#include <time.h>
#include <iomanip>
using namespace std;

void basic_1();
//
void basic_2();
//
double absolute(double num);
void basic_3();
//
void basic_4();

//////////////
class Student
{

public:
    Student();
    Student(string ifirstName, string isecondName, string iphoneNumber, string iID, string ipassword, int iage)
        : firstName(ifirstName), secondName(isecondName), phoneNumber(iphoneNumber), ID(iID), password(ipassword), age(iage) {}

    string getFirstName()
    {
        return firstName;
    }
    void setFirstName(string iFirstName)
    {
        firstName = iFirstName;
    }
    string getSecondName()
    {
        return secondName;
    }
    void setSecondName(string iSecondName)
    {
        firstName = iSecondName;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    void setPhoneNumber(string iPhoneNumber)
    {
        phoneNumber = iPhoneNumber;
    }
    string getID()
    {
        return ID;
    }
    void setID(string iID)
    {
        ID = iID;
    }
    string getPassword()
    {
        return password;
    }
    void setPassword(string iPassword)
    {
        password = iPassword;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int iAge)
    {
        age = iAge;
    }

private:
    string firstName;
    string secondName;
    string phoneNumber;
    string ID;
    string password;
    int age;
};
///////
void advance_2();
unsigned long long int comb(int n, int k);
/////////////

void ML_1();

/////////////
class Line
{
public:
    Line();
    Line(int iA, int iB, int iC) : a(iA), b(iB), c(iC) {}

    int classify(int x, int y)
    {
        return a * x + b * y + c;
    }

private:
    int a;
    int b;
    int c;
};

void
ML_2();

/////////////
int main()
{
    ML_2();

    /*{
        Student students[3] = {Student("Cheng", "Onion", "0974141414", "ABC001", "123123", 16),
                               Student("Wong", "Jimmy", "0912345678", "ABC002", "456456", 32),
                               Student("Yang", "Sheep", "0911111111", "ABC003", "789789", 40)};
        // Student onion1("Cheng", "Onion", "0974141414", "ABC001", "123123", 16);
        // Student onion2("Wong", "Jimmy", "0912345678", "ABC002", "456456", 32);
        // Student onion3("Yang", "Sheep", "0911111111", "ABC003", "789789", 40);
        // students[0] = onion1;
        // students[1] = onion2;
        // students[2] = onion3;

        string input_ID;
        string input_password;
        int found_index = 0;
        bool found = false;

        cout << "Good morning, Mr." << endl;
        cout << "Login first" << endl;
        cout << endl;
        cout << "Input your ID" << endl;
        cout << "ID:";
        cin >> input_ID;

        for (int i = 0; i < 3; i++)
        {
            if (input_ID == students[i].getID())
            {
                found = true;
                found_index = i;
            }
        }
        if (found)
        {
            cout << "Nice to meet you, Mr." << students[found_index].getFirstName() << endl;
            cout << endl;
            cout << "Input your password: " << endl;
            cin >> input_password;
            if (input_password == students[found_index].getPassword())
            {
                cout << "PASS!" << endl;
            }
            else
            {
                cout << "Sorry, your password!" << endl;
            }
        }
        else
        {
            cout << "not found the user!" << endl;
        }
    }*/

    return 0;
}

void basic_1()
{
    int num;
    cin >> num;
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
            sum += i;
        }
    }
    cout << endl;
    cout << "sum: " << sum << endl;
}

void basic_2()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == i)
            {
                cout << i << " ";
            }
        }
    }
    else if (N == 2)
    {
        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // cout << 10 * i + j << " " << pow(i, 2) + pow(j, 2) << endl;
                if (10 * i + j == i * i + j * j)
                {
                    cout << i << j << " ";
                }
            }
        }
    }
    else if (N == 3)
    {
        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    // cout << 100 * i + 10 * j + k << " " << pow(i, 3) + pow(j, 3) + pow(k, 3) << endl;
                    if ((100 * i + 10 * j + k) == i * i * i + j * j * j + k * k * k)
                    {
                        cout << i << j << k << " ";
                    }
                }
            }
        }
    }
    else if (N == 4)
    {
        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    for (int h = 0; h < 10; h++)
                    {
                        if (1000 * i + 100 * j + 10 * k + h == i * i * i * i + j * j * j * j + k * k * k * k + h * h * h * h)
                        {
                            cout << i << j << k << h << " ";
                        }
                    }
                }
            }
        }
    }
}

double absolute(double num)
{
    if (num < 0.0)
        return -num;
    else
        return num;
}

void basic_3()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    /* 常態分布 */
    std::normal_distribution<double> norm(5.0, sqrt(3));

    double array[300];
    double sum = 0.0;
    double sum_square = 0.0;
    double mean = 0.0;
    double sigma = 0.0;

    for (int i = 0; i < 300; i++)
    {
        array[i] = norm(generator);
        sum += array[i];
    }

    mean = sum / 300;

    for (int i = 0; i < 300; i++)
    {
        sum_square += pow(absolute(array[i] - mean), 2);
    }
    sigma = sqrt(sum_square / 300);

    cout << mean << " " << sigma << "-------";
}

void basic_4()
{
    int side;
    vector<int> sides;
    for (int i = 0; i < 3; i++)
    {
        cin >> side;
        sides.push_back(side);
    }
    sort(sides.begin(), sides.end());

    if (sides[0] + sides[1] > sides[2])
    {
        int side_square = sides[0] * sides[0] + sides[1] * sides[1] - sides[2] * sides[2];

        if (side_square < 0)
        {
            cout << "obtuse triangle" << endl;
        }
        else if (side_square == 0)
        {
            cout << "right triangle" << endl;
        }
        else
        {
            cout << "acute triangle" << endl;
        }
    }
    else
    {
        cout << "The triangle doesnt exist!" << endl;
    }
}

unsigned long long int comb(int n, int k)
{
    unsigned long long int n_fact = 1;
    unsigned long long int k_fact = 1;
    int divider = 0;

    for (int i = 0; i < k; i++)
    {
        n_fact = n_fact * (n - i);
        k_fact = k_fact * (1 + i);
        divider = __gcd(n_fact, k_fact);
        n_fact = n_fact / divider;
        k_fact = k_fact / divider;
    }
    return n_fact / k_fact;
}

void advance_2()
{
    int n, k;
    cout << "Input n & k for n choose k: " << endl;
    cin >> n >> k;
    if (k > n / 2)
        cout << comb(n, n - k) << endl;
    else
        cout << comb(n, k) << endl;
}

///////////////////////////
#define p 2

double EuclideanDistance(array<int, p> &A, array<int, p> &B)
{
    double distance = 0;
    for (int i = 0; i < p; i++)
    {
        distance += pow(absolute(A[i] - B[i]), 2);
    }
    return sqrt(distance);
}

void ML_1()
{
    srand(time(NULL));
    int min = -5;
    int max = 5;

    vector<array<int, p>> points;
    array<int, p> point;

    for (int i = 0; i < 10; i++)
    {
        cout << "point[" << i + 1 << "] = (";
        for (int j = 0; j < p; j++)
        {
            point[j] = rand() % (max - min + 1) + min;
            cout << point[j] << " ";
        }
        cout << ")" << endl;
        points.push_back(point);
    }
    double table[10][10];
    cout << "-------------------------" << endl;
    cout << "Matrix: " << endl;
    cout << " ";
    for (int i = 0; i < 10; i++)
    {
        cout << "       " << i + 1;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "  ";
        for (int j = 0; j < 10; j++)
        {
            table[i][j] = EuclideanDistance(points[i], points[j]);
            printf("%-2.4f  ", table[i][j]);
        }
        cout << endl;
    }
}
///////////////////

void ML_2()
{
    int a, b;
    cin >> a >> b;

    Line line1(5, 7, -35);
    Line line2(1, 8, -8);
    Line line3(3, -4, 12);
    int l1 = line1.classify(a, b);
    int l2 = line2.classify(a, b);
    int l3 = line3.classify(a, b);
    cout << l1 << " " << l2 << " " << l3 << endl;
    if(l1 > 0 && l2 > 0 && l3 < 0)
        cout << "Falling in Space I" << endl;
    else if(l1 < 0 && l2 > 0 && l3 < 0)
        cout << "Falling in Space II" << endl;
    else if(l1 < 0 && l2 < 0 && l3 < 0)
        cout << "Falling in Space III" << endl;
    else if(l1 < 0 && l2 < 0 && l3 > 0)
        cout << "Falling in Space IV" << endl;
    else if(l1 < 0 && l2 > 0 && l3 > 0)
        cout << "Falling in Space V\n" << "In the desired area!" << endl;
    else if(l1 > 0 && l2 > 0 && l3 > 0)
        cout << "Falling in Space VI" << endl;
    else if(l1 > 0 && l2 < 0 && l3 > 0)
        cout << "Falling in Space VII" << endl;
    else
        cout << "Falling on line" << endl;
}