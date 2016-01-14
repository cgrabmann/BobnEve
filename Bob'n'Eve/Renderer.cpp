#include "Renderer.h"
#include "View.h"

#include <SFML\Graphics.hpp>
#include "Global.h"
#include "Vector2f.h"
#include "AssetManager.h"
#include <sstream>


Renderer::Renderer() : window_(
#ifdef _DEBUG
	sf::VideoMode::getDesktopMode(), "Bob'n'Eve"
#else
	sf::VideoMode::getFullscreenModes()[0], "Bob'n'Eve", sf::Style::Fullscreen
#endif
	), scale_(2.f, 2.f)
{
	sf::Vector2u size = window_.getSize();

	Global::ScreenWidth = size.x;
	Global::ScreenHeight = size.y;

	window_.setKeyRepeatEnabled(true);
	window_.setJoystickThreshold(15.f);
	window_.setFramerateLimit(60);
	window_.setMouseCursorVisible(false);
	window_.setVerticalSyncEnabled(true);

	sf::View view(sf::FloatRect(0, 0, size.x, size.y));
	window_.setView(view);
}


Renderer::~Renderer()
{
}

void Renderer::Render()
{
	View* view = View::Instance();

	if (menu_ == nullptr)
	{
		window_.setView(GetGameView());
	}
	else
	{
		window_.setView(GetMenuView());
	}

	//draws all objects
	window_.clear();
	view->Draw(*this);

	window_.setView(window_.getDefaultView());

	if (menu_ != nullptr)
	{
		menu_->Draw(*this);
	}
	else
	{
		sf::Font font = *AssetManager::Instance()->GetFont("arial.ttf");
		sf::Color green = sf::Color(0, 255, 33);
		std::stringstream streamBuilder;
		streamBuilder << view->GetScore() << " Points";
		sf::Text score = sf::Text(streamBuilder.str(), font, 48);
		score.setColor(green);
		score.setPosition(10, 10);
		window_.draw(score);
	}

	window_.display();
}

sf::View Renderer::GetGameView()
{
	View* view = View::Instance();
	sf::View sfView = window_.getView();

	//gets data of all important Objects
	std::vector<const Vector2f> focusPoints = view->GetFocusPoints();
	Vector2f size(sfView.getSize()), minPos(focusPoints.at(0)), maxPos(focusPoints.at(0));
	for (std::vector<const Vector2f>::const_iterator it = focusPoints.begin(); it != focusPoints.end(); ++it)
	{
		if ((*it).x < minPos.x)
			minPos.x = (*it).x;
		else if ((*it).x > minPos.x)
			maxPos.x = (*it).x;

		if ((*it).y < minPos.y)
			minPos.y = (*it).y;
		else if ((*it).y > minPos.y)
			maxPos.y = (*it).y;
	}

	//checks if one of the players leave the screen and scales the picture

	// "Frame" for detection
	size -= (Vector2f(400, 200) * scale_);
	Vector2f distance(maxPos - minPos);
	scale_ = (size / distance);
	//get the bigger zoom-out
	scale_.x = std::min(scale_.x, scale_.y);
	//we don't want to zoom-in
	scale_.x = std::min(1.0f, scale_.x);
	//we want to uniform-scale
	scale_.y = scale_.x;

	//sets the focus in the middle of the players
	Vector2f centerPos(minPos + maxPos);
	centerPos /= 2;
	centerPos *= scale_;
	sfView.setCenter(centerPos.ToSFML());
	return sfView;
}

sf::View Renderer::GetMenuView()
{
	sf::View sfView = window_.getView();
	Vector2f map(Global::TileWidth * Global::MapWidth, Global::TileHeight * Global::MapHeight);
	Vector2f size(sfView.getSize());

	scale_ = (size / map);

	//get the bigger zoom-out
	scale_.x = std::min(scale_.x, scale_.y);
	//we don't want to zoom-in
	scale_.x = std::min(1.0f, scale_.x);
	//we want to uniform-scale
	scale_.y = scale_.x;
	
	Vector2f centerPos(map);
	centerPos /= 2;
	centerPos *= scale_;

	sfView.setCenter(centerPos.ToSFML());
	return sfView;
}

void Renderer::Draw(sf::Shape& shape)
{
	window_.draw(shape);
}

