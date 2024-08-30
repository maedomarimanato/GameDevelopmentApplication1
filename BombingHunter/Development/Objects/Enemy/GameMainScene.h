#pragma once
#include <vector>
#include "Enemy.h"
class GameMainScene
{
private:
    std::vector<Enemy*> enemies;

public:
    void Update()
    {
        for (auto it = enemies.begin(); it != enemies.end(); )
        {
            (*it)->Update();
            if (!(*it)->IsAlive())
            {
                delete* it;
                it = enemies.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void Draw() const
    {
        for (const auto& enemy : enemies)
        {
            enemy->Draw();
        }
    }

    void AddEnemy(Enemy* enemy)
    {
        enemies.push_back(enemy);
    }
};
