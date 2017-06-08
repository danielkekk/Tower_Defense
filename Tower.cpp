#include "Tower.h"


Tower::Tower(std::string type, int range, int damage, int rateOfFire, int x, int y){
	Type = type;
	Range=range;
	Damage=damage;
	RateOfFire = rateOfFire;
	X=x;
	Y=y;
}

int Tower::getRateOfFire() const{
	return RateOfFire;
}
std::string Tower::getType() const {
	return Type;
}
int Tower::getRange() const{
	return Range;
}
int Tower::getDamage() const{
	return Damage;
}

void Tower::kirajzol(int TOWER_UNIT) const{
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(X,Y);
		glVertex2i(X + TOWER_UNIT, Y);
		glVertex2i(X + TOWER_UNIT, Y + TOWER_UNIT);
		glVertex2i(X, Y + TOWER_UNIT);
	glEnd();
}

int Tower::getX() const{
	return X;
}

int Tower::loves(Enemy** e, int nulla){
	if (X - Range < (*e)->GetX() && (*e)->GetX() < X + Range && (*e)->getHealth()>0){
		if (nulla % RateOfFire == 0){		//nem a legjobb megold�s, mert itt az i v�ltoz�t adjuk �t a mainb�l amit csak az�rt hagytunk ott hogy minden lefut�sn�l n�velj�k �s itt minden 3. bel�p�sn�l (n�vel�sn�l) l�
			(*e)->HpLower(getDamage());
		}
		return 1;
	}
}