#include "Renderer.h"
#include <Windows.h>

sf::RectangleShape Renderer::CreateRectangle(float width, int height, int scale, sf::Color color) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(width, -height));
	rectangle.setPosition(scale, screenHeight);
	rectangle.setFillColor(color);
	return rectangle;
}

Renderer::Renderer(const int width_, const int height_, sf::RenderWindow* window_, sf::Sound* sound_) {
	screenWidth = width_;
	screenHeight = height_;
	window = window_;
	sound = sound_;
}
void Renderer::DrawSnapshot(std::vector<int> arr, int index) {
	if (!window) return;
	sound->setPitch(0.2 + (arr[index] / static_cast<float>(screenHeight)) * 0.6);

	window->clear();
	const float x = static_cast<float>(screenWidth) / arr.size();
	float scale = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		window->draw(CreateRectangle(x / 2, arr[i], scale, i == index ? sf::Color::Red : sf::Color::White));
		scale += x;
	}
	window->display();
}
void Renderer::DrawFinished(std::vector<int> arr) {
	for (int j = 0; j < arr.size(); j++)
	{
		if (!window) return;
		window->clear();
		const float x = static_cast<float>(screenWidth) / arr.size();
		float scale = 0;
		sound->setPitch(0.2 + (arr[j] / static_cast<float>(screenHeight)) * 0.6);

		for (int i = 0; i < arr.size(); i++)
		{
			sf::Color color;
			if (i <= j) {
				color = sf::Color::Green;
			}
			else {
				color = sf::Color::White;
			}
			window->draw(CreateRectangle(x / 2, arr[i], scale, color));
			scale += x;
		}
		window->display();
		Sleep(5);
	}
}
