#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = ltm->tm_year + 1900;
    int date = ltm->tm_mday;
    int month = ltm->tm_mon;
    int wday = ltm->tm_wday;

    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int second = ltm->tm_sec;

    string hr;
    string min;
    string sec;
    string dat;

    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string day[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    if (hour)
    {
        stringstream ss;
        ss << setw(2) << setfill('0') << hour % 12;
        string result = ss.str();
        hr = result;
    }
    if (minute)
    {
        stringstream ss;
        ss << setw(2) << setfill('0') << minute;
        string result = ss.str();
        min = result;
    }
    if (second)
    {
        stringstream ss;
        ss << setw(2) << setfill('0') << second;
        string result = ss.str();
        sec = result;
    }
    if (date)
    {
        stringstream ss;
        ss << setw(2) << setfill('0') << date;
        string result = ss.str();
        dat = result;
    }

    cout << day[wday] << " " << dat << "/" << months[month] << "/" << year << endl;

    cout << hr << ":" << min << ":" << sec << endl;
}