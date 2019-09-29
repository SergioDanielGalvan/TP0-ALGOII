#ifndef _COMPLEJO_H_INCLUDED_
#define _COMPLEJO_H_INCLUDED_

#include <iostream>

enum TipoPrecision {indefinido, fijo, cientifico};

class complejo {
private:
	double re_, im_;
	int precision;
	TipoPrecision ModoPrecision;

public:
	complejo();
	complejo(double);
	complejo(double, double);
	complejo(const complejo &);
	bool setprecision( int );
	int getprecision() const;
	void setmodoprecision( TipoPrecision );
	TipoPrecision getmodoprecision() const;
	complejo const &operator=(complejo const &);
	complejo const &operator*=(complejo const &);
	complejo const &operator/=(complejo const &);
	complejo const &operator+=(complejo const &);
	complejo const &operator-=(complejo const &);
	// Prototipos de sobrecarga para complejo =/*/+/- real y viceversa
	complejo const &operator=(double const &);
	complejo const &operator*=(double const &);
	complejo const &operator/=(double const &);
	complejo const &operator+=(double const &);
	complejo const &operator-=(double const &);

	~complejo();

	double re() const;
	double im() const;
	double abs() const;
	double abs2() const;
	complejo const &conjugar();
	complejo const conjugado() const;
	bool zero() const;

	friend complejo const operator+(complejo const &, complejo const &);
	friend complejo const operator-(complejo const &, complejo const &);
	friend complejo const operator*(complejo const &, complejo const &);
	friend complejo const operator/(complejo const &, complejo const &);
	friend complejo const operator/(complejo const &, double);

	friend bool operator==(complejo const &, double);
	friend bool operator==(complejo const &, complejo const &);
	friend bool operator!=(complejo const &, double);
	friend bool operator!=(complejo const &, complejo const &);

    // Falta agregar los prototipos de sobrecarga para double
	friend std::ostream &operator<<(std::ostream &, const complejo &);
	friend std::istream &operator>>(std::istream &, complejo &);
};

#endif
