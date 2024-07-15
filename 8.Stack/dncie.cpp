#include <iostream>
using namespace std;

int main() {
    try {
        throw 'c';
    }
    catch (int param) {
        cout << "Int Exception";
    }
    catch(char ch){
        cout<<"Char ecxceptiuon";
    }
    catch (...) {
        cout << "Default Exception";
    }
    return 0;
}
