#include "Projectile.h"
Projectile::Projectile(sf::Vector2f position, float rotation, float speed)
{
	this->f_speed = speed;
	this->f_rotation = rotation;
}
Projectile::Projectile(sf::Vector2f position, float rotation, float speed, std::string str_imageLocation) {
	// Set bullet sprite properties (color, size)
	sprite_projectile.setTexture(*li.loadImage(str_imageLocation));
	this->f_speed = speed;
	this->f_rotation = rotation;
}

void Projectile::update(float deltaTime) {
	position.x += f_velocityX * deltaTime;
	position.y += f_velocityY * deltaTime;
	sprite_projectile.setPosition(position);
}

void Projectile::draw(sf::RenderTarget& target) const {
	target.draw(sprite_projectile);
}

//Set the angle of the projectile.

void Projectile::setRotation(float f_angle) {
	this->f_rotation = f_angle;
	// Calculate initial velocity based on rotation and speed
	f_radians = f_rotation * (3.14159f / 180.f);
	f_velocityX = cos(f_radians) * f_speed;
	f_velocityY = sin(f_radians) * f_speed;
}

void Projectile::setInitialPos(sf::Vector2f v2_pos) {

	// Set bullet position based on sprite's origin
	this->position = v2_pos;

}

sf::Vector2f Projectile::getPosition() {
	return position;
}

bool Projectile::isFired()
{
	return b_fired;
}

void Projectile::fire(bool b_fired)
{
	this->b_fired = b_fired;
}