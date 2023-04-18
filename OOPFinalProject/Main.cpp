#include<SFML/Graphics.hpp>
#include"Classes.h"
#include<iostream>
using namespace std;
void IncreaseDynamicArr(Box*& arr, int size)
{
	Box* newarr = new Box[size + 1];
	for (int i = 0; i < size; i++)
		newarr[i] = arr[i];
	delete[]arr;
	arr = newarr;
}
void roundtoMult(int& val, int mult)
{
	int rem = val % mult;
	if (rem < (mult / 2))
		val = val - rem;
	else
		val = val + mult - rem;
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	sf::Event event;
	int x = 0, y = 0;
	int k = 0;
	bool flag = 0;
	Box* Boxes = new Box[1];
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K) {
				x = sf::Mouse::getPosition(window).x * -1;
				y = sf::Mouse::getPosition(window).y * -1;
				roundtoMult(x, 30);
				roundtoMult(y, 30);
				Box NewBox(x, y, 20, k);
				NewBox.SetWindow(window);
				if (k > 0)
					IncreaseDynamicArr(Boxes, k);
				Boxes[k] = NewBox;
				k++;
			}

		}
		for (int i = 0; i < k; i++)
		{
			flag = 1;
			if (Boxes[i].GetY() > -600 + 20) {
				for (int j = 0; j < k; j++) {
					if (Boxes[i].GetIndex() != Boxes[j].GetIndex())
						if (Boxes[i].GetX() < Boxes[j].GetX() + 20 && Boxes[i].GetX() > Boxes[j].GetX() - 20)
							if (Boxes[i].GetY() - 20 == Boxes[j].GetY())
								flag = 0;
				}
				if (flag)
					Boxes[i].DecrementY();
			}
		}
		window.clear();

		for (int i = 0; i < k; i++)
			Boxes[i].Draw();
		window.display();
	}
	delete[]Boxes;
}