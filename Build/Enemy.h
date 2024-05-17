#pragma once
#include "Initialise.h"
class Enemy : public GameObject{
private:
	sf::Sprite sprite_enemy;
	LoadableImage li;
	float f_speed = 0.f;
	sf::Vector2u u2_size;
public:
	Enemy() = default;
	virtual ~Enemy() = default;


	////Overload the constructor.
	Enemy(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale, std::string& str_imageLoc, float& f_speed, sf::Vector2u& u2_size);

	//Get the sprite of the Enemy.
	sf::Sprite getSprite();

	//Set the position of the sprite.
	void setSpriteLoc(sf::Vector2f v2_pos);

	//Set the movement speed of the Enemy.
	void setSpeed(float f_speed);

	//Override the setrotation function from the gameobject. 
	void setRotation(float f_rotation);
};