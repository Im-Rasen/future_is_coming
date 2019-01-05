#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace sf;

class Button
{
private:
    Vector2f position;
    Vector2f size;
    Color button_color;
    RenderWindow *window;
public:
    Button(Vector2f pos, Vector2f scale, RenderWindow *wind) {
        position = pos;
        size = scale;
        window = wind;
    }
    
    void change_button_color(Color colour)
    {
        button_color = colour;
    }
    
    void draw()
    {
        RectangleShape Button(size);
        Button.setFillColor(button_color);
        Button.setPosition(position);
        (*window).draw(Button);
    }
};

int main()
{
    RenderWindow window(VideoMode(640, 480), "Awesome button");
    
    Button *awesome = new Button(Vector2f(300.f, 200.f), Vector2f(100.f, 100.f), &window);
    (*awesome).change_button_color(Color::Red);
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            (*awesome).change_button_color(Color::Magenta);
        }
        if (!Mouse::isButtonPressed(Mouse::Left))
        {
            (*awesome).change_button_color(Color::Red);
        }
        window.clear();
        (*awesome).draw();
        window.display();
    }
    return 0;
}
