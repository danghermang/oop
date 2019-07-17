int main(void)
{
	Monitor *m = new LifeMonitor();
	EndlessClock chronos(0, 0, 0);
	Human decebal = { 11,7,30,27740 };
	Human constantin_cel_mare = { 27,2,272,23725 };
	Human stefan_cel_mare = { 2,7,1433,25915 };
	Human milarepa = { 4,10,1052,28109 };
	Human columb = { 21,9,1451,26774 };
	Human eminescu = { 15,1,1850,14235 };
	Human einstein = { 14,3,1879,27740 };
	Human chuck_norris = { 1,1,0,2999999999 };
	chronos.AddMonitor(m);
	chronos.AddHuman(decebal);
	chronos.AddHuman(constantin_cel_mare);
	chronos.AddHuman(stefan_cel_mare);
	chronos.AddHuman(milarepa);
	chronos.AddHuman(columb);
	chronos.AddHuman(eminescu);
	chronos.AddHuman(einstein);
	chronos.AddHuman(chuck_norris);
	chronos.RunTime();
	return 0;
}