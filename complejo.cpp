#include <iostream>
#include <cmath>
#include <iomanip>

#include "complejo.h"

using namespace std;

complejo::complejo()
	: re_(0), im_(0), precision(2), ModoPrecision( indefinido )   // Inicializadores de miembros.
{
}

complejo::complejo(double r)
	: re_(r), im_(0)
{
}

complejo::complejo(double r, double i)
	: re_(r), im_(i)
{
}

complejo::complejo(complejo const &c)
	: re_(c.re_), im_(c.im_)
{
}

complejo const &
complejo::operator=(complejo const &c)
{
	re_ = c.re_;
	im_ = c.im_;
	return *this;
}

complejo const &
complejo::operator*=(complejo const &c)
{
	double re = re_ * c.re_ - im_ * c.im_;
	double im = re_ * c.im_ + im_ * c.re_;
	re_ = re, im_ = im;
	return *this;
}

complejo const &
complejo::operator/=(complejo const &c)
{
	double modulo = c.abs2();
	double re = re_ * c.re_ + im_ * c.im_;
	double im = re_ * c.im_ - im_ * c.re_;
	re_ = re / modulo, im_ = im / modulo;
	return *this;
}

complejo const &
complejo::operator+=(complejo const &c)
{
	double re = re_ + c.re_;
	double im = im_ + c.im_;
	re_ = re, im_ = im;
	return *this;
}

complejo const &
complejo::operator-=(complejo const &c)
{
	double re = re_ - c.re_;
	double im = im_ - c.im_;
	re_ = re, im_ = im;
	return *this;
}

/** Sobrecarga para Reales */
complejo const &
complejo::operator*=(double const &a)
{
	double re = re_ * a;
	double im = re_ * a;
	re_ = re, im_ = im;
	return *this;
}

complejo const &
complejo::operator/=(double const &a)
{
	double re = re_ / a;
	double im = re_ / a;
	re_ = re, im_ = im;
	return *this;
}

complejo const &
complejo::operator+=(double const &a)
{
	double re = re_ + a;
	re_ = re;
	return *this;
}

complejo const &
complejo::operator-=(double const &a)
{
	double re = re_ - a;
	re_ = re;
	return *this;
}

complejo::~complejo()
{
}

double
complejo::re() const
{
	return re_;
}

double complejo::im() const
{
	return im_;
}

double
complejo::abs() const
{
	return std::sqrt(re_ * re_ + im_ * im_);
}

double
complejo::abs2() const
{
	return re_ * re_ + im_ * im_;
}

complejo const &
complejo::conjugar()
{
	im_*= -1;
	return *this;
}

complejo const
complejo::conjugado() const
{
	return complejo(re_, -im_);
}

bool
complejo::zero() const
{
#define ZERO(x) ((x) == +0.0 && (x) == -0.0)
	return ZERO(re_) && ZERO(im_) ? true : false;
}

complejo const
operator+(complejo const &x, complejo const &y)
{
	complejo z(x.re_ + y.re_, x.im_ + y.im_);
	return z;
}

complejo const
operator-(complejo const &x, complejo const &y)
{
	complejo r(x.re_ - y.re_, x.im_ - y.im_);
	return r;
}

complejo const
operator*(complejo const &x, complejo const &y)
{
	complejo r(x.re_ * y.re_ - x.im_ * y.im_,
	          x.re_ * y.im_ + x.im_ * y.re_);
	return r;
}

complejo const
operator/(complejo const &x, complejo const &y)
{
	return x * y.conjugado() / y.abs2();
}

complejo const
operator/(complejo const &c, double f)
{
	return complejo(c.re_ / f, c.im_ / f);
}

bool
operator==(complejo const &c, double f)
{
	bool b = (c.im_ != 0 || c.re_ != f) ? false : true;
	return b;
}

bool
operator==(complejo const &x, complejo const &y)
{
	bool b = (x.re_ != y.re_ || x.im_ != y.im_) ? true : false;
	return b;
}

bool
operator!=(complejo const &c, double f)
{
	bool b = (c.im_ == 0 && c.re_ == f) ? false : true;
	return b;
}

bool
operator!=(complejo const &x, complejo const &y)
{
	bool b = (x.re_ == y.re_ && x.im_ == y.im_) ? false : true;
	return b;
}

ostream &
operator<<(ostream &os, const complejo &c)
{
	return os << "(" 
	          << c.re_
	          << ", " 
	          << c.im_
	          << ")";
}

istream &
operator>>(istream &is, complejo &c)
{
	int good = false;
	int bad  = false;
	double re = 0;
	double im = 0;
	char ch = 0;

	if (is >> ch
	    && ch == '(') {
		if (is >> re
		    && is >> ch
		    && ch == ','
		    && is >> im
		    && is >> ch
		    && ch == ')')
			good = true;
		else
			bad = true;
	} else if (is.good()) {
		is.putback(ch);
		if (is >> re)
			good = true;
		else
			bad = true;
	}

	if (good)
		c.re_ = re, c.im_ = im;
	if (bad)
		is.clear(ios::badbit);

	return is;
}

// http://www.cplusplus.com/reference/iomanip/setprecision/

bool complejo::setprecision(int digitos)
{
	// Validaciones
	if (digitos < 0) return false;

	precision = digitos;
	return true;
}

int complejo::getprecision() const
{
	return precision;
}

void complejo::setmodoprecision( TipoPrecision valor) 
{
	ModoPrecision = valor;
}

TipoPrecision complejo::getmodoprecision()  const
{
	return ModoPrecision;
}