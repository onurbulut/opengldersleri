#include "SDL.h" //-->SDLnin ana headerýný include ettik

//Þimdi OpenGL headerlerýmýzý include edelim
#include <windows.h>//<----Windows kullanan arkadaþlar için gereklidir.Yoksa hata alýrsýnýz
#include <gl/gl.h>
#include <gl/glu.h>



//Þimdi yapazaðýmýz kod ***SDL için*** gereklidir.
//Bu kod main voidimizi aktif edecektir.
//Aksi halde derleyicimiz bize giriþ noktasý isteyecektir.
#undef main


//-----------ANA(main) voidimizi yazalým.-------------
int main()
{

	GLsizei pencereGenisligi = 1024;//<---pencere geniþliðimizi girdik
	GLsizei pencereYuksekligi = 768;//<---pencere yüksekliðini girdik
	//!!!!!!!!BURADA ÖNEMLÝ BÝR NOKTA VAR!!!!!!!!
	//pencereGenisligi ni veya pencereYuksekligi ni int olarak girebilirdik.
	//ama multi-platform olmasý için bu gerekli.
	//Detaya girmeyeceðim.Ama siz int de yazabilirsiniz


	SDL_Init(SDL_INIT_VIDEO);//SDLyi hazýrlýyoruz
	
	SDL_SetVideoMode(pencereGenisligi,pencereYuksekligi,0,SDL_OPENGL);//sdlyi ayarladýk

	bool calisiyor = true;//döngümüzün çalýþýp çalmadýðýný kontrol etmek için gereklidir.


	while (calisiyor)//<--oyun döngümüze giriþ yapýyoruz
	{

		SDL_Event olaylar;//<---SDL_Event olaylarýmýz için gereklidir.
		//Mesela bir çýkýþ olayý nasýl olmalý,veya bir tuþa basma olayý,
		//bir pencereyi yeniden boyutlandýrýrsak neler olacak diye gerekli 
		while( SDL_PollEvent(&olaylar) )//Olaylarý "olaylar"ýmýza yüklüyoruz
		{

			if(olaylar.type == SDL_QUIT)//SDLden çýkýþta dögümüzden çýkmasýný istiyoruz.
				calisiyor = false;
		}

	}


	SDL_Quit();//<--sdlden çýkarken bunu yazmalýyýz

	return 0;//<--heþey bitti,kapatýyoruz...

}



