#include <iostream>
#include <vector>
#include <string>

//using namespace std;

int main(int argc, char** argv) {    
    std::vector<int> a;
    std::string v;
    

    for (int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    
    for (int i : a) {
        std::cout << i << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}

