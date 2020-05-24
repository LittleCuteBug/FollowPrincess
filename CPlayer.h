class CPlayer
	{
	private:
		int Life, Level;
	public:
		CPlayer(int _Life =20, int _Level = 1);
		void Setter(int _Life, int _Level);
		pii Getter();
		void LifeDecrease();
		void LifeRestore(int _Life = 10);
		void LevelIncrease();
		bool isDead();
		void Print();
		void SDLRenderingGame();
	};