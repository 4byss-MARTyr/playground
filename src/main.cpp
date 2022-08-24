#include "anime.h"

int main()
{
	anime Naruto("Naruto", shounen | comedy | drama | action, "Masashi Kishimoto");
	Naruto.studio = "Pierrot";
	
	Naruto.add_season("Naruto", time_season::fall, 220, anime_status::release);
	Naruto.add_season("Naruto Shippuden", time_season::winter, 500, anime_status::release);

	Naruto.print();

	return 0;
}