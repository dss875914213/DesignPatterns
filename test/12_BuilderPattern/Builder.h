#pragma once

class PersonBuilder
{
public:
	virtual void BuildHead() = 0;
	virtual void BuildBody() = 0;
};

class PersonThinBuilder:public PersonBuilder
{
public:
	void BuildHead() override;
	void BuildBody() override;
};

class PersonFatBuilder :public PersonBuilder
{
public:
	void BuildHead() override;
	void BuildBody() override;
};

class PersonDirector
{
public:
	void CreatePerson(PersonBuilder* pb);
};


