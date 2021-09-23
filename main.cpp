#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>

using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

int main() {
    int count = 1;

    // Infinite loop
    while(0 < 1) {
        string command = "top -n 1 -b > " + to_string(count) + "-log-" + currentDateTime() + ".txt";
        const char* command2 = command.c_str();
        
        system(command2);

        cout << "log " << count << " created" << endl;

        count++;

        cout << "waiting 5 seconds..." << endl;
        
        sleep(5); // 5 seconds delay
    }
    
    return 0;
}
