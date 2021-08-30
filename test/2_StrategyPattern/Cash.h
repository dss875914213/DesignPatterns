#pragma once
class CashSuper
{
public:
	virtual double acceptCash(double money) = 0;
};

class CashNormal :public CashSuper
{
public:
	double acceptCash(double money) override;
};

class CashRebate :public CashSuper
{
public:
	CashRebate(double moneyDebate);
	double acceptCash(double money) override;

private:
	double m_moneyDebate = 1.0;
};

class CashReturn : public CashSuper
{
public:
	CashReturn(double moneyCondition, double moneyReturn);
	double acceptCash(double money) override;
private:
	double m_moneyCondition = 0.0;
	double m_moneyReturn = 0.0;
};
