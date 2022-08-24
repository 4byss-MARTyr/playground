#include "database.h"
#include <iostream>
void database::add_anime(anime _anime)
{
	animes.push_back(_anime);
}

void database::print_animes() const
{
	for (int i = 0; i < animes.size(); i++)
	{
		std::cout << "#############################################################" << std::endl;
		animes[i].print();
	}
}