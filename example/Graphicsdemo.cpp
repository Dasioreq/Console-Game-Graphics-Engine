#include <cligfx/cligfx.hpp>
#include <thread>
#include <chrono>

int main()
{
	cf::FrameBuffer fb({10, 10});

	int x = 0;
	int y = 0;
	cf::Text text("ABC");
	while(true)
	{
		fb.clear();
		text.position = {float(x++ % 10), float(y++ % 10)};
		fb.draw(text);
		fb.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		std::cout << "END OF FRAME" << std::endl;
	}
}
