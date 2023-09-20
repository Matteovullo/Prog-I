#include <iostream>

using namespace std;

#include<iostream>
using namespace std;

int main() {
    /*{
        int x = 2;
        {
            int y = x/2;
            cout << y;
        }
    }
}


    {
        int x = 2;
        {
            int y = x/2;
        }
    }
    cout << y;
}*/

    {
        int *x = new int(5);
        {
            int y = 3;
            x = &y;
        }
    }
    cout << *x;
}

