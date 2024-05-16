#pragma once
#include "Initialise.h"
class Player : public GameObject {
private:
	sf::Sprite sprite_player;
	LoadableImage li;
	float f_speed = 0.f;
	sf::Vector2u u2_size;

public:
	Player() = default;
	virtual ~Player() = default;

	//Overload the constructor for testing.
	Player(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale);

	//Overload the constructor.
	Player(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale, std::string& str_imageLoc, float& f_speed, sf::Vector2u& u2_size);

	//Get the sprite of the player.
	sf::Sprite getSprite();

	//Set the position of the sprite.
	void setSpriteLoc(sf::Vector2f v2_pos);

	//Set the speed of the player.
	void setSpeed(float f_speed);

	//Set the rotation of the player.
	void rotateSprite(float f_rotation);

};
