#include <iostream>

using namespace std;

class rectangle
{

    int length, width;

public:
    void set_dimensions(int l, int w)
    {

        length = l;
        width = w;
    }

    int area()
    {
        return length * width;
    }

    int perimeter()
    {

        return 2 * (length + width);
    }
};

int main()
{

    int length, width, number_rectangle;

    cout << "Enter the number of ractangle: ";
    cin >> number_rectangle;
    cout << endl;

    rectangle Rectangles[number_rectangle];

    for (int i = 0; i < number_rectangle; i++)
    {

        cout << "Enter the Length and Width of rectangle " << i + 1 << ":  ";
        cin >> length >> width;

        Rectangles[i].set_dimensions(length, width);

        int area = Rectangles[i].area();
        int perimeter = Rectangles[i].perimeter();

        cout << "The Area of rectangle " << i + 1 << " is " << area << " & The perimeter is " << perimeter << endl;
        cout << endl;
    }
    cout << "24CE108_VIVEK_SANGANI" << endl;
}
