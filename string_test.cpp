#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void convertTime(string time){
    cout << "TIME: " << time;
    string meridiem = time.substr(8,2);
    string hour = time.substr(0,2);    
    
    if (meridiem.compare("AM") == 0) {
        if (hour.compare("12") == 0) {
            hour = "00";
        }        
    }
    else {
        if (hour.compare("12") != 0) {
            stringstream convert(hour);
            int h;
            convert >> h;
            h += 12;
            hour = to_string(h);
        }
    }
    
    cout << " Converted: " << hour << time.substr(2,6) << endl;        
}
int main(int argc, char** argv) {
    convertTime("07:05:45PM");
    convertTime("10:05:45PM");
    convertTime("11:05:45PM");
    convertTime("11:05:45AM");
    convertTime("12:05:45AM");        
    
    return 0;
}

