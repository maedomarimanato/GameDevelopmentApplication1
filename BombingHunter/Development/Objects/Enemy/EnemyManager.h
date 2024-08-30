#pragma once
#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "Enemy.h"
#include <vector>

class EnemyManager
{
public:
    EnemyManager();
    ~EnemyManager();

    void Initialize();
    void Update();
    void Draw() const;
    void Finalize();

private:
    std::vector<Enemy*> enemies;

    void CreateEnemy(); // “G‚ğ©“®¶¬‚·‚éƒƒ\ƒbƒh
};

#endif // ENEMY_MANAGER_H
