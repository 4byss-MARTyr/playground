#include <string>
#include <vector>

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
	isekai = BIT(9),
	harem = BIT(10),
	casual = BIT(11),
};

enum class time_season
{
	winter,
	spring, 
	summer,
	autumn,
	fall = autumn,
};

enum class status
{
	ongoing,
	release,
	frozen,
	anounce,
};

struct season
{
	string name = "some shit";
	time_season time = time_season::fall;
	int episodes = 0;
	status status = status::ongoing;
};

struct anime
{
	string name = "some shit";
	bitmask genres = 0;
	string author = "Tsugumi Oba";
	
	int episodes = 0;
	string studio = "some studio";
	std::vector<season> seasons;
};


int main()
{
	unsigned int genre = action | comedy;
	return 0;
}