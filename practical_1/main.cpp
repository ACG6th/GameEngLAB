#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A, //Player1 UP
	Keyboard::Z, //Player1 Down
	Keyboard::Up, //Player2 UP
	Keyboard::Down //Player2 Down
};

const Vector2f paddleSize(25.f, 100.f);
const float ballRadius = 10.f;
const int gameWidth = 800;
const int gameHeight = 600;
const float paddleSpeed = 400.f;
const float paddleOffsetWall = 10.f;
Vector2f ballVelocity;
bool isPlayer1Serving = false; //decides which player os serving the ball and which direction the ball starts moving
const float initialVelocityX = 100.f;
const float initialVelocityY = 60.0f;
const float velocityMultiplier = 1.1f;

CircleShape ball;
RectangleShape paddles[2];
	
void Load(){
		//Set size and origin of paddles
		for (auto &p : paddles) {
			p.setSize(paddleSize);
			p.setOrigin(paddleSize / 2.f);
		}
		
		ballVelocity = { (isPlayer1Serving ? initialVelocityX : -initialVelocityX), initialVelocityY }; //inline if statement
		
		//Set size and origin of ball
		ball.setRadius(ballRadius);
		ball.setOrigin(ballRadius, ballRadius); //Should be half the ball width and height
		//reset paddle position
		paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
		paddles[1].setPosition(Vector2f(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f));
		//reset Ball position
		ball.setPosition(Vector2f(gameWidth / 2.f, gameHeight / 2.f));
}
	
void reset(){
	//reset paddle position
		paddles[0].setPosition(Vector2f(paddleOffsetWall + paddleSize.x / 2.f, gameHeight / 2.f));
		paddles[1].setPosition(Vector2f(gameWidth - paddleOffsetWall - paddleSize.x / 2.f, gameHeight / 2.f));
		//reset Ball position
		ball.setPosition(Vector2f(gameWidth / 2.f, gameHeight / 2.f));
		else if (bx > gameWidth){
			//right wall
			reset();
		} else if (bx < 0) {
			//left wall
			reset();
			
else if (
	//ball is inline or behind AND
	bx < paddleSize.x + paddleOffsetWall &&
	//ball is below top edge of paddle AND
	by > paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
	//ball is above bottom edge of paddle
	by < paddles[0].getPosition().y + (paddleSize.y * 0.5))
	{
		//bounce off left paddle
	}else if (...) {
		//bounce off right paddle
	}
}	
	
	
	
void Update(RenderWindow &window) {
	//Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	//check and consume events
	Event event;
	ball.move(ballVelocity * dt); //moving the ball by its velocity
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		}
	}
	
	//Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
	
	//handle paddle movement
	float direction = 0.0f;
	if (Keyboard::isKeyPressed(controls[0])) {
		direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		direction++;
	}
	paddles[0].move(Vector2f(0.f, direction * paddleSpeed * dt));
	
	//check ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight) { //bottom wall
	//bottom wall
	ballVelocity.x *= velocityMulitiplier;
	ballVelocity.y *= -velocityMultiplier;
	ball.move(Vector2(0.f, 10.f));	
}
	
/*int main(){
  sf::RenderWindow window(sf::VideoMode({200, 200}), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);


  while (window.isOpen()){
      sf::Event event;
      while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
*/

void Render(RenderWindow &window) {
	//Draw everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}