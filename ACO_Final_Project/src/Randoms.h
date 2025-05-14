#ifndef RANDOMS_H
#define RANDOMS_H

class Randoms {
private:
	long xpto;
public:
	Randoms (long x);
	double Normal (double avg, double sigma);
	double Uniforme();
	double sorte(int m);
};

#endif // RANDOMS_H
