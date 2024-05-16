#pragma once
#include "Initialise.h"
class Projectile : public GameObject {
private:
	bool b_fired = false;
	float f_angleRadian = 0;
	float f_projectSpeed = 0;
	float f_angle = 0;
	float f_speed = 0;
	sf::Vector2f v2_direction;
	sf::Vector2f v2_velocity;
	sf::Vector2f v2_position;
	sf::CircleShape cs_circle;
	sf::Sprite sprite_projectile;
	sf::Vector2f position;
	float f_velocityX = 0;
	float f_velocityY = 0;
	float f_rotation = 0;
	float f_radians = 0;
	LoadableImage li;

public:
	Projectile() = default;
	~Projectile() = default;
	Projectile(sf::Vector2f position, float rotation, float speed);
	Projectile(sf::Vector2f position, float rotation, float speed, std::string str_image);

	void update(float deltaTime);
	void draw(sf::RenderTarget& target) const;


	//Overload the constructor.

	//Set the angle of the projectile.
	void setRotation(float f_angle);

	sf::Vector2f getPosition();

	//Set the initial position
	void setInitialPos(sf::Vector2f v2_pos);

	//Check if the projectile is fired.
	bool isFired();

	//Fire the projectile.
	void fire(bool b_fired);

};