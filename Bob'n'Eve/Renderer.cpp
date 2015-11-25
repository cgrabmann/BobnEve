#include "Renderer.h"
#include "View.h"

#include <SFML\Graphics.hpp>
#include "Global.h"
#include "Vector2f.h"


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

sf::RenderWindow& Renderer::GetWindow()
{
	return window_;
}

sf::RenderTarget& Renderer::GetTarget()
{
	return window_;
}

void Renderer::Render()
{
	View* view = View::Instance();

	sf::View sfView = window_.getView();

	std::vector<const Vector2f> focusPoints = view->GetFocusPoints();
	Vector2f centerPoint, size(sfView.getSize()), minPos(focusPoints.at(0)), maxPos(focusPoints.at(0));
	for (std::vector<const Vector2f>::const_iterator it = focusPoints.begin(); it != focusPoints.end(); ++it)
	{
		centerPoint += (*it);

		if ((*it).x < minPos.x)
			minPos.x = (*it).x;
		else if ((*it).x > minPos.x)
			maxPos.x = (*it).x;

		if ((*it).y < minPos.y)
			minPos.y = (*it).y;
		else if ((*it).y > minPos.y)
			maxPos.y = (*it).y;
	}

	size -= Vector2f(300, 200);
	Vector2f distance(maxPos - minPos);
	scale_ = (size / distance);
	scale_.x = std::min(scale_.x, scale_.y);
	scale_.x = std::min(1.0f, scale_.x);
	scale_.y = scale_.x;

	centerPoint /= focusPoints.size();
	centerPoint *= scale_;
	sfView.setCenter(centerPoint.ToSFML());

	window_.setView(sfView);
	
	window_.clear();
	view->Draw(*this);
	window_.display();
}

void Renderer::Draw(sf::Shape& shape)
{
	window_.draw(shape);
}

Vector2f Renderer::GetScale() const
{
	return scale_;
}

