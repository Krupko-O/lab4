#include <iostream>
#include <cmath>
using namespace std;

// оголошення функцій
void Swap(double &X, double &Y);                // обмін двох чисел
bool in_ABCD(double &pA, double &pB, double &pC, double &pD); // введення A, B, C, D
void out_ABCD(double pA, double pB, double pC, double pD);    // виведення A, B, C, D
void task_Proc10();                             // задача Proc10

void RectPS(double x1, double y1, double x2, double y2, double &P, double &S); // периметр і площа
bool in_rect(double &x1, double &y1, double &x2, double &y2);  // введення координат
void out_rect(double pP, double pS);            // виведення P і S
void task_Proc5();                              // задача Proc5

bool in_sec(int &pSec);                         // введення секунд
void calc_quarter(int pSec, int &pQ, int &pT);  // підрахунок Integer32
void out_quarter(int pQ, int pT);               // виведення результату
void task_Int32();                              // задача Integer32

int main()
{
    int choice;                                 // вибір в меню
    do
    {
        cout << endl << "Меню:" << endl;
        cout << "1 - Proc10" << endl;
        cout << "2 - Proc5" << endl;
        cout << "3 - Integer32" << endl;
        cout << "0 - Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;                          // введення вибору
        if (cin.fail())                         // якщо ввели не число
        {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = -1;
        }
        switch (choice)
        {
        case 1: task_Proc10(); break;           // задача Proc10
        case 2: task_Proc5(); break;            // задача Proc5
        case 3: task_Int32(); break;            // задача Integer32
        case 0: cout << "Кінець" << endl; break;
        default: cout << "Такого пункту немає!" << endl;
        }
    } while (choice != 0);                      // поки не вибрали вихід
    return 0;
}

// ---------- Proc10 ----------
void Swap(double &X, double &Y)
{
    double t = X;                               // запам'ятали X
    X = Y;                                      // в X записали Y
    Y = t;                                      // в Y записали старе X
}

bool in_ABCD(double &pA, double &pB, double &pC, double &pD)
{
    cout << "Proc10." << endl;
    cout << "Введіть A, B, C, D (від -100 до 100): ";
    cin >> pA >> pB >> pC >> pD;                // введення
    if (cin.fail())                             // перевірка на помилку
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return true;
    }
    if (pA < -100 || pA > 100 || pB < -100 || pB > 100 ||
        pC < -100 || pC > 100 || pD < -100 || pD > 100)
        return true;                            // число не в діапазоні
    return false;
}

void out_ABCD(double pA, double pB, double pC, double pD)
{
    cout << "A = " << pA << ", B = " << pB << ", C = " << pC << ", D = " << pD << endl;
}

void task_Proc10()
{
    double A, B, C, D;                          // оголошення змінних
    if (in_ABCD(A, B, C, D))                    // введення
        cout << "Помилка введення!" << endl;
    else
    {
        Swap(A, B);                             // міняємо A і B
        Swap(C, D);                             // міняємо C і D
        Swap(B, C);                             // міняємо B і C
        cout << "Нові значення:" << endl;
        out_ABCD(A, B, C, D);                   // виведення
    }
}

// ---------- Proc5 ----------
void RectPS(double x1, double y1, double x2, double y2, double &P, double &S)
{
    double a = fabs(x2 - x1);                   // довжина сторони
    double b = fabs(y2 - y1);                   // ширина сторони
    P = 2 * (a + b);                            // периметр
    S = a * b;                                  // площа
}

bool in_rect(double &x1, double &y1, double &x2, double &y2)
{
    cout << "Введіть x1, y1, x2, y2 (від -100 до 100): ";
    cin >> x1 >> y1 >> x2 >> y2;                // введення
    if (cin.fail())                             // перевірка на помилку
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return true;
    }
    if (x1 < -100 || x1 > 100 || y1 < -100 || y1 > 100 ||
        x2 < -100 || x2 > 100 || y2 < -100 || y2 > 100)
        return true;                            // число не в діапазоні
    return false;
}

void out_rect(double pP, double pS)
{
    cout << "P = " << pP << ", S = " << pS << endl;
}

void task_Proc5()
{
    double ax1, ay1, ax2, ay2;                  // 1 прямокутник
    double bx1, by1, bx2, by2;                  // 2 прямокутник
    double cx1, cy1, cx2, cy2;                  // 3 прямокутник
    double P, S;                                // периметр і площа
    cout << "Proc5." << endl;
    cout << "Прямокутник 1. ";
    if (in_rect(ax1, ay1, ax2, ay2))
    {
        cout << "Помилка введення!" << endl;
        return;                                 // виходимо з процедури
    }
    cout << "Прямокутник 2. ";
    if (in_rect(bx1, by1, bx2, by2))
    {
        cout << "Помилка введення!" << endl;
        return;
    }
    cout << "Прямокутник 3. ";
    if (in_rect(cx1, cy1, cx2, cy2))
    {
        cout << "Помилка введення!" << endl;
        return;
    }
    RectPS(ax1, ay1, ax2, ay2, P, S);           // рахуємо 1 прямокутник
    out_rect(P, S);
    RectPS(bx1, by1, bx2, by2, P, S);           // рахуємо 2 прямокутник
    out_rect(P, S);
    RectPS(cx1, cy1, cx2, cy2, P, S);           // рахуємо 3 прямокутник
    out_rect(P, S);
}

// ---------- Integer32 ----------
bool in_sec(int &pSec)
{
    cout << "Integer32." << endl;
    cout << "Введіть секунди (1-59): ";
    cin >> pSec;                                // введення
    if (cin.fail())                             // перевірка на помилку
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return true;
    }
    if (pSec < 1 || pSec > 59)                  // число не в діапазоні
        return true;
    return false;
}

void calc_quarter(int pSec, int &pQ, int &pT)
{
    pQ = pSec / 900 + 1;                        // номер чверті (900 с = 15 хв)
    pT = pSec % 900;                            // скільки секунд пройшло
}

void out_quarter(int pQ, int pT)
{
    cout << "Номер чверті: " << pQ << endl;
    cout << "Пройшло секунд: " << pT << endl;
}

void task_Int32()
{
    int sec, q, t;                              // оголошення змінних
    if (in_sec(sec))                            // введення
        cout << "Помилка введення!" << endl;
    else
    {
        calc_quarter(sec, q, t);                // підрахунок
        out_quarter(q, t);                      // виведення
    }
}