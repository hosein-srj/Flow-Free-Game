#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>

std::string to_str(int i)
{
    std::stringstream ss;
    ss << i;

    std::string result(ss.str());

    return result;
}
int mokhtasat(int y)
{

    if(y>=100&&y<162.5)
        return 0;
    else if(y>=162.5&&y<225)
        return 1;
    else if(y>=225&&y<287.5)
        return 2;
    else if(y>=287.5&&y<350)
        return 3;
    else if(y>=350&&y<412.5)
        return 4;
    else if(y>=412.5&&y<475)
        return 5;
    else if(y>=475&&y<537.5)
        return 6;
    else if(y>=537.5&&y<600)
        return 7;
    else
        return 50;
}

int main(void)
{
    int higsocre=0;
    int level=0,shomar=0;
    int pauses2=0,pauses3=0;
    char a1[8][8]={
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ','M',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ','G',' ',' '},
                  {'M','C',' ','R',' ',' ',' ',' '},
                  {'R',' ',' ','Y','G',' ',' ',' '},
                  {' ','C',' ',' ','B',' ','B','Y'},
                  {' ',' ',' ',' ',' ',' ',' ',' '}
                 };
    char a2[8][8]={
                  {' ',' ',' ',' ',' ',' ','M',' '},
                  {' ','B',' ','R','C',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ','Y',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {'B','G',' ',' ',' ',' ','R','M'},
                  {' ',' ',' ',' ',' ',' ',' ','C'},
                  {'G',' ',' ',' ',' ',' ',' ','Y'}
                 };
    char b1[8][8]={
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '}
                 };
    char c1[8][8]={
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '},
                  {' ',' ',' ',' ',' ',' ',' ',' '}
                 };
    int i,j;
    char p;
    int x1,y1,x2,y2,x3,y3;
    int bo1=0,bo2;
    sf::RenderWindow window(sf::VideoMode(1200, 675), "Flow Free");
    sf::RectangleShape line1(sf::Vector2f(500,3)),line2(sf::Vector2f(3,500)),khat1(sf::Vector2f(80,20)),khat2(sf::Vector2f(20,82.5));
    sf::Texture texture1;
    if(!texture1.loadFromFile("texture1.jpg"))
        return -1;
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sf::CircleShape circle(22.5);
    sf::Font font;
    if (!font.loadFromFile("A.otf"))
        printf("!");
    sf::Time highscore;
    sf::Clock clock;

    while (window.isOpen())
    {
        while(pauses2==0)
        {
            window.clear();
            sf::Text play,welcome;
            play.setString("PLAY");
            play.setFont(font);
            play.setColor(sf::Color::Red);
            play.setCharacterSize(100);
            play.setPosition(450,300);
            welcome.setString("Flow Free Game");
            welcome.setFont(font);
            welcome.setColor(sf::Color::Red);
            welcome.setCharacterSize(110);
            welcome.setPosition(210,100);
            sf::Event event3;
            while (window.pollEvent(event3))
            {
                if (event3.type == sf::Event::Closed)
                    window.close();
                if ( event3.type == sf::Event::MouseMoved )
                {
                    x1=event3.mouseMove.x;
                    y1=event3.mouseMove.y;
                }
                if(event3.type==sf::Event::MouseButtonPressed)
                {
                    if(event3.mouseButton.button==sf::Mouse::Left)
                    {

                        if(x1>450&&x1<725&&y1>320&&y1<420)
                            pauses2=1;
                    }
                }
            }
            if(x1>450&&x1<725&&y1>320&&y1<420)
            {
                play.setStyle(sf::Text::Bold | sf::Text::Underlined );
                play.setColor(sf::Color::Green);
            }
            window.draw(sprite1);
            window.draw(play);
            window.draw(welcome);
            window.display();
        }
        while(pauses3==0)
        {
            window.clear();
            sf::Text marhale1,marhale2;
            marhale1.setString("Level 2");
            marhale1.setFont(font);
            marhale1.setColor(sf::Color::Red);
            marhale1.setCharacterSize(100);
            marhale1.setPosition(450,300);
            marhale2.setString("Level 1");
            marhale2.setFont(font);
            marhale2.setColor(sf::Color::Red);
            marhale2.setCharacterSize(100);
            marhale2.setPosition(450,180);
            sf::Event event3;
            while (window.pollEvent(event3))
            {
                if (event3.type == sf::Event::Closed)
                    window.close();
                if ( event3.type == sf::Event::MouseMoved )
                {
                    x1=event3.mouseMove.x;
                    y1=event3.mouseMove.y;
                }
                if(event3.type==sf::Event::MouseButtonPressed)
                {
                    if(event3.mouseButton.button==sf::Mouse::Left)
                    {

                        if(x1>450&&x1<745&&y1>320&&y1<420)
                        {
                            pauses3=1;
                            level=1;
                        }
                        if(x1>450&&x1<745&&y1>200&&y1<300)
                        {
                            pauses3=1;
                            level=2;
                        }
                    }
                }
            }
            if(x1>450&&x1<745&&y1>320&&y1<420)
            {
                marhale1.setStyle(sf::Text::Bold | sf::Text::Underlined );
                marhale1.setColor(sf::Color::Green);
            }
            if(x1>450&&x1<745&&y1>200&&y1<300)
            {
                marhale2.setStyle(sf::Text::Bold | sf::Text::Underlined );
                marhale2.setColor(sf::Color::Green);
            }
            window.draw(sprite1);
            window.draw(marhale1);
            window.draw(marhale2);
            window.display();
        }
        while(level==1)
        {
            highscore=clock.getElapsedTime();
            window.clear();
            window.draw(sprite1);
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        x1=mokhtasat(event.mouseButton.y);
                        y1=mokhtasat(event.mouseButton.x);
                        if(a1[x1][y1]!=' ')
                        {
                            bo1=1;
                            p=a1[x1][y1]+32;
                            for(i=0;i<8;i++)
                            {
                                for(j=0;j<8;j++)
                                {
                                    if(a1[i][j]==a1[x1][y1]+32)
                                        a1[i][j]=' ';
                                    if(b1[i][j]==p)
                                        b1[i][j]=' ';
                                    if(c1[i][j]==p)
                                        c1[i][j]=' ';
                                }
                            }
                        }
                    }
                }
                if(event.type == sf::Event::MouseButtonReleased)
                {
                    bo1=0;
                }
                if(event.type == sf::Event::MouseMoved && bo1==1)
                {
                    x3=event.mouseMove.x;
                    y3=event.mouseMove.y;
                    x2=mokhtasat(event.mouseMove.y);
                    y2=mokhtasat(event.mouseMove.x);
                    if(a1[x2][y2]==' ')
                        a1[x2][y2]=p;
                    for (i=0;i<8;i++)
                    {
                        for(j=0;j<8;j++)
                        {
                            if( x3>100+j*62.5 && x3<100+62.5*(j+1) && y3>157.5+i*62.5&&y3<167.5+i*62.5)
                                b1[i][j]=p;
                            if( y3>100+i*62.5 && y3<100+62.5*(i+1) && x3>157.5+j*62.5&&x3<167.5+j*62.5)
                                c1[i][j]=p;
                        }
                    }
                }
            }
            for(i=0;i<=8;i++)
            {
                line1.setPosition(100,100+i*62.5);
                window.draw(line1);
            }
            for(i=0;i<=8;i++)
            {
                line2.setPosition(100+i*62.5,100);
                window.draw(line2);
            }
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    circle.setPosition(110+62.5*j,110+62.5*i);
                    if(a1[i][j]=='M' )
                    {
                        circle.setFillColor(sf::Color::Magenta);
                        window.draw(circle);
                    }
                    else if(a1[i][j]=='R')
                    {
                        circle.setFillColor(sf::Color::Red);
                        window.draw(circle);
                    }
                    else if(a1[i][j]=='G' )
                    {
                        circle.setFillColor(sf::Color::Green);
                        window.draw(circle);
                    }
                    else if(a1[i][j]=='B' )
                    {
                        circle.setFillColor(sf::Color::Blue);
                        window.draw(circle);
                    }
                    else if(a1[i][j]=='C' )
                    {
                        circle.setFillColor(sf::Color::Cyan);
                        window.draw(circle);
                    }
                    else if(a1[i][j]=='Y' )
                    {
                        circle.setFillColor(sf::Color::Yellow);
                        window.draw(circle);
                    }
                }
            }
            for (i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    khat2.setPosition(122.5+62.5*j,122.5+62.5*i);
                    if(b1[i][j]=='m' )
                    {
                        khat2.setFillColor(sf::Color::Magenta);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='r')
                    {
                        khat2.setFillColor(sf::Color::Red);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='g' )
                    {
                        khat2.setFillColor(sf::Color::Green);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='b' )
                    {
                        khat2.setFillColor(sf::Color::Blue);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='c' )
                    {
                        khat2.setFillColor(sf::Color::Cyan);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='y' )
                    {
                        khat2.setFillColor(sf::Color::Yellow);
                        window.draw(khat2);
                    }
                }
            }
            for (i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    khat1.setPosition(122.5+62.5*j,122.5+62.5*i);
                    if(c1[i][j]=='m' )
                    {
                        khat1.setFillColor(sf::Color::Magenta);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='r')
                    {
                        khat1.setFillColor(sf::Color::Red);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='g' )
                    {
                        khat1.setFillColor(sf::Color::Green);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='b' )
                    {
                        khat1.setFillColor(sf::Color::Blue);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='c' )
                    {
                        khat1.setFillColor(sf::Color::Cyan);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='y' )
                    {
                        khat1.setFillColor(sf::Color::Yellow);
                        window.draw(khat1);
                    }
                }
            }
            shomar=0;
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(b1[i][j]!=' ')
                        shomar++;
                    if(c1[i][j]!=' ')
                        shomar++;
                }
            }
            if(   a1[0][0]=='g' && a1[0][1]=='g' && a1[0][2]=='g' && a1[0][3]=='g' && a1[0][4]=='g' && a1[0][5]=='g' && a1[0][6]=='g' && a1[0][7]=='g'
               && a1[1][0]=='g' && a1[1][1]=='M' && a1[1][2]=='m' && a1[1][3]=='m' && a1[1][4]=='m' && a1[1][5]=='m' && a1[1][6]=='m' && a1[1][7]=='g'
               && a1[2][0]=='g' && a1[2][1]=='g' && a1[2][2]=='g' && a1[2][3]=='g' && a1[2][4]=='g' && a1[2][5]=='g' && a1[2][6]=='m' && a1[2][7]=='g'
               && a1[3][0]=='m' && a1[3][1]=='m' && a1[3][2]=='m' && a1[3][3]=='m' && a1[3][4]=='m' && a1[3][5]=='G' && a1[3][6]=='m' && a1[3][7]=='g'
               && a1[4][0]=='M' && a1[4][1]=='C' && a1[4][2]=='r' && a1[4][3]=='R' && a1[4][4]=='m' && a1[4][5]=='m' && a1[4][6]=='m' && a1[4][7]=='g'
               && a1[5][0]=='R' && a1[5][1]=='c' && a1[5][2]=='r' && a1[5][3]=='Y' && a1[5][4]=='G' && a1[5][5]=='g' && a1[5][6]=='g' && a1[5][7]=='g'
               && a1[6][0]=='r' && a1[6][1]=='C' && a1[6][2]=='r' && a1[6][3]=='y' && a1[6][4]=='B' && a1[6][5]=='b' && a1[6][6]=='B' && a1[6][7]=='Y'
               && a1[7][0]=='r' && a1[7][1]=='r' && a1[7][2]=='r' && a1[7][3]=='y' && a1[7][4]=='y' && a1[7][5]=='y' && a1[7][6]=='y' && a1[7][7]=='y'
               && shomar==58 )
            {
                if(higsocre==0)
                    higsocre=highscore.asSeconds();
                sf::Text win,high;
                win.setFont(font);
                win.setString("You Win\n Score:");
                win.setPosition(800,200);
                win.setCharacterSize(70);
                high.setFont(font);
                high.setString(to_str(higsocre));
                high.setPosition(1020,290);
                high.setCharacterSize(70);
                window.draw(high);
                window.draw(win);

            }
            window.display();
        }
        while(level==2)
        {
            highscore=clock.getElapsedTime();
            window.clear();
            window.draw(sprite1);
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        x1=mokhtasat(event.mouseButton.y);
                        y1=mokhtasat(event.mouseButton.x);
                        if(a2[x1][y1]!=' ')
                        {
                            bo1=1;
                            p=a2[x1][y1]+32;
                            for(i=0;i<8;i++)
                            {
                                for(j=0;j<8;j++)
                                {
                                    if(a2[i][j]==a2[x1][y1]+32)
                                        a2[i][j]=' ';
                                    if(b1[i][j]==p)
                                        b1[i][j]=' ';
                                    if(c1[i][j]==p)
                                        c1[i][j]=' ';
                                }
                            }
                        }
                    }
                }
                if(event.type == sf::Event::MouseButtonReleased)
                {
                    bo1=0;
                }
                if(event.type == sf::Event::MouseMoved && bo1==1)
                {
                    x3=event.mouseMove.x;
                    y3=event.mouseMove.y;
                    x2=mokhtasat(event.mouseMove.y);
                    y2=mokhtasat(event.mouseMove.x);
                    if(a2[x2][y2]==' ')
                        a2[x2][y2]=p;
                    for (i=0;i<8;i++)
                    {
                        for(j=0;j<8;j++)
                        {
                            if( x3>100+j*62.5 && x3<100+62.5*(j+1) && y3>157.5+i*62.5&&y3<167.5+i*62.5)
                                b1[i][j]=p;
                            if( y3>100+i*62.5 && y3<100+62.5*(i+1) && x3>157.5+j*62.5&&x3<167.5+j*62.5)
                                c1[i][j]=p;
                        }
                    }
                }
            }
            for(i=0;i<=8;i++)
            {
                line1.setPosition(100,100+i*62.5);
                window.draw(line1);
            }
            for(i=0;i<=8;i++)
            {
                line2.setPosition(100+i*62.5,100);
                window.draw(line2);
            }
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    circle.setPosition(110+62.5*j,110+62.5*i);
                    if(a2[i][j]=='M' )
                    {
                        circle.setFillColor(sf::Color::Magenta);
                        window.draw(circle);
                    }
                    else if(a2[i][j]=='R')
                    {
                        circle.setFillColor(sf::Color::Red);
                        window.draw(circle);
                    }
                    else if(a2[i][j]=='G' )
                    {
                        circle.setFillColor(sf::Color::Green);
                        window.draw(circle);
                    }
                    else if(a2[i][j]=='B' )
                    {
                        circle.setFillColor(sf::Color::Blue);
                        window.draw(circle);
                    }
                    else if(a2[i][j]=='C' )
                    {
                        circle.setFillColor(sf::Color::Cyan);
                        window.draw(circle);
                    }
                    else if(a2[i][j]=='Y' )
                    {
                        circle.setFillColor(sf::Color::Yellow);
                        window.draw(circle);
                    }
                }
            }
            for (i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    khat2.setPosition(122.5+62.5*j,122.5+62.5*i);
                    if(b1[i][j]=='m' )
                    {
                        khat2.setFillColor(sf::Color::Magenta);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='r')
                    {
                        khat2.setFillColor(sf::Color::Red);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='g' )
                    {
                        khat2.setFillColor(sf::Color::Green);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='b' )
                    {
                        khat2.setFillColor(sf::Color::Blue);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='c' )
                    {
                        khat2.setFillColor(sf::Color::Cyan);
                        window.draw(khat2);
                    }
                    else if(b1[i][j]=='y' )
                    {
                        khat2.setFillColor(sf::Color::Yellow);
                        window.draw(khat2);
                    }
                }
            }
            for (i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    khat1.setPosition(122.5+62.5*j,122.5+62.5*i);
                    if(c1[i][j]=='m' )
                    {
                        khat1.setFillColor(sf::Color::Magenta);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='r')
                    {
                        khat1.setFillColor(sf::Color::Red);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='g' )
                    {
                        khat1.setFillColor(sf::Color::Green);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='b' )
                    {
                        khat1.setFillColor(sf::Color::Blue);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='c' )
                    {
                        khat1.setFillColor(sf::Color::Cyan);
                        window.draw(khat1);
                    }
                    else if(c1[i][j]=='y' )
                    {
                        khat1.setFillColor(sf::Color::Yellow);
                        window.draw(khat1);
                    }
                }
            }
            shomar=0;
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(b1[i][j]!=' ')
                        shomar++;
                    if(c1[i][j]!=' ')
                        shomar++;
                }
            }
            if(   a2[0][0]=='g' && a2[0][1]=='g' && a2[0][2]=='g' && a2[0][3]=='r' && a2[0][4]=='r' && a2[0][5]=='r' && a2[0][6]=='M' && a2[0][7]=='m'
               && a2[1][0]=='g' && a2[1][1]=='B' && a2[1][2]=='g' && a2[1][3]=='R' && a2[1][4]=='C' && a2[1][5]=='r' && a2[1][6]=='r' && a2[1][7]=='m'
               && a2[2][0]=='g' && a2[2][1]=='b' && a2[2][2]=='g' && a2[2][3]=='g' && a2[2][4]=='c' && a2[2][5]=='c' && a2[2][6]=='r' && a2[2][7]=='m'
               && a2[3][0]=='g' && a2[3][1]=='b' && a2[3][2]=='b' && a2[3][3]=='g' && a2[3][4]=='Y' && a2[3][5]=='c' && a2[3][6]=='r' && a2[3][7]=='m'
               && a2[4][0]=='g' && a2[4][1]=='g' && a2[4][2]=='b' && a2[4][3]=='g' && a2[4][4]=='y' && a2[4][5]=='c' && a2[4][6]=='r' && a2[4][7]=='m'
               && a2[5][0]=='B' && a2[5][1]=='G' && a2[5][2]=='b' && a2[5][3]=='g' && a2[5][4]=='y' && a2[5][5]=='c' && a2[5][6]=='R' && a2[5][7]=='M'
               && a2[6][0]=='b' && a2[6][1]=='b' && a2[6][2]=='b' && a2[6][3]=='g' && a2[6][4]=='y' && a2[6][5]=='c' && a2[6][6]=='c' && a2[6][7]=='C'
               && a2[7][0]=='G' && a2[7][1]=='g' && a2[7][2]=='g' && a2[7][3]=='g' && a2[7][4]=='y' && a2[7][5]=='y' && a2[7][6]=='y' && a2[7][7]=='Y'
               && shomar==58)
            {

                if(higsocre==0)
                    higsocre=highscore.asSeconds();
                sf::Text win,high;
                win.setFont(font);
                win.setString("You Win\n Score:");
                win.setPosition(800,200);
                win.setCharacterSize(70);
                high.setFont(font);
                high.setString(to_str(higsocre));
                high.setPosition(1020,290);
                high.setCharacterSize(70);
                window.draw(high);
                window.draw(win);
            }
            window.display();
        }
    }
    return 0;
}
