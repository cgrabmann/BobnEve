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
	static View* Instance();

	void Register(Player* bob, Player* eve, std::vector<Platform*>* platforms, std::vector<Enemy*>* enemies);
	void CleanUp();

	void Update(int16_t ms);
	void Draw(Renderer& renderer) const;

	const Vector2f GetCenterPoint() const;

protected:
	View();
	~View();

private:
	static View* instance_;

	Player* bob_;
	Player* eve_;

	std::vector<Platform*>* platforms_;

	std::vector<Enemy*>* enemys_;

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