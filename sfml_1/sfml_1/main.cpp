#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int window_length = 800, window_hight =600;

const double ball_radius = 40;

const float ball_speed_x = 500, ball_speed_y = 500;

const float racket_a = 20, racket_b = 150;
const float racket_speed_x = 500, racket_speed_y =500;
const float player_xzone = window_length/12;   /* расстояние  по х от грани окна, где каждый из игроков может перемещать свою ракетку по Х */



void start_menu(sf::RenderWindow &window) {
	/*--------------------------------------------Buttons--------------------------------------------------------*/
	sf::Image image_play1;

	if (!image_play1.loadFromFile("play2.jpg")) {
		std::cout << "Imagee_play loading error! " << std::endl;
	}
	else std::cout << "Image_play1 is loaded! " << std::endl;

	image_play1.createMaskFromColor(sf::Color::White);
	

	sf::Texture texture_play1, texture_play2, texture_exit, texture_settings, texture_back;

	if (!texture_play1.loadFromImage(image_play1)) {
	std::cout << "Texture_play1 loading error! " << std::endl;
	}
	else std::cout << "Texture_play is loaded from image! " << std::endl;


	/*if (!texture_play1.loadFromFile("play2.jpg")) {
		std::cout << "Texture_play1 loading error! " << std::endl;
	}
	else std::cout << "Texture_play is loaded! " << std::endl;
	*/


	if (!texture_play2.loadFromFile("play2.jpg")) {
		std::cout << "Texture_play loading error! " << std::endl;
	}
	else std::cout << "Texture_play2 is loaded! " << std::endl;

	if (!texture_exit.loadFromFile("exit.jpg")) {
		std::cout << "Texture_exit loading error! " << std::endl;
	}
	else std::cout << "Texture_exit is loaded! " << std::endl;

	if (!texture_settings.loadFromFile("settings.jpg")) {
		std::cout << "Texture_settings loading error! " << std::endl;
	}
	else std::cout << "Texture_settings is loaded! " << std::endl;

	if (!texture_back.loadFromFile("back.jpg")) {
		std::cout << "Texture_settings loading error! " << std::endl;
	}
	else std::cout << "Texture_back is loaded! " << std::endl;

	sf::Sprite sprite_play1, sprite_play2, sprite_exit, sprite_settings, sprite_back;

	sprite_play1.setTexture(texture_play1);                                 /* menu_namber=1 */
	sprite_play1.setPosition(sf::Vector2f(50, 11));
	sprite_play1.scale(0.0711116f, 0.071111f);

	sprite_play2.setTexture(texture_play1);                                  /* menu_namber=2 */
	sprite_play2.setPosition(sf::Vector2f(50, 161));
	sprite_play2.scale(0.071111f, 0.071111f);

	sprite_settings.setTexture(texture_settings);                             /* menu_namber=3 */
	sprite_settings.setPosition(sf::Vector2f(50, 311));
	sprite_settings.scale(0.0625f, 0.0625f);

	sprite_exit.setTexture(texture_exit);                                    /* menu_namber=4*/
	sprite_exit.setPosition(sf::Vector2f(50, 461));
	sprite_exit.scale(0.0625f, 0.0625f);
	

	sprite_back.setTexture(texture_back);                                    
	sprite_back.setPosition(sf::Vector2f(0, 0));
	sprite_back.scale(0.78125f, 0.88105f);

	/*----------------------------------------Text-----------------------------------------------------*/
	sf::Font font;
	if (font.loadFromFile("ARIALUNI.TTF")) {
		cout << " Font is loaded! " << endl;
	}
	else cout << " Error! Font is not loaded! " << endl;

	sf::Text text_single_player;
	text_single_player.setFont(font);
	text_single_player.setFillColor(sf::Color(69, 139, 116));
	text_single_player.setCharacterSize(40);
	text_single_player.setString("Single player");
	text_single_player.setStyle(sf::Text::Bold);
	text_single_player.setPosition(150, 11);


	sf::Text text_multy_player;
	text_multy_player.setFont(font);
	text_multy_player.setFillColor(sf::Color(69, 139, 116));
	text_multy_player.setCharacterSize(40);
	text_multy_player.setString("Multyplayer");
	text_multy_player.setStyle(sf::Text::Bold);
	text_multy_player.setPosition(150, 161);

	sf::Text text_settings;
	text_settings.setFont(font);
	text_settings.setFillColor(sf::Color(69, 139, 116));
	text_settings.setCharacterSize(40);
	text_settings.setString("Settings");
	text_settings.setStyle(sf::Text::Bold);
	text_settings.setPosition(150, 311);

	sf::Text text_exit;
	text_exit.setFont(font);
	text_exit.setFillColor(sf::Color(69, 139, 116));
	text_exit.setCharacterSize(40);
	text_exit.setString("Exit");
	text_exit.setStyle(sf::Text::Bold);
	text_exit.setPosition(150, 461);




	/*---------------------------------------Main loop--------------------------------------------------*/

	bool is_Start_Menu = true;
	/*sf::RenderWindow start_menu(sf::VideoMode(window_length, window_hight), "Start_Menu");*/
	int menu_number = 0;

	while (is_Start_Menu)
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { is_Start_Menu = false; }*/

		
		/* Проверяем куда попадаем мышкой. Проверяется попадаем ли мы мышкой в область картинки соответствующей кнопки */
		/* Тут же снимаем выделение с кнопок после увода мышки */

		if (sf::IntRect(50, 11, 128, 128).contains(sf::Mouse::getPosition(window))) {
			text_single_player.setFillColor(sf::Color(255, 255, 0));
			menu_number = 1;		
		}else text_single_player.setFillColor(sf::Color(69, 139, 116));

		if (sf::IntRect(50, 161, 128, 128).contains(sf::Mouse::getPosition(window))) {
			text_multy_player.setFillColor(sf::Color(255, 255, 0));
			menu_number = 2;
		}else text_multy_player.setFillColor(sf::Color(69, 139, 116));

		if (sf::IntRect(50, 311, 128, 128).contains(sf::Mouse::getPosition(window))) {
			text_settings.setFillColor(sf::Color(255, 255, 0));
			menu_number = 3;
		}else text_settings.setFillColor(sf::Color(69, 139, 116));

		if (sf::IntRect(50, 461, 128, 128).contains(sf::Mouse::getPosition(window))) {
			text_exit.setFillColor(sf::Color(255, 255, 0));
			menu_number = 4;
		}else text_exit.setFillColor(sf::Color(69, 139, 116));

		
		

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		
			if (menu_number == 1) { is_Start_Menu = false; }
			if (menu_number == 2) { is_Start_Menu = false; }
			if (menu_number == 3) { is_Start_Menu = false; }
			if (menu_number == 4) { 				
				window.close();
				is_Start_Menu = false; }		
		}

		/*-------------------------------------------------------------------------------------------*/







		/*-------------------------------------------------------------------------------------------*/
		window.clear(sf::Color(255, 255, 255));
		/*-------------------------------------------------------------------------------------------*/
		window.draw(sprite_back);
		window.draw(sprite_play1);
		window.draw(sprite_play2);
		window.draw(sprite_settings);
		window.draw(sprite_exit);
		window.draw(text_single_player);
		window.draw(text_multy_player);
		window.draw(text_settings);
		window.draw(text_exit);







		/*-------------------------------------------------------------------------------------------*/
		window.display();
		/*-------------------------------------------------------------------------------------------*/

	}

}








int main()
{

	


	sf::RenderWindow window(sf::VideoMode(window_length, window_hight), "My window");

	start_menu(window);                    /* функция начального меню */



	window.setVerticalSyncEnabled(true);  // вертикальная синхронизация для плавной анимации
	sf::Clock clock;      // переменная таймера


	

	sf::CircleShape circ(ball_radius);
	circ.setFillColor(sf::Color(255, 140, 0));
	circ.setPosition(window_length/4.0, window_hight/4.0);
	circ.setOrigin(ball_radius, ball_radius);                   /* координаты центра шара от верхнего левого угла  */

	sf::Vector2f speed_ball = { ball_speed_x, ball_speed_y};    /* скорость мяча заданная вектором */
	sf::Vector2f speed_racket = { racket_speed_x, racket_speed_y };  /* скорость рокетки заданная вектором */

	/* ракетка 1*/

	sf::RectangleShape racket_1(sf::Vector2f(racket_a, racket_b));
	racket_1.setFillColor(sf::Color(0, 0, 255));
	racket_1.setOrigin(racket_a / 2.0, racket_b / 2.0);
	racket_1.setPosition(racket_a/2.0, window_hight / 2.0);

	/* ракетка 2*/

	sf::RectangleShape racket_2(sf::Vector2f(racket_a, racket_b));
	racket_2.setFillColor(sf::Color(255, 0, 0));
	racket_2.setOrigin(racket_a / 2.0, racket_b / 2.0);
	racket_2.setPosition(window_length - racket_a / 2.0, window_hight / 2.0);


	/*
	sf::Texture texture;
	if (!texture.loadFromFile("txtr_123.jpg")) {
		std::cout << "Texture loading error! " << std::endl;	
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(50, 300));
	sprite.setTextureRect(sf::IntRect(39, 39, 50, 50));
	/**/

	/*-----------------------звук---------------------------------------------------------------*/
	
	sf::SoundBuffer buffer_1;
	if (buffer_1.loadFromFile("Cow.wav")) {
		std::cout <<" Sound1 is loaded!" << std::endl;
	}
	else cout << " Sound2 loading error!" << endl;

	sf::Sound sound_1;
	sound_1.setBuffer(buffer_1);

	sf::SoundBuffer buffer_2;
	if (buffer_2.loadFromFile("Horse.wav")) {
		std::cout << " Sound2 is loaded!" << std::endl;
	}
	else cout << " Sound2 loading error!" << endl;
	sf::Sound sound_2;
	sound_2.setBuffer(buffer_2);
	
	



	/*-------------------------------------------Текст----------------------------------------- */
	sf::Font font;
	if (font.loadFromFile("ARIALUNI.TTF")) {
		cout << " Font is loaded! " << endl;
	}
	else cout << " Error! Font is not loaded! " << endl;

	sf::Text game_name;
	game_name.setFont(font);
	game_name.setFillColor(sf::Color(69, 139, 116));
	game_name.setCharacterSize(50);
	game_name.setString("Dark Orange Ping-Pong  =)");
	game_name.setStyle(sf::Text::Bold);
	game_name.setPosition(window_length / 9, window_hight / 1000);

	sf::Text version;
	version.setFont(font);
	version.setFillColor(sf::Color(0, 100, 0));
	version.setCharacterSize(20);
	version.setString("Version v1.0.0.0");
	version.setPosition(window_length - 200, window_hight - 25);

	sf::Text brend;
	brend.setFont(font);
	brend.setFillColor(sf::Color(0, 100, 0));
	brend.setCharacterSize(20);
	brend.setString("MaxMalakhovGameDev=)");
	brend.setPosition(25, window_hight - 25);

	/*-------------------------------------------счетчик очков----------------------------------------- */
	sf::Text score_left;
	sf::Text score_right;
	score_left.setFont(font);
	score_right.setFont(font);
	score_left.setFillColor(sf::Color(0, 0, 255));
	score_right.setFillColor(sf::Color(255, 0, 0));
	score_left.setCharacterSize(50);
	score_right.setCharacterSize(50);
	score_left.setPosition( 50, 50);
	score_right.setPosition(window_length - 100,50);
	//score_left.setString("00");
	//score_right.setString("00");
	int score_l = 0, score_r = 0;   /* Инициализируем переменные начальными значениями */
	
	/*------------первый вариант счетчика - вывод через строку символов - char массив------------------*/
	/*
	char str1[] = "123456789";
	text.setString(str1[1]);
	text.setStyle(sf::Text::Bold);
	text.setPosition(window_length / 3, window_hight / 1000);
	/**/

	/*-----второй вариант - испоьзование заголовочного файла <sstream> и гласса sstringstream --------------------*/

	//stringstream ss;
	//float score = 13.1559;
	//ss << score;
	//string st = ss.str(); - возможно обойтись и без этой строки.
	//text.setString(ss.str());

	/**/







	/*___________________________Главный цикл____________________________________________________  */

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if ((event.type == sf::Event::Closed)|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		/*---------------------------------------------------------------------------------------*/


		/* Сюда (перед window.clear() ) пишем код отвечающий за всю движуху =)))  */

		/*---------------------Движение мяча и ракетки ------------------------------------------------------*/



		const float delta_time = clock.restart().asSeconds();		
		sf::Vector2f pos_ball = circ.getPosition();   /*  вектор координат мяча */		
		sf::Vector2f pos_racket_1 = racket_1.getPosition();  /* вектор координат рокетки 1*/
		sf::Vector2f pos_racket_2 = racket_2.getPosition();  /* вектор координат рокетки 2*/


		bool goal = true;		/* переменная отвечает за то забит ли гол , т.е. вышел ли мяч за границы поля */





/*-----------------------Движение ракетки 1----------------------------------------------------*/	


		/* Ниже идущий кусок закомментированного кода не работал с кнопками клавы  кроме  left right up doun ..... хз почему.  */

		/*if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Up && pos_racket_1.y>=racket_b/2.0  )
			{
				cout << " najata knopka vverh! " << endl;
				pos_racket_1.y += -speed_racket.y*delta_time;
			}
			if (event.key.code == sf::Keyboard::Down && pos_racket_1.y<=window_hight-racket_b/2.0)
			{
				cout << " najata knopka vniz! " << endl;
				pos_racket_1.y += speed_racket.y*delta_time;
			}
			
			if (event.key.code == sf::Keyboard::Left && pos_racket_1.x>=racket_a / 2.0)
			{
				cout << " najata knopka left! " << endl;
				pos_racket_1.x += -speed_racket.x*delta_time;
			}
			if (event.key.code == sf::Keyboard::Right && pos_racket_1.x<=player_1_xzone - racket_a / 2.0)
			{
				cout << " najata knopka right! " << endl;
				pos_racket_1.x += speed_racket.x*delta_time;
			}	

			
		}
		/**/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pos_racket_1.y >= racket_b / 2.0)
		{
			cout << " najata knopka vverh! " << endl;
			pos_racket_1.y += -speed_racket.y*delta_time;
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pos_racket_1.y <= window_hight - racket_b / 2.0)
		{
			cout << " najata knopka vniz! " << endl;
			pos_racket_1.y += speed_racket.y*delta_time;
		}


		/* Движение влево и вправо в границах player_xzone */
		/*
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && pos_racket_1.x >= racket_a / 2.0)
		{
			cout << " najata knopka left! " << endl;
			pos_racket_1.x += -speed_racket.x*delta_time;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && pos_racket_1.x <= player_xzone - racket_a / 2.0)
		{
			cout << " najata knopka right! " << endl;
			pos_racket_1.x += speed_racket.x*delta_time;
		}
		/**/

		racket_1.setPosition(pos_racket_1);


		/*---------------------------------------------------------------------------------------*/




		/*-----------------------Движение ракетки 2----------------------------------------------------*/		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos_racket_2.y >= racket_b / 2.0)
		{
			cout << " najata knopka vverh! " << endl;
			pos_racket_2.y += -speed_racket.y*delta_time;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos_racket_2.y <= window_hight - racket_b / 2.0)
		{
			cout << " najata knopka vniz! " << endl;
			pos_racket_2.y += speed_racket.y*delta_time;
		}


		/* Движение влево и вправо в границах player_xzone */
		/*
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && pos_racket_1.x >= racket_a / 2.0)
		{
		cout << " najata knopka left! " << endl;
		pos_racket_1.x += -speed_racket.x*delta_time;
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && pos_racket_1.x <= player_xzone - racket_a / 2.0)
		{
		cout << " najata knopka right! " << endl;
		pos_racket_1.x += speed_racket.x*delta_time;
		}
		/**/

		racket_2.setPosition(pos_racket_2);


		/*---------------------------------------------------------------------------------------*/


		/* Условия отражения от стенок  */

		/* От левой и правой  */
		/*
		if (pos_ball.x >= window_length - ball_radius && speed_ball.x > 0) {

			speed_ball.x=-speed_ball.x;
		}
		/**/
		/*
		if (pos_ball.x <=ball_radius && speed_ball.x < 0) {

			speed_ball.x = -speed_ball.x;
		}
		/**/





		/* От верхней и нижней */
		if (pos_ball.y >= window_hight - ball_radius && speed_ball.y > 0) {

			speed_ball.y = -speed_ball.y;
		}
		if (pos_ball.y <= ball_radius && speed_ball.y < 0) {

			speed_ball.y = -speed_ball.y;
		}

		/* Условия отражения от ракетки 1  */
		if ((pos_ball.x-ball_radius <= pos_racket_1.x + racket_a / 2.0 && pos_ball.y>=pos_racket_1.y-racket_b/2.0-0.8*ball_radius 
			&& pos_ball.y <= pos_racket_1.y + racket_b / 2.0+ 0.8*ball_radius)) {
			speed_ball.x = -speed_ball.x;		
		}


		/* Условия отражения от ракетки 2  */
		if ((pos_ball.x + ball_radius >= pos_racket_2.x - racket_a / 2.0 && pos_ball.y >= pos_racket_2.y - racket_b / 2.0 - 0.8*ball_radius
			&& pos_ball.y <= pos_racket_2.y + racket_b / 2.0 + 0.8*ball_radius)) {
			speed_ball.x = -speed_ball.x;
		}


		/* Если мяч улетает за левую или правую грань экрана, прибавляется 1 к счетчику очков соответствующего
		игрока и мячик вводится в игру заново при этом подача осуществляется в направлении противоположного игрока */



		if (pos_ball.x > window_length + ball_radius) {
			goal = false;
			score_l++;			
			sound_1.play();
		}
		if (pos_ball.x < -ball_radius) {
			goal = false;
			score_r++;		
			sound_2.play();
		}
		

	

		if (goal) {
			pos_ball += speed_ball*delta_time;
			circ.setPosition(pos_ball);
		}
		else {
			circ.setPosition(window_length / 2.0, window_hight / 2.0);
			speed_ball.x = -speed_ball.x;			
		}

		/*--------------------------------------------------------------------------------------------*/
		/* перевод int значений счетчиков в char чтобы их можно было вывести на экран */

		stringstream s_score_l, s_score_r;

		s_score_l << score_l;
		s_score_r << score_r;

		score_left.setString(s_score_l.str());
		score_right.setString(s_score_r.str());
        /*-------------------------------------------------------------------------------------------*/






		/*-------------------------------------------------------------------------------------------*/
		window.clear(sf::Color(255, 255, 255));
		/*-------------------------------------------------------------------------------------------*/
		/* Сюда пишем код отвечающий за вывод на экран всех объектов */

		window.draw(circ);
		window.draw(racket_1);
		window.draw(racket_2);
		window.draw(game_name);
		window.draw(score_left);
		window.draw(score_right);
		window.draw(version);
		window.draw(brend);
	

		/*-------------------------------------------------------------------------------------------*/
		window.display();

	}





	return 0;
}