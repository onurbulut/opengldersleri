#include "SDL.h" //-->SDLnin ana header�n� include ettik

//�imdi OpenGL headerler�m�z� include edelim
#include <windows.h>//<----Windows kullanan arkada�lar i�in gereklidir.Yoksa hata al�rs�n�z
#include <gl/gl.h>
#include <gl/glu.h>



//�imdi yapaza��m�z kod ***SDL i�in*** gereklidir.
//Bu kod main voidimizi aktif edecektir.
//Aksi halde derleyicimiz bize giri� noktas� isteyecektir.
#undef main


//-----------ANA(main) voidimizi yazal�m.-------------
int main()
{

	GLsizei pencereGenisligi = 1024;//<---pencere geni�li�imizi girdik
	GLsizei pencereYuksekligi = 768;//<---pencere y�ksekli�ini girdik
	//!!!!!!!!BURADA �NEML� B�R NOKTA VAR!!!!!!!!
	//pencereGenisligi ni veya pencereYuksekligi ni int olarak girebilirdik.
	//ama multi-platform olmas� i�in bu gerekli.
	//Detaya girmeyece�im.Ama siz int de yazabilirsiniz


	SDL_Init(SDL_INIT_VIDEO);//SDLyi haz�rl�yoruz
	
	SDL_SetVideoMode(pencereGenisligi,pencereYuksekligi,0,SDL_OPENGL);//sdlyi ayarlad�k

	bool calisiyor = true;//d�ng�m�z�n �al���p �almad���n� kontrol etmek i�in gereklidir.


	while (calisiyor)//<--oyun d�ng�m�ze giri� yap�yoruz
	{

		SDL_Event olaylar;//<---SDL_Event olaylar�m�z i�in gereklidir.
		//Mesela bir ��k�� olay� nas�l olmal�,veya bir tu�a basma olay�,
		//bir pencereyi yeniden boyutland�r�rsak neler olacak diye gerekli 
		while( SDL_PollEvent(&olaylar) )//Olaylar� "olaylar"�m�za y�kl�yoruz
		{

			if(olaylar.type == SDL_QUIT)//SDLden ��k��ta d�g�m�zden ��kmas�n� istiyoruz.
				calisiyor = false;
		}

	}


	SDL_Quit();//<--sdlden ��karken bunu yazmal�y�z

	return 0;//<--he�ey bitti,kapat�yoruz...

}



