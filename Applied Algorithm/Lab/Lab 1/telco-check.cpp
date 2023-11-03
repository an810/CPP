#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool check_phone(string phone)
{
    if(phone.length() != 10) return false;
    for(int i = 0; i < phone.size(); ++i)
    {
        if(phone[i] < '0' || phone[i] > '9') return false;
    }
    return true;
}

int count_time(string startTime, string endTime) {
    int startTotal = 3600* ((startTime[0] - '0')*10 + startTime[1] - '0') + 60 * ((startTime[3] - '0')*10 + startTime[4] - '0') + ((startTime[6] - '0')*10 + startTime[7] - '0');
    int endTotal = 3600* ((endTime[0] - '0')*10 + endTime[1] - '0') + 60 * ((endTime[3] - '0')*10 + endTime[4] - '0') + ((endTime[6] - '0')*10 + endTime[7] - '0');
    return endTotal - startTotal;
}

map<string, int> nbCalls, timeCall;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    
    int totalCalls = 0, invalidPhone = 0;
    string cmd;

    do {
        cin >> cmd;
        if (cmd == "#") continue;
        ++totalCalls;
        string fnum, tnum, date, startTime, endTime;
        cin >> fnum >> tnum >> date >> startTime >> endTime;
        if (!check_phone(fnum) || !check_phone(tnum)) {
            ++invalidPhone;
            continue;
        }
        nbCalls[fnum] += 1;
        timeCall[fnum] += count_time(startTime, endTime);
    } while (cmd != "#");

    do {
        cin >> cmd;
        if (cmd == "#") continue;
        if (cmd == "?check_phone_number") {
            if (invalidPhone == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (cmd == "?number_calls_from") {
            string fnum;
            cin >> fnum;
            if (nbCalls.find(fnum) == nbCalls.end()) cout << 0 << endl;
            else cout << nbCalls[fnum] << endl;
        }
        else if (cmd == "?number_total_calls") {
            cout << totalCalls << endl;
        }
        else if (cmd == "?count_time_calls_from") {
            string fnum;
            cin >> fnum;
            if (timeCall.find(fnum) == timeCall.end()) cout << 0 << endl;
            else cout << timeCall[fnum] << endl;
        }
    } while (cmd != "#");
    return 0;
}