#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

char choice;
char data1 = 0x90;
char data2 = 0x00;

void menu();
void crack();

void menu()
{
	std::cout<<"\t __________                       __     ________  \n";
	std::cout<<"\t/___   ___/__ __ _______   ____  |  | __ \\_____  \\ \n";
	std::cout<<"\t   |  |   |  |  \\\\_  __ \\ /  _ \\ |  |/ /  /  ____/ \n";
	std::cout<<"\t   |  |   |  |  / |  | \\/(  <_> )|    <  /       \\ \n";
	std::cout<<"\t   |  |   |____/  |__|    \\____/ |__|_ \\ \\_______ \\\n";
	std::cout<<"\t   | /                                \\/         \\/\n";
	std::cout<<"\t   |/												\n";
	std::cout<<"    ___  ____  ____  _  _   __   __ _     ___  ____   __    ___  __ _ \n";
	std::cout<<"   / __)(  __)(  _ \\( \\/ ) / _\\ (  ( \\   / __)(  _ \\ / _\\  / __)(  / )\n";
	std::cout<<"  ( (_ \\ ) _)  )   // \\/ \\/    \\/    /  ( (__  )   //    \\( (__  )  ( \n";
	std::cout<<"   \\___/(____)(__\\_)\\_)(_/\\_/\\_/\\_)__)   \\___)(__\\_)\\_/\\_/ \\___)(__\\_)\n\n";
	std::cout<<"\t\t\tby NaRk0zA (C) 2022\n\n";
	std::cout<<"[1] CRACK!\n";
	std::cout<<"[q] Quit\n";
	std::cout<<"\nChoice: ";

	std::cin>>choice;

	switch(choice)
	{
		case '1': crack();
			break;
		case 'q': exit(0);
			break;
		default:
		{
			std::cout<<"Wrong choice!";
			getch();
		}

	}
}

void crack()
{
	std::ofstream t2ger;
	t2ger.open("Turok2.exe", std::ofstream::binary | std::ofstream::in);

	if ( t2ger.is_open() )
	{
		for(char i=0x04; i<=0x0F; i++)
		{
			t2ger.seekp(0xA0300+i, std::ios::beg);
			t2ger.write(( const char * ) & data1, sizeof(data1) );
		}

		for(char j=0x00; j<=0x0F; j++)
		{
			t2ger.seekp(0xA0310+j, std::ios::beg);
			t2ger.write(( const char * ) & data1, sizeof(data1) );
		}

		t2ger.seekp(0x124F50+0x08, std::ios::beg);
		t2ger.write(( const char * ) & data2, sizeof(data2) );
		
		t2ger.close();

		std::cout<<"Turok2 has been cracked successfully! Enjoy :)";
		getch();
	}
	else
	{
		std::cout<<"Cannot open Turok2.exe! Wrong file or file does not exist!";
		getch();
	}

}

int main()
{
	menu();
	return 0;
}