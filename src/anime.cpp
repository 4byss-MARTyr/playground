#include "anime.h"

void print_if(bitmask genres, bitmask mask, const string& text)
{
	if (genres & mask) std::cout << " - " << text << std::endl;
}

void print_genres(bitmask genres)
{
	print_if(genres, shounen, "shounen");
	print_if(genres, romantic, "romantic");
	print_if(genres, action, "action");
	print_if(genres, ecchi, "ecchi");
	print_if(genres, comedy, "comedy");
	print_if(genres, shoujo, "shoujo");
	print_if(genres, paranormal, "paranormal");
	print_if(genres, drama, "drama");
	print_if(genres, school, "school");
	print_if(genres, ISEKAI, "ISEKAI");
	print_if(genres, harem, "harem");
	print_if(genres, casual, "casual");
}

void print_season(time_season season)
{
	switch (season)
	{
	case time_season::winter:std::cout << "Winter" << std::endl; break;
	case time_season::spring:std::cout << "spring" << std::endl; break;
	case time_season::summer:std::cout << "summer" << std::endl; break;
	case time_season::fall:std::cout << "fall" << std::endl;     break;
	}
}

void print_status(anime_status status)
{
	switch (status)
	{
	case anime_status::ongoing:std::cout << "ongoing" << std::endl; break;
	case anime_status::release:std::cout << "release" << std::endl; break;
	case anime_status::frozen:std::cout << "frozen" << std::endl;   break;
	case anime_status::anounce:std::cout << "anounce" << std::endl; break;
	}
}

season::season(const string& new_name, time_season new_time, int new_episodes, anime_status new_status)
{
	name = new_name;
	time = new_time;
	episodes = new_episodes;
	status = new_status;
}

void season::print() const
{
	std::cout << " - Name: " << name
		<< "\n - Episodes: " << episodes << std::endl;
	std::cout << " - Season: ";
	print_season(time);
	std::cout << " - Status: ";
	print_status(status);
}

anime::anime(const string& new_name, bitmask new_genres, const string& new_author)
{
	name = new_name;
	genres = new_genres;
	author = new_author;
}

void anime::print() const
{
	std::cout << "Name: " << name
		<< "\nAuthor: " << author
		<< "\nStudio: " << studio << std::endl;
	print_genres(genres);
	for (int i = 0; i < seasons.size(); i++)
	{
		std::cout << "Season " << i + 1 << std::endl;
		seasons[i].print();
	}
}

void anime::add_season(const string& new_name, time_season new_time, int new_episodes, anime_status new_status)
{
	season season(new_name, new_time, new_episodes, new_status);
	seasons.push_back(season);
}