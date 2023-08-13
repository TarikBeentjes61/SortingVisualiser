#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Renderer {
private:
	int screenWidth;
	int screenHeight;
	sf::RenderWindow* window = nullptr;
	sf::Sound* sound;
	sf::RectangleShape CreateRectangle(float width, int height, int scale, sf::Color color);

public:
	Renderer(const int width_, const int height_, sf::RenderWindow* window_, sf::Sound* sound_);
	void DrawSnapshot(std::vector<int> arr, int index);
	void DrawFinished(std::vector<int> arr);
};