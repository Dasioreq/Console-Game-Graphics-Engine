class Drawable
{
public:
	virtual ~Drawable() = default;
	void virtual draw() const = 0;
};
