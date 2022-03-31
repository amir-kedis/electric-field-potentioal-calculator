#include <iostream>

using namespace std;

struct charge
{
    float value;
    float x;
    float y;
};

// max number of charges
#define QNUMMAX 10

int main()
{
    // get number of point charges from user
    int QNum;

    cout << "\nNumber of point charges: ";
    cin >> QNum;

    // check input
    while (true)
    {
        if (QNum > QNUMMAX || QNum < 0)
        {
            cout << "\nNumber of point charges can not exceed 10";

            cout << "\nNumber of point charges: ";
            cin >> QNum;
        }
        else {
            break;
        }
    }

    // define charge array
    charge charges[QNUMMAX];

    // Get input
    for (int i = 0; i < QNum; i++)
    {
        cout << "\ncharge " << i + 1 << " value in microColomb: ";
        cin >> charges[i].value;

        cout << "\ncharge " << i + 1 << " X: ";
        cin >> charges[i].x;

        cout << "\ncharge " << i + 1 << " Y: ";
        cin >> charges[i].y;
    }

    // calculate magnitude of E at origin
    double E = 0;
    double V = 0;
    for (int i = 0; i < QNum; i++)
    {
        // calculate dist from origin
        double dist = sqrt(charges[i].x * charges[i].x + charges[i].y * charges[i].y);
        
        if (dist != 0)
        {
            E += (9 * pow(10, 9)) * (charges[i].value * pow(10, -6)) / (dist * dist);
            
            V += (9 * pow(10, 9)) * (charges[i].value * pow(10, -6)) / (dist);
        }
    }

    cout << "\nMagnitude of electric field at origin is " << E;
    cout << "\nMagnitude of electric potential at origin is " << V;

    cout << "\n\n\n";

    return 0;
}
