#pragma once
class RoleStateMemento
{
public:
	RoleStateMemento(int vit, int atk, int def);
	void SetVitality(int vit);
	int GetVitality();
	void SetAttck(int atk);
	int GetAttck();
	void SetDefense(int def);
	int GetDefense();

private:
	int m_vit;
	int m_atk;
	int m_def;

};

