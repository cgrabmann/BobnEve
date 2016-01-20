#include "MenuBase.h"
#include "Renderer.h"
#include "MainMenu.h"
#include "Global.h"

const Vector2f MenuBase::DefaultSize = Vector2f(1920, 1080);

MenuBase::MenuBase(): isActive_(true)
{
}

void MenuBase::Update(int16_t ms)
{
}

void MenuBase::Draw(Renderer& renderer) const
{
	//for (int i = 0; i < elements_.size(); i++)
	//{
	//	renderer.GetTarget().draw(*elements_.at(i));
	//}

	for (std::vector<sf::Drawable*>::const_iterator it = elements_.begin(); it != elements_.end(); ++it)
	{
		renderer.GetTarget().draw(**it);
	}
}

void MenuBase::CenterSprite(sf::Sprite* sprite, int top) const
{
	sprite->setOrigin(sprite->getLocalBounds().width / 2, 0);
	sprite->setPosition(Global::ScreenWidth / 2, top);
}

void MenuBase::CenterText(sf::Text* text, int top) const
{
	text->setOrigin(text->getLocalBounds().width / 2, 0);
	text->setPosition(Global::ScreenWidth / 2, top);
}

void MenuBase::RTLText(sf::Text* text, int left, int top) const
{
	text->setOrigin(text->getLocalBounds().width, 0);
	text->setPosition(left, top);
}
