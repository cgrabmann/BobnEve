#include <vector>
#include <cinttypes>
#include "GameObject.h"
#include "Player.h"
#include "Score.h"
#include "Finish.h"

class Coin;
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
	void Register(Coin* coin);
	void Register(GameObject* object);
	void CleanUp();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;
	void Destroy(Enemy* enemy);
	void Destroy(Player* player);
	void Destroy(Finish* finish);
	void Destroy(Coin* coin);
	std::vector<const Vector2f> GetFocusPoints() const;

	int GetScore() const
	{
		return score_;
	}
	bool IsActive() const
	{
		return isActive_;
	}

protected:
	View();
	~View();

	void DestroyAllKilledEnemies();
	void DestroyAllCollectedCoins();

private:
	static View* instance_;

	std::vector<Enemy*> enemies_;
	std::vector<Player*> players_;
	std::vector<Coin*> coins_;
	std::vector<GameObject*> objects_;

	std::vector<Enemy*> enemiesToDelete_;
	std::vector<Coin*> coinsToDelete_;

	int score_;
	bool isActive_;

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