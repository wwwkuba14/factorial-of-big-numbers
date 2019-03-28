#include "kontener.hpp"

using namespace std;

int main()
{

    Kontener test('A',10);
    for(int i=0; i < test.size(); i++)
        cout << test[i] << endl;


    return 0;
}