#include <vector>
#include <cinttypes>
#include "GameObject.h"
#include "Player.h"
#include "Score.h"
#include "Finish.h"
#include <SFML/include/SFML/System/Time.hpp>

class Coin;
class Vector2f;
class Renderer;
class Platform;
class Player;
class Enemy;

class Map
{
public:
	enum MapState
	{
		Active, Victory, GameOver
	};

	static Map* Instance();

	void Register(Enemy* enemy);
	void Register(Player* player);
	void Register(Coin* coin);
	void Register(GameObject* object);
	void Register(Finish* finish);
	void CleanUp();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;
	void Destroy(Enemy* enemy);
	void Destroy(Player* player);
	void Destroy(Finish* finish);
	void Destroy(Coin* coin);
	std::vector<const Vector2f> GetFocusPoints() const;

	sf::Time GetTime() const
	{
		return time_;
	}
	MapState GetStatus() const
	{
		return status_;
	}

protected:
	Map();
	~Map();

	void DestroyAllKilledEnemies();
	void DestroyAllCollectedCoins();

private:
	static Map* instance_;

	std::vector<Enemy*> enemies_;
	std::vector<Player*> players_;
	std::vector<Coin*> coins_;
	std::vector<GameObject*> objects_;
	Finish* finish_;

	std::vector<Enemy*> enemiesToDelete_;
	std::vector<Coin*> coinsToDelete_;

	sf::Time time_;
	MapState status_;

	//std::vector<Background*> backgrounds;

	class CGuard
	{
	public:
		~CGuard()
		{
			if (NULL != Map::instance_)
			{
				delete Map::instance_;
				Map::instance_ = NULL;
			}
		}
	};
};