#include <iostream>
#include "ArrayManager.h"

short SquareWave(double time, double freq, double amp) {
	short result;
	double tpc = 44100 / freq; // ticks per cycle
	double cycles = time / tpc;
	double rad = 6.283185307 * cycles;
	short amplitude = 32767 * amp;
	result = amplitude * (sin(rad) >= 0.0 ? 1.0 : -1.0);
	return result;
}

int main()
{
	//Screen settings
	const int width = 1920;
	const int height = 1000;

	//Array settings
	const int length = 300;

	//Create sound object with basic samples
	sf::Sound sound;
	sf::SoundBuffer sb;
	std::vector<sf::Int16> samples;

	for (int i = 0; i < 44100; i++) {
		samples.push_back(SquareWave(i, 440, 0.05));
	}

	sb.loadFromSamples(samples.data(), samples.size(), 1, 44100);
	sound.setBuffer(sb);
	sound.setLoop(true);
	
	//Create window object and renderer object
	sf::RenderWindow window(sf::VideoMode(width, height), "Sorting Visualiser");
	Renderer renderer(width, height, &window, &sound);

	sf::Text text;
	//Create empty array manager
	IntArray values(&renderer, length);
	ArrayManager manager(values, length, &renderer);
	manager.Fill(height);
	//Window loop
	bool sorted = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				sound.play();
				switch (event.key.code)
				{
					case sf::Keyboard::F: 
						std::cout << "Filling\n";
						manager.Fill(height); 
						break;
					case sf::Keyboard::Num1:
						std::cout << "Quick Sort\n";
						manager.QuickSort(0, length - 1);
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num2:
						std::cout << "Bubble Sort\n";
						manager.BubbleSort();
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num3:
						std::cout << "Selection Sort\n";
						manager.SelectionSort();
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num4:
						std::cout << "Insertion Sort\n";
						manager.InsertionSort();
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num5:
						std::cout << "Cocktail Sort\n";
						manager.CocktailSort();
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num6:
						std::cout << "Pigeonhole Sort\n";
						manager.PigeonholeSort();
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num7:
						std::cout << "Merge Sort\n";
						manager.MergeSort(0, length-1);
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num8:
						std::cout << "Counting Sort\n";
						manager.CountingSort();	
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
					case sf::Keyboard::Num9:
						std::cout << "Gnome Sort\n";
						manager.GnomeSort();
						renderer.DrawFinished(manager.GetIntArray().GetArray());
						break;
				}
				sound.stop();
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}



