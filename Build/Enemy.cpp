#include "Enemy.h"

Enemy::Enemy(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale, std::string& str_imageLoc, float& f_speed, sf::Vector2u& u2_size) {
	this->setPosition(v2_position);
	this->setRotation(f_rotation);
	this->setScale(v2_scale);
	this->sprite_enemy.setTexture(*li.loadImage(str_imageLoc));
	this->fr_bounds = sprite_enemy.getLocalBounds();
	this->sprite_enemy.setPosition(v2_position);
	this->sprite_enemy.setScale(v2_scale);
	this->f_speed = f_speed;
	this->u2_size = u2_size;
};

//Get the sprite of the Enemy.
sf::Sprite Enemy::getSprite() {
	return sprite_enemy;
};

//Set the position of the sprite.
void Enemy::setSpriteLoc(sf::Vector2f v2_pos) {
	sprite_enemy.setPosition(v2_pos);
};

//Set the movement speed of the Enemy.
void Enemy::setSpeed(float f_speed) {
	this->f_speed = f_speed;
};

//Override the setrotation function from the gameobject. 
void Enemy::setRotation(float f_rotation) {
	this->sprite_enemy.setRotation(f_rotation);
};

