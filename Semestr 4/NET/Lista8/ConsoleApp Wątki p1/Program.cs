using System;
using System.Threading;

class MyThread
{
	static void Main()
	{
		Thread watek = new Thread(JakasFunkcja);
		watek.Start();
		for (int i = 0; i < 10; i++) Console.Write("={0}).A=", i);
	}
	static void JakasFunkcja()
	{
		for(int i=0;i<10;i++) Console.Write("+{0}).B+",i);
	}
}