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

enum class time_season
{
	winter,
	spring, 
	summer,
	autumn,
	fall = autumn,
};

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

enum class status
{
	ongoing,
	release,
	frozen,
	anounce,
};

void print_status(status status)
{
	switch (status)
	{
	case status::ongoing:std::cout << "ongoing" << std::endl; break;
	case status::release:std::cout << "release" << std::endl; break;
	case status::frozen:std::cout << "frozen" << std::endl;   break;
	case status::anounce:std::cout << "anounce" << std::endl; break;
	}
}

struct season
{
	season() = default;
	season(const string& new_name, time_season new_time, int new_episodes, status new_status)
	{
		name = new_name;
		time = new_time;
		episodes = new_episodes;
		status = new_status;
	}
	
	string name = "some shit";
	time_season time = time_season::fall;
	int episodes = 0;
	status status = status::ongoing;

	void print() const
	{
		std::cout << " - Name: " << name
		<< "\n - Episodes: " << episodes << std::endl;
		std::cout << " - Season: ";
		print_season(time);
		std::cout << " - Status: ";
		print_status(status);
	}
};

struct anime
{
	anime() = default;
	anime(const string& new_name, bitmask new_genres, const string& new_author)
	{
		name = new_name;
		genres = new_genres;
		author = new_author;
	}
	
	string name = "some shit";
	bitmask genres = 0;
	string author = "Tsugumi Oba";
	
	string studio = "some studio";
	std::vector<season> seasons;

	void print() const
	{
		std::cout << "Name: " << name
		          << "\nAuthor: " << author 
		          << "\nStudio: " << studio << std::endl;
		print_genres(genres);
		for (int i = 0; i < seasons.size(); i++)
		{
			std::cout << "Season " << i+1 << std::endl;
			seasons[i].print();
		}
	}

	void add_season(const string& new_name, time_season new_time, int new_episodes, status new_status)
	{
		season season(new_name, new_time, new_episodes, new_status);
		seasons.push_back(season);
	}
};


int main()
{
	anime Naruto("Naruto", shounen | comedy | drama | action, "Masashi Kishimoto");
	Naruto.studio = "Pierrot";
	
	Naruto.add_season("Naruto", time_season::fall, 220, status::release);
	Naruto.add_season("Naruto Shippuden", time_season::winter, 500, status::release);

	Naruto.print();

	return 0;
}