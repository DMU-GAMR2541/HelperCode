#include "Player.h"

//Overload constructor
Player::Player(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale)
{
	this->setPosition(v2_position);
	this->setRotation(f_rotation);
	this->setScale(v2_scale);
	this->sprite_player.setTexture(*li.loadImage("../Assets/topdown/PNG/Hitman 1/hitman1_gun.png"));
	this->fr_bounds = sprite_player.getLocalBounds();
	this->sprite_player.setPosition(v2_position);
	this->sprite_player.setScale(v2_scale);
}
//Overload the constructor.
Player::Player(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale, std::string& str_imageLoc, float& f_speed, sf::Vector2u& u2_size) {
	this->setPosition(v2_position);
	this->setRotation(f_rotation);
	this->setScale(v2_scale);
	this->sprite_player.setTexture(*li.loadImage(str_imageLoc));
	this->fr_bounds = sprite_player.getLocalBounds();
	this->sprite_player.setPosition(v2_position);
	this->sprite_player.setScale(v2_scale);
	this->f_speed = f_speed;
	this->u2_size = u2_size;
}

//Get the sprite of the player.
sf::Sprite Player::getSprite() {
	return sprite_player;
}

//Set the position of the sprite.
void Player::setSpriteLoc(sf::Vector2f v2_pos) {
	sprite_player.setPosition(v2_pos);
}

//Set the movement speed of the player.
void Player::setSpeed(float f_speed) {
	this->f_speed = f_speed;
}

//Rotate sprite
void Player::rotateSprite(float f_rotation) {
	sprite_player.setRotation(f_rotation);
}