#pragma once
#include <iostream>
using namespace std;
class Knight
{
	unsigned attack, defence, health, max_health, experiance;
public:
	Knight();
	Knight(const Knight&);
	Knight(unsigned, unsigned, unsigned, unsigned, unsigned);
	void operator = (const Knight&);
	unsigned get_experiance();
	void print_stats();
	void buff() { attack *= 3; }
	void attack_enemy(Knight&);
};

Knight::Knight() : attack(10), defence(10), health(100), max_health(100), experiance(0) {}
Knight::Knight(const Knight& other)
{
	attack = other.attack;
	defence = other.defence;
	health = other.health;
	max_health = other.max_health;
	experiance = other.experiance;
}
void Knight::operator=(const Knight& other)
{
	attack = other.attack;
	defence = other.defence;
	health = other.health;
	max_health = other.max_health;
	experiance = other.experiance;
}
unsigned Knight::get_experiance()
{
	return experiance;
}
void Knight::print_stats()
{
	cout << attack << ' ' << defence << ' ' << health << ' ' << max_health << ' ' << experiance << endl;
}
void Knight::attack_enemy(Knight& enemy)
{
	if (attack - enemy.defence > 0)
	{
		enemy.health -= attack - enemy.defence;
		experiance++;
		if (experiance == 20)
		{
			attack += 40;
			defence += 20;
			max_health += 20;
			experiance = 0;
		}
	}
}
Knight::Knight(unsigned _attack, unsigned _defence, unsigned _health, unsigned _max_health, unsigned _experiance) :
	attack(_attack), defence(_defence), health(_health), max_health(_max_health), experiance(_experiance) {}