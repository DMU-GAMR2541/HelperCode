#pragma once
class GameObject {
private:
	sf::Vector2f v2_position = sf::Vector2f(0.f,0.f); //SFML vector for position.
	float f_rotation = 0.f; //Rotation value.
	sf::Vector2f v2_scale = sf::Vector2f(0.f, 0.f);
	bool b_colliding = false; //Check for collision.

protected:
	sf::FloatRect fr_bounds;

public:
	GameObject() = default;//Default constructor.
	virtual ~GameObject() = default;//Default destructor.

	sf::Vector2f getPosition() {
		return v2_position;
	}

	float getRotation() {
		return f_rotation;
	}

	sf::Vector2f getScale() {
		return v2_scale;
	}

	void setPosition(sf::Vector2f v2_position) {
		this->v2_position = v2_position;
	}

	void setScale(sf::Vector2f v2_scale) {
		this->v2_scale = v2_scale;
	}

	void setRotation(float f_rotation) {
		this->f_rotation = f_rotation;
	}
	
	bool isColliding(sf::FloatRect fr_gameObject, sf::FloatRect fr_entity) {
		b_colliding = fr_gameObject.intersects(fr_entity);
		return b_colliding;
	};

};