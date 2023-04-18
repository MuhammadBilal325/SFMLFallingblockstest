#include<iostream>
#include<SFML/Graphics.hpp>
class Box
{
private:
	int x, y;
	int index;
	int size;
	sf::RectangleShape shape;
	sf::RenderWindow* window;
public:
	Box() :x(0), y(0) ,size(0),window(nullptr) {}
	Box(int i, int j,int s,int k) :x(i), y(j),size(s),window(nullptr) {
		size = s;
		index = k;
		shape.setSize(sf::Vector2f(size, size));
	}
	void SetPosition(int i, int j)
	{
		x = i;
		y = j;
		UpdateOrigin();
	}
	void Draw() {
		window->draw(shape);
	}
	void DecrementY() {
		y--;
		UpdateOrigin();
	}
	void UpdateOrigin() {
		shape.setOrigin(x, y);
	}
	int GetY() { return y; }
	int GetX() { return x; }
	int GetIndex() { return index; }
	void SetWindow(sf::RenderWindow&win)
	{
		window = &win;
	}
	Box& operator=(const Box& RHS)
	{
		x = RHS.x;
		y = RHS.y;
		window = RHS.window;
		shape = RHS.shape;
		size = RHS.size;
		index = RHS.index;
		return *this;
	}
};