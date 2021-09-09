#include "Expression.h"

void Expression::Interpret(PlayContext* context)
{
	if (context->GetText().size() == 0)
	{
		return;
	}
	else
	{
		string playKey = context->GetText().substr(0,1);
		context->SetText(context->GetText().substr(2));
		int blankIndex = FindBlankPosition(context->GetText());
		double playValue = atof(context->GetText().substr(0, blankIndex).c_str());
		context->SetText(context->GetText().substr(blankIndex + 1));
		Excute(playKey, playValue);
	}
}

static int FindBlankPosition(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			return i;
		}
	}
	return str.size();
}


void Note::Excute(string key, double value)
{
	string note = "";
	if (key == "C")
	{
		note = "1";
	}
	else if (key == "D")
	{
		note = "2";
	}
	else if (key == "E")
	{
		note = "3";
	}
	else if (key == "F")
	{
		note = "4";
	}
	else if (key == "G")
	{
		note = "5";
	}
	else if (key == "A")
	{
		note = "6";
	}
	else if (key == "B")
	{
		note = "7";
	}
	cout << note << endl;
}

void Scale::Excute(string key, double value)
{
	string scale = "";
	switch (int(value))
	{
	case 1:
		scale = "µÍÒô";
		break;
	case 2:
		scale = "ÖÐÒô";
		break;
	case 3:
		scale = "¸ßÒô";
		break;
	}
	cout << scale << endl;
}
