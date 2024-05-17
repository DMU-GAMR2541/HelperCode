#include "Initialise.h"
//Defining pi
#define M_PI 3.14159265358979323846

bool contained(sf::Vector2f v2A, const sf::RenderWindow& window) {
	if(v2A.x > window.getSize().x || v2A.x < 0 || v2A.y > window.getSize().y || v2A.y < 0){
		return false;
	}
	else {
		return true;
	}
}
	


int main()
{
	//Variables for the main game.
	bool b_invOpen = true;
	sf::RenderWindow window(sf::VideoMode(3400, 2400, 16), "Game Demo", sf::Style::Close); //Draw an SFML window.
	window.setKeyRepeatEnabled(false);
	float f_playerSpeed = 0.01f;
	float f_enemySpeed = 0.01f;
	float f_imageRot = 0.f;
	unsigned int i_enemyNum = 6;
	sf::Vector2u u2_windowSize = window.getSize();
	std::string str_playerImage = "../Assets/topdown/PNG/Hitman 1/hitman1_gun.png";
	std::string str_enemyImage = "../Assets/topdown/PNG/Zombie 1/zoimbie1_machine.png";
	std::string str_sceneryImage = "../Assets/topdown/PNG/Tiles/tile_02.png";
	sf::Vector2f v2_playerStart(10.f, 10.f);
	sf::Vector2f v2_enemyStart(100.f, 100.f);
	sf::Vector2f v2_tilePosition(50.f, 50.f);
	sf::Vector2f v2_imageScale(2.f, 2.f);

	//Gameobjects.
	std::unique_ptr<Player> player(new Player(v2_playerStart,f_imageRot,v2_imageScale, str_playerImage, f_playerSpeed, u2_windowSize));
	std::unique_ptr<Enemy> enemy (new Enemy(v2_enemyStart, f_imageRot, v2_imageScale, str_enemyImage, f_enemySpeed, u2_windowSize));
	std::unique_ptr<Scenery> sceneryTile(new Scenery(v2_tilePosition, f_imageRot, v2_imageScale, str_sceneryImage));
	Projectile proj(player->getPosition(), 0.f, 0.5f, "../Assets/topdown/PNG/Tiles/tile_132.png");

	sf::Vector2i vi_mousePos;
	sf::Vector2f v2_direction;
	float f_angle;

	//Setting the fps. This can dictate the movement / redraw speed.
	const float f_FPS = 60.0f; //The desired FPS. (The number of updates each second).
	bool b_redraw = true;      //Redraw everything on the screen.
	//Clock to get the time.
	sf::Clock clock;

	//Check if the window is open or closed.
	sf::Event event;

	while (window.isOpen())
	{
		//Wait until 1/60th of a second has passed, then update everything.
		if (clock.getElapsedTime().asSeconds() >= 1.0f / f_FPS)
		{
			b_redraw = true; //We're ready to redraw everything
			clock.restart();
		}

	//Check the keyboard for input.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (player->getPosition().y >= 0.1f) {
				player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y - f_playerSpeed));
				player->setSpriteLoc(player->getPosition());
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (player->getPosition().x >= 0.f) {
				player->setPosition(sf::Vector2f(player->getSprite().getPosition().x - f_playerSpeed, player->getSprite().getPosition().y));
				player->setSpriteLoc(player->getPosition());
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (player->getPosition().y < u2_windowSize.y) {
				player->setPosition(sf::Vector2f(player->getSprite().getPosition().x, player->getSprite().getPosition().y + f_playerSpeed));
				player->setSpriteLoc(player->getPosition());
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player->setPosition(sf::Vector2f(player->getSprite().getPosition().x + f_playerSpeed, player->getSprite().getPosition().y));
			player->setSpriteLoc(player->getPosition());
		}

		//std::cout << player->getPosition().x << " " << player->getPosition().y << std::endl;
		//Rotate the player
		vi_mousePos = sf::Mouse::getPosition(window);
		v2_direction = (sf::Vector2f)vi_mousePos - player->getSprite().getPosition();
		f_angle = std::atan2(v2_direction.y, v2_direction.x) * 180.f / M_PI;
		player->rotateSprite(f_angle);

		//Check the mouse for an input.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!contained(proj.getPosition(),window))
			{
				proj.fire(false);
			}

			if (!proj.isFired())
			{
				proj.setInitialPos(player->getPosition());
				proj.setRotation(f_angle);
			}
			proj.fire(true);
		}

		if (proj.isFired()) {
			proj.update(clock.getElapsedTime().asSeconds());
		}


		//Check the mouse for an input.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//Can add code here for UI.
		}

		//Poll an event on the SFML window. Only really need to know about closure. 
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		//Draw to the window.
		if (b_redraw)
		{
			b_redraw = false;
			window.clear();
			window.draw(sceneryTile->getSprite());
			if (!player->isColliding(player->getSprite().getGlobalBounds(), enemy->getSprite().getGlobalBounds())) {
				window.draw(enemy->getSprite());
			}
			window.draw(player->getSprite());
			if (proj.isFired()) {
				proj.draw(window);
			}
			window.display();
		}
	}
	return 0;
}
