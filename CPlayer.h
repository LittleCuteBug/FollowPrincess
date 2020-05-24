class CPlayer
	{
	private:
		int Life, Level;
	public:
		CPlayer(int _Life =20, int _Level = 1)
		{
			Setter(_Life,_Level);
		}
		void Setter(int _Life, int _Level)
		{
			Level = _Level;
			Life = _Life;
		}
		pii Getter()
		{
			return pii(Life,Level);
		}
		void LifeDecrease()
		{
			Life--;
		}
		void LifeRestore(int _Life = 10)
		{
			Life = _Life;
		}
		void LevelIncrease()
		{
			Level++;
			LifeRestore();
		}
		bool isDead()
		{
			return Life<=0;
		}
		void Print()
		{
			cout<<"Life: "<<Life<<" Level: "<<Level<<endl;
		}
		void SDLRenderingGame();
	};