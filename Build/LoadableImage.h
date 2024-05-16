#pragma once
class LoadableImage {
private:
	std::shared_ptr<sf::Texture> txt_load;
	sf::Texture tex;
public:
	LoadableImage() = default;
	~LoadableImage() = default;

	//Return a shared pointer to a game object.
	std::shared_ptr<sf::Texture> loadImage(const std::string& str_imageLocation) {
		if (!tex.loadFromFile(str_imageLocation)) {
			std::cout << "Error loading the image!" << std::endl;
		}
		txt_load = std::make_shared<sf::Texture>(tex);
		return txt_load;
	}

	void loadImageText(const std::string& str_imageLocation) {
		if (!tex.loadFromFile(str_imageLocation)) {
			std::cout << "Error loading the image!" << std::endl;
		}
		txt_load = std::make_shared<sf::Texture>(tex);
	}

	std::shared_ptr<sf::Texture> textureCreated() {
		return txt_load;
	}

};