#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>
#include "TextGame.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio.hpp>


	


bool event_draw_square = false;
bool event_fill_square = false;
bool event_play_celadon = false;
bool event_celadon_playing = false;


void DrawWindow()
{

	

	sf::RenderWindow window(sf::VideoMode(640, 480, 4),"Game");//create window that can be drawn on
	sf::Event event;//creates an event object
	sf::RectangleShape square(sf::Vector2f(100, 100));

	sf::Music music;
	music.openFromFile("Celadon.wav");
	music.setLoop(true);



	//sound.play();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch(event.type)
			{

				case sf::Event::Closed:
				window.close();
				break;

				case sf::Event::KeyPressed:
				{
					switch(event.key.code)
					{
					case sf::Keyboard::Escape:
							window.close();
							break;
						
					}
				}
				default:
					break;
			}
		}

		window.clear(sf::Color::Black);

		if (event_draw_square)
		{
		square.setPosition(320, 240);
		window.draw(square);
			if (event_fill_square)
			{
				square.setFillColor(sf::Color::Red);
			}
		}

		if (event_play_celadon && !event_celadon_playing)
		{
			music.play();
			event_play_celadon = true;
			event_celadon_playing = true;
		}

		window.display();

	}
	
	
}


int main()
{
	thread draw_thread(DrawWindow);
	
	sf::Window text_window();
	
	Player player;//player object
	Narrator narrator;//narrator object


	player.SetName(narrator.prompt<string>("What is your name? \n", 50));//ask the player's name
	player.SetState(narrator.prompt<string>("Hello " + player.GetName() + ", how are you? \n", 50));//ask how they are feeling
	narrator.PrintText("You're feeling " + player.GetState() + ", huh? Well stop it--because you know what?  Your future is happening here and now. \n", 50);
	narrator.PrintText("...\n", 500);
	
	if (narrator.prompt<string>("Does that upset you? \n", 100).compare("yes") == 0)
	{
		narrator.PrintText("...\n", 500);
		narrator.PrintText("That's too bad. Sucks to be you, y'know? Here's a square: \n", 100);
		event_draw_square = true;
		narrator.PrintText("", 2000);
		narrator.PrintText("Feel any better?", 100);
		narrator.PrintText("\n", 5000);
		narrator.PrintText("... \n", 500);
		narrator.PrintText("It's the color, isn't it? ", 100);
		narrator.PrintText("Just give me a second", 100);
		narrator.PrintText("...\n", 500);
		event_fill_square = true;
		narrator.PrintText("; )\n", 100);
		narrator.prompt<string>("" , 50);


	}

	else {
		narrator.PrintText("...\n", 500);
		narrator.PrintText("Well shit. ", 100);
		narrator.PrintText("", 500);
		narrator.PrintText("I haven't actually been programmed to know what to do past this point so umm", 50);
		narrator.PrintText("...here's the Celedon City tune from Pokemon Red and Blue >.> \n", 50);
		event_play_celadon = true;
		narrator.PrintText("'Peace.\n", 100);
		narrator.prompt<string>("" , 50);
	}
	



	
	cin.get();

	 return 0;

}
   
