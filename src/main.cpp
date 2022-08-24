#include "anime.h"
#include "database.h"

int main()
{
	database database;
	
	anime Naruto("Naruto", shounen | comedy | drama | action, "Masashi Kishimoto", "Pierrot");
	Naruto.add_season("Naruto", time_season::fall, 220, anime_status::release);
	Naruto.add_season("Naruto Shippuden", time_season::winter, 500, anime_status::release);

	anime Bleach("Bleach", shounen | comedy | drama | action, "Tite Kubo", "Pierrot");
	Bleach.add_season("Bleach", time_season::fall, 366, anime_status::release);
	Bleach.add_season("Bleach: Sennen Kessen-hen", time_season::fall, 0, anime_status::anounce);

	anime Mushoku_Tensei("Mushoku Tensei", ISEKAI | shounen | comedy | drama | action | harem | school | ecchi | romantic, 
		"Rifujin na Magonote", "Studio Bind");
	Mushoku_Tensei.add_season("Mushoku Tensei: Isekai Ittara Honki Dasu", time_season::winter, 24, anime_status::release);
	Mushoku_Tensei.add_season("Mushoku Tensei: Isekai Ittara Honki Dasu 2nd Season", time_season::fall, 0, anime_status::anounce);
	database.add_anime(Naruto);
	database.add_anime(Bleach);
	database.add_anime(Mushoku_Tensei);
	database.print_animes();

	return 0;
}