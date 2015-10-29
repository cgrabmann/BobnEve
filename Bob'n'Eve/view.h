#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include <vector>
#include "AssetManager.h"

class View
{
public:
	View();
	~View();

	void Update(int16_t ms);

	void Draw(Renderer& renderer) const;

private:
	Player* player1_;
	Player* player2_;

	std::vector<Platform*> platforms_;

	std::vector<Enemy*> enemys_;

	//std::vector<Background*> backgrounds;

	AssetManager assets_;
};