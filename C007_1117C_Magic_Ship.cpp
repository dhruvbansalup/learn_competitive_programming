//https://codeforces.com/problemset/problem/1117/C

//Getting Error

#include <iostream>
#include <vector>
using namespace std;

class coordinate
{
public:
    int x;
    int y;
    coordinate() {}
    coordinate(int x, int y) : x(x), y(y) {}
    int length()
    {
        return (abs(x) + abs(y));
    }
    coordinate operator-(coordinate const &obj)
    {
        coordinate s;
        s.x = this->x - obj.x;
        s.y = this->y - obj.y;
        return s;
    }
    coordinate operator+(coordinate const &obj)
    {
        coordinate s;
        s.x = this->x + obj.x;
        s.y = this->y + obj.y;
        return s;
    }
};

int main()
{
    // Take Input
    int x1, y1, x2, y2, n;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> n;

    string winds;
    cin >> winds;

    coordinate start(x1, y1);
    coordinate end(x2, y2);

    // Calculate effects of winds
    vector<coordinate> effect_of_wind(n + 1, coordinate(0, 0));

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (winds[i] == 'U')
            y++;
        else if (winds[i] == 'D')
            y--;
        else if (winds[i] == 'L')
            x--;
        else if (winds[i] == 'R')
            x++;
        effect_of_wind[i + 1] = coordinate(x, y);
    }

    // Binary Search
    int lower = 0;
    int upper = 2e9;

    while (lower < upper)
    {
        int mid = (lower + upper) / 2;

        // Computing Distance
        int cycles = mid / n;
        int rem = mid % n;
        x = cycles * effect_of_wind[n].x + effect_of_wind[rem].x;
        y = cycles * effect_of_wind[n].y + effect_of_wind[rem].y;
        coordinate effect(x, y);

        coordinate offset = end - (start + effect);

        if (offset.length() <= mid)
        {
            upper = mid;
        }
        else
        {
            lower = mid + 1;
        }
    }

    if (lower >= (2e9))
    {
        cout << -1;
    }
    else
    {
        cout << upper;
    }
}