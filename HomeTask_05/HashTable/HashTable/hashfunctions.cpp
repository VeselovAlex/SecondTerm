#include "hashfunctions.h"

int polynomeHash (QString string, int first, int last, int mod)
{
    long int hash = 0;
	int multi = 1;
	const int changes = 2;
	for (int i = first; i < last; i++)
	{
        multi *= changes;
	}
	for (int i = first; i <= last; i++)
	{
        hash = ((hash + (int)(string[i].cell()) * multi));
		multi = multi / changes;
	}
	hash = hash % mod;
	return hash;
}

int polynomeHash (QString string, int mod)
{
    return polynomeHash (string, 0, string.length() - 1, mod);
}

int hashSums(QString string, int first, int last, int mod)
{
	long int sum = 0;
	for (int i = first; i <= last; i++)
    {
        char symbol = string[i].cell();
        sum = sum + symbol;
    }
	int res = sum % mod;
	return res;
}

int hashSums (QString string, int mod)
{
    return hashSums (string, 0, string.length() - 1, mod);
}
