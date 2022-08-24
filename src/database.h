#pragma once
#include "anime.h"
#include <vector>

struct database
{
	std::vector<anime> animes;

	void add_anime(anime _anime);
	void print_animes() const;
};

