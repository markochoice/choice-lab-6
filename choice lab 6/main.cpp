#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct emplopyeeType
{
    string firstName,lastName;
    double Annual_salary, monthly_grosspay, monthly_netPay,Federal_grossPay;
    double state_Tax,Social_Securitytax,Medicare_tax,Pension_plan;
    double Health_insurance,Month_Netpay;
    
}employee[25];

void read(emplopyeeType list[],ifstream& in);
void calculatepaycheck(emplopyeeType list[]);
double computefedTax(double monthpay);

void Printpaycheck(emplopyeeType list[]);


ifstream in;
ofstream out;

const double STATETAX= 0.05;
const double SOCIALSECURITY = 0.062;
const double MEDICARETAX = 0.0145;
const double PENSIONPLAN = 0.05;
const double HEALTHINSURANCE = 125.00;

int main ()
{
    
    
    in.open("employees.txt");
    out.open("choice.txt");
    
    read(employee,in);
    calculatepaycheck( employee);
    Printpaycheck( employee);
    
    
    in.close();
    out.close();
    
    // system ("pause");
    return 0;
    
}
void read(emplopyeeType list[],ifstream& in)
{
    for(size_t i=0;i<25;i++)
    {
        in >> employee[i].firstName;
        in >> employee[i].lastName;
        in >> employee[i].Annual_salary;
    }
}

void calculatepaycheck(emplopyeeType list[])
{
    double sum;
    
    for(size_t i =0;i<25;i++)
    {
        employee[i].monthly_grosspay= employee[i].Annual_salary / 12;
        employee[i].state_Tax = employee[i].monthly_grosspay*STATETAX;
        employee[i].Social_Securitytax=employee[i].monthly_grosspay*SOCIALSECURITY;
        employee[i].Medicare_tax=employee[i].monthly_grosspay*MEDICARETAX;
        employee[i].Pension_plan=employee[i].monthly_grosspay*PENSIONPLAN;
        employee[i].Health_insurance = HEALTHINSURANCE;
        employee[i].Federal_grossPay=computefedTax(employee[i].monthly_grosspay);
        
        
        sum = (employee[i].Federal_grossPay + employee[i].state_Tax
               + employee[i].Social_Securitytax + employee[i].Medicare_tax + employee[i].Pension_plan + employee[i].Health_insurance);
        employee[i].monthly_netPay = employee[i].monthly_grosspay - sum;
    }
    
    
}
void Printpaycheck(emplopyeeType list[])
{
    out << fixed << showpoint << setprecision(2);
    for (size_t i=0;i<25;i++)
    {
        out << " First and Last name  is: " << employee[i].firstName << " " << employee[i].lastName << endl;
        out << " Annual Salary  is: " << employee[i].Annual_salary << endl;
        out << " Monthly Gross pay  is: " << employee[i].Annual_salary / 12 << endl;
        out << " Federal Tax reduction  is: " << employee[i].Federal_grossPay << endl;
        out << " State Tax reduction  is: "<< employee[i].state_Tax << endl;
        out << " Social Security Tax reduction  is: "  << employee[i].Social_Securitytax << endl;
        out << " Medicare tax reduction  is: " << employee[i].Medicare_tax << endl;
        out << " Pension Plan reduction is: " << employee[i].Pension_plan << endl;
        out << " Health Insurance reduction is: " << employee[i].Health_insurance << endl;
        out << " Monthly Net pay is: " << employee[i].monthly_netPay << endl;
        out << endl;
    }
}
double computefedTax(double monthpay)
{
    double fedTax;
    
    if (monthpay >= 0 && monthpay <= 179)
        fedTax =  0;
    else if (monthpay > 179 && monthpay  <= 904)
        fedTax = (monthpay - 179) * 0.10;
    else if (monthpay >  904 && monthpay  < 3125)
        fedTax = (monthpay-904)*0.15 + 72.50;
    else if (monthpay > 3125 && monthpay  <= 7317)
        fedTax = (monthpay-3125)*0.25 + 405.65;
    else if (monthpay > 7317 && monthpay  <= 15067)
        fedTax = (monthpay-7317)*0.28 + 1453.65;
    else if (monthpay > 15067 && monthpay  <= 32542)
        fedTax = (monthpay-15067)*0.33 + 3623.65;
    else 
        fedTax = (monthpay-32542)*0.35 + 9390.40;
    
    
    return fedTax;
}
