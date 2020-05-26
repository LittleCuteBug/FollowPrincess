#include "../include/main.h"
#include "../include/CPlayer.h"

CPlayer::CPlayer(int _Life, int _Level)
{
	Setter(_Life, _Level);
}
void CPlayer::Setter(int _Life, int _Level) {
	Level = _Level;
	Life = _Life;
}
pii CPlayer::Getter()
{
	return pii(Life, Level);
}
void CPlayer::LifeDecrease()
{
	Life--;
}
void CPlayer::LifeRestore(int _Life)
{
	Life = _Life;
}
void CPlayer::LevelIncrease()
{
	Level++;
	LifeRestore();
}
bool CPlayer::isDead()
{
	return Life <= 0;
}
void CPlayer::Print()
{
	cout << "Life: " << Life << " Level: " << Level << endl;
}