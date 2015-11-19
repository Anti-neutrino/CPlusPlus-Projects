#ifndef ALCOHOL
#define ALCOHOL

class AlcoholicDrink
{
	char name[32];
	double price;
	float abv;
public:
	AlcoholicDrink();
	AlcoholicDrink(char *name1, double value, float abv1);
	const char* getName()const;
	double getPrice()const;
	float getAbv()const;
	void setName(char*);
	void setPrice(double);
	void setAbv(float);
	double waterToLowerPercentage(double, double);
	void Print();
};

#endif