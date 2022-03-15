#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{  
    ofstream ofs;
    ofs.open("test.txt");
    for (int i = 0; i < 5000000; i++){
        ofs << "set" << " " << i << " " << i + 1 << endl;
    }

    for (int i = 0; i < 5000000; i++){
        ofs << "get" << " " << i << endl;
    }

    for (int i = 0; i < 5000000; i++){
        ofs << "set" << " " << i << " " << 900000 + 1 << endl;
    }
    ofs.close();
    return 0;
}