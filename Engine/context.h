
namespace engine
{
	class Context
	{
	public:
		Context();
		virtual ~Context();
		virtual void Tick(double);
	};
};