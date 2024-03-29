#include <vector>
#include <cinttypes>

class Vector2f;
class Renderer;
class Platform;
class Player;
class Enemy;

class View
{
public:
	View(Player* bob, Player* eve, std::vector<Platform*>* platforms, std::vector<Enemy*>* enemies);
	~View();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;

	const Vector2f GetCenterPoint();

private:
	Player* bob_;
	Player* eve_;

	std::vector<Platform*>* platforms_;

	std::vector<Enemy*>* enemys_;

	//std::vector<Background*> backgrounds;
};