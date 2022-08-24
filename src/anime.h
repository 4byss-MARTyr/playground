#pragma once

#include <string>
#include <vector>
#include <iostream>

#define BIT(x) (1 << (x))

using std::string;
using bitmask = uint32_t;
enum genres
{
	shounen = BIT(0),
	romantic = BIT(1),
	action = BIT(2),
	ecchi = BIT(3),
	comedy = BIT(4),
	shoujo = BIT(5),
	paranormal = BIT(6),
	drama = BIT(7),
	school = BIT(8),
	ISEKAI = BIT(9),
	harem = BIT(10),
	casual = BIT(11),
};

void print_if(bitmask genres, bitmask mask, const string& text);

void print_genres(bitmask genres);

enum class time_season
{
	winter,
	spring,
	summer,
	autumn,
	fall = autumn,
};

void print_season(time_season season);

enum class anime_status
{
	ongoing,
	release,
	frozen,
	anounce,
};

void print_status(anime_status status);

struct season
{
	season() = default;
	season(const string& new_name, time_season new_time, int new_episodes, anime_status new_status);

	string name = "some shit";
	time_season time = time_season::fall;
	int episodes = 0;
	anime_status anime_status = anime_status::ongoing;

	void print() const;
};

struct anime
{
	anime() = default;
	anime(const string& new_name, bitmask new_genres, const string& new_author);

	string name = "some shit";
	bitmask genres = 0;
	string author = "Tsugumi Oba";

	string studio = "some studio";
	std::vector<season> seasons;

	void print() const;

	void add_season(const string& new_name, time_season new_time, int new_episodes, anime_status new_status);
};