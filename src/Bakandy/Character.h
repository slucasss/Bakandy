#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

#include "geometry.h"
#include "Projectile.h"

typedef __int32 int32_t;



class Character : public Geometry{


protected:

    int m_hp;
    int m_maxHp;

    int m_Attack;

    int m_speed;
    uint32_t last_shot_time;
    int COOLDOWN_MS;
  /*  int m_xp;*/
  

public:

    Character(int x, int y, int width, int height, int maxHp, int baseAtk, int sp);

    void takeDamage(int amount);

    int GetHP() const;

   
    virtual Projectile* attack() = 0;

    virtual void MoveC(float deltaTime) = 0;

    bool IsAlive() const;

    int GetMaxHP() const;

    virtual ~Character() = default;

    virtual void Draw(SDL_Renderer*) override = 0;

    bool IsColliding(Geometry* target);

    
    int GetSpeed() { return m_speed; }

};