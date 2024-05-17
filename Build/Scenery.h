#pragma once
class Scenery : public GameObject{
private:
	sf::Sprite sprite_scenery;
	LoadableImage li;
public:
	Scenery() = default;
	virtual ~Scenery() = default;

	Scenery(sf::Vector2f& v2_position, float& f_rotation, sf::Vector2f& v2_scale, std::string& str_imageLoc) {
		this->setPosition(v2_position);
		this->setRotation(f_rotation);
		this->setScale(v2_scale);
		this->sprite_scenery.setScale(v2_scale);
		this->sprite_scenery.setTexture(*li.loadImage(str_imageLoc));
	}

	//Get the sprite of the player.
	sf::Sprite getSprite() {
		return sprite_scenery;
	}

	//Set the position of the sprite.
	void setSpriteLoc(sf::Vector2f v2_pos) {
		sprite_scenery.setPosition(v2_pos);
	}
};
