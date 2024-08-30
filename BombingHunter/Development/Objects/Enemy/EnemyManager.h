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

    void CreateEnemy(); // 敵を自動生成するメソッド
};

#endif // ENEMY_MANAGER_H
