#include <iostream>
using namespace std;

void reachHome(int start, int desti)
{
    cout << start << " " << desti << " " << endl;

    // Base condition
    if (start == desti)
    {
        cout << "Reached at Home" << endl;
        return;
    }

// Process - increase walking step
    start++;
    
    // Recusive Relation (recursive Call)
    reachHome(start, desti);
}

int main()
{
    int start = 1;
    int desti = 10;
    reachHome(start, desti);
}