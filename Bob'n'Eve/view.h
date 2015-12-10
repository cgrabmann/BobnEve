#include <vector>
#include <cinttypes>
#include "GameObject.h"
#include "Player.h"

class Vector2f;
class Renderer;
class Platform;
class Player;
class Enemy;

class View
{
public:
	static View* Instance();

	void Register(Enemy* enemy);
	void Register(Player* player);
	void Register(GameObject* object);
	void CleanUp();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;
	void DeleteAllEnemiesToDelete();
	void DeleteEnemy(Enemy* enemy);
	void DeleteEnemyById(size_t id); 
	std::vector<const Vector2f> GetFocusPoints() const;

protected:
	View();
	~View();

private:
	static View* instance_;

	std::vector<Platform*> platforms_;
	std::vector<Enemy*> enemies_;
	std::vector<Enemy*> enemiesToDelete_;
	std::vector<Player*> players_;
	std::vector<GameObject*> objects_;

	//std::vector<Background*> backgrounds;

	class CGuard
	{
	public:
		~CGuard()
		{
			if (NULL != View::instance_)
			{
				delete View::instance_;
				View::instance_ = NULL;
			}
		}
	};
};