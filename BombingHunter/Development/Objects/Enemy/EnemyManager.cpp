#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
    Finalize();
}

void EnemyManager::Initialize(int count)
{
    for (int i = 0; i < count; ++i)
    {
        // ƒ‰ƒ“ƒ_ƒ€‚ÈˆÊ’u‚É“G‚ğ¶¬‚·‚é
        Vector2D initial_location(rand() % 640, rand() % 480);
        Enemy* enemy = new Enemy(initial_location);
        enemy->Initialize();
        enemies.push_back(enemy);
    }
}

void EnemyManager::Update()
{
    for (Enemy* enemy : enemies)
    {
        enemy->Update();
    }
}

void EnemyManager::Draw() const
{
    for (const Enemy* enemy : enemies)
    {
        enemy->Draw();
    }
}

void EnemyManager::Finalize()
{
    for (Enemy* enemy : enemies)
    {
        enemy->Finalize();
        delete enemy;
    }
    enemies.clear();
}
