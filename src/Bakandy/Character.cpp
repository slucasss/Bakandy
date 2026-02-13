#include <iostream>
#include "Character.h"

Character::Character(int x, int y, int width, int height, int maxHp, int baseAtk, int sp)
 : Geometry(width, height), m_hp(maxHp), m_maxHp(maxHp), m_Attack(baseAtk), m_speed(sp){ 
    SetPosition(x, y, 0.5, 0.5);
}
 
void Character::takeDamage(int amount) {
    m_hp -= amount;

    if (m_hp < 0) {
        m_hp = 0;
    }

}

bool Character::IsAlive() const {
    return m_hp > 0;
}

int Character::GetHP() const {
    return m_hp;
}

int Character::GetMaxHP() const {
    return m_maxHp;

}

bool Character::IsColliding(Geometry* target)
{
    Vector2f center1 = GetPosition(0.5f, 0.5f);
    Vector2f center2 = target->GetPosition(0.5f, 0.5f);

    float distance = Math::GetDistance(center1.x, center1.y, center2.x, center2.y);
    float radiusDist = m_height/2 + target->GetHeight()/2;

    return distance <= radiusDist;
}


